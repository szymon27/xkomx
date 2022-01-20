#include "orderdetailswindow.h"
#include "ui_orderdetailswindow.h"

OrderDetailsWindow::OrderDetailsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDetailsWindow)
{
    ui->setupUi(this);
    ui->leName->setText(CurrentUser::instance()->user().name());
    ui->leSurname->setText(CurrentUser::instance()->user().surname());
    ui->leCity->setText(CurrentUser::instance()->user().city());
    ui->lePostalCode->setText(CurrentUser::instance()->user().postCode());
    ui->leAddress->setText(CurrentUser::instance()->user().address());
    ui->leCountry->setText(CurrentUser::instance()->user().country());
}

OrderDetailsWindow::~OrderDetailsWindow()
{
    delete ui;
}

bool OrderDetailsWindow::success() const
{
    return m_success;
}

void OrderDetailsWindow::on_btnConfirm_clicked()
{
    QString username = ui->leBankUsername->text();
    QString password = ui->leBankPassword->text();
    m_success = DbManager::instance()->order(username, password);
    if(m_success) {
        QMessageBox::information(this, "XKOMX", "Ordered successfully!");
        emit on_success();
        this->close();
    }
    else QMessageBox::warning(this, "XKOMX", "Order failed!");
}


void OrderDetailsWindow::on_btnCancel_clicked()
{
    this->close();
}

