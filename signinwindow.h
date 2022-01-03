#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QDialog>

namespace Ui {
class SignInWindow;
}

class SignInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignInWindow(QWidget *parent = nullptr);
    ~SignInWindow();

private:
    Ui::SignInWindow *ui;
};

#endif // SIGNINWINDOW_H
