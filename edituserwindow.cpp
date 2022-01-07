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
    ui->leName->setText(CurrentUser::instance()->user().name());
    ui->leSurname->setText(CurrentUser::instance()->user().surname());
    ui->leCountry->setText(CurrentUser::instance()->user().country());
    ui->lePostalCode->setText(CurrentUser::instance()->user().postCode());
    ui->leAddress->setText(CurrentUser::instance()->user().address());
    ui->leCity->setText(CurrentUser::instance()->user().city());
}
