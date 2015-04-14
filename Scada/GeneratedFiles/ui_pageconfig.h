/********************************************************************************
** Form generated from reading UI file 'pageconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGECONFIG_H
#define UI_PAGECONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageConfig
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QTabWidget *tabWidget;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *PageConfig)
    {
        if (PageConfig->objectName().isEmpty())
            PageConfig->setObjectName(QStringLiteral("PageConfig"));
        PageConfig->resize(363, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PageConfig->sizePolicy().hasHeightForWidth());
        PageConfig->setSizePolicy(sizePolicy);
        PageConfig->setFocusPolicy(Qt::ClickFocus);
        verticalLayout = new QVBoxLayout(PageConfig);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_2 = new QSplitter(PageConfig);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setBaseSize(QSize(500, 0));
        tabWidget->setFocusPolicy(Qt::ClickFocus);
        splitter_2->addWidget(tabWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeWidget = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QStringLiteral("2"));
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        treeWidget->setMinimumSize(QSize(100, 0));
        treeWidget->setMaximumSize(QSize(400, 16777215));
        treeWidget->setBaseSize(QSize(300, 400));
        treeWidget->setFocusPolicy(Qt::ClickFocus);
        treeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        treeWidget->setAutoScrollMargin(40);
        treeWidget->setDragEnabled(true);
        treeWidget->setTextElideMode(Qt::ElideMiddle);
        treeWidget->setAutoExpandDelay(-1);
        treeWidget->setIndentation(20);
        treeWidget->setHeaderHidden(false);
        treeWidget->setExpandsOnDoubleClick(false);
        treeWidget->setColumnCount(2);
        splitter->addWidget(treeWidget);
        treeWidget->header()->setCascadingSectionResizes(false);
        treeWidget->header()->setDefaultSectionSize(150);
        treeWidget->header()->setMinimumSectionSize(40);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        stackedWidget->setMinimumSize(QSize(100, 0));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        stackedWidget->setBaseSize(QSize(300, 400));
        splitter->addWidget(stackedWidget);
        splitter_2->addWidget(splitter);

        verticalLayout->addWidget(splitter_2);


        retranslateUi(PageConfig);

        tabWidget->setCurrentIndex(-1);
        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PageConfig);
    } // setupUi

    void retranslateUi(QWidget *PageConfig)
    {
        PageConfig->setWindowTitle(QApplication::translate("PageConfig", "PageConfig", 0));
    } // retranslateUi

};

namespace Ui {
    class PageConfig: public Ui_PageConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGECONFIG_H
