/********************************************************************************
** Form generated from reading UI file 'thermometerconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THERMOMETERCONFIG_H
#define UI_THERMOMETERCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThermoMeterConfig
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLineEdit *channelLineEdit;
    QLabel *channelLablel;
    QCheckBox *titleCheckBox;
    QLineEdit *titleLineEdit;
    QLineEdit *unitsLineEdit;
    QLabel *label;
    QGroupBox *PosGroupBox;
    QGridLayout *gridLayout_6;
    QLabel *currentPageLablel;
    QSpinBox *pageSpinBox;
    QLabel *posLablel;
    QSpinBox *posSpinBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QSpinBox *maxValueSpinBox;
    QSpinBox *minValueSpinBox;
    QLabel *maxLabel;
    QLabel *minLabel;
    QGroupBox *majorScalegroupBox;
    QGridLayout *gridLayout_2;
    QSpinBox *majorWidthSpinBox;
    QLabel *majorScaleWidthLabel;
    QLabel *majorScaleLengthLabel;
    QSpinBox *majorNumSpinBox;
    QLabel *majorScaleNumLablel;
    QSpinBox *majorLengthSpinBox;
    QGroupBox *minnorScaleGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *minorScaleLengthLabel;
    QSpinBox *minorLengthSpinBox;
    QLabel *minorScaleNumLablel;
    QSpinBox *minorWidthSpinBox;
    QLabel *minorScaleWidthLabel;
    QDoubleSpinBox *minorNumDoubleSpinBox;
    QGroupBox *geometryGroupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *centerGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *radiusXLablel;
    QSpinBox *XSpinBox;
    QLabel *radiusYLablel;
    QSpinBox *YSpinBox;
    QGridLayout *gridLayout;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QLabel *heightLabel;
    QSpinBox *heightSpinBox;

    void setupUi(QWidget *ThermoMeterConfig)
    {
        if (ThermoMeterConfig->objectName().isEmpty())
            ThermoMeterConfig->setObjectName(QStringLiteral("ThermoMeterConfig"));
        ThermoMeterConfig->setWindowModality(Qt::WindowModal);
        ThermoMeterConfig->resize(400, 789);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ThermoMeterConfig->sizePolicy().hasHeightForWidth());
        ThermoMeterConfig->setSizePolicy(sizePolicy);
        ThermoMeterConfig->setMinimumSize(QSize(200, 300));
        ThermoMeterConfig->setMaximumSize(QSize(400, 16777215));
        ThermoMeterConfig->setBaseSize(QSize(300, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        ThermoMeterConfig->setFont(font);
        verticalLayout_4 = new QVBoxLayout(ThermoMeterConfig);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(ThermoMeterConfig);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 331, 747));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        channelLineEdit = new QLineEdit(scrollAreaWidgetContents);
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

        gridLayout_4->addWidget(channelLineEdit, 0, 1, 1, 1);

        channelLablel = new QLabel(scrollAreaWidgetContents);
        channelLablel->setObjectName(QStringLiteral("channelLablel"));
        sizePolicy1.setHeightForWidth(channelLablel->sizePolicy().hasHeightForWidth());
        channelLablel->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(channelLablel, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        titleCheckBox = new QCheckBox(scrollAreaWidgetContents);
        titleCheckBox->setObjectName(QStringLiteral("titleCheckBox"));
        titleCheckBox->setFocusPolicy(Qt::ClickFocus);
        titleCheckBox->setChecked(true);

        gridLayout_4->addWidget(titleCheckBox, 1, 0, 1, 1);

        titleLineEdit = new QLineEdit(scrollAreaWidgetContents);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        titleLineEdit->setFocusPolicy(Qt::ClickFocus);

        gridLayout_4->addWidget(titleLineEdit, 1, 1, 1, 1);

        unitsLineEdit = new QLineEdit(scrollAreaWidgetContents);
        unitsLineEdit->setObjectName(QStringLiteral("unitsLineEdit"));
        unitsLineEdit->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(unitsLineEdit->sizePolicy().hasHeightForWidth());
        unitsLineEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(unitsLineEdit, 2, 1, 1, 1);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        PosGroupBox = new QGroupBox(scrollAreaWidgetContents);
        PosGroupBox->setObjectName(QStringLiteral("PosGroupBox"));
        gridLayout_6 = new QGridLayout(PosGroupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        currentPageLablel = new QLabel(PosGroupBox);
        currentPageLablel->setObjectName(QStringLiteral("currentPageLablel"));

        gridLayout_6->addWidget(currentPageLablel, 0, 0, 1, 1);

        pageSpinBox = new QSpinBox(PosGroupBox);
        pageSpinBox->setObjectName(QStringLiteral("pageSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pageSpinBox->sizePolicy().hasHeightForWidth());
        pageSpinBox->setSizePolicy(sizePolicy3);
        pageSpinBox->setFocusPolicy(Qt::ClickFocus);

        gridLayout_6->addWidget(pageSpinBox, 0, 1, 1, 1);

        posLablel = new QLabel(PosGroupBox);
        posLablel->setObjectName(QStringLiteral("posLablel"));

        gridLayout_6->addWidget(posLablel, 1, 0, 1, 1);

        posSpinBox = new QSpinBox(PosGroupBox);
        posSpinBox->setObjectName(QStringLiteral("posSpinBox"));
        sizePolicy3.setHeightForWidth(posSpinBox->sizePolicy().hasHeightForWidth());
        posSpinBox->setSizePolicy(sizePolicy3);
        posSpinBox->setFocusPolicy(Qt::ClickFocus);

        gridLayout_6->addWidget(posSpinBox, 1, 1, 1, 1);


        verticalLayout_2->addWidget(PosGroupBox);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        maxValueSpinBox = new QSpinBox(groupBox);
        maxValueSpinBox->setObjectName(QStringLiteral("maxValueSpinBox"));
        sizePolicy3.setHeightForWidth(maxValueSpinBox->sizePolicy().hasHeightForWidth());
        maxValueSpinBox->setSizePolicy(sizePolicy3);
        maxValueSpinBox->setFocusPolicy(Qt::ClickFocus);
        maxValueSpinBox->setMinimum(-1000);
        maxValueSpinBox->setMaximum(1000);

        gridLayout_7->addWidget(maxValueSpinBox, 1, 1, 1, 1);

        minValueSpinBox = new QSpinBox(groupBox);
        minValueSpinBox->setObjectName(QStringLiteral("minValueSpinBox"));
        sizePolicy3.setHeightForWidth(minValueSpinBox->sizePolicy().hasHeightForWidth());
        minValueSpinBox->setSizePolicy(sizePolicy3);
        minValueSpinBox->setFocusPolicy(Qt::ClickFocus);
        minValueSpinBox->setMinimum(-1000);
        minValueSpinBox->setMaximum(1000);

        gridLayout_7->addWidget(minValueSpinBox, 0, 1, 1, 1);

        maxLabel = new QLabel(groupBox);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));

        gridLayout_7->addWidget(maxLabel, 1, 0, 1, 1);

        minLabel = new QLabel(groupBox);
        minLabel->setObjectName(QStringLiteral("minLabel"));

        gridLayout_7->addWidget(minLabel, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        majorScalegroupBox = new QGroupBox(scrollAreaWidgetContents);
        majorScalegroupBox->setObjectName(QStringLiteral("majorScalegroupBox"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        majorScalegroupBox->setFont(font2);
        gridLayout_2 = new QGridLayout(majorScalegroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        majorWidthSpinBox = new QSpinBox(majorScalegroupBox);
        majorWidthSpinBox->setObjectName(QStringLiteral("majorWidthSpinBox"));
        majorWidthSpinBox->setMinimum(1);

        gridLayout_2->addWidget(majorWidthSpinBox, 2, 1, 1, 1);

        majorScaleWidthLabel = new QLabel(majorScalegroupBox);
        majorScaleWidthLabel->setObjectName(QStringLiteral("majorScaleWidthLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(majorScaleWidthLabel->sizePolicy().hasHeightForWidth());
        majorScaleWidthLabel->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(majorScaleWidthLabel, 2, 0, 1, 1);

        majorScaleLengthLabel = new QLabel(majorScalegroupBox);
        majorScaleLengthLabel->setObjectName(QStringLiteral("majorScaleLengthLabel"));
        sizePolicy4.setHeightForWidth(majorScaleLengthLabel->sizePolicy().hasHeightForWidth());
        majorScaleLengthLabel->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(majorScaleLengthLabel, 1, 0, 1, 1);

        majorNumSpinBox = new QSpinBox(majorScalegroupBox);
        majorNumSpinBox->setObjectName(QStringLiteral("majorNumSpinBox"));
        majorNumSpinBox->setMinimum(1);

        gridLayout_2->addWidget(majorNumSpinBox, 0, 1, 1, 1);

        majorScaleNumLablel = new QLabel(majorScalegroupBox);
        majorScaleNumLablel->setObjectName(QStringLiteral("majorScaleNumLablel"));
        sizePolicy4.setHeightForWidth(majorScaleNumLablel->sizePolicy().hasHeightForWidth());
        majorScaleNumLablel->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(majorScaleNumLablel, 0, 0, 1, 1);

        majorLengthSpinBox = new QSpinBox(majorScalegroupBox);
        majorLengthSpinBox->setObjectName(QStringLiteral("majorLengthSpinBox"));
        majorLengthSpinBox->setMinimum(1);

        gridLayout_2->addWidget(majorLengthSpinBox, 1, 1, 1, 1);


        verticalLayout_2->addWidget(majorScalegroupBox);

        minnorScaleGroupBox = new QGroupBox(scrollAreaWidgetContents);
        minnorScaleGroupBox->setObjectName(QStringLiteral("minnorScaleGroupBox"));
        minnorScaleGroupBox->setFont(font2);
        gridLayout_3 = new QGridLayout(minnorScaleGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        minorScaleLengthLabel = new QLabel(minnorScaleGroupBox);
        minorScaleLengthLabel->setObjectName(QStringLiteral("minorScaleLengthLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(minorScaleLengthLabel->sizePolicy().hasHeightForWidth());
        minorScaleLengthLabel->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(minorScaleLengthLabel, 1, 0, 1, 1);

        minorLengthSpinBox = new QSpinBox(minnorScaleGroupBox);
        minorLengthSpinBox->setObjectName(QStringLiteral("minorLengthSpinBox"));
        minorLengthSpinBox->setMinimum(1);

        gridLayout_3->addWidget(minorLengthSpinBox, 1, 1, 1, 1);

        minorScaleNumLablel = new QLabel(minnorScaleGroupBox);
        minorScaleNumLablel->setObjectName(QStringLiteral("minorScaleNumLablel"));
        sizePolicy5.setHeightForWidth(minorScaleNumLablel->sizePolicy().hasHeightForWidth());
        minorScaleNumLablel->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(minorScaleNumLablel, 0, 0, 1, 1);

        minorWidthSpinBox = new QSpinBox(minnorScaleGroupBox);
        minorWidthSpinBox->setObjectName(QStringLiteral("minorWidthSpinBox"));
        minorWidthSpinBox->setMinimum(1);

        gridLayout_3->addWidget(minorWidthSpinBox, 2, 1, 1, 1);

        minorScaleWidthLabel = new QLabel(minnorScaleGroupBox);
        minorScaleWidthLabel->setObjectName(QStringLiteral("minorScaleWidthLabel"));
        sizePolicy5.setHeightForWidth(minorScaleWidthLabel->sizePolicy().hasHeightForWidth());
        minorScaleWidthLabel->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(minorScaleWidthLabel, 2, 0, 1, 1);

        minorNumDoubleSpinBox = new QDoubleSpinBox(minnorScaleGroupBox);
        minorNumDoubleSpinBox->setObjectName(QStringLiteral("minorNumDoubleSpinBox"));
        minorNumDoubleSpinBox->setMinimum(0.01);
        minorNumDoubleSpinBox->setSingleStep(0.01);

        gridLayout_3->addWidget(minorNumDoubleSpinBox, 0, 1, 1, 1);


        verticalLayout_2->addWidget(minnorScaleGroupBox);

        geometryGroupBox = new QGroupBox(scrollAreaWidgetContents);
        geometryGroupBox->setObjectName(QStringLiteral("geometryGroupBox"));
        geometryGroupBox->setFont(font2);
        verticalLayout = new QVBoxLayout(geometryGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        centerGroupBox = new QGroupBox(geometryGroupBox);
        centerGroupBox->setObjectName(QStringLiteral("centerGroupBox"));
        horizontalLayout = new QHBoxLayout(centerGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radiusXLablel = new QLabel(centerGroupBox);
        radiusXLablel->setObjectName(QStringLiteral("radiusXLablel"));
        sizePolicy4.setHeightForWidth(radiusXLablel->sizePolicy().hasHeightForWidth());
        radiusXLablel->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(radiusXLablel);

        XSpinBox = new QSpinBox(centerGroupBox);
        XSpinBox->setObjectName(QStringLiteral("XSpinBox"));
        XSpinBox->setMinimum(-400);
        XSpinBox->setMaximum(400);

        horizontalLayout->addWidget(XSpinBox);

        radiusYLablel = new QLabel(centerGroupBox);
        radiusYLablel->setObjectName(QStringLiteral("radiusYLablel"));
        sizePolicy4.setHeightForWidth(radiusYLablel->sizePolicy().hasHeightForWidth());
        radiusYLablel->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(radiusYLablel);

        YSpinBox = new QSpinBox(centerGroupBox);
        YSpinBox->setObjectName(QStringLiteral("YSpinBox"));
        YSpinBox->setMinimum(-300);
        YSpinBox->setMaximum(300);

        horizontalLayout->addWidget(YSpinBox);


        verticalLayout->addWidget(centerGroupBox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widthLabel = new QLabel(geometryGroupBox);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        sizePolicy4.setHeightForWidth(widthLabel->sizePolicy().hasHeightForWidth());
        widthLabel->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(widthLabel, 0, 0, 1, 1);

        widthSpinBox = new QSpinBox(geometryGroupBox);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMinimum(0);
        widthSpinBox->setMaximum(2000);

        gridLayout->addWidget(widthSpinBox, 0, 1, 1, 1);

        heightLabel = new QLabel(geometryGroupBox);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));

        gridLayout->addWidget(heightLabel, 1, 0, 1, 1);

        heightSpinBox = new QSpinBox(geometryGroupBox);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMinimum(0);
        heightSpinBox->setMaximum(2000);

        gridLayout->addWidget(heightSpinBox, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(geometryGroupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout_4->addWidget(groupBox_2);

#ifndef QT_NO_SHORTCUT
        channelLablel->setBuddy(channelLineEdit);
        majorScaleWidthLabel->setBuddy(majorWidthSpinBox);
        majorScaleLengthLabel->setBuddy(majorLengthSpinBox);
        majorScaleNumLablel->setBuddy(majorNumSpinBox);
        minorScaleLengthLabel->setBuddy(minorLengthSpinBox);
        minorScaleNumLablel->setBuddy(minorNumDoubleSpinBox);
        minorScaleWidthLabel->setBuddy(minorWidthSpinBox);
        radiusXLablel->setBuddy(XSpinBox);
        radiusYLablel->setBuddy(YSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(ThermoMeterConfig);
        QObject::connect(titleCheckBox, SIGNAL(clicked(bool)), titleLineEdit, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(ThermoMeterConfig);
    } // setupUi

    void retranslateUi(QWidget *ThermoMeterConfig)
    {
        ThermoMeterConfig->setWindowTitle(QApplication::translate("ThermoMeterConfig", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("ThermoMeterConfig", "\346\270\251\345\272\246\350\256\241", 0));
        channelLablel->setText(QApplication::translate("ThermoMeterConfig", "\351\200\232\351\201\223", 0));
        titleCheckBox->setText(QApplication::translate("ThermoMeterConfig", "\345\220\215\347\247\260", 0));
        unitsLineEdit->setText(QApplication::translate("ThermoMeterConfig", "\342\204\203", 0));
        label->setText(QApplication::translate("ThermoMeterConfig", "\345\215\225\344\275\215", 0));
        PosGroupBox->setTitle(QApplication::translate("ThermoMeterConfig", "\351\241\265\351\235\242\344\270\216\344\275\215\347\275\256", 0));
        currentPageLablel->setText(QApplication::translate("ThermoMeterConfig", "\345\275\223\345\211\215\351\241\265\351\235\242", 0));
        posLablel->setText(QApplication::translate("ThermoMeterConfig", "\345\275\223\345\211\215\344\275\215\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("ThermoMeterConfig", "\351\207\217\347\250\213", 0));
        maxLabel->setText(QApplication::translate("ThermoMeterConfig", "\346\234\200\345\244\247\345\200\274", 0));
        minLabel->setText(QApplication::translate("ThermoMeterConfig", "\346\234\200\345\260\217\345\200\274", 0));
        majorScalegroupBox->setTitle(QApplication::translate("ThermoMeterConfig", "\345\244\247\345\210\273\345\272\246\347\272\277", 0));
        majorScaleWidthLabel->setText(QApplication::translate("ThermoMeterConfig", "\345\256\275\345\272\246", 0));
        majorScaleLengthLabel->setText(QApplication::translate("ThermoMeterConfig", "\351\225\277\345\272\246", 0));
        majorScaleNumLablel->setText(QApplication::translate("ThermoMeterConfig", "\351\227\264\350\267\235", 0));
        minnorScaleGroupBox->setTitle(QApplication::translate("ThermoMeterConfig", "\345\260\217\345\210\273\345\272\246\347\272\277", 0));
        minorScaleLengthLabel->setText(QApplication::translate("ThermoMeterConfig", "\351\225\277\345\272\246", 0));
        minorScaleNumLablel->setText(QApplication::translate("ThermoMeterConfig", "\351\227\264\350\267\235", 0));
        minorScaleWidthLabel->setText(QApplication::translate("ThermoMeterConfig", "\345\256\275\345\272\246", 0));
        geometryGroupBox->setTitle(QApplication::translate("ThermoMeterConfig", "\344\273\252\350\241\250\345\244\247\345\260\217", 0));
        centerGroupBox->setTitle(QApplication::translate("ThermoMeterConfig", "\344\270\255\345\277\203\347\202\271", 0));
        radiusXLablel->setText(QApplication::translate("ThermoMeterConfig", "X", 0));
        radiusYLablel->setText(QApplication::translate("ThermoMeterConfig", "Y", 0));
        widthLabel->setText(QApplication::translate("ThermoMeterConfig", "\345\256\275\345\272\246", 0));
        heightLabel->setText(QApplication::translate("ThermoMeterConfig", "\351\253\230\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class ThermoMeterConfig: public Ui_ThermoMeterConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THERMOMETERCONFIG_H
