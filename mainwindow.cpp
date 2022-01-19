#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnProfile->setVisible(false);
    ui->btnAdminPanel->setVisible(false);
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

        if(CurrentUser::instance()->user().userType() != UserType::Guest) {
            ui->btnSignIn->setText("Sign out");
            ui->btnProfile->setVisible(true);
            if(CurrentUser::instance()->user().userType() != UserType::Customer)
                ui->btnAdminPanel->setVisible(true);

        }
        return;
    }
    ui->btnSignIn->setText("Sign in");
    ui->btnProfile->setVisible(false);
    ui->btnAdminPanel->setVisible(false);
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


