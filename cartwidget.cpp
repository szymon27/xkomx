#include "cartwidget.h"
#include "ui_cartwidget.h"

CartWidget::CartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CartWidget)
{
    ui->setupUi(this);
    ui->saCart->takeWidget();
    ui->saCart->setWidget(ui->verticalLayoutWidget);
}

CartWidget::~CartWidget()
{
    delete ui;
}

void CartWidget::setUpWidget()
{
    update();
}

void CartWidget::update()
{
    QLayoutItem* item;
    while ( ( item = ui->vlCart->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }

    QVector<CartElement> cart = Cart::instance()->cartList(); //Zmiana na koszyk usera
    for(int i = 0; i < cart.size(); i++) {
        CartDeviceWidget *deviceWidget = new CartDeviceWidget(cart.at(i), this);
        connect(deviceWidget, SIGNAL(update()), this, SLOT(update()));
        connect(deviceWidget, SIGNAL(changePrice()), this, SLOT(setPrice()));
        ui->vlCart->addWidget(deviceWidget);
    }
    setPrice();
}

void CartWidget::on_btnBuy_clicked()
{
    if(CurrentUser::instance()->user().userType() == UserType::Guest) {
        QMessageBox::warning(this, "XKOMX", "You have to sign in.");
        return;
    }

    if(Cart::instance()->cartList().size() <= 0) {
        QMessageBox::warning(this, "XKOMX", "Pusty koszyk");
        return;
    }

    if(!Cart::instance()->checkCart()) {
        QMessageBox::warning(this, "XKOMX", "Brak produktow");
        return;
    }

    OrderDetailsWindow *window = new OrderDetailsWindow();
    connect(window, SIGNAL(on_success()), this, SLOT(on_btnRemoveAll_clicked()));
    window->exec();
    delete window;
}



void CartWidget::on_btnRemoveAll_clicked()
{
    Cart::instance()->clearCartList();
    QLayoutItem* item;
    while ( ( item = ui->vlCart->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        item = nullptr;
    }
    setPrice();
}

void CartWidget::setPrice()
{
    ui->lbSum->setText(QString::number(Cart::instance()->sum(),'f',2) + " PLN");
}

