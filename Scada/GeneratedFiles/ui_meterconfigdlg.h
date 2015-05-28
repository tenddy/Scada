/********************************************************************************
** Form generated from reading UI file 'meterconfigdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METERCONFIGDLG_H
#define UI_METERCONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_MeterConfigDlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_5;
    QCheckBox *titleCheckBox;
    QLineEdit *UnitsLineEdit;
    QLabel *channelLablel;
    QLineEdit *titleLineEdit;
    QCheckBox *unitsCheckBox;
    QLineEdit *channelLineEdit;
    QGroupBox *PosGroupBox;
    QGridLayout *gridLayout_6;
    QLabel *currentPageLablel;
    QSpinBox *pageSpinBox;
    QLabel *posLablel;
    QSpinBox *posSpinBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QLabel *minLabel;
    QSpinBox *minValueSpinBox;
    QLabel *maxLabel;
    QSpinBox *maxValueSpinBox;
    QCheckBox *rateCheckBox;
    QComboBox *rateComboBox;
    QGridLayout *gridLayout_4;
    QLabel *startAngleLablel;
    QSpinBox *endAngleSpinBox;
    QLabel *radiusLablel;
    QSpinBox *radiusSpinBox;
    QLabel *endAngleLablel;
    QSpinBox *startAngleSpinBox;
    QGroupBox *centerGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *radiusXLablel;
    QSpinBox *XSpinBox;
    QLabel *radiusYLablel;
    QSpinBox *YSpinBox;
    QGroupBox *majorScalegroupBox;
    QGridLayout *gridLayout_2;
    QSpinBox *majorWidthSpinBox;
    QLabel *majorScaleWidthLabel;
    QLabel *majorScaleLengthLabel;
    QSpinBox *majorNumSpinBox;
    QLabel *majorScaleNumLablel;
    QSpinBox *majorLengthSpinBox;
    QGroupBox *middleScalegroupBox;
    QGridLayout *gridLayout;
    QSpinBox *middleWidthSpinBox;
    QLabel *middleScaleWidthLablel;
    QLabel *middleScaleLengthLabel;
    QSpinBox *middleLengthSpinBox;
    QSpinBox *middleNumSpinBox;
    QLabel *middleScaleNumLablel;
    QGroupBox *minnorScaleGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *minorScaleLengthLabel;
    QSpinBox *minorLengthSpinBox;
    QLabel *minorScaleNumLablel;
    QSpinBox *minorWidthSpinBox;
    QLabel *minorScaleWidthLabel;
    QDoubleSpinBox *minorNumDoubleSpinBox;

    void setupUi(QWidget *MeterConfigDlg)
    {
        if (MeterConfigDlg->objectName().isEmpty())
            MeterConfigDlg->setObjectName(QStringLiteral("MeterConfigDlg"));
        MeterConfigDlg->setWindowModality(Qt::WindowModal);
        MeterConfigDlg->resize(335, 580);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MeterConfigDlg->sizePolicy().hasHeightForWidth());
        MeterConfigDlg->setSizePolicy(sizePolicy);
        MeterConfigDlg->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        MeterConfigDlg->setFont(font);
        verticalLayout_3 = new QVBoxLayout(MeterConfigDlg);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(MeterConfigDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(30);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 30, -1, -1);
        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -371, 266, 924));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        titleCheckBox = new QCheckBox(scrollAreaWidgetContents);
        titleCheckBox->setObjectName(QStringLiteral("titleCheckBox"));
        titleCheckBox->setChecked(true);

        gridLayout_5->addWidget(titleCheckBox, 1, 0, 1, 1);

        UnitsLineEdit = new QLineEdit(scrollAreaWidgetContents);
        UnitsLineEdit->setObjectName(QStringLiteral("UnitsLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(UnitsLineEdit->sizePolicy().hasHeightForWidth());
        UnitsLineEdit->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(UnitsLineEdit, 2, 1, 1, 1);

        channelLablel = new QLabel(scrollAreaWidgetContents);
        channelLablel->setObjectName(QStringLiteral("channelLablel"));

        gridLayout_5->addWidget(channelLablel, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        titleLineEdit = new QLineEdit(scrollAreaWidgetContents);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        gridLayout_5->addWidget(titleLineEdit, 1, 1, 1, 1);

        unitsCheckBox = new QCheckBox(scrollAreaWidgetContents);
        unitsCheckBox->setObjectName(QStringLiteral("unitsCheckBox"));
        unitsCheckBox->setChecked(true);

        gridLayout_5->addWidget(unitsCheckBox, 2, 0, 1, 1);

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

        gridLayout_5->addWidget(channelLineEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        PosGroupBox = new QGroupBox(scrollAreaWidgetContents);
        PosGroupBox->setObjectName(QStringLiteral("PosGroupBox"));
        QFont font2;
        font2.setPointSize(12);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        PosGroupBox->setFont(font2);
        PosGroupBox->setInputMethodHints(Qt::ImhDigitsOnly);
        gridLayout_6 = new QGridLayout(PosGroupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        currentPageLablel = new QLabel(PosGroupBox);
        currentPageLablel->setObjectName(QStringLiteral("currentPageLablel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        currentPageLablel->setFont(font3);

        gridLayout_6->addWidget(currentPageLablel, 0, 0, 1, 1);

        pageSpinBox = new QSpinBox(PosGroupBox);
        pageSpinBox->setObjectName(QStringLiteral("pageSpinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pageSpinBox->sizePolicy().hasHeightForWidth());
        pageSpinBox->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(pageSpinBox, 0, 1, 1, 1);

        posLablel = new QLabel(PosGroupBox);
        posLablel->setObjectName(QStringLiteral("posLablel"));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        posLablel->setFont(font4);

        gridLayout_6->addWidget(posLablel, 1, 0, 1, 1);

        posSpinBox = new QSpinBox(PosGroupBox);
        posSpinBox->setObjectName(QStringLiteral("posSpinBox"));
        sizePolicy2.setHeightForWidth(posSpinBox->sizePolicy().hasHeightForWidth());
        posSpinBox->setSizePolicy(sizePolicy2);
        posSpinBox->setInputMethodHints(Qt::ImhNone);

        gridLayout_6->addWidget(posSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(PosGroupBox);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font5;
        font5.setPointSize(12);
        groupBox->setFont(font5);
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        minLabel = new QLabel(groupBox);
        minLabel->setObjectName(QStringLiteral("minLabel"));
        minLabel->setFont(font4);

        gridLayout_7->addWidget(minLabel, 0, 0, 1, 1);

        minValueSpinBox = new QSpinBox(groupBox);
        minValueSpinBox->setObjectName(QStringLiteral("minValueSpinBox"));
        sizePolicy2.setHeightForWidth(minValueSpinBox->sizePolicy().hasHeightForWidth());
        minValueSpinBox->setSizePolicy(sizePolicy2);
        minValueSpinBox->setMinimum(-9999);
        minValueSpinBox->setMaximum(9999);

        gridLayout_7->addWidget(minValueSpinBox, 0, 1, 1, 1);

        maxLabel = new QLabel(groupBox);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));
        maxLabel->setFont(font4);

        gridLayout_7->addWidget(maxLabel, 1, 0, 1, 1);

        maxValueSpinBox = new QSpinBox(groupBox);
        maxValueSpinBox->setObjectName(QStringLiteral("maxValueSpinBox"));
        sizePolicy2.setHeightForWidth(maxValueSpinBox->sizePolicy().hasHeightForWidth());
        maxValueSpinBox->setSizePolicy(sizePolicy2);
        maxValueSpinBox->setMinimum(-1000);
        maxValueSpinBox->setMaximum(1000);

        gridLayout_7->addWidget(maxValueSpinBox, 1, 1, 1, 1);

        rateCheckBox = new QCheckBox(groupBox);
        rateCheckBox->setObjectName(QStringLiteral("rateCheckBox"));
        rateCheckBox->setFont(font4);
        rateCheckBox->setChecked(false);

        gridLayout_7->addWidget(rateCheckBox, 2, 0, 1, 1);

        rateComboBox = new QComboBox(groupBox);
        rateComboBox->setObjectName(QStringLiteral("rateComboBox"));
        rateComboBox->setEnabled(false);
        rateComboBox->setEditable(true);

        gridLayout_7->addWidget(rateComboBox, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        startAngleLablel = new QLabel(scrollAreaWidgetContents);
        startAngleLablel->setObjectName(QStringLiteral("startAngleLablel"));

        gridLayout_4->addWidget(startAngleLablel, 0, 0, 1, 1);

        endAngleSpinBox = new QSpinBox(scrollAreaWidgetContents);
        endAngleSpinBox->setObjectName(QStringLiteral("endAngleSpinBox"));
        endAngleSpinBox->setMaximum(360);

        gridLayout_4->addWidget(endAngleSpinBox, 2, 1, 1, 1);

        radiusLablel = new QLabel(scrollAreaWidgetContents);
        radiusLablel->setObjectName(QStringLiteral("radiusLablel"));

        gridLayout_4->addWidget(radiusLablel, 3, 0, 1, 1);

        radiusSpinBox = new QSpinBox(scrollAreaWidgetContents);
        radiusSpinBox->setObjectName(QStringLiteral("radiusSpinBox"));
        radiusSpinBox->setMaximum(200);

        gridLayout_4->addWidget(radiusSpinBox, 3, 1, 1, 1);

        endAngleLablel = new QLabel(scrollAreaWidgetContents);
        endAngleLablel->setObjectName(QStringLiteral("endAngleLablel"));

        gridLayout_4->addWidget(endAngleLablel, 2, 0, 1, 1);

        startAngleSpinBox = new QSpinBox(scrollAreaWidgetContents);
        startAngleSpinBox->setObjectName(QStringLiteral("startAngleSpinBox"));
        sizePolicy2.setHeightForWidth(startAngleSpinBox->sizePolicy().hasHeightForWidth());
        startAngleSpinBox->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        startAngleSpinBox->setFont(font6);
        startAngleSpinBox->setMaximum(360);
        startAngleSpinBox->setSingleStep(1);

        gridLayout_4->addWidget(startAngleSpinBox, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        centerGroupBox = new QGroupBox(scrollAreaWidgetContents);
        centerGroupBox->setObjectName(QStringLiteral("centerGroupBox"));
        horizontalLayout = new QHBoxLayout(centerGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radiusXLablel = new QLabel(centerGroupBox);
        radiusXLablel->setObjectName(QStringLiteral("radiusXLablel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(radiusXLablel->sizePolicy().hasHeightForWidth());
        radiusXLablel->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(radiusXLablel);

        XSpinBox = new QSpinBox(centerGroupBox);
        XSpinBox->setObjectName(QStringLiteral("XSpinBox"));
        XSpinBox->setMinimum(-400);
        XSpinBox->setMaximum(400);

        horizontalLayout->addWidget(XSpinBox);

        radiusYLablel = new QLabel(centerGroupBox);
        radiusYLablel->setObjectName(QStringLiteral("radiusYLablel"));
        sizePolicy3.setHeightForWidth(radiusYLablel->sizePolicy().hasHeightForWidth());
        radiusYLablel->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(radiusYLablel);

        YSpinBox = new QSpinBox(centerGroupBox);
        YSpinBox->setObjectName(QStringLiteral("YSpinBox"));
        YSpinBox->setMinimum(-300);
        YSpinBox->setMaximum(300);

        horizontalLayout->addWidget(YSpinBox);


        verticalLayout->addWidget(centerGroupBox);

        majorScalegroupBox = new QGroupBox(scrollAreaWidgetContents);
        majorScalegroupBox->setObjectName(QStringLiteral("majorScalegroupBox"));
        gridLayout_2 = new QGridLayout(majorScalegroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        majorWidthSpinBox = new QSpinBox(majorScalegroupBox);
        majorWidthSpinBox->setObjectName(QStringLiteral("majorWidthSpinBox"));
        majorWidthSpinBox->setMinimum(1);

        gridLayout_2->addWidget(majorWidthSpinBox, 2, 1, 1, 1);

        majorScaleWidthLabel = new QLabel(majorScalegroupBox);
        majorScaleWidthLabel->setObjectName(QStringLiteral("majorScaleWidthLabel"));
        sizePolicy3.setHeightForWidth(majorScaleWidthLabel->sizePolicy().hasHeightForWidth());
        majorScaleWidthLabel->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(majorScaleWidthLabel, 2, 0, 1, 1);

        majorScaleLengthLabel = new QLabel(majorScalegroupBox);
        majorScaleLengthLabel->setObjectName(QStringLiteral("majorScaleLengthLabel"));
        sizePolicy3.setHeightForWidth(majorScaleLengthLabel->sizePolicy().hasHeightForWidth());
        majorScaleLengthLabel->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(majorScaleLengthLabel, 1, 0, 1, 1);

        majorNumSpinBox = new QSpinBox(majorScalegroupBox);
        majorNumSpinBox->setObjectName(QStringLiteral("majorNumSpinBox"));
        majorNumSpinBox->setMinimum(1);
        majorNumSpinBox->setMaximum(1000);
        majorNumSpinBox->setSingleStep(1);
        majorNumSpinBox->setValue(10);
        majorNumSpinBox->setDisplayIntegerBase(10);

        gridLayout_2->addWidget(majorNumSpinBox, 0, 1, 1, 1);

        majorScaleNumLablel = new QLabel(majorScalegroupBox);
        majorScaleNumLablel->setObjectName(QStringLiteral("majorScaleNumLablel"));
        sizePolicy3.setHeightForWidth(majorScaleNumLablel->sizePolicy().hasHeightForWidth());
        majorScaleNumLablel->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(majorScaleNumLablel, 0, 0, 1, 1);

        majorLengthSpinBox = new QSpinBox(majorScalegroupBox);
        majorLengthSpinBox->setObjectName(QStringLiteral("majorLengthSpinBox"));
        majorLengthSpinBox->setMinimum(1);

        gridLayout_2->addWidget(majorLengthSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(majorScalegroupBox);

        middleScalegroupBox = new QGroupBox(scrollAreaWidgetContents);
        middleScalegroupBox->setObjectName(QStringLiteral("middleScalegroupBox"));
        middleScalegroupBox->setCheckable(true);
        middleScalegroupBox->setChecked(false);
        gridLayout = new QGridLayout(middleScalegroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        middleWidthSpinBox = new QSpinBox(middleScalegroupBox);
        middleWidthSpinBox->setObjectName(QStringLiteral("middleWidthSpinBox"));
        middleWidthSpinBox->setMinimum(1);

        gridLayout->addWidget(middleWidthSpinBox, 3, 1, 1, 1);

        middleScaleWidthLablel = new QLabel(middleScalegroupBox);
        middleScaleWidthLablel->setObjectName(QStringLiteral("middleScaleWidthLablel"));
        sizePolicy3.setHeightForWidth(middleScaleWidthLablel->sizePolicy().hasHeightForWidth());
        middleScaleWidthLablel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(middleScaleWidthLablel, 3, 0, 1, 1);

        middleScaleLengthLabel = new QLabel(middleScalegroupBox);
        middleScaleLengthLabel->setObjectName(QStringLiteral("middleScaleLengthLabel"));
        sizePolicy3.setHeightForWidth(middleScaleLengthLabel->sizePolicy().hasHeightForWidth());
        middleScaleLengthLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(middleScaleLengthLabel, 2, 0, 1, 1);

        middleLengthSpinBox = new QSpinBox(middleScalegroupBox);
        middleLengthSpinBox->setObjectName(QStringLiteral("middleLengthSpinBox"));
        middleLengthSpinBox->setMinimum(1);

        gridLayout->addWidget(middleLengthSpinBox, 2, 1, 1, 1);

        middleNumSpinBox = new QSpinBox(middleScalegroupBox);
        middleNumSpinBox->setObjectName(QStringLiteral("middleNumSpinBox"));
        middleNumSpinBox->setEnabled(false);
        middleNumSpinBox->setMinimum(0);
        middleNumSpinBox->setMaximum(1000);

        gridLayout->addWidget(middleNumSpinBox, 1, 1, 1, 1);

        middleScaleNumLablel = new QLabel(middleScalegroupBox);
        middleScaleNumLablel->setObjectName(QStringLiteral("middleScaleNumLablel"));
        sizePolicy3.setHeightForWidth(middleScaleNumLablel->sizePolicy().hasHeightForWidth());
        middleScaleNumLablel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(middleScaleNumLablel, 1, 0, 1, 1);


        verticalLayout->addWidget(middleScalegroupBox);

        minnorScaleGroupBox = new QGroupBox(scrollAreaWidgetContents);
        minnorScaleGroupBox->setObjectName(QStringLiteral("minnorScaleGroupBox"));
        gridLayout_3 = new QGridLayout(minnorScaleGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        minorScaleLengthLabel = new QLabel(minnorScaleGroupBox);
        minorScaleLengthLabel->setObjectName(QStringLiteral("minorScaleLengthLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(minorScaleLengthLabel->sizePolicy().hasHeightForWidth());
        minorScaleLengthLabel->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(minorScaleLengthLabel, 1, 0, 1, 1);

        minorLengthSpinBox = new QSpinBox(minnorScaleGroupBox);
        minorLengthSpinBox->setObjectName(QStringLiteral("minorLengthSpinBox"));
        minorLengthSpinBox->setMinimum(1);

        gridLayout_3->addWidget(minorLengthSpinBox, 1, 1, 1, 1);

        minorScaleNumLablel = new QLabel(minnorScaleGroupBox);
        minorScaleNumLablel->setObjectName(QStringLiteral("minorScaleNumLablel"));
        sizePolicy4.setHeightForWidth(minorScaleNumLablel->sizePolicy().hasHeightForWidth());
        minorScaleNumLablel->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(minorScaleNumLablel, 0, 0, 1, 1);

        minorWidthSpinBox = new QSpinBox(minnorScaleGroupBox);
        minorWidthSpinBox->setObjectName(QStringLiteral("minorWidthSpinBox"));
        minorWidthSpinBox->setMinimum(1);

        gridLayout_3->addWidget(minorWidthSpinBox, 2, 1, 1, 1);

        minorScaleWidthLabel = new QLabel(minnorScaleGroupBox);
        minorScaleWidthLabel->setObjectName(QStringLiteral("minorScaleWidthLabel"));
        sizePolicy4.setHeightForWidth(minorScaleWidthLabel->sizePolicy().hasHeightForWidth());
        minorScaleWidthLabel->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(minorScaleWidthLabel, 2, 0, 1, 1);

        minorNumDoubleSpinBox = new QDoubleSpinBox(minnorScaleGroupBox);
        minorNumDoubleSpinBox->setObjectName(QStringLiteral("minorNumDoubleSpinBox"));
        minorNumDoubleSpinBox->setMinimum(0.01);
        minorNumDoubleSpinBox->setMaximum(9999.99);
        minorNumDoubleSpinBox->setSingleStep(0.01);

        gridLayout_3->addWidget(minorNumDoubleSpinBox, 0, 1, 1, 1);


        verticalLayout->addWidget(minnorScaleGroupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_3->addWidget(groupBox_2);

#ifndef QT_NO_SHORTCUT
        channelLablel->setBuddy(channelLineEdit);
        currentPageLablel->setBuddy(endAngleSpinBox);
        posLablel->setBuddy(endAngleSpinBox);
        startAngleLablel->setBuddy(startAngleSpinBox);
        radiusLablel->setBuddy(radiusSpinBox);
        endAngleLablel->setBuddy(endAngleSpinBox);
        radiusXLablel->setBuddy(XSpinBox);
        radiusYLablel->setBuddy(YSpinBox);
        majorScaleWidthLabel->setBuddy(majorWidthSpinBox);
        majorScaleLengthLabel->setBuddy(majorLengthSpinBox);
        majorScaleNumLablel->setBuddy(majorNumSpinBox);
        middleScaleWidthLablel->setBuddy(middleWidthSpinBox);
        middleScaleLengthLabel->setBuddy(middleLengthSpinBox);
        middleScaleNumLablel->setBuddy(middleNumSpinBox);
        minorScaleLengthLabel->setBuddy(minorLengthSpinBox);
        minorScaleNumLablel->setBuddy(minorNumDoubleSpinBox);
        minorScaleWidthLabel->setBuddy(minorWidthSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(MeterConfigDlg);
        QObject::connect(titleCheckBox, SIGNAL(clicked(bool)), titleLineEdit, SLOT(setEnabled(bool)));
        QObject::connect(unitsCheckBox, SIGNAL(clicked(bool)), UnitsLineEdit, SLOT(setEnabled(bool)));
        QObject::connect(rateCheckBox, SIGNAL(clicked(bool)), rateComboBox, SLOT(setEnabled(bool)));

        rateComboBox->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MeterConfigDlg);
    } // setupUi

    void retranslateUi(QWidget *MeterConfigDlg)
    {
        MeterConfigDlg->setWindowTitle(QApplication::translate("MeterConfigDlg", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("MeterConfigDlg", "\344\273\252\350\241\250\350\256\276\347\275\256", 0));
        titleCheckBox->setText(QApplication::translate("MeterConfigDlg", "\345\220\215\347\247\260", 0));
        channelLablel->setText(QApplication::translate("MeterConfigDlg", "\351\200\232\351\201\223", 0));
        unitsCheckBox->setText(QApplication::translate("MeterConfigDlg", "\345\215\225\344\275\215", 0));
#ifndef QT_NO_STATUSTIP
        channelLineEdit->setStatusTip(QApplication::translate("MeterConfigDlg", "\351\200\232\351\201\223", 0));
#endif // QT_NO_STATUSTIP
        PosGroupBox->setTitle(QApplication::translate("MeterConfigDlg", "\351\241\265\351\235\242\344\270\216\344\275\215\347\275\256", 0));
        currentPageLablel->setText(QApplication::translate("MeterConfigDlg", "\345\275\223\345\211\215\351\241\265\351\235\242", 0));
        posLablel->setText(QApplication::translate("MeterConfigDlg", "\345\275\223\345\211\215\344\275\215\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("MeterConfigDlg", "\351\207\217\347\250\213", 0));
        minLabel->setText(QApplication::translate("MeterConfigDlg", "\346\234\200\345\260\217\345\200\274", 0));
        maxLabel->setText(QApplication::translate("MeterConfigDlg", "\346\234\200\345\244\247\345\200\274", 0));
        rateCheckBox->setText(QApplication::translate("MeterConfigDlg", "\346\257\224\347\216\207  X", 0));
        rateComboBox->clear();
        rateComboBox->insertItems(0, QStringList()
         << QApplication::translate("MeterConfigDlg", "0.0001", 0)
         << QApplication::translate("MeterConfigDlg", "0.001", 0)
         << QApplication::translate("MeterConfigDlg", "0.01", 0)
         << QApplication::translate("MeterConfigDlg", "0.1", 0)
         << QApplication::translate("MeterConfigDlg", "1", 0)
         << QApplication::translate("MeterConfigDlg", "10", 0)
         << QApplication::translate("MeterConfigDlg", "100", 0)
         << QApplication::translate("MeterConfigDlg", "1000", 0)
         << QApplication::translate("MeterConfigDlg", "10000", 0)
        );
        rateComboBox->setCurrentText(QApplication::translate("MeterConfigDlg", "1", 0));
        startAngleLablel->setText(QApplication::translate("MeterConfigDlg", "\350\265\267\345\247\213\350\247\222", 0));
        radiusLablel->setText(QApplication::translate("MeterConfigDlg", "\345\215\212\345\276\204", 0));
        endAngleLablel->setText(QApplication::translate("MeterConfigDlg", "\347\273\210\346\255\242\350\247\222", 0));
#ifndef QT_NO_STATUSTIP
        startAngleSpinBox->setStatusTip(QApplication::translate("MeterConfigDlg", "0~360", 0));
#endif // QT_NO_STATUSTIP
        centerGroupBox->setTitle(QApplication::translate("MeterConfigDlg", "\344\270\255\345\277\203\347\202\271", 0));
        radiusXLablel->setText(QApplication::translate("MeterConfigDlg", "X", 0));
        radiusYLablel->setText(QApplication::translate("MeterConfigDlg", "Y", 0));
        majorScalegroupBox->setTitle(QApplication::translate("MeterConfigDlg", "\345\244\247\345\210\273\345\272\246\347\272\277", 0));
        majorScaleWidthLabel->setText(QApplication::translate("MeterConfigDlg", "\345\256\275\345\272\246", 0));
        majorScaleLengthLabel->setText(QApplication::translate("MeterConfigDlg", "\351\225\277\345\272\246", 0));
        majorScaleNumLablel->setText(QApplication::translate("MeterConfigDlg", "\351\227\264\350\267\235", 0));
        middleScalegroupBox->setTitle(QApplication::translate("MeterConfigDlg", "\344\270\255\345\210\273\345\272\246\347\272\277", 0));
        middleScaleWidthLablel->setText(QApplication::translate("MeterConfigDlg", "\345\256\275\345\272\246", 0));
        middleScaleLengthLabel->setText(QApplication::translate("MeterConfigDlg", "\351\225\277\345\272\246", 0));
        middleScaleNumLablel->setText(QApplication::translate("MeterConfigDlg", "\351\227\264\350\267\235", 0));
        minnorScaleGroupBox->setTitle(QApplication::translate("MeterConfigDlg", "\345\260\217\345\210\273\345\272\246\347\272\277", 0));
        minorScaleLengthLabel->setText(QApplication::translate("MeterConfigDlg", "\351\225\277\345\272\246", 0));
        minorScaleNumLablel->setText(QApplication::translate("MeterConfigDlg", "\351\227\264\350\267\235", 0));
        minorScaleWidthLabel->setText(QApplication::translate("MeterConfigDlg", "\345\256\275\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class MeterConfigDlg: public Ui_MeterConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METERCONFIGDLG_H
