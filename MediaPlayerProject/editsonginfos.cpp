#include "editsonginfos.h"
#include "ui_editsonginfos.h"

EditSongInfos::EditSongInfos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditSongInfos)
{
    ui->setupUi(this);
}

EditSongInfos::~EditSongInfos()
{
    delete ui;
}

void EditSongInfos::setMainWindow(MainWindow* w) {
    mainWindow = w;
}

void EditSongInfos::setSongInfos(int songIndex, QString fileUrl, QString artistName, QString albumName, QString albumCoverImageUrl){
    itemToModifyIndex = songIndex;
    ui->lineEdit_File_Url->setText(fileUrl);
    ui->lineEdit_Artist_Name->setText(artistName);
    ui->lineEdit_Album_Name->setText(albumName);
    ui->lineEdit_Album_Cover->setText(albumCoverImageUrl);
}

void EditSongInfos::on_buttonBox_accepted()
{
    // Stocker:
    //le lien du fichier
    QString newFileUrl = ui->lineEdit_File_Url->text();
    // le nom de l'artiste
    QString artistName = ui->lineEdit_Artist_Name->text();
    // le nom de l'album
    QString albumName = ui->lineEdit_Album_Name->text();
    // le lien de la cover de l'album
    QString albumCoverImageUrl = ui->lineEdit_Album_Cover->text();

    // On vérifie que les liens sont valides
    if (QUrl(newFileUrl).isValid() && newFileUrl != "" && artistName != "" && albumName != ""){
        // Appeler une fonction qui va gérer la création du fichier audio
        mainWindow->EditAudioFile(itemToModifyIndex, newFileUrl, artistName, albumName, albumCoverImageUrl);
    }
}


void EditSongInfos::on_pushButton_Browse_clicked()
{
    QString fileUrl = QFileDialog::getOpenFileName(this,tr("Select Audio File"), "", tr("MP3 Files (*.mp3)"));
    ui->lineEdit_File_Url->setText(fileUrl);
}


void EditSongInfos::on_pushButton_Browse_2_clicked()
{
    QString fileUrl = QFileDialog::getOpenFileName(this,tr("Select Album Cover File"), "", tr("PNG Files (*.png)"));
    ui->lineEdit_Album_Cover->setText(fileUrl);
}