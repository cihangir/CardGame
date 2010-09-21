/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 21 17:40:15 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *styletool;
    QComboBox *stylecombo;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QFrame *westHand;
    QFrame *southHand;
    QFrame *eastHand;
    QFrame *tableEast;
    QFrame *tableCenter;
    QFrame *tableWest;
    QFrame *tableNorth;
    QFrame *tableSouth;
    QFrame *northHand;
    QWidget *page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *resultlabel;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(635, 548);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 111, 195);"));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(222, 222, 222);\n"
"font: 75 10pt \"DejaVu Sans Mono\";\n"
"\n"
""));
        pushButton->setCheckable(false);
        pushButton->setFlat(true);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 40, 101, 17));
        pushButton_2 = new QPushButton(page_3);
        buttonGroup = new QButtonGroup(Widget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 220, 93, 27));
        pushButton_3 = new QPushButton(page_3);
        buttonGroup->addButton(pushButton_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 260, 93, 27));
        widget = new QWidget(page_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 60, 359, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        styletool = new QToolButton(widget);
        styletool->setObjectName(QString::fromUtf8("styletool"));
        styletool->setStyleSheet(QString::fromUtf8(" QToolButton#styletool {\n"
"     background-color: red;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: beige;\n"
"     font: bold 12px;\n"
"     min-width: 10em;\n"
"     padding: 6px;\n"
" }\n"
"\n"
" QToolButton#styletool:pressed {\n"
"	 padding: 5px;\n"
"     background-color: rgb(195, 0, 0);\n"
"     border-style: inset;\n"
" }\n"
""));

        horizontalLayout->addWidget(styletool);

        stylecombo = new QComboBox(widget);
        stylecombo->setObjectName(QString::fromUtf8("stylecombo"));
        stylecombo->setStyleSheet(QString::fromUtf8(" QComboBox#stylecombo {\n"
"     background-color: red;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: beige;\n"
"     font: bold 12px;\n"
"     min-width: 10em;\n"
"     padding: 6px;\n"
" }\n"
"\n"
"  QComboBox#stylecombo:pressed {\n"
"	 padding: 5px;\n"
"     background-color: rgb(224, 0, 0);\n"
"     border-style: inset;\n"
" }\n"
""));

        horizontalLayout->addWidget(stylecombo);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(9, 9, 9, 9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        westHand = new QFrame(page_2);
        westHand->setObjectName(QString::fromUtf8("westHand"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(westHand->sizePolicy().hasHeightForWidth());
        westHand->setSizePolicy(sizePolicy);
        westHand->setFrameShape(QFrame::NoFrame);
        westHand->setFrameShadow(QFrame::Raised);
        westHand->setLineWidth(1);

        gridLayout->addWidget(westHand, 0, 0, 4, 1);

        southHand = new QFrame(page_2);
        southHand->setObjectName(QString::fromUtf8("southHand"));
        southHand->setMinimumSize(QSize(50, 50));
        southHand->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(southHand, 4, 0, 1, 5);

        eastHand = new QFrame(page_2);
        eastHand->setObjectName(QString::fromUtf8("eastHand"));
        eastHand->setFrameShape(QFrame::NoFrame);
        eastHand->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(eastHand, 0, 4, 4, 1);

        tableEast = new QFrame(page_2);
        tableEast->setObjectName(QString::fromUtf8("tableEast"));
        tableEast->setFrameShape(QFrame::NoFrame);
        tableEast->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(tableEast, 2, 3, 1, 1);

        tableCenter = new QFrame(page_2);
        tableCenter->setObjectName(QString::fromUtf8("tableCenter"));
        tableCenter->setFrameShape(QFrame::NoFrame);
        tableCenter->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(tableCenter, 2, 2, 1, 1);

        tableWest = new QFrame(page_2);
        tableWest->setObjectName(QString::fromUtf8("tableWest"));
        tableWest->setFrameShape(QFrame::NoFrame);
        tableWest->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(tableWest, 2, 1, 1, 1);

        tableNorth = new QFrame(page_2);
        tableNorth->setObjectName(QString::fromUtf8("tableNorth"));
        tableNorth->setFrameShape(QFrame::NoFrame);
        tableNorth->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(tableNorth, 1, 2, 1, 1);

        tableSouth = new QFrame(page_2);
        tableSouth->setObjectName(QString::fromUtf8("tableSouth"));
        tableSouth->setFrameShape(QFrame::NoFrame);
        tableSouth->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(tableSouth, 3, 2, 1, 1);

        northHand = new QFrame(page_2);
        northHand->setObjectName(QString::fromUtf8("northHand"));
        northHand->setFrameShape(QFrame::NoFrame);
        northHand->setFrameShadow(QFrame::Raised);
        northHand->setLineWidth(1);

        gridLayout->addWidget(northHand, 0, 1, 1, 3);

        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 20, 451, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8(""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        resultlabel = new QLabel(verticalLayoutWidget);
        resultlabel->setObjectName(QString::fromUtf8("resultlabel"));
        sizePolicy.setHeightForWidth(resultlabel->sizePolicy().hasHeightForWidth());
        resultlabel->setSizePolicy(sizePolicy);
        resultlabel->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Bitstream Charter\";"));

        verticalLayout->addWidget(resultlabel);

        stackedWidget->addWidget(page);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButton->setText(QApplication::translate("Widget", "Restart Game", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "Game Type", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", 0, QApplication::UnicodeUTF8));
        styletool->setText(QApplication::translate("Widget", "New Game", 0, QApplication::UnicodeUTF8));
        stylecombo->clear();
        stylecombo->insertItems(0, QStringList()
         << QApplication::translate("Widget", "4 Player", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "2 Player", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#424242;\">Game Over</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        resultlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
