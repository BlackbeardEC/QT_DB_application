#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void set_unp(QString, QString);
    QString get_u();
    QString get_p();

signals:
    void up_set();


private slots:
    void on_exit_btn_clicked();
    void on_login_btn_clicked();


private:
    Ui::Login *ui;
    QString du;
    QString dp;
};

#endif // LOGIN_H
