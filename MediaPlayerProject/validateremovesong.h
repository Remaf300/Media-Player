#ifndef VALIDATEREMOVESONG_H
#define VALIDATEREMOVESONG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ValidateRemoveSong;
}

class ValidateRemoveSong : public QDialog
{
    Q_OBJECT

public:
    explicit ValidateRemoveSong(QWidget *parent = nullptr);
    ~ValidateRemoveSong();

    void setMainWindow(MainWindow* w);
    void setSongToDelete(QString songName, int itemToRemoveIndex);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ValidateRemoveSong *ui;

    MainWindow* mainWindow;
    int itemToDeleteIndex;
};

#endif // VALIDATEREMOVESONG_H
