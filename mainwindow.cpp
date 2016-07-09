#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller = new Controller(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete controller;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   controller->operate("asdas");
 }
