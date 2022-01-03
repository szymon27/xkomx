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
    QString username = ui->leLogin->text();
    QString password = ui->lePassword->text();

    // ########## walidacja

    User user = DbManager::getInstance()->signIn(username, password);
    CurrentUser::getInstance()->setUser(user);

    if(CurrentUser::getInstance()->getUser().getUserType() != UserType::Guest)
        close();
}


void SignInWindow::on_btnSignUp_clicked()
{
    SignUpWindow* signUpWindow = new SignUpWindow();
    signUpWindow->exec();
    delete signUpWindow;

    if(CurrentUser::getInstance()->getUser().getUserType() != UserType::Guest)
        close();
}

