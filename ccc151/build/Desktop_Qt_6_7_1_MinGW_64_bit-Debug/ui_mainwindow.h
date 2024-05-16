/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *LastName;
    QPushButton *SearchStudButt;
    QPushButton *SeachCourseButt;
    QLineEdit *FirstName;
    QLineEdit *MiddleName;
    QLineEdit *IDNumber;
    QComboBox *ComboBox;
    QComboBox *Gender;
    QComboBox *YearLevel;
    QTableView *tableView;
    QPushButton *ShowStudButton;
    QPushButton *ShowCourButton;
    QPushButton *DeleteStudButt;
    QPushButton *DelCoursButt;
    QLineEdit *CourseCode;
    QLineEdit *CourseName;
    QPushButton *AddCoursButt;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *IDNumberCombobox;
    QPushButton *AddStudentButton;
    QLabel *label_9;
    QLineEdit *Search;
    QPushButton *pushButton_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1034, 563);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(255, 217, 206);\n"
"background-color: rgb(255, 213, 171);"));
        LastName = new QLineEdit(centralwidget);
        LastName->setObjectName("LastName");
        LastName->setGeometry(QRect(20, 40, 211, 31));
        SearchStudButt = new QPushButton(centralwidget);
        SearchStudButt->setObjectName("SearchStudButt");
        SearchStudButt->setGeometry(QRect(440, 80, 91, 31));
        SeachCourseButt = new QPushButton(centralwidget);
        SeachCourseButt->setObjectName("SeachCourseButt");
        SeachCourseButt->setGeometry(QRect(770, 80, 91, 31));
        FirstName = new QLineEdit(centralwidget);
        FirstName->setObjectName("FirstName");
        FirstName->setGeometry(QRect(20, 110, 211, 31));
        MiddleName = new QLineEdit(centralwidget);
        MiddleName->setObjectName("MiddleName");
        MiddleName->setGeometry(QRect(20, 180, 211, 31));
        IDNumber = new QLineEdit(centralwidget);
        IDNumber->setObjectName("IDNumber");
        IDNumber->setGeometry(QRect(140, 250, 91, 31));
        ComboBox = new QComboBox(centralwidget);
        ComboBox->setObjectName("ComboBox");
        ComboBox->setGeometry(QRect(20, 370, 211, 31));
        Gender = new QComboBox(centralwidget);
        Gender->setObjectName("Gender");
        Gender->setGeometry(QRect(130, 320, 101, 21));
        YearLevel = new QComboBox(centralwidget);
        YearLevel->setObjectName("YearLevel");
        YearLevel->setGeometry(QRect(20, 320, 91, 21));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(240, 160, 561, 371));
        ShowStudButton = new QPushButton(centralwidget);
        ShowStudButton->setObjectName("ShowStudButton");
        ShowStudButton->setGeometry(QRect(70, 450, 111, 31));
        ShowCourButton = new QPushButton(centralwidget);
        ShowCourButton->setObjectName("ShowCourButton");
        ShowCourButton->setGeometry(QRect(70, 490, 111, 31));
        DeleteStudButt = new QPushButton(centralwidget);
        DeleteStudButt->setObjectName("DeleteStudButt");
        DeleteStudButt->setGeometry(QRect(850, 240, 141, 51));
        DelCoursButt = new QPushButton(centralwidget);
        DelCoursButt->setObjectName("DelCoursButt");
        DelCoursButt->setGeometry(QRect(850, 310, 141, 51));
        CourseCode = new QLineEdit(centralwidget);
        CourseCode->setObjectName("CourseCode");
        CourseCode->setGeometry(QRect(820, 390, 191, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        CourseCode->setFont(font);
        CourseName = new QLineEdit(centralwidget);
        CourseName->setObjectName("CourseName");
        CourseName->setGeometry(QRect(820, 440, 191, 31));
        CourseName->setFont(font);
        AddCoursButt = new QPushButton(centralwidget);
        AddCoursButt->setObjectName("AddCoursButt");
        AddCoursButt->setGeometry(QRect(870, 490, 91, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 20, 761, 61));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka Text")});
        font1.setPointSize(22);
        font1.setBold(false);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 91, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 90, 91, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 160, 91, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 230, 91, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 300, 91, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(130, 300, 91, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 350, 91, 20));
        IDNumberCombobox = new QComboBox(centralwidget);
        IDNumberCombobox->setObjectName("IDNumberCombobox");
        IDNumberCombobox->setGeometry(QRect(20, 250, 101, 31));
        AddStudentButton = new QPushButton(centralwidget);
        AddStudentButton->setObjectName("AddStudentButton");
        AddStudentButton->setGeometry(QRect(80, 410, 91, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 0, 291, 16));
        Search = new QLineEdit(centralwidget);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(240, 120, 761, 31));
        QFont font2;
        font2.setPointSize(19);
        font2.setBold(true);
        Search->setFont(font2);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(850, 180, 141, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SearchStudButt->setText(QCoreApplication::translate("MainWindow", "Search Student", nullptr));
        SeachCourseButt->setText(QCoreApplication::translate("MainWindow", "Search Course", nullptr));
        ShowStudButton->setText(QCoreApplication::translate("MainWindow", "Show Students", nullptr));
        ShowCourButton->setText(QCoreApplication::translate("MainWindow", "Show Courses", nullptr));
        DeleteStudButt->setText(QCoreApplication::translate("MainWindow", "Delete Student", nullptr));
        DelCoursButt->setText(QCoreApplication::translate("MainWindow", "Delete Course", nullptr));
        CourseCode->setInputMask(QString());
        CourseCode->setText(QString());
        CourseCode->setPlaceholderText(QCoreApplication::translate("MainWindow", "Course Code", nullptr));
        CourseName->setInputMask(QString());
        CourseName->setText(QString());
        CourseName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Course Name", nullptr));
        AddCoursButt->setText(QCoreApplication::translate("MainWindow", "Add Course", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">Simple Student Information System</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Middle Name", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ID Number", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Year Level", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Course Code", nullptr));
        AddStudentButton->setText(QCoreApplication::translate("MainWindow", "Add Student", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "[+] Status", nullptr));
        Search->setText(QString());
        Search->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
