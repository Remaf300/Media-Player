#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewaudio.h"
#include "validateremovesong.h"
#include "editsonginfos.h"
#include <QPixmap>
#include <QFile>
#include <QMessageBox>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MPlayer = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    // Ouvrir le fichier save
    QFile file(path);
    if(file.exists()){
        if(!file.open(QIODevice::ReadWrite)){
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);
        // Tant qu'il y a encore des lignes dans le fichier txt, on récupère le texte et on crée un item à mettre dans le listWidget
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList songInfoslist = line.split(QRegularExpression(";"), Qt::SkipEmptyParts);
            QString fileUrl = songInfoslist[0];
            QString songArtistName = songInfoslist[1];
            QString songAlbumName = songInfoslist[2];
            QString songDuration = songInfoslist[3];
            QString songAlbumCoverUrl = songInfoslist[4];

            QFileInfo fileinfo(fileUrl);

            QTreeWidgetItem* itemSaved = new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr),
                                                             QStringList(QString(fileinfo.baseName())));
            itemSaved->setText(1, songArtistName);
            itemSaved->setText(2, songAlbumName);
            itemSaved->setText(3, songDuration);

            playlistItems.append(itemSaved);
            // Ajouter les sons à la playlist
            playlist.append(fileUrl);
            playlistAlbumCoverUrls.append(songAlbumCoverUrl);
        }

        ui->treeWidget->insertTopLevelItems(0, playlistItems);
    }
    file.close();

    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->verticalSlider_Audio_Volume->setMinimum(1);
    ui->verticalSlider_Audio_Volume->setMaximum(100);
    ui->verticalSlider_Audio_Volume->setValue(70);

    vol = (qfloat16)(ui->verticalSlider_Audio_Volume->value() / 200.0);
    audioOutput->setVolume(vol);
    MPlayer->setAudioOutput(audioOutput);

    connect(MPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(MPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    // Si on a récupéré au moins un fichier audio, on le séléctionne
    if (playlist.length() >= 1){
        SetAudioFile(playlist[0]);
        UpdateColumnSize();
    }

    ui->horizontalSlider_Audio_File_Duration->setRange(0, MPlayer->duration() / 1000);

    // Timer qui appelle la fonction UpdateColumSize toutes les frames environ
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(UpdateColumnSize()));
    timer->start(1);
}


MainWindow::~MainWindow()
{
    delete ui;

    // Créer le fichier save
    QFile::remove(path);
    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    // Récupérer l'url de chaque son dans la playlist et le tree widget
    for (int i = 0; i < playlist.length(); ++i) {
        out<<playlist[i];
        out << ";" <<ui->treeWidget->topLevelItem(i)->text(1);
        out << ";" <<ui->treeWidget->topLevelItem(i)->text(2);
        out << ";" <<ui->treeWidget->topLevelItem(i)->text(3);
        out << ";" << playlistAlbumCoverUrls[i];
        if (i != playlist.length() - 1){
            out<<"\n";
        }
    }

    file.close();
}

void MainWindow::updateduration(qint64 duration)
{
    QString timestr;
    if(duration || Mduration){
        QTime CurrentTime((duration / 3600) % 60,(duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
        QTime totalTime((Mduration / 3600) % 60, (Mduration / 60)% 60, Mduration % 60, (Mduration * 1000) % 1000);

        // Passer à la chanson suivante si le son est terminé
        if (CurrentTime == totalTime){
            on_pushButton_Seek_Forward_clicked();
        }

        QString format = "mm:ss";
        if(Mduration > 3600){
            format = "hh:mm:ss";
        }
        ui->label_Value_1->setText(CurrentTime.toString(format));
        ui->label_Value_2->setText(totalTime.toString(format));

        int currentSongIndex = FindCurrentSongIndexInPlaylist();
        QTreeWidgetItem* currentSong = ui->treeWidget->topLevelItem(currentSongIndex);
        if(currentSong->text(3) == " "){
            currentSong->setText(3, totalTime.toString(format));
        }
    }
}

void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration / 1000;
    ui->horizontalSlider_Audio_File_Duration->setMaximum(Mduration);
}

void MainWindow::positionChanged(qint64 progress)
{
    if(!ui->horizontalSlider_Audio_File_Duration->isSliderDown()){
        ui->horizontalSlider_Audio_File_Duration->setValue(progress / 1000);
    }

    updateduration(progress / 1000);
}

void MainWindow::on_pushButton_Volume_clicked()
{
    if (IS_Muted == false){
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        IS_Muted = true;

    }else{
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        IS_Muted = false;
    }

    audioOutput->setMuted(IS_Muted);
}


void MainWindow::on_actionAddAudioFile_triggered()
{
    // création d'un objet de la classe AddNewAudio et on affiche la fenêtre
    AddNewAudio addNewAudio;
    addNewAudio.setModal(true);
    addNewAudio.setMainWindow(this);
    addNewAudio.exec();
}

void MainWindow::AddAudioFile(QString newFileUrl, QString artistName, QString albumName, QString albumCoverImageUrl){
    // Vérifier si le son n'est pas déjà dans la liste
    QFileInfo fileinfo(newFileUrl);
    QString songUrl = newFileUrl;
    songUrl.remove(0, 1);
    bool isAlreadyInPlaylist = false;
    for (int i = 0; i < playlist.length(); i++){
        QString urlInPlaylist = playlist[i];
        urlInPlaylist.remove(0, 1);
        if(newFileUrl == urlInPlaylist){
            isAlreadyInPlaylist = true;
        }
    }

    if(!isAlreadyInPlaylist){
        // Ajouter le son à la playlist
        playlist.append(newFileUrl);
        playlistAlbumCoverUrls.append(albumCoverImageUrl);
        // Ajouter le son dans le widget des chansons
        QTreeWidgetItem* itemToAdd = new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr),
                                                         QStringList(QString(fileinfo.baseName())));
        itemToAdd->setText(1, artistName);
        itemToAdd->setText(2, albumName);
        itemToAdd->setText(3, " ");

        playlistItems.append(itemToAdd);
        ui->treeWidget->addTopLevelItems(playlistItems);

        if(!MPlayer->isPlaying()){
            SetAudioFile(newFileUrl);
        }

        UpdateColumnSize();
    }
}

