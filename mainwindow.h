#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "program.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Program* prog = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui = nullptr;
    Program* program = nullptr;
};
#endif // MAINWINDOW_H
