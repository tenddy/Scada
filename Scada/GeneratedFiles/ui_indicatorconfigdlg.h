/********************************************************************************
** Form generated from reading UI file 'indicatorconfigdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDICATORCONFIGDLG_H
#define UI_INDICATORCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndicatorConfigDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *channelLablel;
    QLineEdit *channelLineEdit;
    QCheckBox *titleCheckBox;
    QLineEdit *titleLineEdit;
    QGroupBox *PosGroupBox;
    QGridLayout *gridLayout_6;
    QLabel *currentPageLablel;
    QSpinBox *pageSpinBox;
    QLabel *posLablel;
    QSpinBox *posSpinBox;
    QGridLayout *gridLayout;
    QGroupBox *centerGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *radiusXLablel;
    QSpinBox *XSpinBox;
    QLabel *radiusYLablel;
    QSpinBox *YSpinBox;
    QLabel *radiusLablel;
    QSpinBox *radiusSpinBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *IndicatorConfigDlg)
    {
        if (IndicatorConfigDlg->objectName().isEmpty())
            IndicatorConfigDlg->setObjectName(QStringLiteral("IndicatorConfigDlg"));
        IndicatorConfigDlg->resize(257, 492);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IndicatorConfigDlg->sizePolicy().hasHeightForWidth());
        IndicatorConfigDlg->setSizePolicy(sizePolicy);
        IndicatorConfigDlg->setMaximumSize(QSize(400, 16777215));
        IndicatorConfigDlg->setBaseSize(QSize(400, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        IndicatorConfigDlg->setFont(font);
        verticalLayout = new QVBoxLayout(IndicatorConfigDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(IndicatorConfigDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 30, -1, -1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        channelLablel = new QLabel(groupBox);
        channelLablel->setObjectName(QStringLiteral("channelLablel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(channelLablel->sizePolicy().hasHeightForWidth());
        channelLablel->setSizePolicy(sizePolicy1);
        channelLablel->setLayoutDirection(Qt::LeftToRight);
        channelLablel->setAutoFillBackground(false);
        channelLablel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(channelLablel, 0, 0, 1, 1);

        channelLineEdit = new QLineEdit(groupBox);
        channelLineEdit->setObjectName(QStringLiteral("channelLineEdit"));
        channelLineEdit->setEnabled(false);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        channelLineEdit->setFont(font1);
        channelLineEdit->setFocusPolicy(Qt::ClickFocus);
        channelLineEdit->setAutoFillBackground(false);
        channelLineEdit->setReadOnly(false);
        channelLineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout_2->addWidget(channelLineEdit, 0, 1, 1, 1);

        titleCheckBox = new QCheckBox(groupBox);
        titleCheckBox->setObjectName(QStringLiteral("titleCheckBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(titleCheckBox->sizePolicy().hasHeightForWidth());
        titleCheckBox->setSizePolicy(sizePolicy2);
        titleCheckBox->setChecked(true);

        gridLayout_2->addWidget(titleCheckBox, 1, 0, 1, 1);

        titleLineEdit = new QLineEdit(groupBox);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        gridLayout_2->addWidget(titleLineEdit, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        PosGroupBox = new QGroupBox(groupBox);
        PosGroupBox->setObjectName(QStringLiteral("PosGroupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(PosGroupBox->sizePolicy().hasHeightForWidth());
        PosGroupBox->setSizePolicy(sizePolicy3);
        gridLayout_6 = new QGridLayout(PosGroupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        currentPageLablel = new QLabel(PosGroupBox);
        currentPageLablel->setObjectName(QStringLiteral("currentPageLablel"));

        gridLayout_6->addWidget(currentPageLablel, 0, 0, 1, 1);

        pageSpinBox = new QSpinBox(PosGroupBox);
        pageSpinBox->setObjectName(QStringLiteral("pageSpinBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pageSpinBox->sizePolicy().hasHeightForWidth());
        pageSpinBox->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(pageSpinBox, 0, 1, 1, 1);

        posLablel = new QLabel(PosGroupBox);
        posLablel->setObjectName(QStringLiteral("posLablel"));

        gridLayout_6->addWidget(posLablel, 1, 0, 1, 1);

        posSpinBox = new QSpinBox(PosGroupBox);
        posSpinBox->setObjectName(QStringLiteral("posSpinBox"));
        sizePolicy4.setHeightForWidth(posSpinBox->sizePolicy().hasHeightForWidth());
        posSpinBox->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(posSpinBox, 1, 1, 1, 1);


        verticalLayout_2->addWidget(PosGroupBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        centerGroupBox = new QGroupBox(groupBox);
        centerGroupBox->setObjectName(QStringLiteral("centerGroupBox"));
        sizePolicy3.setHeightForWidth(centerGroupBox->sizePolicy().hasHeightForWidth());
        centerGroupBox->setSizePolicy(sizePolicy3);
        horizontalLayout = new QHBoxLayout(centerGroupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radiusXLablel = new QLabel(centerGroupBox);
        radiusXLablel->setObjectName(QStringLiteral("radiusXLablel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(radiusXLablel->sizePolicy().hasHeightForWidth());
        radiusXLablel->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(radiusXLablel);

        XSpinBox = new QSpinBox(centerGroupBox);
        XSpinBox->setObjectName(QStringLiteral("XSpinBox"));
        XSpinBox->setMinimum(-10000);
        XSpinBox->setMaximum(10000);

        horizontalLayout->addWidget(XSpinBox);

        radiusYLablel = new QLabel(centerGroupBox);
        radiusYLablel->setObjectName(QStringLiteral("radiusYLablel"));
        sizePolicy5.setHeightForWidth(radiusYLablel->sizePolicy().hasHeightForWidth());
        radiusYLablel->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(radiusYLablel);

        YSpinBox = new QSpinBox(centerGroupBox);
        YSpinBox->setObjectName(QStringLiteral("YSpinBox"));
        YSpinBox->setMinimum(-10000);
        YSpinBox->setMaximum(10000);

        horizontalLayout->addWidget(YSpinBox);


        gridLayout->addWidget(centerGroupBox, 0, 0, 1, 2);

        radiusLablel = new QLabel(groupBox);
        radiusLablel->setObjectName(QStringLiteral("radiusLablel"));
        sizePolicy5.setHeightForWidth(radiusLablel->sizePolicy().hasHeightForWidth());
        radiusLablel->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(radiusLablel, 1, 0, 1, 1);

        radiusSpinBox = new QSpinBox(groupBox);
        radiusSpinBox->setObjectName(QStringLiteral("radiusSpinBox"));
        radiusSpinBox->setMaximum(1000);

        gridLayout->addWidget(radiusSpinBox, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);

#ifndef QT_NO_SHORTCUT
        channelLablel->setBuddy(channelLineEdit);
        currentPageLablel->setBuddy(pageSpinBox);
        posLablel->setBuddy(posSpinBox);
        radiusXLablel->setBuddy(XSpinBox);
        radiusYLablel->setBuddy(YSpinBox);
        radiusLablel->setBuddy(radiusSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(IndicatorConfigDlg);

        QMetaObject::connectSlotsByName(IndicatorConfigDlg);
    } // setupUi

    void retranslateUi(QWidget *IndicatorConfigDlg)
    {
        IndicatorConfigDlg->setWindowTitle(QApplication::translate("IndicatorConfigDlg", "IndicatorConfigDlg", 0));
        groupBox->setTitle(QApplication::translate("IndicatorConfigDlg", "\346\214\207\347\244\272\347\201\257\350\256\276\347\275\256", 0));
        channelLablel->setText(QApplication::translate("IndicatorConfigDlg", "\351\200\232\351\201\223", 0));
        titleCheckBox->setText(QApplication::translate("IndicatorConfigDlg", "\345\220\215\347\247\260", 0));
        PosGroupBox->setTitle(QApplication::translate("IndicatorConfigDlg", "\351\241\265\351\235\242\344\270\216\344\275\215\347\275\256", 0));
        currentPageLablel->setText(QApplication::translate("IndicatorConfigDlg", "\345\275\223\345\211\215\351\241\265\351\235\242", 0));
        posLablel->setText(QApplication::translate("IndicatorConfigDlg", "\345\275\223\345\211\215\344\275\215\347\275\256", 0));
        centerGroupBox->setTitle(QApplication::translate("IndicatorConfigDlg", "\344\270\255\345\277\203\347\202\271", 0));
        radiusXLablel->setText(QApplication::translate("IndicatorConfigDlg", "X", 0));
        radiusYLablel->setText(QApplication::translate("IndicatorConfigDlg", "Y", 0));
        radiusLablel->setText(QApplication::translate("IndicatorConfigDlg", "\345\215\212\345\276\204", 0));
    } // retranslateUi

};

namespace Ui {
    class IndicatorConfigDlg: public Ui_IndicatorConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDICATORCONFIGDLG_H
