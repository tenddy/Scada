/********************************************************************************
** Form generated from reading UI file 'pageconfigdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGECONFIGDLG_H
#define UI_PAGECONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageConfigDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *pageNameHorizontalLayout;
    QLabel *pageNameLabel;
    QLineEdit *pageNameLineEdit;
    QGroupBox *meterGroupBox;
    QGridLayout *gridLayout;
    QLabel *rowLabel;
    QSpinBox *rowSpinBox;
    QLabel *columnLabel;
    QSpinBox *columnSpinBox;
    QGroupBox *lampGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *lampLabel;
    QSpinBox *lampNumSpinBox;
    QPushButton *posAdjustPushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PageConfigDlg)
    {
        if (PageConfigDlg->objectName().isEmpty())
            PageConfigDlg->setObjectName(QStringLiteral("PageConfigDlg"));
        PageConfigDlg->resize(331, 668);
        PageConfigDlg->setFocusPolicy(Qt::ClickFocus);
        verticalLayout_2 = new QVBoxLayout(PageConfigDlg);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(PageConfigDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(30);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pageNameHorizontalLayout = new QHBoxLayout();
        pageNameHorizontalLayout->setSpacing(6);
        pageNameHorizontalLayout->setObjectName(QStringLiteral("pageNameHorizontalLayout"));
        pageNameLabel = new QLabel(groupBox);
        pageNameLabel->setObjectName(QStringLiteral("pageNameLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pageNameLabel->sizePolicy().hasHeightForWidth());
        pageNameLabel->setSizePolicy(sizePolicy);

        pageNameHorizontalLayout->addWidget(pageNameLabel);

        pageNameLineEdit = new QLineEdit(groupBox);
        pageNameLineEdit->setObjectName(QStringLiteral("pageNameLineEdit"));
        pageNameLineEdit->setFocusPolicy(Qt::ClickFocus);

        pageNameHorizontalLayout->addWidget(pageNameLineEdit);


        verticalLayout->addLayout(pageNameHorizontalLayout);

        meterGroupBox = new QGroupBox(groupBox);
        meterGroupBox->setObjectName(QStringLiteral("meterGroupBox"));
        meterGroupBox->setEnabled(true);
        meterGroupBox->setCheckable(false);
        gridLayout = new QGridLayout(meterGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rowLabel = new QLabel(meterGroupBox);
        rowLabel->setObjectName(QStringLiteral("rowLabel"));
        sizePolicy.setHeightForWidth(rowLabel->sizePolicy().hasHeightForWidth());
        rowLabel->setSizePolicy(sizePolicy);
        rowLabel->setFrameShape(QFrame::NoFrame);
        rowLabel->setFrameShadow(QFrame::Sunken);
        rowLabel->setMargin(0);
        rowLabel->setIndent(-1);

        gridLayout->addWidget(rowLabel, 0, 0, 1, 1);

        rowSpinBox = new QSpinBox(meterGroupBox);
        rowSpinBox->setObjectName(QStringLiteral("rowSpinBox"));
        QFont font1;
        font1.setPointSize(12);
        rowSpinBox->setFont(font1);
        rowSpinBox->setCursor(QCursor(Qt::IBeamCursor));
        rowSpinBox->setMouseTracking(false);
        rowSpinBox->setFocusPolicy(Qt::ClickFocus);
        rowSpinBox->setMinimum(1);
        rowSpinBox->setMaximum(4);

        gridLayout->addWidget(rowSpinBox, 0, 1, 1, 1);

        columnLabel = new QLabel(meterGroupBox);
        columnLabel->setObjectName(QStringLiteral("columnLabel"));

        gridLayout->addWidget(columnLabel, 1, 0, 1, 1);

        columnSpinBox = new QSpinBox(meterGroupBox);
        columnSpinBox->setObjectName(QStringLiteral("columnSpinBox"));
        columnSpinBox->setFont(font1);
        columnSpinBox->setFocusPolicy(Qt::ClickFocus);
        columnSpinBox->setMinimum(1);
        columnSpinBox->setMaximum(4);

        gridLayout->addWidget(columnSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(meterGroupBox);

        lampGroupBox = new QGroupBox(groupBox);
        lampGroupBox->setObjectName(QStringLiteral("lampGroupBox"));
        lampGroupBox->setFocusPolicy(Qt::ClickFocus);
        lampGroupBox->setCheckable(true);
        horizontalLayout = new QHBoxLayout(lampGroupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lampLabel = new QLabel(lampGroupBox);
        lampLabel->setObjectName(QStringLiteral("lampLabel"));
        sizePolicy.setHeightForWidth(lampLabel->sizePolicy().hasHeightForWidth());
        lampLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lampLabel);

        lampNumSpinBox = new QSpinBox(lampGroupBox);
        lampNumSpinBox->setObjectName(QStringLiteral("lampNumSpinBox"));
        lampNumSpinBox->setFocusPolicy(Qt::ClickFocus);
        lampNumSpinBox->setMaximum(6);

        horizontalLayout->addWidget(lampNumSpinBox);


        verticalLayout->addWidget(lampGroupBox);

        posAdjustPushButton = new QPushButton(groupBox);
        posAdjustPushButton->setObjectName(QStringLiteral("posAdjustPushButton"));

        verticalLayout->addWidget(posAdjustPushButton);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 366, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

#ifndef QT_NO_SHORTCUT
        pageNameLabel->setBuddy(pageNameLineEdit);
        rowLabel->setBuddy(rowSpinBox);
        columnLabel->setBuddy(columnSpinBox);
        lampLabel->setBuddy(lampNumSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(PageConfigDlg);
        QObject::connect(lampGroupBox, SIGNAL(clicked(bool)), lampNumSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(lampGroupBox, SIGNAL(toggled(bool)), lampNumSpinBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(PageConfigDlg);
    } // setupUi

    void retranslateUi(QWidget *PageConfigDlg)
    {
        PageConfigDlg->setWindowTitle(QApplication::translate("PageConfigDlg", "PageConfigDlg", 0));
        groupBox->setTitle(QApplication::translate("PageConfigDlg", "\351\241\265\351\235\242\350\256\276\347\275\256", 0));
        pageNameLabel->setText(QApplication::translate("PageConfigDlg", "\351\241\265\351\235\242\345\220\215\347\247\260", 0));
        meterGroupBox->setTitle(QApplication::translate("PageConfigDlg", "\344\273\252\350\241\250\346\230\276\347\244\272\346\226\271\345\274\217", 0));
        rowLabel->setText(QApplication::translate("PageConfigDlg", "\350\241\214\346\225\260", 0));
        columnLabel->setText(QApplication::translate("PageConfigDlg", "\345\210\227\346\225\260", 0));
        lampGroupBox->setTitle(QApplication::translate("PageConfigDlg", "\346\214\207\347\244\272\347\201\257\346\230\276\347\244\272\346\226\271\345\274\217", 0));
        lampLabel->setText(QApplication::translate("PageConfigDlg", "\346\214\207\347\244\272\347\201\257\346\225\260\347\233\256", 0));
        posAdjustPushButton->setText(QApplication::translate("PageConfigDlg", "\350\260\203\346\225\264\344\273\252\350\241\250\344\275\215\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class PageConfigDlg: public Ui_PageConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGECONFIGDLG_H
