#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "signinwindow.h"
#include "currentuser.h"
#include "productwidget.h"

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

    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui = nullptr;
};
#endif // MAINWINDOW_H
