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

void SignInWindow::on_btnSignIn_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    // ########## walidacja

    User user = DbManager::instance()->signIn(username, password);
    CurrentUser::instance()->setUser(user);

    if(CurrentUser::instance()->user().userType() != UserType::Guest)
        close();
}


void SignInWindow::on_btnSignUp_clicked()
{
    SignUpWindow* signUpWindow = new SignUpWindow();
    signUpWindow->exec();
    delete signUpWindow;

    if(CurrentUser::instance()->user().userType() != UserType::Guest)
        close();
}

