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
    this->img = src.clone();
    this->showImage(img);
}

QImage MainWindow::Mat2QImage(const cv::Mat &src)
{
    if(src.type() == CV_8UC1)
    {
        QVector<QRgb> colorTable;
        for(int i = 0; i < 256; i++)
            colorTable.push_back(qRgb(i, i, i));
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage img(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    else if(src.type() == CV_8UC3)
    {
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage img(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "Error! Can't convert image type.";
        return QImage();
    }
}

void MainWindow::showImage(const cv::Mat &src)
{
    cv::Mat dst;
    int width = ui->show_Img->width();
    int height = ui->show_Img->height();
    double labelRatio = (double)width/(double)height;
    double imgRatio = src.cols/src.rows;

    if(labelRatio > imgRatio)
    {
        cv:: resize(src, dst, cv::Size(width, src.rows/(src.cols/width)));
    }
    else
        cv::resize(src, dst, cv::Size(src.cols/(src.rows/height), height));
    ui->show_Img->setPixmap(QPixmap::fromImage(this->Mat2QImage(dst)));
}

void MainWindow::on_brightness_valueChanged(int value)
{
    cv::Mat tmp;
    tmp = this->img.clone();
    for(int i = 0; i < this->img.rows; i++)
    {
        for(int j = 0; j < this->img.cols; j++)
        {
            for(int k = 0; k < this->img.channels(); k++)
            {
                if(this->img.at<cv::Vec3b>(i, j)[k] + value > 255)
                    tmp.at<cv::Vec3b>(i, j)[k] = 255;
                else if(this->img.at<cv::Vec3b>(i, j)[k] + value < 0)
                    tmp.at<cv::Vec3b>(i, j)[k] = 0;
                else
                    tmp.at<cv::Vec3b>(i, j)[k] = this->img.at<cv::Vec3b>(i, j)[k] + value;
            }
        }
    }
    this->showImage(tmp);
}
