#include "userwidget.h"
#include "ui_userwidget.h"

UserWidget::UserWidget(User user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget),
    m_user(user)
{
    ui->setupUi(this);
}

UserWidget::~UserWidget()
{
    delete ui;
}

void UserWidget::setControls()
{
    ui->lbUsername->setText(m_user.username());
    ui->lbName->setText(m_user.name());
    ui->lbSurname->setText(m_user.surname());
    ui->lbType->setText(userTypeToString(m_user.userType()));
}
