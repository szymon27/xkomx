#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Program* prog)
    : QMainWindow(parent), ui(new Ui::MainWindow), program(prog)
{
    prog->setGUI(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

