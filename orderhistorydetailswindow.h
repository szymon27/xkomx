#ifndef ORDERHISTORYDETAILSWINDOW_H
#define ORDERHISTORYDETAILSWINDOW_H

#include <QDialog>
#include "dbmanager.h"
#include "orderhistorydevicewidget.h"

namespace Ui {
class OrderHistoryDetailsWindow;
}

class OrderHistoryDetailsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrderHistoryDetailsWindow(QWidget *parent = nullptr);
    ~OrderHistoryDetailsWindow();

private:
    Ui::OrderHistoryDetailsWindow *ui;
};

#endif // ORDERHISTORYDETAILSWINDOW_H
