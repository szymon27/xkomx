#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QDialog>
#include "dbmanager.h"
#include "currentuser.h"
#include "signupwindow.h"
#include "dbmanager.h"

namespace Ui {
class SignInWindow;
}

class SignInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignInWindow(QWidget *parent = nullptr);
    ~SignInWindow();

signals:


private slots:
    void on_btnSignIn_clicked();

    void on_btnSignUp_clicked();

private:
    Ui::SignInWindow *ui;
};

#endif // SIGNINWINDOW_H
