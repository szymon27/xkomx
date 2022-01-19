#include "adminpanelwindow.h"
#include "ui_adminpanelwindow.h"

AdminPanelWindow::AdminPanelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanelWindow)
{
    ui->setupUi(this);
    ui->saList->takeWidget();
    ui->saList->setWidget(ui->verticalLayoutWidget_2);
    if(CurrentUser::instance()->user().userType() == UserType::Manager)
        ui->btnUsers->setVisible(true);
    else ui->btnUsers->setVisible(false);
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
        connect(productWidget, SIGNAL(refresh()), this, SLOT(on_btnDevices_clicked()));
        ui->vlList->addWidget(productWidget);
    }
}


void AdminPanelWindow::on_btnUsers_clicked()
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
    AddEditDeviceWindow *window = new AddEditDeviceWindow();
    window->exec();
    delete window;
    emit on_btnDevices_clicked();
}

