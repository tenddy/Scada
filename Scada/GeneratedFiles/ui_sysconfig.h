/********************************************************************************
** Form generated from reading UI file 'sysconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSCONFIG_H
#define UI_SYSCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysConfig
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxSensor;
    QGridLayout *gridLayout_6;
    QLabel *labelChannel;
    QComboBox *comboBoxChannel;
    QLabel *labelSensorType;
    QComboBox *comboBoxSensorType;
    QLabel *labelDateType;
    QComboBox *comboBoxDataType;
    QLabel *labelSensorMax;
    QComboBox *comboBoxSensorMax;
    QLabel *labelSensorMin;
    QComboBox *comboBoxSensorMin;
    QGroupBox *groupBoxData;
    QGridLayout *gridLayout_4;
    QLabel *labelDataName;
    QComboBox *comboBoxDataName;
    QLabel *labelDataUint;
    QComboBox *comboBoxDataUint;
    QLabel *labelMeterType;
    QComboBox *comboBoxMeterType;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelInhibitTime;
    QComboBox *comboBoxInhibitTime;
    QComboBox *comboBoxTimeUint;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxWarning;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxLWarning;
    QLineEdit *lineEditLWarning;
    QCheckBox *checkBoxHWarning;
    QLineEdit *lineEditHWarning;
    QGroupBox *groupBoxAlarm;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBoxLAlarm;
    QLineEdit *lineEditLAlarm;
    QCheckBox *checkBoxHAlarm;
    QLineEdit *lineEditHAlarm;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonApplied;
    QTableWidget *tableWidget;

    void setupUi(QWidget *SysConfig)
    {
        if (SysConfig->objectName().isEmpty())
            SysConfig->setObjectName(QStringLiteral("SysConfig"));
        SysConfig->setWindowModality(Qt::WindowModal);
        SysConfig->setEnabled(true);
        SysConfig->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SysConfig->sizePolicy().hasHeightForWidth());
        SysConfig->setSizePolicy(sizePolicy);
        SysConfig->setMinimumSize(QSize(800, 580));
        SysConfig->setMaximumSize(QSize(1920, 1080));
        horizontalLayout_2 = new QHBoxLayout(SysConfig);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        scrollArea = new QScrollArea(SysConfig);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(300, 0));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -212, 319, 745));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBoxSensor = new QGroupBox(scrollAreaWidgetContents);
        groupBoxSensor->setObjectName(QStringLiteral("groupBoxSensor"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBoxSensor->setFont(font);
        groupBoxSensor->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBoxSensor);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        labelChannel = new QLabel(groupBoxSensor);
        labelChannel->setObjectName(QStringLiteral("labelChannel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelChannel->sizePolicy().hasHeightForWidth());
        labelChannel->setSizePolicy(sizePolicy3);
        labelChannel->setMinimumSize(QSize(0, 3));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelChannel->setFont(font1);
        labelChannel->setLayoutDirection(Qt::LeftToRight);
        labelChannel->setAutoFillBackground(false);
        labelChannel->setFrameShape(QFrame::Box);
        labelChannel->setFrameShadow(QFrame::Plain);
        labelChannel->setLineWidth(0);
        labelChannel->setAlignment(Qt::AlignCenter);
        labelChannel->setWordWrap(true);
        labelChannel->setMargin(4);
        labelChannel->setIndent(5);
        labelChannel->setOpenExternalLinks(false);

        gridLayout_6->addWidget(labelChannel, 0, 0, 1, 1);

        comboBoxChannel = new QComboBox(groupBoxSensor);
        comboBoxChannel->setObjectName(QStringLiteral("comboBoxChannel"));
        comboBoxChannel->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBoxChannel->sizePolicy().hasHeightForWidth());
        comboBoxChannel->setSizePolicy(sizePolicy4);
        comboBoxChannel->setMaximumSize(QSize(150, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(10);
        comboBoxChannel->setFont(font2);
        comboBoxChannel->setEditable(false);
        comboBoxChannel->setMaxVisibleItems(10);

        gridLayout_6->addWidget(comboBoxChannel, 0, 1, 1, 1);

        labelSensorType = new QLabel(groupBoxSensor);
        labelSensorType->setObjectName(QStringLiteral("labelSensorType"));
        sizePolicy3.setHeightForWidth(labelSensorType->sizePolicy().hasHeightForWidth());
        labelSensorType->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        labelSensorType->setFont(font3);
        labelSensorType->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelSensorType, 1, 0, 1, 1);

        comboBoxSensorType = new QComboBox(groupBoxSensor);
        comboBoxSensorType->setObjectName(QStringLiteral("comboBoxSensorType"));
        sizePolicy4.setHeightForWidth(comboBoxSensorType->sizePolicy().hasHeightForWidth());
        comboBoxSensorType->setSizePolicy(sizePolicy4);
        comboBoxSensorType->setMaximumSize(QSize(150, 16777215));
        comboBoxSensorType->setFont(font2);

        gridLayout_6->addWidget(comboBoxSensorType, 1, 1, 1, 1);

        labelDateType = new QLabel(groupBoxSensor);
        labelDateType->setObjectName(QStringLiteral("labelDateType"));
        sizePolicy3.setHeightForWidth(labelDateType->sizePolicy().hasHeightForWidth());
        labelDateType->setSizePolicy(sizePolicy3);
        labelDateType->setFont(font3);
        labelDateType->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelDateType, 2, 0, 1, 1);

        comboBoxDataType = new QComboBox(groupBoxSensor);
        comboBoxDataType->setObjectName(QStringLiteral("comboBoxDataType"));
        sizePolicy4.setHeightForWidth(comboBoxDataType->sizePolicy().hasHeightForWidth());
        comboBoxDataType->setSizePolicy(sizePolicy4);
        comboBoxDataType->setMaximumSize(QSize(150, 16777215));
        comboBoxDataType->setFont(font2);

        gridLayout_6->addWidget(comboBoxDataType, 2, 1, 1, 1);

        labelSensorMax = new QLabel(groupBoxSensor);
        labelSensorMax->setObjectName(QStringLiteral("labelSensorMax"));
        sizePolicy3.setHeightForWidth(labelSensorMax->sizePolicy().hasHeightForWidth());
        labelSensorMax->setSizePolicy(sizePolicy3);
        labelSensorMax->setFont(font3);
        labelSensorMax->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelSensorMax, 3, 0, 1, 1);

        comboBoxSensorMax = new QComboBox(groupBoxSensor);
        comboBoxSensorMax->setObjectName(QStringLiteral("comboBoxSensorMax"));
        sizePolicy4.setHeightForWidth(comboBoxSensorMax->sizePolicy().hasHeightForWidth());
        comboBoxSensorMax->setSizePolicy(sizePolicy4);
        comboBoxSensorMax->setMaximumSize(QSize(150, 16777215));
        comboBoxSensorMax->setFont(font2);
        comboBoxSensorMax->setEditable(true);

        gridLayout_6->addWidget(comboBoxSensorMax, 3, 1, 1, 1);

        labelSensorMin = new QLabel(groupBoxSensor);
        labelSensorMin->setObjectName(QStringLiteral("labelSensorMin"));
        sizePolicy3.setHeightForWidth(labelSensorMin->sizePolicy().hasHeightForWidth());
        labelSensorMin->setSizePolicy(sizePolicy3);
        labelSensorMin->setFont(font3);
        labelSensorMin->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelSensorMin, 4, 0, 1, 1);

        comboBoxSensorMin = new QComboBox(groupBoxSensor);
        comboBoxSensorMin->setObjectName(QStringLiteral("comboBoxSensorMin"));
        sizePolicy4.setHeightForWidth(comboBoxSensorMin->sizePolicy().hasHeightForWidth());
        comboBoxSensorMin->setSizePolicy(sizePolicy4);
        comboBoxSensorMin->setMaximumSize(QSize(150, 16777215));
        comboBoxSensorMin->setFont(font2);
        comboBoxSensorMin->setEditable(true);

        gridLayout_6->addWidget(comboBoxSensorMin, 4, 1, 1, 1);


        verticalLayout_2->addWidget(groupBoxSensor);

        groupBoxData = new QGroupBox(scrollAreaWidgetContents);
        groupBoxData->setObjectName(QStringLiteral("groupBoxData"));
        groupBoxData->setFont(font);
        groupBoxData->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBoxData);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        labelDataName = new QLabel(groupBoxData);
        labelDataName->setObjectName(QStringLiteral("labelDataName"));
        sizePolicy3.setHeightForWidth(labelDataName->sizePolicy().hasHeightForWidth());
        labelDataName->setSizePolicy(sizePolicy3);
        labelDataName->setFont(font1);
        labelDataName->setLineWidth(0);
        labelDataName->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelDataName, 0, 0, 1, 1);

        comboBoxDataName = new QComboBox(groupBoxData);
        comboBoxDataName->setObjectName(QStringLiteral("comboBoxDataName"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBoxDataName->sizePolicy().hasHeightForWidth());
        comboBoxDataName->setSizePolicy(sizePolicy5);
        comboBoxDataName->setMaximumSize(QSize(150, 16777215));
        comboBoxDataName->setFont(font2);
        comboBoxDataName->setEditable(true);

        gridLayout_4->addWidget(comboBoxDataName, 0, 1, 1, 1);

        labelDataUint = new QLabel(groupBoxData);
        labelDataUint->setObjectName(QStringLiteral("labelDataUint"));
        sizePolicy3.setHeightForWidth(labelDataUint->sizePolicy().hasHeightForWidth());
        labelDataUint->setSizePolicy(sizePolicy3);
        labelDataUint->setFont(font3);
        labelDataUint->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelDataUint, 1, 0, 1, 1);

        comboBoxDataUint = new QComboBox(groupBoxData);
        comboBoxDataUint->setObjectName(QStringLiteral("comboBoxDataUint"));
        sizePolicy5.setHeightForWidth(comboBoxDataUint->sizePolicy().hasHeightForWidth());
        comboBoxDataUint->setSizePolicy(sizePolicy5);
        comboBoxDataUint->setMaximumSize(QSize(150, 16777215));
        comboBoxDataUint->setFont(font2);

        gridLayout_4->addWidget(comboBoxDataUint, 1, 1, 1, 1);

        labelMeterType = new QLabel(groupBoxData);
        labelMeterType->setObjectName(QStringLiteral("labelMeterType"));
        sizePolicy3.setHeightForWidth(labelMeterType->sizePolicy().hasHeightForWidth());
        labelMeterType->setSizePolicy(sizePolicy3);
        labelMeterType->setFont(font1);
        labelMeterType->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelMeterType, 2, 0, 1, 1);

        comboBoxMeterType = new QComboBox(groupBoxData);
        comboBoxMeterType->setObjectName(QStringLiteral("comboBoxMeterType"));
        sizePolicy5.setHeightForWidth(comboBoxMeterType->sizePolicy().hasHeightForWidth());
        comboBoxMeterType->setSizePolicy(sizePolicy5);
        comboBoxMeterType->setMaximumSize(QSize(150, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(10);
        font4.setItalic(false);
        comboBoxMeterType->setFont(font4);

        gridLayout_4->addWidget(comboBoxMeterType, 2, 1, 1, 1);


        verticalLayout_2->addWidget(groupBoxData);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font);
        groupBox_5->setAlignment(Qt::AlignCenter);
        horizontalLayout_3 = new QHBoxLayout(groupBox_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelInhibitTime = new QLabel(groupBox_5);
        labelInhibitTime->setObjectName(QStringLiteral("labelInhibitTime"));
        sizePolicy3.setHeightForWidth(labelInhibitTime->sizePolicy().hasHeightForWidth());
        labelInhibitTime->setSizePolicy(sizePolicy3);
        labelInhibitTime->setFont(font3);
        labelInhibitTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelInhibitTime);

        comboBoxInhibitTime = new QComboBox(groupBox_5);
        comboBoxInhibitTime->setObjectName(QStringLiteral("comboBoxInhibitTime"));
        sizePolicy5.setHeightForWidth(comboBoxInhibitTime->sizePolicy().hasHeightForWidth());
        comboBoxInhibitTime->setSizePolicy(sizePolicy5);
        comboBoxInhibitTime->setMaximumSize(QSize(100, 16777215));
        comboBoxInhibitTime->setFont(font2);
        comboBoxInhibitTime->setEditable(true);

        horizontalLayout_3->addWidget(comboBoxInhibitTime);

        comboBoxTimeUint = new QComboBox(groupBox_5);
        comboBoxTimeUint->setObjectName(QStringLiteral("comboBoxTimeUint"));
        sizePolicy5.setHeightForWidth(comboBoxTimeUint->sizePolicy().hasHeightForWidth());
        comboBoxTimeUint->setSizePolicy(sizePolicy5);
        comboBoxTimeUint->setMaximumSize(QSize(50, 16777215));
        comboBoxTimeUint->setFont(font4);

        horizontalLayout_3->addWidget(comboBoxTimeUint);


        verticalLayout_2->addWidget(groupBox_5);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(0, 1));
        groupBox_3->setMaximumSize(QSize(500, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        groupBox_3->setFont(font5);
        groupBox_3->setMouseTracking(false);
        groupBox_3->setFocusPolicy(Qt::NoFocus);
        groupBox_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox_3->setAcceptDrops(false);
        groupBox_3->setToolTipDuration(1);
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, -1, -1, -1);
        groupBoxWarning = new QGroupBox(groupBox_3);
        groupBoxWarning->setObjectName(QStringLiteral("groupBoxWarning"));
        groupBoxWarning->setEnabled(true);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        groupBoxWarning->setFont(font6);
        groupBoxWarning->setFlat(true);
        groupBoxWarning->setCheckable(true);
        groupBoxWarning->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBoxWarning);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(15);
        checkBoxLWarning = new QCheckBox(groupBoxWarning);
        checkBoxLWarning->setObjectName(QStringLiteral("checkBoxLWarning"));
        checkBoxLWarning->setEnabled(false);
        sizePolicy5.setHeightForWidth(checkBoxLWarning->sizePolicy().hasHeightForWidth());
        checkBoxLWarning->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(checkBoxLWarning, 0, 0, 1, 1);

        lineEditLWarning = new QLineEdit(groupBoxWarning);
        lineEditLWarning->setObjectName(QStringLiteral("lineEditLWarning"));
        lineEditLWarning->setEnabled(false);
        lineEditLWarning->setMaximumSize(QSize(150, 16777215));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font7.setUnderline(false);
        font7.setStyleStrategy(QFont::PreferAntialias);
        lineEditLWarning->setFont(font7);
        lineEditLWarning->setProperty("LowerWarning", QVariant(0));

        gridLayout_2->addWidget(lineEditLWarning, 0, 1, 1, 1);

        checkBoxHWarning = new QCheckBox(groupBoxWarning);
        checkBoxHWarning->setObjectName(QStringLiteral("checkBoxHWarning"));
        checkBoxHWarning->setEnabled(false);
        sizePolicy5.setHeightForWidth(checkBoxHWarning->sizePolicy().hasHeightForWidth());
        checkBoxHWarning->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(checkBoxHWarning, 1, 0, 1, 1);

        lineEditHWarning = new QLineEdit(groupBoxWarning);
        lineEditHWarning->setObjectName(QStringLiteral("lineEditHWarning"));
        lineEditHWarning->setEnabled(false);
        lineEditHWarning->setMaximumSize(QSize(150, 16777215));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        lineEditHWarning->setFont(font8);

        gridLayout_2->addWidget(lineEditHWarning, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBoxWarning);

        groupBoxAlarm = new QGroupBox(groupBox_3);
        groupBoxAlarm->setObjectName(QStringLiteral("groupBoxAlarm"));
        groupBoxAlarm->setEnabled(true);
        QFont font9;
        font9.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font9.setBold(true);
        font9.setWeight(75);
        groupBoxAlarm->setFont(font9);
        groupBoxAlarm->setFlat(true);
        groupBoxAlarm->setCheckable(true);
        groupBoxAlarm->setChecked(false);
        gridLayout_3 = new QGridLayout(groupBoxAlarm);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(14);
        checkBoxLAlarm = new QCheckBox(groupBoxAlarm);
        checkBoxLAlarm->setObjectName(QStringLiteral("checkBoxLAlarm"));
        sizePolicy5.setHeightForWidth(checkBoxLAlarm->sizePolicy().hasHeightForWidth());
        checkBoxLAlarm->setSizePolicy(sizePolicy5);
        checkBoxLAlarm->setChecked(false);

        gridLayout_3->addWidget(checkBoxLAlarm, 0, 0, 1, 1);

        lineEditLAlarm = new QLineEdit(groupBoxAlarm);
        lineEditLAlarm->setObjectName(QStringLiteral("lineEditLAlarm"));
        lineEditLAlarm->setEnabled(false);
        lineEditLAlarm->setMaximumSize(QSize(150, 16777215));
        lineEditLAlarm->setFont(font8);

        gridLayout_3->addWidget(lineEditLAlarm, 0, 1, 1, 1);

        checkBoxHAlarm = new QCheckBox(groupBoxAlarm);
        checkBoxHAlarm->setObjectName(QStringLiteral("checkBoxHAlarm"));
        sizePolicy5.setHeightForWidth(checkBoxHAlarm->sizePolicy().hasHeightForWidth());
        checkBoxHAlarm->setSizePolicy(sizePolicy5);
        checkBoxHAlarm->setChecked(false);

        gridLayout_3->addWidget(checkBoxHAlarm, 1, 0, 1, 1);

        lineEditHAlarm = new QLineEdit(groupBoxAlarm);
        lineEditHAlarm->setObjectName(QStringLiteral("lineEditHAlarm"));
        lineEditHAlarm->setEnabled(false);
        lineEditHAlarm->setMaximumSize(QSize(150, 16777215));
        lineEditHAlarm->setFont(font8);

        gridLayout_3->addWidget(lineEditHAlarm, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBoxAlarm);

        groupBoxAlarm->raise();
        groupBoxWarning->raise();

        verticalLayout_2->addWidget(groupBox_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 2, 5, 10);
        pushButtonOK = new QPushButton(SysConfig);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        QFont font10;
        font10.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font10.setPointSize(14);
        font10.setBold(true);
        font10.setWeight(75);
        pushButtonOK->setFont(font10);

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(SysConfig);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QFont font11;
        font11.setPointSize(12);
        font11.setBold(true);
        font11.setWeight(75);
        pushButtonCancel->setFont(font11);

        horizontalLayout->addWidget(pushButtonCancel);

        pushButtonApplied = new QPushButton(SysConfig);
        pushButtonApplied->setObjectName(QStringLiteral("pushButtonApplied"));
        pushButtonApplied->setFont(font11);

        horizontalLayout->addWidget(pushButtonApplied);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_6);

        tableWidget = new QTableWidget(SysConfig);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_2->addWidget(tableWidget);

        tableWidget->raise();
#ifndef QT_NO_SHORTCUT
        labelChannel->setBuddy(comboBoxChannel);
        labelSensorType->setBuddy(comboBoxSensorType);
        labelDateType->setBuddy(comboBoxDataType);
        labelSensorMax->setBuddy(comboBoxSensorMax);
        labelSensorMin->setBuddy(comboBoxSensorMin);
        labelDataName->setBuddy(comboBoxDataName);
        labelDataUint->setBuddy(comboBoxDataUint);
        labelMeterType->setBuddy(comboBoxMeterType);
        labelInhibitTime->setBuddy(comboBoxInhibitTime);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBoxChannel, comboBoxSensorType);
        QWidget::setTabOrder(comboBoxSensorType, comboBoxDataType);
        QWidget::setTabOrder(comboBoxDataType, comboBoxSensorMax);
        QWidget::setTabOrder(comboBoxSensorMax, comboBoxSensorMin);
        QWidget::setTabOrder(comboBoxSensorMin, comboBoxDataName);
        QWidget::setTabOrder(comboBoxDataName, comboBoxDataUint);
        QWidget::setTabOrder(comboBoxDataUint, comboBoxMeterType);
        QWidget::setTabOrder(comboBoxMeterType, comboBoxInhibitTime);
        QWidget::setTabOrder(comboBoxInhibitTime, comboBoxTimeUint);
        QWidget::setTabOrder(comboBoxTimeUint, groupBoxWarning);
        QWidget::setTabOrder(groupBoxWarning, checkBoxLWarning);
        QWidget::setTabOrder(checkBoxLWarning, lineEditLWarning);
        QWidget::setTabOrder(lineEditLWarning, checkBoxHWarning);
        QWidget::setTabOrder(checkBoxHWarning, lineEditHWarning);
        QWidget::setTabOrder(lineEditHWarning, groupBoxAlarm);
        QWidget::setTabOrder(groupBoxAlarm, checkBoxLAlarm);
        QWidget::setTabOrder(checkBoxLAlarm, lineEditLAlarm);
        QWidget::setTabOrder(lineEditLAlarm, checkBoxHAlarm);
        QWidget::setTabOrder(checkBoxHAlarm, lineEditHAlarm);
        QWidget::setTabOrder(lineEditHAlarm, pushButtonOK);
        QWidget::setTabOrder(pushButtonOK, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, pushButtonApplied);
        QWidget::setTabOrder(pushButtonApplied, tableWidget);

        retranslateUi(SysConfig);
        QObject::connect(checkBoxLWarning, SIGNAL(clicked(bool)), lineEditLWarning, SLOT(setEnabled(bool)));
        QObject::connect(groupBoxWarning, SIGNAL(clicked(bool)), checkBoxLWarning, SLOT(setEnabled(bool)));
        QObject::connect(groupBoxWarning, SIGNAL(clicked(bool)), checkBoxHWarning, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxHWarning, SIGNAL(clicked(bool)), lineEditHWarning, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxLAlarm, SIGNAL(clicked(bool)), lineEditLAlarm, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxHAlarm, SIGNAL(clicked(bool)), lineEditHAlarm, SLOT(setEnabled(bool)));
        QObject::connect(groupBoxAlarm, SIGNAL(clicked(bool)), checkBoxHAlarm, SLOT(setEnabled(bool)));
        QObject::connect(groupBoxAlarm, SIGNAL(clicked(bool)), checkBoxLAlarm, SLOT(setEnabled(bool)));

        comboBoxChannel->setCurrentIndex(-1);
        comboBoxSensorMax->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SysConfig);
    } // setupUi

    void retranslateUi(QWidget *SysConfig)
    {
        SysConfig->setWindowTitle(QApplication::translate("SysConfig", "SysConfig", 0));
#ifndef QT_NO_STATUSTIP
        SysConfig->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBoxSensor->setTitle(QApplication::translate("SysConfig", "\344\274\240\346\204\237\345\231\250\350\256\276\347\275\256", 0));
        labelChannel->setText(QApplication::translate("SysConfig", "\351\200\232\351\201\223\350\256\276\347\275\256", 0));
        labelSensorType->setText(QApplication::translate("SysConfig", "\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213", 0));
        comboBoxSensorType->clear();
        comboBoxSensorType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SysConfig", "\347\224\265\345\216\213\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("SysConfig", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("SysConfig", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("SysConfig", "\345\212\240\351\200\237\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("SysConfig", "\351\200\237\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("SysConfig", "\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("SysConfig", "\347\224\265\346\265\201\344\274\240\346\204\237\345\231\250", 0)
        );
        labelDateType->setText(QApplication::translate("SysConfig", "\350\276\223\345\205\245\346\225\260\346\215\256\347\261\273\345\236\213", 0));
        comboBoxDataType->clear();
        comboBoxDataType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SysConfig", "\346\250\241\346\213\237\351\207\217\350\276\223\345\205\245", 0)
         << QApplication::translate("SysConfig", "\346\225\260\345\255\227\351\207\217\350\276\223\345\205\245", 0)
        );
        labelSensorMax->setText(QApplication::translate("SysConfig", "\344\274\240\346\204\237\345\231\250\346\234\200\345\244\247\345\200\274", 0));
        comboBoxSensorMax->setCurrentText(QString());
        labelSensorMin->setText(QApplication::translate("SysConfig", "\344\274\240\346\204\237\345\231\250\346\234\200\345\260\217\345\200\274", 0));
        comboBoxSensorMin->setCurrentText(QApplication::translate("SysConfig", "0", 0));
        groupBoxData->setTitle(QApplication::translate("SysConfig", "\346\230\276\347\244\272\346\226\271\345\274\217\350\256\276\347\275\256", 0));
        labelDataName->setText(QApplication::translate("SysConfig", "\346\225\260\346\215\256\345\220\215\347\247\260", 0));
        comboBoxDataName->clear();
        comboBoxDataName->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SysConfig", "\345\217\221\345\212\250\346\234\272\350\275\254\351\200\237", 0)
         << QApplication::translate("SysConfig", "\346\262\271\344\275\215", 0)
         << QApplication::translate("SysConfig", "\345\217\214\345\217\230\346\270\251\345\272\246", 0)
         << QApplication::translate("SysConfig", "\347\274\270\347\233\226\346\270\251\345\272\246", 0)
         << QApplication::translate("SysConfig", "\346\234\272\346\262\271\346\270\251\345\272\246", 0)
         << QApplication::translate("SysConfig", "\346\234\272\346\262\271\345\216\213\345\212\233", 0)
         << QApplication::translate("SysConfig", "\345\210\266\345\212\250\345\216\213\345\212\233", 0)
         << QApplication::translate("SysConfig", "\345\217\214\345\217\230\345\216\213\345\212\233", 0)
         << QApplication::translate("SysConfig", "\345\205\205\347\224\265\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\345\210\271\350\275\246\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\351\242\204\347\203\255\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\345\210\266\345\212\250\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\345\217\221\347\224\265\346\234\272\346\214\207\347\244\272\347\201\257", 0)
        );
        labelDataUint->setText(QApplication::translate("SysConfig", "\346\225\260\346\215\256\345\215\225\344\275\215", 0));
        comboBoxDataUint->clear();
        comboBoxDataUint->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SysConfig", "V", 0)
         << QApplication::translate("SysConfig", "A", 0)
         << QApplication::translate("SysConfig", "Mpa", 0)
         << QApplication::translate("SysConfig", "m", 0)
         << QApplication::translate("SysConfig", "m/s", 0)
         << QApplication::translate("SysConfig", "m/s^2", 0)
         << QApplication::translate("SysConfig", "N/A", 0)
         << QApplication::translate("SysConfig", "\342\204\203", 0)
         << QApplication::translate("SysConfig", "Bar", 0)
        );
        labelMeterType->setText(QApplication::translate("SysConfig", "\346\230\276\347\244\272\346\226\271\345\274\217", 0));
        comboBoxMeterType->clear();
        comboBoxMeterType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("SysConfig", "\350\275\254\351\200\237\350\241\250", 0)
         << QApplication::translate("SysConfig", "\346\262\271\344\275\215\350\241\250", 0)
         << QApplication::translate("SysConfig", "\344\273\252\350\241\250\347\233\230", 0)
         << QApplication::translate("SysConfig", "\346\270\251\345\272\246\350\256\241", 0)
         << QApplication::translate("SysConfig", "\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\345\205\205\347\224\265\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\345\210\271\350\275\246\345\210\266\345\212\250\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\351\242\204\347\203\255\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\345\210\266\345\212\250\345\205\205\345\216\213\346\254\240\345\216\213\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\347\274\270\347\233\226\346\270\251\345\272\246\346\214\207\347\244\272\347\201\257", 0)
         << QApplication::translate("SysConfig", "\346\234\272\346\262\271\346\270\251\345\272\246\346\214\207\347\244\272\347\201\257", 0)
        );
        groupBox_5->setTitle(QApplication::translate("SysConfig", "\346\225\260\346\215\256\345\255\230\345\202\250\350\256\276\347\275\256", 0));
        labelInhibitTime->setText(QApplication::translate("SysConfig", "\345\255\230\345\202\250\345\221\250\346\234\237", 0));
        comboBoxInhibitTime->clear();
        comboBoxInhibitTime->insertItems(0, QStringList()
         << QApplication::translate("SysConfig", "1", 0)
         << QApplication::translate("SysConfig", "10", 0)
         << QApplication::translate("SysConfig", "30", 0)
         << QApplication::translate("SysConfig", "60", 0)
         << QApplication::translate("SysConfig", "600", 0)
         << QApplication::translate("SysConfig", "1000", 0)
        );
        comboBoxTimeUint->clear();
        comboBoxTimeUint->insertItems(0, QStringList()
         << QApplication::translate("SysConfig", "s", 0)
         << QApplication::translate("SysConfig", "min", 0)
        );
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_3->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox_3->setTitle(QApplication::translate("SysConfig", "\351\230\210\345\200\274\350\256\276\347\275\256", "\350\256\276\347\275\256\351\230\210\345\200\274"));
        groupBoxWarning->setTitle(QApplication::translate("SysConfig", "\350\256\276\347\275\256\351\242\204\350\255\246\345\200\274", 0));
        checkBoxLWarning->setText(QApplication::translate("SysConfig", "\344\270\213\351\231\220\345\200\274", 0));
        checkBoxHWarning->setText(QApplication::translate("SysConfig", "\344\270\212\351\231\220\345\200\274", 0));
        groupBoxAlarm->setTitle(QApplication::translate("SysConfig", "\350\256\276\347\275\256\346\212\245\350\255\246\345\200\274", 0));
        checkBoxLAlarm->setText(QApplication::translate("SysConfig", "\344\270\213\351\231\220\345\200\274", 0));
        checkBoxHAlarm->setText(QApplication::translate("SysConfig", "\344\270\212\351\231\220\345\200\274", 0));
        pushButtonOK->setText(QApplication::translate("SysConfig", "\344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("SysConfig", "\345\217\226\346\266\210", 0));
        pushButtonApplied->setText(QApplication::translate("SysConfig", "\345\272\224\347\224\250", 0));
    } // retranslateUi

};

namespace Ui {
    class SysConfig: public Ui_SysConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSCONFIG_H
