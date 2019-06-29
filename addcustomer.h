#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>

namespace Ui {
class AddCustomer;
}

class AddCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomer(QWidget *parent = nullptr);
    ~AddCustomer();
    QHash<QString, int> ehash;

private slots:
    void on_insert_customer_btn_clicked();

    void on_done_btn_clicked();

private:
    Ui::AddCustomer *ui;
};

#endif // ADDCUSTOMER_H
