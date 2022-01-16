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

void EditUserWindow::on_pushButton_clicked()
{
    OrderHistoryWindow *window = new OrderHistoryWindow();
    window->exec();
    delete window;
}


void EditUserWindow::on_btnChangePassword_clicked()
{
    QString oldpass = ui->leOldPass->text();
    QString newpass = ui->leNewPass->text();
    QString confpass = ui->leConfirmPass->text();

    if(oldpass != CurrentUser::instance()->user().password()){
        QMessageBox::warning(this,"XKOMX", "Wrong old password!");
        return;
    }

    QRegExp regPassword("[A-Za-z0-9_@#$%^&*!?]{6,16}");
    if(!(regPassword.exactMatch(newpass) && newpass==confpass)){
        QMessageBox::warning(this, "XKOMX", "invalid password!");
        return;
    }

    if(oldpass == newpass){
        QMessageBox::warning(this, "XKOMX", "New password is the same as old password!");
        return;
    }

    if(DbManager::instance()->newPassword(newpass)) {
        CurrentUser::instance()->user().setPassword(newpass);
        ui->leOldPass->setText("");
        ui->leNewPass->setText("");
        ui->leConfirmPass->setText("");
        QMessageBox::information(this, "XKOMX", "Password changed successfuly!");
    }
    else{
        QMessageBox::warning(this, "XKOMX", "Password change failed!");
    }
}


void EditUserWindow::on_btnChangeInfo_clicked()
{
    QString name = ui->leName->text();
    QString surname = ui->leSurname->text();
    QString city = ui->leCity->text();
    QString postCode = ui->lePostalCode->text();
    QString address = ui->leAddress->text();
    QString country = ui->leCountry->text();

    QRegExp regPostalCode("\\d{2}-\\d{3}");
    QRegExp regNameSurnameCityCountry("[A-Za-z]{3,}");
    QRegExp regAddress("[A-Za-z0-9./ ]{4,}");

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

    if(DbManager::instance()->changeUserDetails(name, surname, city, postCode, address, country)) {
        QMessageBox::information(this, "XKOMX", "Personal details changed successfuly!");
        CurrentUser::instance()->user().setName(name);
        CurrentUser::instance()->user().setSurname(surname);
        CurrentUser::instance()->user().setCity(city);
        CurrentUser::instance()->user().setPostCode(postCode);
        CurrentUser::instance()->user().setAddress(address);
        CurrentUser::instance()->user().setCountry(country);
    }
    else{
        QMessageBox::warning(this, "XKOMX", "Personal details change failed!");
    }

}

