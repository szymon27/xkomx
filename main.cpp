#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.show();
    w.setStyleSheet("QMainWindow{background-color:#222222;}QWidget{background-color:#222222;}QDialog{background-color:#222222;}QLineEdit{background-color:#363636;padding: 0 8px;border: 2px solid #363636;font-family:Helvetica;font-size: 14px;color: white;}QLineEdit:focus{background-color:#4E4E4E;padding: 0 8px;border: 2px solid #4E4E4E;font-family:Helvetica;font-size: 14px;color: white;}QLabel{font-family:Helvetica;font-size: 14px;font-weight: bold;color:white;}QPushButton{background-color:#e8474c;border: 2px solid #e8474c;padding: 0 10px;font-family:Helvetica;font-size: 14px;font-weight: bold;color:white;}");
    return a.exec();
}
