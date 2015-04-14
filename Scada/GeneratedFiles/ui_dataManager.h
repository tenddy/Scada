/********************************************************************************
** Form generated from reading UI file 'dataManager.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMANAGER_H
#define UI_DATAMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_DataManager
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTableList;
    QComboBox *comboBoxTableList;
    QPushButton *pushButtonClearData;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *DataManager)
    {
        if (DataManager->objectName().isEmpty())
            DataManager->setObjectName(QStringLiteral("DataManager"));
        DataManager->resize(590, 455);
        verticalLayout = new QVBoxLayout(DataManager);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DataManager);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelTableList = new QLabel(groupBox);
        labelTableList->setObjectName(QStringLiteral("labelTableList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTableList->sizePolicy().hasHeightForWidth());
        labelTableList->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelTableList->setFont(font);

        horizontalLayout->addWidget(labelTableList);

        comboBoxTableList = new QComboBox(groupBox);
        comboBoxTableList->setObjectName(QStringLiteral("comboBoxTableList"));
        sizePolicy.setHeightForWidth(comboBoxTableList->sizePolicy().hasHeightForWidth());
        comboBoxTableList->setSizePolicy(sizePolicy);
        comboBoxTableList->setFont(font);

        horizontalLayout->addWidget(comboBoxTableList);

        pushButtonClearData = new QPushButton(groupBox);
        pushButtonClearData->setObjectName(QStringLiteral("pushButtonClearData"));

        horizontalLayout->addWidget(pushButtonClearData);

        horizontalSpacer = new QSpacerItem(256, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBox);

        tableView = new QTableView(DataManager);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(DataManager);

        QMetaObject::connectSlotsByName(DataManager);
    } // setupUi

    void retranslateUi(QWidget *DataManager)
    {
        DataManager->setWindowTitle(QApplication::translate("DataManager", "Form", 0));
        groupBox->setTitle(QString());
        labelTableList->setText(QApplication::translate("DataManager", "\346\225\260\346\215\256\350\241\250", 0));
        pushButtonClearData->setText(QApplication::translate("DataManager", "\346\270\205\347\251\272\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class DataManager: public Ui_DataManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMANAGER_H
