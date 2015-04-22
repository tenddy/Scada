/********************************************************************************
** Form generated from reading UI file 'qscalesetting.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSCALESETTING_H
#define UI_QSCALESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QScaleSetting
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_addData;
    QPushButton *pushButton_deleteData;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_default;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QScaleSetting)
    {
        if (QScaleSetting->objectName().isEmpty())
            QScaleSetting->setObjectName(QStringLiteral("QScaleSetting"));
        QScaleSetting->resize(300, 458);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QScaleSetting->sizePolicy().hasHeightForWidth());
        QScaleSetting->setSizePolicy(sizePolicy);
        QScaleSetting->setMinimumSize(QSize(300, 100));
        QScaleSetting->setMaximumSize(QSize(300, 2000));
        QScaleSetting->setBaseSize(QSize(300, 400));
        QScaleSetting->setFocusPolicy(Qt::StrongFocus);
        verticalLayout = new QVBoxLayout(QScaleSetting);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        label = new QLabel(QScaleSetting);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        tableView = new QTableView(QScaleSetting);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMinimumSize(QSize(290, 0));
        tableView->setMaximumSize(QSize(290, 2000));
        tableView->setSizeIncrement(QSize(0, 300));
        tableView->setBaseSize(QSize(300, 400));
        QFont font1;
        font1.setPointSize(12);
        tableView->setFont(font1);
        tableView->setFocusPolicy(Qt::StrongFocus);
        tableView->setFrameShape(QFrame::StyledPanel);
        tableView->setFrameShadow(QFrame::Sunken);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->horizontalHeader()->setDefaultSectionSize(144);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout->addWidget(tableView, 0, Qt::AlignHCenter);

        groupBox = new QGroupBox(QScaleSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        groupBox->setFont(font2);
        groupBox->setFocusPolicy(Qt::TabFocus);
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_addData = new QPushButton(groupBox);
        pushButton_addData->setObjectName(QStringLiteral("pushButton_addData"));

        horizontalLayout_2->addWidget(pushButton_addData);

        pushButton_deleteData = new QPushButton(groupBox);
        pushButton_deleteData->setObjectName(QStringLiteral("pushButton_deleteData"));

        horizontalLayout_2->addWidget(pushButton_deleteData);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        pushButton_save = new QPushButton(QScaleSetting);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy3);
        pushButton_save->setMinimumSize(QSize(30, 40));
        pushButton_save->setBaseSize(QSize(60, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(10);
        pushButton_save->setFont(font3);

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(QScaleSetting);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        sizePolicy3.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy3);
        pushButton_cancel->setMinimumSize(QSize(40, 40));
        pushButton_cancel->setFont(font3);

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_default = new QPushButton(QScaleSetting);
        pushButton_default->setObjectName(QStringLiteral("pushButton_default"));
        sizePolicy3.setHeightForWidth(pushButton_default->sizePolicy().hasHeightForWidth());
        pushButton_default->setSizePolicy(sizePolicy3);
        pushButton_default->setMinimumSize(QSize(110, 40));
        pushButton_default->setFont(font3);

        horizontalLayout->addWidget(pushButton_default);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(QScaleSetting);

        QMetaObject::connectSlotsByName(QScaleSetting);
    } // setupUi

    void retranslateUi(QWidget *QScaleSetting)
    {
        QScaleSetting->setWindowTitle(QApplication::translate("QScaleSetting", "\350\267\235\347\246\273\345\260\272\345\272\246\346\240\207\345\256\232\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("QScaleSetting", "\346\265\213\350\267\235\345\256\232\344\275\215\346\240\207\347\255\276\346\240\207\345\256\232\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("QScaleSetting", "\346\225\260\346\215\256\346\223\215\344\275\234", 0));
        pushButton_addData->setText(QApplication::translate("QScaleSetting", "\346\267\273\345\212\240\346\225\260\346\215\256", 0));
        pushButton_deleteData->setText(QApplication::translate("QScaleSetting", "\345\210\240\351\231\244\346\211\200\351\200\211\346\225\260\346\215\256", 0));
        pushButton_save->setText(QApplication::translate("QScaleSetting", "\344\277\235\345\255\230", 0));
        pushButton_cancel->setText(QApplication::translate("QScaleSetting", "\351\200\200\345\207\272", 0));
        pushButton_default->setText(QApplication::translate("QScaleSetting", "\346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class QScaleSetting: public Ui_QScaleSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSCALESETTING_H
