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


    QRegExp regUsername("[A-Za-z0-9]{6,16}");
    QRegExp regPostalCode("\\d{2}-\\d{3}");
    QRegExp regPassword("[A-Za-z0-9_@#$%^&*!?]{6,16}");
    QRegExp regNameSurnameCityCountry("[A-Za-z]{3,}");
    QRegExp regAddress("[A-Za-z0-9./ ]{4,}");

    if(!regUsername.exactMatch(username)){
        QMessageBox::warning(this, "XKOMX", "invalid username");
        return;
    }
    if(!(regPassword.exactMatch(password)&&password==confirmPassword)){
        QMessageBox::warning(this, "XKOMX", "invalid password");
        return;
    }
    if(!regNameSurnameCityCountry.exactMatch(name)){
        QMessageBox::warning(this, "XKOMX", "invalid name");
        return;
    }
    if(!regNameSurnameCityCountry.exactMatch(surname)){
        QMessageBox::warning(this, "XKOMX", "invalid surname");
        return;
    }
    if(!regNameSurnameCityCountry.exactMatch(city)){
        QMessageBox::warning(this, "XKOMX", "invalid city");
        return;
    }
    if(!regPostalCode.exactMatch(postCode)){
        QMessageBox::warning(this, "XKOMX", "invalid post code");
        return;
    }
    if(!regAddress.exactMatch(address)){
        QMessageBox::warning(this, "XKOMX", "invalid address");
        return;
    }
    if(!regNameSurnameCityCountry.exactMatch(country)){
        QMessageBox::warning(this, "XKOMX", "invalid country");
        return;
    }

    NewUser newUser;
    newUser.username = username;
    newUser.password = password;
    newUser.name = name;
    newUser.surname = surname;
    newUser.city = city;
    newUser.postCode = postCode;
    newUser.address = address;
    newUser.country = country;

    if(DbManager::instance()->signUp(newUser)) {
        User user = DbManager::instance()->signIn(username, password);
        CurrentUser::instance()->setUser(user);
        close();
    }

}

