#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtCore>
#include <QtWidgets>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void AddAudioFile(QString newFileUrl, QString artistName, QString albumName, QString albumCoverImageUrl);
    void RemoveSong(int itemToRemoveIndex);
    void EditAudioFile(int songIndex, QString newFileUrl, QString artistName, QString albumName, QString albumCoverImageUrl);

private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

    void PlayCurrentSound();

    void on_pushButton_Volume_clicked();

    void on_actionAddAudioFile_triggered();

    void SetAudioFile(QString fileName);

    int FindCurrentSongIndexInPlaylist();

    void on_pushButton_Play_clicked();

    void on_pushButton_Seek_Forward_clicked();

    void on_pushButton_Seek_Back_clicked();

    void on_horizontalSlider_Audio_File_Duration_valueChanged(int value);

    void on_verticalSlider_Audio_Volume_valueChanged();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void UpdateColumnSize();

    void on_pushButton_RemoveSong_clicked();

    void on_pushButton_EditSong_clicked();

private:
    void updateduration(qint64 duration);
    Ui::MainWindow *ui;
    bool IS_Muted = false;
    bool IS_Paused = true;
    QMediaPlayer *MPlayer;
    QAudioOutput *audioOutput;
    qint64 Mduration;
    qfloat16 vol;
    QList<QString> playlist;
    QList<QString> playlistAlbumCoverUrls;
    QList<QTreeWidgetItem *> playlistItems;

    int startColumnWidth = 0;
    int startColumnWidth1 = 0;
    int startColumnWidth2 = 0;
    int startColumnWidth3 = 0;

    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/playlistUrls.txt";
};
#endif // MAINWINDOW_H