void MainWindow::SetAudioFile(QString FileName){
    // Convertir le nom du fichier en url
    MPlayer->setSource(QUrl(FileName));

    int currentSongIndex = FindCurrentSongIndexInPlaylist();

    // Actualiser le nom de la chanson
    QFileInfo fileinfo(FileName);
    ui->label_File_Name->setText(fileinfo.fileName().chopped(4));
    // Nom de l'artiste
    ui->label_File_Artist_Name->setText(ui->treeWidget->topLevelItem(currentSongIndex)->text(1));

    // Changer l'image de l'album
    QString defaultImageUrl = "C:/Programmation/QT/Projects/MediaPlayer/images/DefaultAlbumCover.png";
    QPixmap pix(defaultImageUrl);
    // Si l'url donné par l'utilisateur est invalide, on utilise une image par défaut
    if(QUrl(playlistAlbumCoverUrls[currentSongIndex]).isValid() && playlistAlbumCoverUrls[currentSongIndex] != " "){
        pix.load(playlistAlbumCoverUrls[currentSongIndex]);
    }

    ui->label_Album_Cover->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));

    if(!MPlayer->isPlaying()){
        // Changer les timers de la chanson qu'on séléctionne
        QTime currentTime(0, 0, 0, 0);
        QTime totalTime((Mduration / 3600) % 60, (Mduration / 60)% 60, Mduration % 60, (Mduration * 1000) % 1000);
        QString format = "mm:ss";
        if(Mduration > 3600) format = "hh:mm:ss";
        ui->label_Value_1->setText(currentTime.toString(format));
        ui->label_Value_2->setText(totalTime.toString(format));
    }
}


int MainWindow::FindCurrentSongIndexInPlaylist(){
    // Chercher la chanson actuelle
    QString FileUrl = MPlayer->source().url();
    FileUrl.remove(0, 1);

    int currentSongIndex = 0;
    // Trouver sa position dans le widget
    for (int i = 0; i < playlist.length(); i++){
        QString urlInPlaylist = playlist[i];
        urlInPlaylist.remove(0, 1);
        if(FileUrl == urlInPlaylist){
            currentSongIndex = i;
        }
    }

    return currentSongIndex;
}


void MainWindow::on_pushButton_Play_clicked()
{
    if(MPlayer->hasAudio()){
        if(IS_Paused){
            PlayCurrentSound();
        }else{
            MPlayer->pause();
            IS_Paused = true;
            ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        }
    }
}


void MainWindow::on_pushButton_Seek_Forward_clicked()
{
    // Passer à la chanson suivante
    int currentSongIndex = FindCurrentSongIndexInPlaylist();

    // Si on est sur le dernier morceau de la playlist, on met l'index à 0
    if (currentSongIndex == playlist.length() - 1){
        currentSongIndex = 0;
    }else{
        currentSongIndex++;
    }

    // Charger le son suivant dans la liste
    SetAudioFile(playlist[currentSongIndex]);
    PlayCurrentSound();
}


void MainWindow::on_pushButton_Seek_Back_clicked()
{
    // Passer à la chanson précédente
    int currentSongIndex = FindCurrentSongIndexInPlaylist();

    // Si on est sur le dernier morceau de la playlist, on met l'index à 0
    if (currentSongIndex == 0){
        currentSongIndex = playlist.length() - 1;
    }else{
        currentSongIndex--;
    }

    // Charger le son suivant dans la liste
    SetAudioFile(playlist[currentSongIndex]);
    PlayCurrentSound();
}

void MainWindow::PlayCurrentSound(){
    MPlayer->play();
    IS_Paused = false;
    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}


void MainWindow::on_horizontalSlider_Audio_File_Duration_valueChanged(int value)
{
    int newPosition = value*1000;
    if(MPlayer->position() < newPosition - 100 || MPlayer->position() > newPosition + 100){
        MPlayer->setPosition(newPosition);
    }
}


