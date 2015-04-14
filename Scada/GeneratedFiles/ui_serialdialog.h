/********************************************************************************
** Form generated from reading UI file 'serialdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALDIALOG_H
#define UI_SERIALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialDialog
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SerialDialog)
    {
        if (SerialDialog->objectName().isEmpty())
            SerialDialog->setObjectName(QStringLiteral("SerialDialog"));
        SerialDialog->resize(400, 300);
        actionAbout = new QAction(SerialDialog);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(SerialDialog);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(SerialDialog);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Distance/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(SerialDialog);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Distance/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(SerialDialog);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Distance/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(SerialDialog);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Distance/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(SerialDialog);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Distance/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        centralWidget = new QWidget(SerialDialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        SerialDialog->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SerialDialog);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SerialDialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SerialDialog);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SerialDialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SerialDialog);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SerialDialog->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);

        retranslateUi(SerialDialog);

        QMetaObject::connectSlotsByName(SerialDialog);
    } // setupUi

    void retranslateUi(QMainWindow *SerialDialog)
    {
        SerialDialog->setWindowTitle(QApplication::translate("SerialDialog", "Simple Terminal", 0));
        actionAbout->setText(QApplication::translate("SerialDialog", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("SerialDialog", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("SerialDialog", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("SerialDialog", "About Qt", 0));
        actionConnect->setText(QApplication::translate("SerialDialog", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("SerialDialog", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("SerialDialog", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("SerialDialog", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("SerialDialog", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("SerialDialog", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("SerialDialog", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("SerialDialog", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("SerialDialog", "Alt+C", 0));
        actionClear->setText(QApplication::translate("SerialDialog", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("SerialDialog", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("SerialDialog", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("SerialDialog", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("SerialDialog", "Ctrl+Q", 0));
        menuCalls->setTitle(QApplication::translate("SerialDialog", "Calls", 0));
        menuTools->setTitle(QApplication::translate("SerialDialog", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("SerialDialog", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialDialog: public Ui_SerialDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALDIALOG_H
