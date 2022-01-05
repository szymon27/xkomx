#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "signinwindow.h"
#include "currentuser.h"
#include "devicewidget.h"
#include "mainwidget.h"
#include "cartwidget.h"
#include "adminpanelwindow.h"
#include "edituserwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSignIn_clicked();

    void on_btnShop_clicked();

    void on_btnCart_clicked();

    void prepCurrentWidget(QWidget*);
    void on_btnAdminPanel_clicked();

    void on_btnProfile_clicked();

private:
    Ui::MainWindow* ui = nullptr;
    QWidget *currentWidget = nullptr;
};
#endif // MAINWINDOW_H
