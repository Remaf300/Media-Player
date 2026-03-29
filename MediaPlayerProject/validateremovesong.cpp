#include "validateremovesong.h"
#include "ui_validateremovesong.h"

ValidateRemoveSong::ValidateRemoveSong(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ValidateRemoveSong)
{
    ui->setupUi(this);
}

ValidateRemoveSong::~ValidateRemoveSong()
{
    delete ui;
}

void ValidateRemoveSong::setMainWindow(MainWindow* w) {
    mainWindow = w;
}

void ValidateRemoveSong::setSongToDelete(QString songName, int itemToRemoveIndex) {
    itemToDeleteIndex = itemToRemoveIndex;
    ui->label->setText("Remove " + songName + " from your playlist?");
}

void ValidateRemoveSong::on_buttonBox_accepted()
{
    mainWindow->RemoveSong(itemToDeleteIndex);
}

