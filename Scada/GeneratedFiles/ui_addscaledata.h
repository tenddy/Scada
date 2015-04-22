/********************************************************************************
** Form generated from reading UI file 'addscaledata.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCALEDATA_H
#define UI_ADDSCALEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddScaleData
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_standardDistance;
    QLabel *label_2;
    QLineEdit *lineEdit_reallyDistance;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *AddScaleData)
    {
        if (AddScaleData->objectName().isEmpty())
            AddScaleData->setObjectName(QStringLiteral("AddScaleData"));
        AddScaleData->resize(250, 160);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddScaleData->sizePolicy().hasHeightForWidth());
        AddScaleData->setSizePolicy(sizePolicy);
        AddScaleData->setMinimumSize(QSize(200, 160));
        AddScaleData->setMaximumSize(QSize(16777215, 160));
        AddScaleData->setBaseSize(QSize(100, 160));
        verticalLayout = new QVBoxLayout(AddScaleData);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 20, -1, -1);
        label = new QLabel(AddScaleData);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_standardDistance = new QLineEdit(AddScaleData);
        lineEdit_standardDistance->setObjectName(QStringLiteral("lineEdit_standardDistance"));
        lineEdit_standardDistance->setFont(font);

        gridLayout->addWidget(lineEdit_standardDistance, 0, 1, 1, 1);

        label_2 = new QLabel(AddScaleData);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_reallyDistance = new QLineEdit(AddScaleData);
        lineEdit_reallyDistance->setObjectName(QStringLiteral("lineEdit_reallyDistance"));
        lineEdit_reallyDistance->setFont(font);

        gridLayout->addWidget(lineEdit_reallyDistance, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new QPushButton(AddScaleData);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton, 0, Qt::AlignHCenter);

        cancelButton = new QPushButton(AddScaleData);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton, 0, Qt::AlignHCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddScaleData);

        QMetaObject::connectSlotsByName(AddScaleData);
    } // setupUi

    void retranslateUi(QDialog *AddScaleData)
    {
        AddScaleData->setWindowTitle(QApplication::translate("AddScaleData", "AddScaleData", 0));
        label->setText(QApplication::translate("AddScaleData", "\346\240\207\345\207\206\350\267\235\347\246\273", 0));
        lineEdit_standardDistance->setText(QString());
        label_2->setText(QApplication::translate("AddScaleData", "\345\256\236\351\231\205\350\267\235\347\246\273", 0));
        okButton->setText(QApplication::translate("AddScaleData", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("AddScaleData", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddScaleData: public Ui_AddScaleData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCALEDATA_H
