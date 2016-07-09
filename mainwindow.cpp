#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller = new Controller();
}

MainWindow::~MainWindow()
{
    delete controller;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

   ui->pushButton->setText("Ахиха ле васал");
}
