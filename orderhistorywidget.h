#ifndef ORDERHISTORYWIDGET_H
#define ORDERHISTORYWIDGET_H

#include <QWidget>
#include "orderhistorydetailswindow.h"

namespace Ui {
class OrderHistoryWidget;
}

class OrderHistoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderHistoryWidget(Order*, QWidget *parent = nullptr);
    ~OrderHistoryWidget();

private slots:
    void on_btnDetails_clicked();

private:
    Ui::OrderHistoryWidget *ui;
    Order * m_order;
};

#endif // ORDERHISTORYWIDGET_H
