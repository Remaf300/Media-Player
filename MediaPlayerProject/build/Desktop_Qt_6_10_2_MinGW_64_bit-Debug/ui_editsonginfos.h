/********************************************************************************
** Form generated from reading UI file 'editsonginfos.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSONGINFOS_H
#define UI_EDITSONGINFOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditSongInfos
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_File_Url;
    QPushButton *pushButton_Browse;
    QLabel *label;
    QLineEdit *lineEdit_Artist_Name;
    QLineEdit *lineEdit_Album_Name;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Album_Cover;
    QPushButton *pushButton_Browse_2;

    void setupUi(QDialog *EditSongInfos)
    {
        if (EditSongInfos->objectName().isEmpty())
            EditSongInfos->setObjectName("EditSongInfos");
        EditSongInfos->resize(612, 231);
        EditSongInfos->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:rgb(40,40,40);\n"
"}"));
        buttonBox = new QDialogButtonBox(EditSongInfos);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(260, 190, 341, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:rgb(40,40,40);\n"
"}"));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEdit_File_Url = new QLineEdit(EditSongInfos);
        lineEdit_File_Url->setObjectName("lineEdit_File_Url");
        lineEdit_File_Url->setGeometry(QRect(130, 20, 371, 24));
        pushButton_Browse = new QPushButton(EditSongInfos);
        pushButton_Browse->setObjectName("pushButton_Browse");
        pushButton_Browse->setGeometry(QRect(520, 20, 80, 24));
        label = new QLabel(EditSongInfos);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 24, 61, 15));
        lineEdit_Artist_Name = new QLineEdit(EditSongInfos);
        lineEdit_Artist_Name->setObjectName("lineEdit_Artist_Name");
        lineEdit_Artist_Name->setGeometry(QRect(130, 60, 371, 24));
        lineEdit_Album_Name = new QLineEdit(EditSongInfos);
        lineEdit_Album_Name->setObjectName("lineEdit_Album_Name");
        lineEdit_Album_Name->setGeometry(QRect(130, 100, 371, 24));
        label_2 = new QLabel(EditSongInfos);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 71, 16));
        label_3 = new QLabel(EditSongInfos);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 100, 71, 16));
        label_4 = new QLabel(EditSongInfos);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 140, 121, 16));
        lineEdit_Album_Cover = new QLineEdit(EditSongInfos);
        lineEdit_Album_Cover->setObjectName("lineEdit_Album_Cover");
        lineEdit_Album_Cover->setGeometry(QRect(130, 140, 371, 24));
        pushButton_Browse_2 = new QPushButton(EditSongInfos);
        pushButton_Browse_2->setObjectName("pushButton_Browse_2");
        pushButton_Browse_2->setGeometry(QRect(520, 140, 80, 24));

        retranslateUi(EditSongInfos);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditSongInfos, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditSongInfos, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditSongInfos);
    } // setupUi

    void retranslateUi(QDialog *EditSongInfos)
    {
        EditSongInfos->setWindowTitle(QCoreApplication::translate("EditSongInfos", "Add a new file", nullptr));
        pushButton_Browse->setText(QCoreApplication::translate("EditSongInfos", "Browse...", nullptr));
        label->setText(QCoreApplication::translate("EditSongInfos", "File Name", nullptr));
        label_2->setText(QCoreApplication::translate("EditSongInfos", "Artist Name", nullptr));
        label_3->setText(QCoreApplication::translate("EditSongInfos", "Album Name", nullptr));
        label_4->setText(QCoreApplication::translate("EditSongInfos", "Album Cover Image", nullptr));
        pushButton_Browse_2->setText(QCoreApplication::translate("EditSongInfos", "Browse...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditSongInfos: public Ui_EditSongInfos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSONGINFOS_H
