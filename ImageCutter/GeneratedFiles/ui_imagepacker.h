/********************************************************************************
** Form generated from reading UI file 'imagepacker.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPACKER_H
#define UI_IMAGEPACKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagePackerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_Scene;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGroupBox *groupBox;
    QLineEdit *imageID;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLabel *label_size;
    QLabel *label_pos;
    QLabel *label_wh;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *ImagePackerClass)
    {
        if (ImagePackerClass->objectName().isEmpty())
            ImagePackerClass->setObjectName(QStringLiteral("ImagePackerClass"));
        ImagePackerClass->resize(1233, 853);
        ImagePackerClass->setAcceptDrops(true);
        centralWidget = new QWidget(ImagePackerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_Scene = new QHBoxLayout();
        horizontalLayout_Scene->setSpacing(1);
        horizontalLayout_Scene->setObjectName(QStringLiteral("horizontalLayout_Scene"));

        verticalLayout_4->addLayout(horizontalLayout_Scene);

        ImagePackerClass->setCentralWidget(centralWidget);
        dockWidget_2 = new QDockWidget(ImagePackerClass);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(347, 818));
        dockWidget_2->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        groupBox = new QGroupBox(dockWidgetContents_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 341, 41));
        imageID = new QLineEdit(groupBox);
        imageID->setObjectName(QStringLiteral("imageID"));
        imageID->setGeometry(QRect(10, 10, 231, 20));
        imageID->setInputMethodHints(Qt::ImhDigitsOnly);
        imageID->setMaxLength(5);
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(250, 10, 81, 16));
        groupBox_2 = new QGroupBox(dockWidgetContents_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 50, 341, 98));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_name = new QLabel(groupBox_2);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout->addWidget(label_name);

        label_size = new QLabel(groupBox_2);
        label_size->setObjectName(QStringLiteral("label_size"));

        verticalLayout->addWidget(label_size);

        label_pos = new QLabel(groupBox_2);
        label_pos->setObjectName(QStringLiteral("label_pos"));

        verticalLayout->addWidget(label_pos);

        label_wh = new QLabel(groupBox_2);
        label_wh->setObjectName(QStringLiteral("label_wh"));

        verticalLayout->addWidget(label_wh);

        dockWidget_2->setWidget(dockWidgetContents_2);
        ImagePackerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);
        menuBar = new QMenuBar(ImagePackerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1233, 21));
        ImagePackerClass->setMenuBar(menuBar);

        retranslateUi(ImagePackerClass);

        QMetaObject::connectSlotsByName(ImagePackerClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImagePackerClass)
    {
        ImagePackerClass->setWindowTitle(QApplication::translate("ImagePackerClass", "ImagePacker", 0));
        groupBox->setTitle(QString());
        checkBox->setText(QApplication::translate("ImagePackerClass", "OnlyAlpha", 0));
        groupBox_2->setTitle(QApplication::translate("ImagePackerClass", "Info", 0));
        label_name->setText(QApplication::translate("ImagePackerClass", "name:", 0));
        label_size->setText(QApplication::translate("ImagePackerClass", "size:", 0));
        label_pos->setText(QApplication::translate("ImagePackerClass", "pos:", 0));
        label_wh->setText(QApplication::translate("ImagePackerClass", "wh:", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagePackerClass: public Ui_ImagePackerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPACKER_H
