#include "orderhistorydetailswindow.h"
#include "ui_orderhistorydetailswindow.h"

OrderHistoryDetailsWindow::OrderHistoryDetailsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderHistoryDetailsWindow)
{
    ui->setupUi(this);
    ui->saDevices->takeWidget();
    ui->saDevices->setWidget(ui->verticalLayoutWidget_2);

    QLayoutItem* item;
    while ( ( item = ui->vlDevices->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Device*> devices = DbManager::instance()->devicesList(); //tu trzeba liste urzadzen po id wczesniej wybranego zamowienia
    for(int i = 0; i < devices.size(); i++) {
        OrderHistoryDeviceWidget *productWidget = new OrderHistoryDeviceWidget(); //tu jako argument devices[i] i w widgecie sie bedzie wypelnialo tak jak w deviceWidget
        ui->vlDevices->addWidget(productWidget);
    }
    //jeszcze ustawienie daty i calkowitego kosztu poszczegolnych urzadzen i calego zamowienia(to tez z klasy order mozna)
}

OrderHistoryDetailsWindow::~OrderHistoryDetailsWindow()
{
    delete ui;
}
