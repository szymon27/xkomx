#ifndef ADDNEWDEVICEWINDOW_H
#define ADDNEWDEVICEWINDOW_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "devicetype.h"
#include "addnewcomputerwidget.h"
#include "addnewkeyboardwidget.h"
#include "addnewmonitorwidget.h"
#include "addnewmousewidget.h"
#include "dbmanager.h"

namespace Ui {
class AddNewDeviceWindow;
}

class AddNewDeviceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDeviceWindow(QWidget *parent = nullptr);
    ~AddNewDeviceWindow();
private slots:
    void on_cbxDeviceType_currentIndexChanged(const QString &arg1);

    void on_btnCancel_clicked();

    void on_btnConfirm_clicked();

    void on_btnAddImage_clicked();

private:
    Ui::AddNewDeviceWindow *ui;
    QWidget *detailsWidget;
    QString imagePath = "";
    QFile *file;
    void fillCombo();
};

#endif // ADDNEWDEVICEWINDOW_H
