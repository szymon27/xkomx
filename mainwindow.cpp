#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    emit on_btnShop_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSignIn_clicked()
{
    if(CurrentUser::instance()->user().userType() == UserType::Guest) {
        SignInWindow* signInWindow = new SignInWindow(this);
        signInWindow->exec();
        delete signInWindow;

        if(CurrentUser::instance()->user().userType() != UserType::Guest)
            ui->btnSignIn->setText("Sign out");
        return;
    }
    ui->btnSignIn->setText("Sign in");
    CurrentUser::instance()->setUser(User());
}

void MainWindow::prepCurrentWidget(QWidget *widget)
{
    QLayoutItem* item;
    while ( ( item = ui->verticalLayout_2->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
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
}


void MainWindow::on_btnCart_clicked()
{
    CartWidget* Cwidget = new CartWidget();
    Cwidget->setUpWidget();
    prepCurrentWidget(Cwidget);
    Cwidget = nullptr;
}


// stary on_btnShop_clicked()
//while(ui->vlProducts->count() > 0)
//    delete ui->vlProducts->takeAt(0);
//
//QVector<Device> devices = DbManager::getInstance()->getDevicesList();
//for(int i = 0; i < devices.size(); i++) {
//    DeviceWidget *productWidget = new DeviceWidget();
//    productWidget->setProduct(devices.at(i));
//    ui->vlProducts->addWidget(productWidget);
//}


void MainWindow::on_btnAdminPanel_clicked()
{
    AdminPanelWindow *window = new AdminPanelWindow();
    window->exec();
    delete window;
}


void MainWindow::on_btnProfile_clicked()
{
    EditUserWindow *window = new EditUserWindow();
    window->exec();
    delete window;
}

