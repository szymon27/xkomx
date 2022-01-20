#include "orderhistorywidget.h"
#include "ui_orderhistorywidget.h"

OrderHistoryWidget::OrderHistoryWidget(Order o, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryWidget),
    m_order(o)
{
    ui->setupUi(this);
    ui->lbDate->setText(m_order.orderDate().toString("dd.MM.yyyy"));
    ui->lbTotalCost->setText(QString::number(m_order.totalCost(),'f',2) + " PLN");
}

OrderHistoryWidget::~OrderHistoryWidget()
{
    delete ui;
}

void OrderHistoryWidget::on_btnDetails_clicked()
{
    OrderHistoryDetailsWindow *window = new OrderHistoryDetailsWindow(m_order.id(), m_order.orderDate(), m_order.totalCost());
    window->exec();
    delete window;
}

