/********************************************************************************
** Form generated from reading UI file 'monitorsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORSYSTEM_H
#define UI_MONITORSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonitorSystemClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonChangedPage;
    QLabel *alarmLabel;

    void setupUi(QWidget *MonitorSystemClass)
    {
        if (MonitorSystemClass->objectName().isEmpty())
            MonitorSystemClass->setObjectName(QStringLiteral("MonitorSystemClass"));
        MonitorSystemClass->resize(600, 395);
        MonitorSystemClass->setFocusPolicy(Qt::ClickFocus);
        MonitorSystemClass->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(MonitorSystemClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 11);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(MonitorSystemClass);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        font.setUnderline(false);
        stackedWidget->setFont(font);
        stackedWidget->setToolTipDuration(10);
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setLineWidth(0);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonChangedPage = new QPushButton(MonitorSystemClass);
        pushButtonChangedPage->setObjectName(QStringLiteral("pushButtonChangedPage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonChangedPage->sizePolicy().hasHeightForWidth());
        pushButtonChangedPage->setSizePolicy(sizePolicy);
        pushButtonChangedPage->setMinimumSize(QSize(100, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButtonChangedPage->setFont(font1);

        horizontalLayout->addWidget(pushButtonChangedPage);

        alarmLabel = new QLabel(MonitorSystemClass);
        alarmLabel->setObjectName(QStringLiteral("alarmLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        alarmLabel->setFont(font2);
        alarmLabel->setFrameShape(QFrame::StyledPanel);
        alarmLabel->setLineWidth(0);
        alarmLabel->setTextFormat(Qt::RichText);
        alarmLabel->setScaledContents(true);
        alarmLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(alarmLabel);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(MonitorSystemClass);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MonitorSystemClass);
    } // setupUi

    void retranslateUi(QWidget *MonitorSystemClass)
    {
        MonitorSystemClass->setWindowTitle(QApplication::translate("MonitorSystemClass", "MonitorSystem", 0));
#ifndef QT_NO_STATUSTIP
        MonitorSystemClass->setStatusTip(QApplication::translate("MonitorSystemClass", "1232", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        stackedWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonChangedPage->setText(QApplication::translate("MonitorSystemClass", "\350\247\206\351\242\221", 0));
        alarmLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonitorSystemClass: public Ui_MonitorSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORSYSTEM_H
