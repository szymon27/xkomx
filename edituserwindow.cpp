#include "edituserwindow.h"
#include "ui_edituserwindow.h"

EditUserWindow::EditUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUserWindow)
{
    ui->setupUi(this);
    setControls();
}

EditUserWindow::~EditUserWindow()
{
    delete ui;
}

void EditUserWindow::setControls()
{
    ui->leName->setText(CurrentUser::getInstance()->getUser().name());
    ui->leSurname->setText(CurrentUser::getInstance()->getUser().surname());
    ui->leCountry->setText(CurrentUser::getInstance()->getUser().country());
    ui->lePostalCode->setText(CurrentUser::getInstance()->getUser().postCode());
    ui->leAddress->setText(CurrentUser::getInstance()->getUser().address());
    ui->leCity->setText(CurrentUser::getInstance()->getUser().city());
}
