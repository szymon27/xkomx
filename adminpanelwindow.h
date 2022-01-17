#ifndef ADMINPANELWINDOW_H
#define ADMINPANELWINDOW_H

#include <QDialog>
#include "device.h"
#include "managerdevicewidget.h"
#include "manageruserwidget.h"
#include "addnewdevicewindow.h"
#include "dbmanager.h"

namespace Ui {
class AdminPanelWindow;
}

class AdminPanelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanelWindow(QWidget *parent = nullptr);
    ~AdminPanelWindow();

private slots:
    void on_btnDevices_clicked();

    void on_btnUseres_clicked();

    void on_btnAdd_clicked();

private:
    Ui::AdminPanelWindow *ui;
};

#endif // ADMINPANELWINDOW_H
