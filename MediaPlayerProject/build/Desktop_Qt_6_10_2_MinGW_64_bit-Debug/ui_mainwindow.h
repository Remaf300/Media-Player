/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddAudioFile;
    QWidget *centralwidget;
    QLabel *label_File_Name;
    QSlider *horizontalSlider_Audio_File_Duration;
    QSlider *verticalSlider_Audio_Volume;
    QPushButton *pushButton_Volume;
    QLabel *label_Value_1;
    QLabel *label_Value_2;
    QLabel *label_Album_Cover;
    QLabel *label_File_Artist_Name;
    QPushButton *pushButton_Seek_Back;
    QPushButton *pushButton_Seek_Forward;
    QPushButton *pushButton_Play;
    QTreeWidget *treeWidget;
    QPushButton *pushButton_RemoveSong;
    QPushButton *pushButton_EditSong;
    QMenuBar *menubar;
    QMenu *menuOpen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(934, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:rgb(40,40,40);\n"
"}"));
        actionAddAudioFile = new QAction(MainWindow);
        actionAddAudioFile->setObjectName("actionAddAudioFile");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_File_Name = new QLabel(centralwidget);
        label_File_Name->setObjectName("label_File_Name");
        label_File_Name->setGeometry(QRect(90, 470, 431, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_File_Name->setFont(font);
        label_File_Name->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:rgb(255,255,255);\n"
"	border:none;\n"
"}"));
        label_File_Name->setFrameShape(QFrame::Shape::Panel);
        label_File_Name->setLineWidth(2);
        label_File_Name->setScaledContents(false);
        label_File_Name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        horizontalSlider_Audio_File_Duration = new QSlider(centralwidget);
        horizontalSlider_Audio_File_Duration->setObjectName("horizontalSlider_Audio_File_Duration");
        horizontalSlider_Audio_File_Duration->setGeometry(QRect(260, 530, 411, 41));
        horizontalSlider_Audio_File_Duration->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal{\n"
"	height:10px;\n"
"	width:385px;\n"
"	background:rgb(70,70,70);\n"
"	border-radius:5px;\n"
"	alternate-background-color: rgb(99, 226, 255);\n"
"}\n"
"QSlider::handle:horizontal{\n"
"	background:rgb(153, 204, 255);\n"
"	width:15px;\n"
"	height:20px;\n"
"	margin:-6px -6px;\n"
"	border-radius:5;\n"
"	border-color:rgb(0,0,0);\n"
"}\n"
"\n"
"QSlider::handle:horizontal:Hover{\n"
"	background-color:rgb(123, 174, 225);\n"
"}"));
        horizontalSlider_Audio_File_Duration->setOrientation(Qt::Orientation::Horizontal);
        verticalSlider_Audio_Volume = new QSlider(centralwidget);
        verticalSlider_Audio_Volume->setObjectName("verticalSlider_Audio_Volume");
        verticalSlider_Audio_Volume->setGeometry(QRect(870, 390, 51, 181));
        verticalSlider_Audio_Volume->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical{\n"
"	height:150px;\n"
"	width:10px;\n"
"	background:gray;\n"
"	border-radius:5px;\n"
"}\n"
"QSlider::handle:vertical{\n"
"	background-color:rgb(153, 204, 255);\n"
"	width:20px;\n"
"	height:20px;\n"
"	margin:-7px -7px;\n"
"	border-radius:10;\n"
"}\n"
"\n"
"QSlider::handle:vertical:Hover{\n"
"	background-color:rgb(123, 174, 225);\n"
"}"));
        verticalSlider_Audio_Volume->setOrientation(Qt::Orientation::Vertical);
        pushButton_Volume = new QPushButton(centralwidget);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setGeometry(QRect(830, 520, 41, 41));
        pushButton_Volume->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	background-color:rgb(153, 204, 255);\n"
"	color:rgb(52,51,64);\n"
"	padding:0px;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color:rgb(123, 174, 225);\n"
"}"));
        pushButton_Volume->setIconSize(QSize(32, 32));
        label_Value_1 = new QLabel(centralwidget);
        label_Value_1->setObjectName("label_Value_1");
        label_Value_1->setGeometry(QRect(210, 540, 51, 20));
        QFont font1;
        font1.setBold(true);
        label_Value_1->setFont(font1);
        label_Value_1->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:rgb(255,255,255);\n"
"}"));
        label_Value_1->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_Value_2 = new QLabel(centralwidget);
        label_Value_2->setObjectName("label_Value_2");
        label_Value_2->setGeometry(QRect(670, 540, 61, 20));
        label_Value_2->setFont(font1);
        label_Value_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:rgb(255,255,255);\n"
