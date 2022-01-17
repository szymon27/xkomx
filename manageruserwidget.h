#ifndef MANAGERUSERWIDGET_H
#define MANAGERUSERWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "user.h"
#include "dbmanager.h"

namespace Ui {
class ManagerUserWidget;
}

class ManagerUserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerUserWidget(User, QWidget *parent = nullptr);
    ~ManagerUserWidget();;

private slots:
    void on_btnEdit_clicked();

private:
    Ui::ManagerUserWidget *ui;
    User m_user;
    void setControls();
};

#endif // MANAGERUSERWIDGET_H
