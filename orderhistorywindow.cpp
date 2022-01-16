#include "orderhistorywindow.h"
#include "ui_orderhistorywindow.h"

OrderHistoryWindow::OrderHistoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderHistoryWindow)
{
    ui->setupUi(this);
    ui->saHistory->takeWidget();
    ui->saHistory->setWidget(ui->verticalLayoutWidget);

    QLayoutItem* item;
    while ( ( item = ui->vlHistory->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Order*> orders = DbManager::instance()->currentUserOrders(); //tu trzeba liste zamowien currentusera + klasa order do QVectora
    for(int i = 0; i < orders.size(); i++) {
        OrderHistoryWidget *productWidget = new OrderHistoryWidget(orders.at(i)); //tu jako argument orders[i] i w widgecie sie bedzie wypelnialo 2 labele
        ui->vlHistory->addWidget(productWidget);
    }
}

OrderHistoryWindow::~OrderHistoryWindow()
{
    delete ui;
}

