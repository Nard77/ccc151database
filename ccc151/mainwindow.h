#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddStudentButton_clicked();

    void on_AddCoursButt_clicked();

    void on_ShowCourButton_clicked();

    void on_ShowStudButton_clicked();

    void on_SearchStudButt_clicked();

    void on_SeachCourseButt_clicked();

    void on_pushButton_3_clicked();

    void on_DeleteStudButt_clicked();

    void on_DelCoursButt_clicked();

    void populateCourseCodeComboBox();

    void enableEdit();

    void saveChanges();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase cccdb;
};


void validateIDNumber(const QString& idNumber);

#endif // MAINWINDOW_H
