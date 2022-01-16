#include "orderhistorywidget.h"
#include "ui_orderhistorywidget.h"

OrderHistoryWidget::OrderHistoryWidget(Order* o, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryWidget),
    m_order(o)
{
    ui->setupUi(this);
    ui->lbDate->setText(o->orderDate().toString("dd.MM.yyyy"));
    ui->lbTotalCost->setText(QString::number(o->totalCost()));
}

OrderHistoryWidget::~OrderHistoryWidget()
{
    delete ui;
}

void OrderHistoryWidget::on_btnDetails_clicked()
{
    OrderHistoryDetailsWindow *window = new OrderHistoryDetailsWindow();
    window->exec();
    delete window;
}

