#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_actionLoad_image_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    cv::Mat src = cv::imread(fileName.toStdString());
}

QImage MainWindow::Mat2QImage(const cv::Mat src)
{

}
