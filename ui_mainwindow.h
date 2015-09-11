/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_image;
    QWidget *centralWidget;
    QLabel *show_Img;
    QSlider *brightness;
    QSlider *red;
    QSlider *green;
    QSlider *bluw;
    QPushButton *grayscale;
    QPushButton *blur;
    QPushButton *save_Img;
    QLabel *label_brightness;
    QLabel *label_colorTemp;
    QLabel *label_red;
    QLabel *label_green;
    QLabel *label_blue;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(979, 420);
        actionLoad_image = new QAction(MainWindow);
        actionLoad_image->setObjectName(QStringLiteral("actionLoad_image"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        show_Img = new QLabel(centralWidget);
        show_Img->setObjectName(QStringLiteral("show_Img"));
        show_Img->setGeometry(QRect(30, 20, 501, 311));
        brightness = new QSlider(centralWidget);
        brightness->setObjectName(QStringLiteral("brightness"));
        brightness->setGeometry(QRect(650, 70, 160, 22));
        brightness->setOrientation(Qt::Horizontal);
        red = new QSlider(centralWidget);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(690, 130, 160, 22));
        red->setOrientation(Qt::Horizontal);
        green = new QSlider(centralWidget);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(690, 170, 160, 22));
        green->setOrientation(Qt::Horizontal);
        bluw = new QSlider(centralWidget);
        bluw->setObjectName(QStringLiteral("bluw"));
        bluw->setGeometry(QRect(690, 210, 160, 22));
        bluw->setOrientation(Qt::Horizontal);
        grayscale = new QPushButton(centralWidget);
        grayscale->setObjectName(QStringLiteral("grayscale"));
        grayscale->setGeometry(QRect(620, 250, 101, 41));
        QFont font;
        font.setPointSize(12);
        grayscale->setFont(font);
        blur = new QPushButton(centralWidget);
        blur->setObjectName(QStringLiteral("blur"));
        blur->setGeometry(QRect(740, 250, 101, 41));
        blur->setFont(font);
        save_Img = new QPushButton(centralWidget);
        save_Img->setObjectName(QStringLiteral("save_Img"));
        save_Img->setGeometry(QRect(660, 310, 141, 41));
        save_Img->setFont(font);
        label_brightness = new QLabel(centralWidget);
        label_brightness->setObjectName(QStringLiteral("label_brightness"));
        label_brightness->setGeometry(QRect(610, 40, 71, 21));
        label_brightness->setFont(font);
        label_colorTemp = new QLabel(centralWidget);
        label_colorTemp->setObjectName(QStringLiteral("label_colorTemp"));
        label_colorTemp->setGeometry(QRect(610, 100, 81, 21));
        label_colorTemp->setFont(font);
        label_red = new QLabel(centralWidget);
        label_red->setObjectName(QStringLiteral("label_red"));
        label_red->setGeometry(QRect(650, 130, 21, 21));
        label_red->setFont(font);
        label_green = new QLabel(centralWidget);
        label_green->setObjectName(QStringLiteral("label_green"));
        label_green->setGeometry(QRect(650, 170, 31, 21));
        label_green->setFont(font);
        label_blue = new QLabel(centralWidget);
        label_blue->setObjectName(QStringLiteral("label_blue"));
        label_blue->setGeometry(QRect(650, 200, 31, 31));
        label_blue->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 979, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionLoad_image);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad_image->setText(QApplication::translate("MainWindow", "Load image", 0));
        show_Img->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        grayscale->setText(QApplication::translate("MainWindow", "\347\201\260\351\232\216\345\214\226", 0));
        blur->setText(QApplication::translate("MainWindow", "\346\250\241\347\263\212\345\214\226", 0));
        save_Img->setText(QApplication::translate("MainWindow", "\345\204\262\345\255\230\345\275\261\345\203\217", 0));
        label_brightness->setText(QApplication::translate("MainWindow", "\350\252\277\346\225\264\344\272\256\345\272\246", 0));
        label_colorTemp->setText(QApplication::translate("MainWindow", "\350\252\277\346\225\264\350\211\262\346\272\253", 0));
        label_red->setText(QApplication::translate("MainWindow", "\347\264\205", 0));
        label_green->setText(QApplication::translate("MainWindow", "\347\266\240", 0));
        label_blue->setText(QApplication::translate("MainWindow", "\350\227\215", 0));
        menu->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
