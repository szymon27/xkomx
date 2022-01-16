#ifndef EDITUSERWINDOW_H
#define EDITUSERWINDOW_H

#include <QDialog>
#include "currentuser.h"
#include "orderhistorywindow.h"
#include <QMessageBox>
namespace Ui {
class EditUserWindow;
}

class EditUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserWindow(QWidget *parent = nullptr);
    ~EditUserWindow();

private slots:
    void on_pushButton_clicked();

    void on_btnChangePassword_clicked();

    void on_btnChangeInfo_clicked();

private:
    Ui::EditUserWindow *ui;
    void setControls();
};

#endif // EDITUSERWINDOW_H
