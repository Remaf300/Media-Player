#ifndef ADDNEWAUDIO_H
#define ADDNEWAUDIO_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class AddNewAudio;
}

class AddNewAudio : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewAudio(QWidget *parent = nullptr);
    ~AddNewAudio();

    void setMainWindow(MainWindow* w);

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_Browse_clicked();

    void on_pushButton_Browse_2_clicked();

private:
    Ui::AddNewAudio *ui;

    MainWindow* mainWindow;
};

#endif // ADDNEWAUDIO_H
