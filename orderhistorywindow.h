#ifndef ORDERHISTORYWINDOW_H
#define ORDERHISTORYWINDOW_H

#include <QDialog>
#include "dbmanager.h"
#include "orderhistorywidget.h"

namespace Ui {
class OrderHistoryWindow;
}

class OrderHistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrderHistoryWindow(QWidget *parent = nullptr);
    ~OrderHistoryWindow();

private:
    Ui::OrderHistoryWindow *ui;
};

#endif // ORDERHISTORYWINDOW_H
