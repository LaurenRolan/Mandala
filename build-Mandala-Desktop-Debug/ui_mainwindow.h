/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionEdit;
    QAction *actionHelp;
    QWidget *centralWidget;
    QFrame *frame;
    QLineEdit *slicesEdit;
    QPushButton *removeSliceButton;
    QPushButton *addSliceButton;
    QLabel *slicesLabel;
    QCheckBox *mirrorBox;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QPushButton *pushButton;
    QFrame *frame_2;
    QWidget *widget;
    QFrame *frame_3;
    QLabel *label_3;
    QGraphicsView *graphicsView;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(772, 608);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QString::fromUtf8("actionFile"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 0, 751, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        slicesEdit = new QLineEdit(frame);
        slicesEdit->setObjectName(QString::fromUtf8("slicesEdit"));
        slicesEdit->setGeometry(QRect(40, 30, 41, 27));
        removeSliceButton = new QPushButton(frame);
        removeSliceButton->setObjectName(QString::fromUtf8("removeSliceButton"));
        removeSliceButton->setGeometry(QRect(80, 30, 31, 27));
        addSliceButton = new QPushButton(frame);
        addSliceButton->setObjectName(QString::fromUtf8("addSliceButton"));
        addSliceButton->setGeometry(QRect(10, 30, 31, 27));
        slicesLabel = new QLabel(frame);
        slicesLabel->setObjectName(QString::fromUtf8("slicesLabel"));
        slicesLabel->setGeometry(QRect(40, 10, 41, 17));
        mirrorBox = new QCheckBox(frame);
        mirrorBox->setObjectName(QString::fromUtf8("mirrorBox"));
        mirrorBox->setGeometry(QRect(150, 10, 97, 22));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(150, 40, 97, 22));
        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(270, 30, 160, 29));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 10, 91, 20));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(460, 30, 85, 27));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 10, 31, 17));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 30, 99, 27));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 90, 751, 371));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 0, 481, 371));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(9, 470, 751, 51));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 71, 17));
        graphicsView = new QGraphicsView(frame_3);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(90, 10, 31, 31));
        horizontalSlider_2 = new QSlider(frame_3);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(140, 10, 160, 29));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 10, 99, 27));
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(640, 10, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionFile);
        mainToolBar->addAction(actionEdit);
        mainToolBar->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionFile->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        actionFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        actionEdit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        removeSliceButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        addSliceButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        slicesLabel->setText(QApplication::translate("MainWindow", "Slices", 0, QApplication::UnicodeUTF8));
        mirrorBox->setText(QApplication::translate("MainWindow", "Mirror", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Show grid", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Grid intensity", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "640x360", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "800x600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1280x1024", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1920x1080", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Line width", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Line color", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Background", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
