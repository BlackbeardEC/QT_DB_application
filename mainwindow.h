#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Login login;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connection_close(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool add_employee(QString name, QString address, QString phone, QString email);
    bool add_customer(QString name, QString address, QString phone, QString email, int rep_id);
    bool connection_open();
    void set_dbu_dbp(QString user, QString pass);
    void launch_login();

public slots:
    void on_actionExit_triggered();
    void up_get();

private slots:

    void on_employee_button_clicked();
    void on_customer_button_clicked();
    void on_add_employee_btn_clicked();
    void on_actionLogin_triggered();

    void on_add_customer_btn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *query_model;
    QString db_user;
    QString db_pass;
    bool connected;
};

#endif // MAINWINDOW_H