void MainWindow::on_verticalSlider_Audio_Volume_valueChanged()
{
    double value = ui->verticalSlider_Audio_Volume->value();
    if(value <= 1){
        value = 0;
    }
    vol = (qfloat16)(value / 200.0);
    audioOutput->setVolume(vol);
    MPlayer->setAudioOutput(audioOutput);
}


void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    int itemIndex = 0;
    // Trouver la position de l'item dans le listWidget
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        if(item == ui->treeWidget->topLevelItem(i)){
            itemIndex = i;
        }
    }

    // Jouer le son
    SetAudioFile(playlist[itemIndex]);
    PlayCurrentSound();
}

void MainWindow::UpdateColumnSize(){

    int currentColumnWidth = ui->treeWidget->columnWidth(0);
    int currentColumnWidth1 = ui->treeWidget->columnWidth(1);
    int currentColumnWidth2 = ui->treeWidget->columnWidth(2);
    int currentColumnWidth3 = ui->treeWidget->columnWidth(3);

    bool shouldUpdateSize = startColumnWidth != currentColumnWidth
                            || startColumnWidth1 != currentColumnWidth1
                            || startColumnWidth2 != currentColumnWidth2
                            || startColumnWidth3 != currentColumnWidth3;
    // Actualiser la taille des colonnes seulement si une colonne change de taille
    if(shouldUpdateSize == true){
        ui->treeWidget->resizeColumnToContents(0);
        ui->treeWidget->resizeColumnToContents(1);
        ui->treeWidget->resizeColumnToContents(2);
        ui->treeWidget->resizeColumnToContents(3);

        startColumnWidth = ui->treeWidget->columnWidth(0);
        startColumnWidth = ui->treeWidget->columnWidth(1);
        startColumnWidth = ui->treeWidget->columnWidth(2);
        startColumnWidth = ui->treeWidget->columnWidth(3);
    }

}

void MainWindow::on_pushButton_RemoveSong_clicked()
{
    // Récupérer l'item séléctionné
    QTreeWidgetItem* itemToDelete = ui->treeWidget->currentItem();
    if(itemToDelete == NULL) return;

    int songToDeleteIndex = 0;
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        if(itemToDelete == ui->treeWidget->topLevelItem(i)){
            songToDeleteIndex = i;
        }
    }

    QString songName = ui->treeWidget->currentItem()->text(0);

    // Faire spawn une fenêtre qui nous dit si on est sûr
    ValidateRemoveSong validateRemoveSong;
    validateRemoveSong.setModal(true);
    validateRemoveSong.setMainWindow(this);
    validateRemoveSong.setSongToDelete(songName, songToDeleteIndex);
    validateRemoveSong.exec();
}

void MainWindow::RemoveSong(int itemToRemoveIndex){
    ui->treeWidget->takeTopLevelItem(itemToRemoveIndex);
    playlist.remove(itemToRemoveIndex);
    playlistAlbumCoverUrls.remove(itemToRemoveIndex);
}


void MainWindow::on_pushButton_EditSong_clicked()
{
    // Récupérer l'item séléctionné
    QTreeWidgetItem* itemToEdit = ui->treeWidget->currentItem();
    if(itemToEdit == NULL) return;

    int songToEditIndex = 0;
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        if(itemToEdit == ui->treeWidget->topLevelItem(i)){
            songToEditIndex = i;
        }
    }

    QString songUrl = playlist[songToEditIndex];
    QString songArtist = ui->treeWidget->topLevelItem(songToEditIndex)->text(1);
    QString songAlbum = ui->treeWidget->topLevelItem(songToEditIndex)->text(2);
    QString songAlbumCoverUrl = playlistAlbumCoverUrls[songToEditIndex];

    // Faire spawn une fenêtre qui nous dit si on est sûr
    EditSongInfos editSongInfos;
    editSongInfos.setModal(true);
    editSongInfos.setMainWindow(this);
    editSongInfos.setSongInfos(songToEditIndex, songUrl, songArtist, songAlbum, songAlbumCoverUrl);
    editSongInfos.exec();
}

void MainWindow::EditAudioFile(int songIndex, QString newFileUrl, QString artistName, QString albumName, QString albumCoverImageUrl){
    // Vérifier si le son n'est pas déjà dans la liste
    QFileInfo fileinfo(newFileUrl);

    // Modifier dans les playlists
    playlist[songIndex] = newFileUrl;
    playlistAlbumCoverUrls[songIndex] = albumCoverImageUrl;

    // Ajouter le son dans le widget des chansons
    ui->treeWidget->topLevelItem(songIndex)->setText(0, fileinfo.baseName());
    ui->treeWidget->topLevelItem(songIndex)->setText(1, artistName);
    ui->treeWidget->topLevelItem(songIndex)->setText(1, artistName);
    ui->treeWidget->topLevelItem(songIndex)->setText(2, albumName);

    //playlistItems[songIndex] = ui->treeWidget->topLevelItem(songIndex);

    UpdateColumnSize();
}