#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSignIn_clicked()
{
    if(CurrentUser::getInstance()->getUser().getUserType() == UserType::Guest) {
        SignInWindow* signInWindow = new SignInWindow(this);
        signInWindow->exec();
        delete signInWindow;

        if(CurrentUser::getInstance()->getUser().getUserType() != UserType::Guest)
            ui->btnSignIn->setText("Sign out");
        return;
    }
    ui->btnSignIn->setText("Sign in");
    CurrentUser::getInstance()->setUser(User());
}

