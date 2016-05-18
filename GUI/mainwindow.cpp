#include "mainwindow.h"
#include "ui_mainwindow.h"


int i=0; //testowanie licznika cykli pod kalwisz


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == QString("Start"))
            {
        ui->pushButton->setText(tr("Stop"));

        ui->lcdNumber->display(i);
        i++;
    }
    else
            ui->pushButton->setText(tr("Start"));
}
