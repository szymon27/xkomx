#include "manageruserwidget.h"
#include "ui_manageruserwidget.h"

ManagerUserWidget::ManagerUserWidget(User user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerUserWidget),
    m_user(user)
{
    ui->setupUi(this);
    setControls();
}

ManagerUserWidget::~ManagerUserWidget()
{
    delete ui;
}

void ManagerUserWidget::setControls()
{
    ui->lbUsername->setText(m_user.username());
    ui->lbName->setText(m_user.name());
    ui->lbSurname->setText(m_user.surname());
    switch (m_user.userType()){
    case UserType::Customer:
        ui->rbtnCustomer->setChecked(true);
        break;
    case UserType::Employee:
        ui->rbtnEmployee->setChecked(true);
        break;
    case UserType::Manager:
        ui->rbtnManager->setChecked(true);
        break;
    case UserType::Guest:
        return;
    }
}

void ManagerUserWidget::on_btnEdit_clicked()
{
    int newType = (int)m_user.userType();
    if(ui->rbtnCustomer->isChecked() == true)
        newType = (int)UserType::Customer;
    if(ui->rbtnEmployee->isChecked() == true)
        newType = (int)UserType::Employee;
    if(ui->rbtnManager->isChecked() == true)
        newType = (int)UserType::Manager;
    if(newType == (int)m_user.userType())
        QMessageBox::warning(this, "XKOMX", "User type wasn't changed");
    else{
        if(DbManager::instance()->changeUserType(m_user.id(), newType)){
            m_user.setUserType((UserType)newType);
            QMessageBox::information(this, "XKOMX", "User type changed successfully!");
        }
        else
            QMessageBox::warning(this, "XKOMX", "User type change failed!");
    }
}

