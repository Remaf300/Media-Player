#ifndef EDITSONGINFOS_H
#define EDITSONGINFOS_H

#include <mainwindow.h>
#include <QDialog>

namespace Ui {
class EditSongInfos;
}

class EditSongInfos : public QDialog
{
    Q_OBJECT

public:
    explicit EditSongInfos(QWidget *parent = nullptr);
    ~EditSongInfos();

    void setMainWindow(MainWindow* w);
    void setSongInfos(int songIndex, QString fileUrl, QString artistName, QString albumName, QString albumCoverImageUrl);

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_Browse_clicked();

    void on_pushButton_Browse_2_clicked();

private:
    Ui::EditSongInfos *ui;

    MainWindow* mainWindow;
    int itemToModifyIndex;
};

#endif // EDITSONGINFOS_H
