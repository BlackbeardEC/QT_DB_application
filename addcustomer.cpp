#include "addcustomer.h"
#include "ui_addcustomer.h"
#include "mainwindow.h"

AddCustomer::AddCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomer)
{
    ui->setupUi(this);

    QSqlQuery query("SELECT * FROM employee");
    while (query.next()) {
        QString name = query.value("name").toString();
        int id = query.value("id").toInt();
        ehash.insert(name,id);
    }
    QHashIterator<QString, int> i(ehash);
    while (i.hasNext()) {
        i.next();
        // insert into comboBox
        ui->reps_combo_box->addItem(i.key());
    }

}

AddCustomer::~AddCustomer()
{
    delete ui;
}

void AddCustomer::on_insert_customer_btn_clicked()
{
    // Get the values from form
    QString name, address, phone, email;
    int id;
    id = ehash.value(ui->reps_combo_box->currentText());
    name = ui->name_line_edit->text();
    address = ui->address_line_edit->text();
    phone = ui->phone_number_line_edit->text();
    email = ui->email_line_edit->text();
    // Insert record into db
    bool results;
    MainWindow *mw = static_cast<MainWindow*>(parent());
    results = mw->add_customer(name, address, phone, email, id);

    if(results){
        ui->results_label->setText("Customer Added");
    }else{
        ui->results_label->setText("Error: Customer NOT Added");
    }
    // Clear the form
    ui->name_line_edit->setText("");
    ui->address_line_edit->setText("");
    ui->phone_number_line_edit->setText("");
    ui->email_line_edit->setText("");
}

void AddCustomer::on_done_btn_clicked()
{
    done(0);
}
