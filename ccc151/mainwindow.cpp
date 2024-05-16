#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QStyledItemDelegate>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    populateCourseCodeComboBox();

    // Populate IDNumberCombobox
    for (int year = 2000; year <= 2024; ++year) {
        ui->IDNumberCombobox->addItem(QString::number(year)+ "-");
    }

    // Add items to YearLevel combobox
    ui->YearLevel->addItem("First Year");
    ui->YearLevel->addItem("Second Year");
    ui->YearLevel->addItem("Third Year");
    ui->YearLevel->addItem("Fourth Year");
    ui->YearLevel->addItem("Ongoing");

    // Add items to Gender combobox
    ui->Gender->addItem("Male");
    ui->Gender->addItem("Female");

    // Initialize and open the database connection
    cccdb = QSqlDatabase::addDatabase("QSQLITE");
    cccdb.setDatabaseName("D:/Documents/ccc151/cccdb.db");

    if (cccdb.open())
        ui->label_9->setText("Database Connected");
    else
        ui->label_9->setText("Failed to connect");

    // Connect the "Save" button to a slot
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddStudentButton_clicked()
{
    // Retrieve input data
    QString lastName = ui->LastName->text();
    QString firstName = ui->FirstName->text();
    QString middleName = ui->MiddleName->text();
    QString idNumberComboBox = ui->IDNumberCombobox->currentText();
    QString idNumberLineEdit = ui->IDNumber->text();
    QString yearLevelComboBox = ui->YearLevel->currentText();
    QString genderComboBox = ui->Gender->currentText();
    QString courseCodeComboBox = ui->ComboBox->currentText();

    // Check if any field is empty
    if (lastName.isEmpty() || firstName.isEmpty() || middleName.isEmpty() ||
        idNumberComboBox.isEmpty() || idNumberLineEdit.isEmpty() ||
        yearLevelComboBox.isEmpty() || genderComboBox.isEmpty() ||
        courseCodeComboBox.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in all fields.");
        return;
    }

    // Combine IDNumber values from combobox and line edit
    QString combinedIDNumber = idNumberComboBox + idNumberLineEdit;

    if (idNumberLineEdit.length() != 4) {
        QMessageBox::warning(this, "Invalid IDNumber", "IDNumber must be exactly 4 digits.");
        return;
    }

    // Check if IDNumber already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM StudentInfo WHERE IDNumber = :idNumber");
    checkQuery.bindValue(":idNumber", combinedIDNumber);
    if (checkQuery.exec() && checkQuery.next()) {
        QMessageBox::warning(this, "Warning", "IDNumber already exists. Please enter a different IDNumber.");
        return;
    }

    // Insert new student data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO StudentInfo (LastName, FirstName, MiddleName, CombinedIDNumber, YearLevel, Gender, CourseCode) "
                  "VALUES (:lastName, :firstName, :middleName, :combinedIDNumber, :yearLevelComboBox, :genderComboBox, :courseCodeComboBox)");
    query.bindValue(":lastName", lastName);
    query.bindValue(":firstName", firstName);
    query.bindValue(":middleName", middleName);
    query.bindValue(":combinedIDNumber", combinedIDNumber);
    query.bindValue(":yearLevelComboBox", yearLevelComboBox);
    query.bindValue(":genderComboBox", genderComboBox);
    query.bindValue(":courseCodeComboBox", courseCodeComboBox);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Student added successfully");
    } else {
        QMessageBox::critical(this, "Error", "Error adding student: " + query.lastError().text());
    }
}

void MainWindow::on_AddCoursButt_clicked()
{
    // Retrieve course code and course name
    QString courseCode = ui->CourseCode->text();
    QString courseName = ui->CourseName->text();

    // Check if any field is empty
    if (courseCode.isEmpty() || courseName.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please fill in all fields.");
        return;
    }

    // Check if CourseCode and CourseName combination already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Courses WHERE [Course Code] = :courseCode OR [Course Name] = :courseName");
    checkQuery.bindValue(":courseCode", courseCode);
    checkQuery.bindValue(":courseName", courseName);
    if (checkQuery.exec() && checkQuery.next()) {
        QMessageBox::warning(this, "Warning", "Course already exists. Please enter a different CourseCode or CourseName.");
        return;
    }

    // Insert new course data into the database
    QSqlQuery courseQuery;
    courseQuery.prepare("INSERT INTO Courses ([Course Code], [Course Name]) "
                        "VALUES (:courseCode, :courseName)");
    courseQuery.bindValue(":courseCode", courseCode);
    courseQuery.bindValue(":courseName", courseName);

    if (courseQuery.exec())
    {
        QMessageBox::information(this, "Success", "Course Added Successfully");
        populateCourseCodeComboBox();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Error adding course: " + courseQuery.lastError().text());
    }
}


void MainWindow::on_ShowCourButton_clicked()
{
    // Display courses in QTableView
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("Courses");

    if (model->select()) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
    } else {
        QMessageBox::critical(this, "Error", "Failed to retrieve courses: " + model->lastError().text());
    }
}

