#include "addemployee.h"
#include "ui_addemployee.h"
#include "mainwindow.h"

AddEmployee::AddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployee)
{
    ui->setupUi(this);
}

AddEmployee::~AddEmployee()
{
    delete ui;
}

void AddEmployee::on_done_btn_clicked()
{
    done(0);
}

void AddEmployee::on_insert_employee_btn_clicked()
{
    // Get the values from form
    QString name, address, phone, email;
    name = ui->name_line_edit->text();
    address = ui->address_line_edit->text();
    phone = ui->phone_number_line_edit->text();
    email = ui->email_line_edit->text();
    // Insert record into db
    bool results;
    MainWindow *mw = static_cast<MainWindow*>(parent());//->QApplication::activeWindow();
    results = mw->add_employee(name, address, phone, email);

    if(results){
        ui->results_label->setText("Employee Added");
    }else{
        ui->results_label->setText("Error: Employee NOT Added");
    }
    // Clear the form
    ui->name_line_edit->setText("");
    ui->address_line_edit->setText("");
    ui->phone_number_line_edit->setText("");
    ui->email_line_edit->setText("");

}
