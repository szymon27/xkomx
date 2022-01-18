#ifndef ADDEDITDEVICEWINDOW_H
#define ADDEDITDEVICEWINDOW_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "devicetype.h"
#include "device.h"
#include "addeditcomputerwidget.h"
#include "addeditkeyboardwidget.h"
#include "addeditmonitorwidget.h"
#include "addeditmousewidget.h"
#include "dbmanager.h"

enum Action{
    Editing = true,
    Adding = false
};


namespace Ui {
class AddEditDeviceWindow;
}

class AddEditDeviceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDeviceWindow(QWidget *parent = nullptr);
    explicit AddEditDeviceWindow(Device* device, QWidget *parent = nullptr);
    ~AddEditDeviceWindow();
private slots:
    void on_cbxDeviceType_currentIndexChanged(const QString &arg1);

    void on_btnCancel_clicked();

    void on_btnConfirm_clicked();

    void on_btnAddImage_clicked();

private:
    Action ACTION;
    Ui::AddEditDeviceWindow *ui;
    QWidget *detailsWidget;
    QString imagePath = "";
    Device *m_device = nullptr;
    void fillCombo();
    void setUpEditing();
};

#endif // ADDEDITDEVICEWINDOW_H