void MainWindow::on_ShowStudButton_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("StudentInfo");

    if (model->select()) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
    } else {
        QMessageBox::critical(this, "Error", "Failed to retrieve student data: " + model->lastError().text());
    }
}

void MainWindow::on_SearchStudButt_clicked()
{
    if (!cccdb.isOpen()) {
        QMessageBox::critical(this, "Error", "Database is not open.");
        return;
    }

    QString searchTerm = ui->Search->text();
    QString queryString = "SELECT * FROM StudentInfo WHERE "
                          "[LastName] LIKE :searchTerm OR "
                          "[FirstName] LIKE :searchTerm OR "
                          "[MiddleName] LIKE :searchTerm OR "
                          "[CombinedIDNumber] LIKE :searchTerm OR "
                          "[YearLevel] LIKE :searchTerm OR "
                          "[Gender] LIKE :searchTerm";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":searchTerm", "%" + searchTerm + "%");
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Error executing search query for StudentInfo: " + query.lastError().text());
        return;
    }

    QSqlQueryModel *studentModel = new QSqlQueryModel(this);
    studentModel->setQuery(query);
    if (studentModel->lastError().isValid()) {
        QMessageBox::critical(this, "Error", "Error setting model for StudentInfo: " + studentModel->lastError().text());
        return;
    }

    ui->tableView->setModel(studentModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_SeachCourseButt_clicked()
{
    if (!cccdb.isOpen()) {
        QMessageBox::critical(this, "Error", "Database is not open.");
        return;
    }

    QString searchTerm = ui->Search->text();
    QString queryString = "SELECT * FROM Courses WHERE "
                          "[Course Code] LIKE :searchTerm OR "
                          "[Course Name] LIKE :searchTerm";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":searchTerm", "%" + searchTerm + "%");
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Error executing search query for Courses: " + query.lastError().text());
        return;
    }

    QSqlQueryModel *courseModel = new QSqlQueryModel(this);
    courseModel->setQuery(query);
    if (courseModel->lastError().isValid()) {
        QMessageBox::critical(this, "Error", "Error setting model for Courses: " + courseModel->lastError().text());
        return;
    }

    ui->tableView->setModel(courseModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void MainWindow::on_DeleteStudButt_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Warning", "Please select a row to delete.");
        return;
    }

    int row = currentIndex.row();
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
    if (!model) {
        QMessageBox::critical(this, "Error", "Failed to retrieve model.");
        return;
    }

    if (QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this student?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
        return;
    }

    if (!model->removeRow(row)) {
        QMessageBox::critical(this, "Error", "Failed to delete student.");
        return;
    }

    if (!model->submitAll()) {
        QMessageBox::critical(this, "Error", "Failed to update database.");
        model->revertAll();
        return;
    }

    model->select(); // Refresh the model to reflect changes in the database
    QMessageBox::information(this, "Success", "Student deleted successfully.");
}

void MainWindow::on_DelCoursButt_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    // Check if any row is selected
    if(selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No course selected for deletion.");
        return;
    }

    // Ask for confirmation
    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete the selected course(s)?",
                                         QMessageBox::Yes | QMessageBox::No);

    if (confirmation == QMessageBox::No)
        return;

    // Access the database
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    // Start a transaction to ensure atomicity
    db.transaction();

    // Delete each selected course
    foreach(const QModelIndex& index, selectedIndexes) {
        int row = index.row();

        // Get the Course Code of the selected course
        QString courseCode = ui->tableView->model()->index(row, 0).data().toString();

        // Prepare the delete query
        query.prepare("DELETE FROM Courses WHERE [Course Code] = :courseCode");
        query.bindValue(":courseCode", courseCode);

        // Execute the delete query
        if (!query.exec()) {
            QMessageBox::critical(this, "Error", "Failed to delete course: " + query.lastError().text());
            db.rollback(); // Rollback the transaction
            return;
        }
    }

    // Commit the transaction
    if (!db.commit()) {
        QMessageBox::critical(this, "Error", "Failed to commit transaction: " + db.lastError().text());
        return;
    }

    // Update the table view
    on_ShowCourButton_clicked(); // Refresh the course list
    QMessageBox::information(this, "Success", "Course(s) deleted successfully.");
}

void MainWindow::populateCourseCodeComboBox()
{
    cccdb = QSqlDatabase::addDatabase("QSQLITE");
    cccdb.setDatabaseName("D:/Documents/ccc151/cccdb.db");

    if (!cccdb.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database: " + cccdb.lastError().text());
        return;
    }

    // Clear the existing items in the combobox
    ui->ComboBox->clear();

    // Create a QSqlQuery to fetch the Course Code values from the Courses table
    QSqlQuery query("SELECT [Course Code] FROM Courses");

    // Execute the query and iterate over the results
    while (query.next())
    {
        QString courseCode = query.value(0).toString(); // Assuming Course Code is the first column
        ui->ComboBox->addItem(courseCode); // Add the Course Code to the combobox
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
    if (!model) {
        QMessageBox::critical(this, "Error", "Failed to retrieve model.");
        return;
    }

    if (model->submitAll()) {
        QMessageBox::information(this, "Success", "Changes saved successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to save changes: " + model->lastError().text());
    }
}

