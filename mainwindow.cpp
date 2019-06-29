#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addemployee.h"
#include "addcustomer.h"

#include <QMessageBox>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&login, SIGNAL(up_set()), this, SLOT(up_get()));
    connected = false;

    // Init query_model
    query_model = new QSqlQueryModel();

}

MainWindow::~MainWindow()
{
    delete ui;
    connection_close();
}

bool MainWindow::connection_open(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("project_db");
    db.setUserName(db_user);
    db.setPassword(db_pass);
    if(!db.open()){
        qDebug() << "Error: Cannot connect to database.";
        return false;
    }else{
        qDebug() << "Success: Connected to database.";
        return true;
    }
}

void MainWindow::launch_login(){
    login.setModal(true);
    login.exec();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_employee_button_clicked()
{
    // Check if we're connected
    if(connected){
        // Query employee table and populate table veiw
        query_model->setQuery("SELECT * FROM employee");
        ui->query_table_view->setModel(query_model);
    }else{
        QMessageBox::warning(this,"Error","Unable to connect to the database");
        return;
    }
}

void MainWindow::on_customer_button_clicked()
{
    // Check if we're connected
    if(connected){
        // Query customer table and populate table veiw
        query_model->setQuery("SELECT * FROM customer");
        ui->query_table_view->setModel(query_model);
        // Set column widths
        ui->query_table_view->setColumnWidth(0,40);
        ui->query_table_view->setColumnWidth(1,125);
        ui->query_table_view->setColumnWidth(2,150);
        ui->query_table_view->setColumnWidth(3,130);
        ui->query_table_view->setColumnWidth(4,300);
        ui->query_table_view->setColumnWidth(5,40);
    }else{
        QMessageBox::warning(this,"Error","Unable to connect to the database");
        return;
    }
}

void MainWindow::on_add_employee_btn_clicked()
{
    if(connected){
        AddEmployee add_employee;
        add_employee.setModal(true);
        add_employee.exec();
    }else{
        QMessageBox::warning(this,"Error","Unable to connect to the database");
        return;
    }
}

void MainWindow::on_add_customer_btn_clicked()
{
    if(connected){
        AddCustomer add_customer;
        add_customer.setModal(true);
        add_customer.exec();
    }else{
        QMessageBox::warning(this,"Error","Unable to connect to the database");
        return;
    }
}

bool MainWindow::add_employee(QString name, QString address, QString phone, QString email){
    QSqlQuery q;
    bool ret;
    ret = q.exec(QString("insert into employee values(NULL,'%1','%2','%3','%4')")
                 .arg(name).arg(address).arg(phone).arg(email));
    return ret;
}

bool MainWindow::add_customer(QString name, QString address, QString phone, QString email, int rep_id){
    QSqlQuery q;
    bool ret;
    ret = q.exec(QString("insert into customer values(NULL,'%1','%2','%3','%4','%5')")
                 .arg(name).arg(address).arg(phone).arg(email).arg(rep_id));
    qDebug() << ret;
    return ret;
}

void MainWindow::set_dbu_dbp(QString user, QString pass){
    db_user = user;
    db_pass = pass;
    qDebug() << "db_user and db_pass set to: " << db_user << db_pass;
}

void MainWindow::up_get(){
    db_user = login.get_u();
    db_pass = login.get_p();
    if(connection_open()){
        ui->connect_label->setText("Connected.");
        connected = true;
    }else{
        QMessageBox::warning(this,"Error","Unable to connect to the database");
        ui->connect_label->setText("NOT Connected.");
    }
}

void MainWindow::on_actionLogin_triggered()
{
    launch_login();
}


