#ifndef ORDERDETAILSWINDOW_H
#define ORDERDETAILSWINDOW_H

#include <QDialog>
#include "currentuser.h"
#include "dbmanager.h"
#include <QMessageBox>

namespace Ui {
class OrderDetailsWindow;
}

class OrderDetailsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDetailsWindow(QWidget *parent = nullptr);
    ~OrderDetailsWindow();
    bool success() const;

signals:
    void on_success();
private slots:
    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

private:
    Ui::OrderDetailsWindow *ui;
    bool m_success = false;
};

#endif // ORDERDETAILSWINDOW_H
