#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller = new Controller(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete controller;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

   controller->operate("asdas");
   ui->pushButton->setText("Ахиха ле васал");
}
