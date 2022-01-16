#include "orderhistorywidget.h"
#include "ui_orderhistorywidget.h"

OrderHistoryWidget::OrderHistoryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryWidget)
{
    ui->setupUi(this);
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

