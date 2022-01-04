#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->scrollArea->takeWidget();
    //ui->scrollArea->setWidget(ui->verticalLayoutWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSignIn_clicked()
{
    if(CurrentUser::getInstance()->getUser().getUserType() == UserType::Guest) {
        SignInWindow* signInWindow = new SignInWindow(this);
        signInWindow->exec();
        delete signInWindow;

        if(CurrentUser::getInstance()->getUser().getUserType() != UserType::Guest)
            ui->btnSignIn->setText("Sign out");
        return;
    }
    ui->btnSignIn->setText("Sign in");
    CurrentUser::getInstance()->setUser(User());
}

void MainWindow::prepCurrentWidget(QWidget *widget)
{
    QLayoutItem* item;
    if ( ( item = ui->verticalLayout_2->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
    currentWidget = widget;
    ui->verticalLayout_2->addWidget(currentWidget);
}

void MainWindow::on_btnShop_clicked()
{

    MainWidget* Mwidget = new MainWidget();
    Mwidget->setUpWidget();
    prepCurrentWidget(Mwidget);
    Mwidget = nullptr;

    //while(ui->vlProducts->count() > 0)
    //    delete ui->vlProducts->takeAt(0);
    //
    //QVector<Device> devices = DbManager::getInstance()->getDevicesList();
    //for(int i = 0; i < devices.size(); i++) {
    //    DeviceWidget *productWidget = new DeviceWidget();
    //    productWidget->setProduct(devices.at(i));
    //    ui->vlProducts->addWidget(productWidget);
    //}
}


void MainWindow::on_btnCart_clicked()
{
    CartWidget* Cwidget = new CartWidget();
    Cwidget->setUpWidget();
    prepCurrentWidget(Cwidget);
    Cwidget = nullptr;
}



