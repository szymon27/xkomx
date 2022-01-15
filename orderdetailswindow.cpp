#include "orderdetailswindow.h"
#include "ui_orderdetailswindow.h"

OrderDetailsWindow::OrderDetailsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDetailsWindow)
{
    ui->setupUi(this);
}

OrderDetailsWindow::~OrderDetailsWindow()
{
    delete ui;
}
