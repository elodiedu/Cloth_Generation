/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QScrollBar *horizontalScrollBar_4;
    QScrollBar *horizontalScrollBar_5;
    QScrollBar *horizontalScrollBar_6;
    QScrollBar *horizontalScrollBar_7;
    QScrollBar *horizontalScrollBar_8;
    QScrollBar *horizontalScrollBar_9;
    QScrollBar *horizontalScrollBar_10;
    QScrollBar *horizontalScrollBar_11;
    QScrollBar *horizontalScrollBar_12;
    QScrollBar *horizontalScrollBar_13;
    QStackedWidget *page_1;
    QWidget *page;
    QWidget *page_2;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_1;
    QScrollBar *horizontalScrollBar_3;
    QScrollBar *horizontalScrollBar_2;
    QScrollBar *horizontalScrollBar;
    QStackedWidget *page_5;
    QWidget *page_3;
    QLabel *label_14;
    QScrollBar *horizontalScrollBar_14;
    QLabel *label_15;
    QScrollBar *horizontalScrollBar_15;
    QWidget *page_4;
    QPushButton *btnSelectImage;
    QLabel *Selected_Image;
    QLabel *WaitDialog;
    QPushButton *helpButton;
    QPushButton *DeleteButton;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 1200);
        QPalette palette;
        QBrush brush(QColor(127, 127, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(214, 214, 214, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(202, 208, 213, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(100, 100, 100, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(68, 68, 68, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QBrush brush5(QColor(163, 181, 192, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        MainWindow->setPalette(palette);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 350, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(15);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton->setIconSize(QSize(59, 50));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 680, 111, 16));
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 710, 111, 16));
        comboBox = new QComboBox(MainWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 470, 111, 21));
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 470, 81, 16));
        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 530, 111, 16));
        label_5 = new QLabel(MainWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 560, 111, 16));
        label_6 = new QLabel(MainWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 590, 111, 16));
        label_7 = new QLabel(MainWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 620, 111, 16));
        label_9 = new QLabel(MainWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 650, 111, 16));
        label_10 = new QLabel(MainWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 740, 111, 16));
        label_12 = new QLabel(MainWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 770, 111, 16));
        label_13 = new QLabel(MainWindow);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 800, 111, 16));
        horizontalScrollBar_4 = new QScrollBar(MainWindow);
        horizontalScrollBar_4->setObjectName(QString::fromUtf8("horizontalScrollBar_4"));
        horizontalScrollBar_4->setGeometry(QRect(140, 800, 261, 16));
        horizontalScrollBar_4->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_5 = new QScrollBar(MainWindow);
        horizontalScrollBar_5->setObjectName(QString::fromUtf8("horizontalScrollBar_5"));
        horizontalScrollBar_5->setGeometry(QRect(140, 770, 261, 16));
        horizontalScrollBar_5->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_6 = new QScrollBar(MainWindow);
        horizontalScrollBar_6->setObjectName(QString::fromUtf8("horizontalScrollBar_6"));
        horizontalScrollBar_6->setGeometry(QRect(140, 740, 261, 16));
        horizontalScrollBar_6->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_7 = new QScrollBar(MainWindow);
        horizontalScrollBar_7->setObjectName(QString::fromUtf8("horizontalScrollBar_7"));
        horizontalScrollBar_7->setGeometry(QRect(140, 710, 261, 16));
        horizontalScrollBar_7->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_8 = new QScrollBar(MainWindow);
        horizontalScrollBar_8->setObjectName(QString::fromUtf8("horizontalScrollBar_8"));
        horizontalScrollBar_8->setGeometry(QRect(140, 680, 261, 16));
        horizontalScrollBar_8->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_9 = new QScrollBar(MainWindow);
        horizontalScrollBar_9->setObjectName(QString::fromUtf8("horizontalScrollBar_9"));
        horizontalScrollBar_9->setGeometry(QRect(140, 650, 261, 16));
        horizontalScrollBar_9->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_10 = new QScrollBar(MainWindow);
        horizontalScrollBar_10->setObjectName(QString::fromUtf8("horizontalScrollBar_10"));
        horizontalScrollBar_10->setGeometry(QRect(140, 620, 261, 16));
        horizontalScrollBar_10->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_11 = new QScrollBar(MainWindow);
        horizontalScrollBar_11->setObjectName(QString::fromUtf8("horizontalScrollBar_11"));
        horizontalScrollBar_11->setGeometry(QRect(140, 590, 261, 16));
        horizontalScrollBar_11->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_12 = new QScrollBar(MainWindow);
        horizontalScrollBar_12->setObjectName(QString::fromUtf8("horizontalScrollBar_12"));
        horizontalScrollBar_12->setGeometry(QRect(140, 560, 261, 16));
        horizontalScrollBar_12->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_13 = new QScrollBar(MainWindow);
        horizontalScrollBar_13->setObjectName(QString::fromUtf8("horizontalScrollBar_13"));
        horizontalScrollBar_13->setGeometry(QRect(140, 530, 261, 16));
        horizontalScrollBar_13->setOrientation(Qt::Orientation::Horizontal);
        page_1 = new QStackedWidget(MainWindow);
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setGeometry(QRect(0, 820, 461, 91));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page_1->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 111, 16));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 40, 111, 16));
        label_1 = new QLabel(page_2);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 70, 101, 16));
        horizontalScrollBar_3 = new QScrollBar(page_2);
        horizontalScrollBar_3->setObjectName(QString::fromUtf8("horizontalScrollBar_3"));
        horizontalScrollBar_3->setGeometry(QRect(140, 10, 261, 16));
        horizontalScrollBar_3->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar_2 = new QScrollBar(page_2);
        horizontalScrollBar_2->setObjectName(QString::fromUtf8("horizontalScrollBar_2"));
        horizontalScrollBar_2->setGeometry(QRect(140, 40, 261, 16));
        horizontalScrollBar_2->setOrientation(Qt::Orientation::Horizontal);
        horizontalScrollBar = new QScrollBar(page_2);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(140, 70, 261, 16));
        horizontalScrollBar->setOrientation(Qt::Orientation::Horizontal);
        page_1->addWidget(page_2);
        page_5 = new QStackedWidget(MainWindow);
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(10, 920, 401, 151));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 0, 101, 16));
        horizontalScrollBar_14 = new QScrollBar(page_3);
        horizontalScrollBar_14->setObjectName(QString::fromUtf8("horizontalScrollBar_14"));
        horizontalScrollBar_14->setGeometry(QRect(130, 0, 261, 16));
        horizontalScrollBar_14->setOrientation(Qt::Orientation::Horizontal);
        label_15 = new QLabel(page_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(0, 30, 101, 16));
        horizontalScrollBar_15 = new QScrollBar(page_3);
        horizontalScrollBar_15->setObjectName(QString::fromUtf8("horizontalScrollBar_15"));
        horizontalScrollBar_15->setGeometry(QRect(130, 30, 261, 16));
        horizontalScrollBar_15->setOrientation(Qt::Orientation::Horizontal);
        page_5->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_5->addWidget(page_4);
        btnSelectImage = new QPushButton(MainWindow);
        btnSelectImage->setObjectName(QString::fromUtf8("btnSelectImage"));
        btnSelectImage->setGeometry(QRect(140, 290, 171, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        btnSelectImage->setFont(font1);
        Selected_Image = new QLabel(MainWindow);
        Selected_Image->setObjectName(QString::fromUtf8("Selected_Image"));
        Selected_Image->setGeometry(QRect(140, 40, 181, 181));
        WaitDialog = new QLabel(MainWindow);
        WaitDialog->setObjectName(QString::fromUtf8("WaitDialog"));
        WaitDialog->setGeometry(QRect(350, 350, 191, 41));
        helpButton = new QPushButton(MainWindow);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(470, 130, 80, 24));
        DeleteButton = new QPushButton(MainWindow);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setGeometry(QRect(380, 130, 80, 24));

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(3);
        page_1->setCurrentIndex(1);
        page_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Create Cloth", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Shoulder to Sleeve", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Width Along Bottom", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Round Neck Shirt", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "V-Neck Shirt", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Hoodie", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Tank Top", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Cloth Type", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Neck to Hem", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Chest", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Shoulder to Shoulder", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Sleeve Width", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Shoulder to Pit", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Width of Neck", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Front Neck Height", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Back Neck Height", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Pit to Sleeve", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Center Back Length", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "Width Bottom", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Hoodie Height", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Hoodie Width", nullptr));
        btnSelectImage->setText(QCoreApplication::translate("MainWindow", "Load Images", nullptr));
        Selected_Image->setText(QCoreApplication::translate("MainWindow", "No Image Slected", nullptr));
        WaitDialog->setText(QCoreApplication::translate("MainWindow", "Creating...Please Wait", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Cloth", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
