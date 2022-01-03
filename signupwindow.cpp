#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_btnSignUp_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    QString confirmPassword = ui->leConfirmPassword->text();
    QString name = ui->leName->text();
    QString surname = ui->leSurname->text();
    QString city = ui->leCity->text();
    QString postCode = ui->lePostalCode->text();
    QString address = ui->leAddress->text();
    QString country = ui->leCountry->text();
    //############ walidacja

    NewUser newUser;
    newUser.username = username;
    newUser.password = password;
    newUser.name = name;
    newUser.surname = surname;
    newUser.city = city;
    newUser.postCode = postCode;
    newUser.address = address;
    newUser.country = country;

    if(DbManager::getInstance()->signUp(newUser)) {
        User user = DbManager::getInstance()->signIn(username, password);
        CurrentUser::getInstance()->setUser(user);
        close();
    }

}

