#include "adminpanelwindow.h"
#include "ui_adminpanelwindow.h"

AdminPanelWindow::AdminPanelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanelWindow)
{
    ui->setupUi(this);
    ui->saList->takeWidget();
    ui->saList->setWidget(ui->verticalLayoutWidget_2);
    emit on_btnDevices_clicked();
}

AdminPanelWindow::~AdminPanelWindow()
{
    delete ui;
}

void AdminPanelWindow::on_btnDevices_clicked()
{
    ui->btnAdd->show();
    QLayoutItem* item;
    while ( ( item = ui->vlList->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<Device*> devices = DbManager::instance()->devicesList();
    for(int i = 0; i < devices.size(); i++) {
        ManagerDeviceWidget *productWidget = new ManagerDeviceWidget(devices.at(i));
        ui->vlList->addWidget(productWidget);
    }
}


void AdminPanelWindow::on_btnUseres_clicked()
{
    ui->btnAdd->hide();
    QLayoutItem* item;
    while ( ( item = ui->vlList->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }
    QVector<User> users = DbManager::instance()->usersList();
    for(int i = 0; i < users.size(); i++) {
        ManagerUserWidget *productWidget = new ManagerUserWidget(users.at(i));
        ui->vlList->addWidget(productWidget);
    }
}


void AdminPanelWindow::on_btnAdd_clicked()
{
    AddNewDeviceWindow *window = new AddNewDeviceWindow();
    window->exec();
    delete window;
}

