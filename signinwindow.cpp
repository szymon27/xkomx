#include "signinwindow.h"
#include "ui_signinwindow.h"

SignInWindow::SignInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInWindow)
{
    ui->setupUi(this);
}

SignInWindow::~SignInWindow()
{
    delete ui;
}
