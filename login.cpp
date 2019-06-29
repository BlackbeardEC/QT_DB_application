#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_exit_btn_clicked()
{
    done(0);
}

void Login::on_login_btn_clicked()
{
    QString user, pass;
    user = ui->username_line_edit->text();
    pass = ui->password_line_edit->text();
    qDebug() << "Sending login, user: " << user << ", pass: " << pass;
    set_unp(user, pass);
    emit up_set();
    done(0);
}

void Login::set_unp(QString u, QString p){
    du= u;
    dp = p;
}

QString Login::get_u(){
    return du;
}

QString Login::get_p(){
    return dp;
}
