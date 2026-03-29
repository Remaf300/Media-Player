/********************************************************************************
** Form generated from reading UI file 'validateremovesong.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALIDATEREMOVESONG_H
#define UI_VALIDATEREMOVESONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ValidateRemoveSong
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *ValidateRemoveSong)
    {
        if (ValidateRemoveSong->objectName().isEmpty())
            ValidateRemoveSong->setObjectName("ValidateRemoveSong");
        ValidateRemoveSong->resize(400, 100);
        ValidateRemoveSong->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:rgb(40,40,40);\n"
"}"));
        buttonBox = new QDialogButtonBox(ValidateRemoveSong);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(110, 60, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Yes);
        buttonBox->setCenterButtons(true);
        label = new QLabel(ValidateRemoveSong);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 381, 41));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        retranslateUi(ValidateRemoveSong);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ValidateRemoveSong, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ValidateRemoveSong, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ValidateRemoveSong);
    } // setupUi

    void retranslateUi(QDialog *ValidateRemoveSong)
    {
        ValidateRemoveSong->setWindowTitle(QCoreApplication::translate("ValidateRemoveSong", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ValidateRemoveSong", "Delete \"This Song\" ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ValidateRemoveSong: public Ui_ValidateRemoveSong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALIDATEREMOVESONG_H