"}"));
        label_Value_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_Album_Cover = new QLabel(centralwidget);
        label_Album_Cover->setObjectName("label_Album_Cover");
        label_Album_Cover->setGeometry(QRect(10, 470, 70, 70));
        label_Album_Cover->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	min-width:50px;\n"
"	max-width:70px;\n"
"	min-height:50px;\n"
"	max-height:70px;\n"
"}"));
        label_File_Artist_Name = new QLabel(centralwidget);
        label_File_Artist_Name->setObjectName("label_File_Artist_Name");
        label_File_Artist_Name->setGeometry(QRect(90, 500, 291, 20));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        label_File_Artist_Name->setFont(font2);
        label_File_Artist_Name->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:rgb(255,255,255);\n"
"	border:none;\n"
"}"));
        label_File_Artist_Name->setFrameShape(QFrame::Shape::Panel);
        label_File_Artist_Name->setLineWidth(2);
        label_File_Artist_Name->setScaledContents(false);
        label_File_Artist_Name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_Seek_Back = new QPushButton(centralwidget);
        pushButton_Seek_Back->setObjectName("pushButton_Seek_Back");
        pushButton_Seek_Back->setGeometry(QRect(390, 490, 40, 40));
        pushButton_Seek_Back->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	background-color:rgb(255,255,255, 0);\n"
"	color:rgb(255,255,255);\n"
"	min-width:20px;\n"
"	max-width:20px;\n"
"	min-height:20px;\n"
"	max-height:20px;\n"
"	padding:10px;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color:rgb(50,50,50);\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MediaSkipBackward));
        pushButton_Seek_Back->setIcon(icon);
        pushButton_Seek_Back->setIconSize(QSize(20, 20));
        pushButton_Seek_Forward = new QPushButton(centralwidget);
        pushButton_Seek_Forward->setObjectName("pushButton_Seek_Forward");
        pushButton_Seek_Forward->setGeometry(QRect(490, 490, 40, 40));
        pushButton_Seek_Forward->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"	border-radius:15px;\n"
"	background-color:rgb(255,255,255, 0);\n"
"	color:rgb(255,255,255);\n"
"	min-width:20px;\n"
"	max-width:20px;\n"
"	min-height:20px;\n"
"	max-height:20px;\n"
"	padding:10px;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color:rgb(50,50,50);\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MediaSkipForward));
        pushButton_Seek_Forward->setIcon(icon1);
        pushButton_Seek_Forward->setIconSize(QSize(20, 20));
        pushButton_Play = new QPushButton(centralwidget);
        pushButton_Play->setObjectName("pushButton_Play");
        pushButton_Play->setGeometry(QRect(440, 490, 40, 40));
        pushButton_Play->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	background-color:rgb(153, 204, 255);\n"
"	color:rgb(52,51,64);\n"
"	min-width:20px;\n"
"	max-width:20px;\n"
"	min-height:20px;\n"
"	max-height:20px;\n"
"	padding:10px;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color:rgb(123, 174, 225);\n"
"}"));
        pushButton_Play->setIconSize(QSize(20, 20));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 20, 911, 361));
        treeWidget->setAutoFillBackground(false);
        treeWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget->setLineWidth(5);
        treeWidget->setMidLineWidth(5);
        treeWidget->setAlternatingRowColors(false);
        treeWidget->setIndentation(10);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setItemsExpandable(true);
        treeWidget->setAnimated(false);
        treeWidget->setWordWrap(true);
        treeWidget->setHeaderHidden(false);
        treeWidget->setSupportedDragActions(Qt::DropAction::IgnoreAction);
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setCascadingSectionResizes(true);
        treeWidget->header()->setMinimumSectionSize(150);
        treeWidget->header()->setDefaultSectionSize(150);
        treeWidget->header()->setHighlightSections(false);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);
        pushButton_RemoveSong = new QPushButton(centralwidget);
        pushButton_RemoveSong->setObjectName("pushButton_RemoveSong");
        pushButton_RemoveSong->setGeometry(QRect(100, 400, 80, 24));
        pushButton_EditSong = new QPushButton(centralwidget);
        pushButton_EditSong->setObjectName("pushButton_EditSong");
        pushButton_EditSong->setGeometry(QRect(10, 400, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 934, 21));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionAddAudioFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAddAudioFile->setText(QCoreApplication::translate("MainWindow", "Add Audio File", nullptr));
        label_File_Name->setText(QCoreApplication::translate("MainWindow", "No Song Selected", nullptr));
        pushButton_Volume->setText(QString());
        label_Value_1->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_Value_2->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_Album_Cover->setText(QString());
        label_File_Artist_Name->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton_Seek_Back->setText(QString());
        pushButton_Seek_Forward->setText(QString());
        pushButton_Play->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "Duration", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "Album", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Artist", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Title", nullptr));
        pushButton_RemoveSong->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        pushButton_EditSong->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
