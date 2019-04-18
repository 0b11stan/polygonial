#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int x=3; x <= 10; x++) {
        ui->cb_sides->addItem(QString(std::to_string(x).c_str()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::cout << "Hello There !" << std::endl;
}
