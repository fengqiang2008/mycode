/********************************************************************************
** Form generated from reading UI file 'weathershowdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERSHOWDLG_H
#define UI_WEATHERSHOWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherShowDlgClass
{
public:
    QAction *actionSelectDir;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuSystem;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WeatherShowDlgClass)
    {
        if (WeatherShowDlgClass->objectName().isEmpty())
            WeatherShowDlgClass->setObjectName(QStringLiteral("WeatherShowDlgClass"));
        WeatherShowDlgClass->resize(763, 548);
        actionSelectDir = new QAction(WeatherShowDlgClass);
        actionSelectDir->setObjectName(QStringLiteral("actionSelectDir"));
        centralWidget = new QWidget(WeatherShowDlgClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(groupBox);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(treeWidget);

        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(tableWidget);


        horizontalLayout_2->addWidget(groupBox);

        WeatherShowDlgClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WeatherShowDlgClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 763, 23));
        menuSystem = new QMenu(menuBar);
        menuSystem->setObjectName(QStringLiteral("menuSystem"));
        WeatherShowDlgClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WeatherShowDlgClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WeatherShowDlgClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WeatherShowDlgClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WeatherShowDlgClass->setStatusBar(statusBar);

        menuBar->addAction(menuSystem->menuAction());
        menuSystem->addAction(actionSelectDir);

        retranslateUi(WeatherShowDlgClass);

        QMetaObject::connectSlotsByName(WeatherShowDlgClass);
    } // setupUi

    void retranslateUi(QMainWindow *WeatherShowDlgClass)
    {
        WeatherShowDlgClass->setWindowTitle(QApplication::translate("WeatherShowDlgClass", "WeatherShowDlg", 0));
        actionSelectDir->setText(QApplication::translate("WeatherShowDlgClass", "SelectDir", 0));
        groupBox->setTitle(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("WeatherShowDlgClass", "File", 0));
        menuSystem->setTitle(QApplication::translate("WeatherShowDlgClass", "System", 0));
    } // retranslateUi

};

namespace Ui {
    class WeatherShowDlgClass: public Ui_WeatherShowDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERSHOWDLG_H
