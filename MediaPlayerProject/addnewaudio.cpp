#include "addnewaudio.h"
#include "ui_addnewaudio.h"
#include "mainwindow.h"

AddNewAudio::AddNewAudio(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewAudio)
{
    ui->setupUi(this);
}

AddNewAudio::~AddNewAudio()
{
    delete ui;
}

void AddNewAudio::setMainWindow(MainWindow* w) {
    mainWindow = w;
}

void AddNewAudio::on_buttonBox_accepted()
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
        mainWindow->AddAudioFile(newFileUrl, artistName, albumName, albumCoverImageUrl);
    }
}


void AddNewAudio::on_pushButton_Browse_clicked()
{
    QString fileUrl = QFileDialog::getOpenFileName(this,tr("Select Audio File"), "", tr("MP3 Files (*.mp3)"));
    ui->lineEdit_File_Url->setText(fileUrl);
}


void AddNewAudio::on_pushButton_Browse_2_clicked()
{
    QString fileUrl = QFileDialog::getOpenFileName(this,tr("Select Album Cover File"), "", tr("PNG Files (*.png)"));
    ui->lineEdit_Album_Cover->setText(fileUrl);
}

