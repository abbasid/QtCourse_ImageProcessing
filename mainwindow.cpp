#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    saveImageOrNot = true;
    clock = new QTimer;
    clock->setInterval(1000);
    connect(clock, SIGNAL(timeout()), this, SLOT(save_image()));
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
    this->real_time_img = this->img.clone();
    clock->start();
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

void MainWindow::changeColorTemp(cv::Mat &src, cv::Mat &tmp, QVector<int> color)
{
    for(int i = 0; i < src.rows; i++)
    {
        for(int j = 0; j < src.cols; j++)
        {
            for(int k = 0; k < src.channels(); k++)
            {
                if(src.at<cv::Vec3b>(i, j)[k] + color[k] > 255)
                    tmp.at<cv::Vec3b>(i, j)[k] = 255;
                else if(src.at<cv::Vec3b>(i, j)[k] + color[k] < 0)
                    tmp.at<cv::Vec3b>(i, j)[k] = 0;
                else
                    tmp.at<cv::Vec3b>(i, j)[k] = src.at<cv::Vec3b>(i, j)[k] + color[k];
            }
        }
    }
}

void MainWindow::on_brightness_valueChanged(int value)
{
    for(int i = 0; i < this->img.rows; i++)
    {
        for(int j = 0; j < this->img.cols; j++)
        {
            for(int k = 0; k < this->img.channels(); k++)
            {
                if(this->real_time_img.at<cv::Vec3b>(i, j)[k] + value > 255)
                    this->real_time_img.at<cv::Vec3b>(i, j)[k] = 255;
                else if(this->real_time_img.at<cv::Vec3b>(i, j)[k] + value < 0)
                    this->real_time_img.at<cv::Vec3b>(i, j)[k] = 0;
                else
                    this->real_time_img.at<cv::Vec3b>(i, j)[k] = this->tmp.at<cv::Vec3b>(i, j)[k] + value;
            }
        }
    }
    this->showImage(this->real_time_img);
    this->saveImageOrNot = false;
    this->realTimechanged = true;
    this->graychanged = false;
    this->constrastChanged = false;
    this->invertChanged = false;
}

void MainWindow::on_red_valueChanged(int value)
{
    QVector<int> colorTemp;
    colorTemp.push_back(ui->blue->value());
    colorTemp.push_back(ui->green->value());
    colorTemp.push_back(ui->red->value());
    this->changeColorTemp(this->tmp, this->real_time_img, colorTemp);
    this->showImage(this->real_time_img);
    this->saveImageOrNot = false;
    this->realTimechanged = true;
    this->graychanged = false;
    this->constrastChanged = false;
    this->invertChanged = false;
}


void MainWindow::on_green_valueChanged(int value)
{
    cv::Mat tmp;
    tmp = this->img.clone();
    QVector<int> colorTemp;
    colorTemp.push_back(ui->blue->value());
    colorTemp.push_back(ui->green->value());
    colorTemp.push_back(ui->red->value());
    this->changeColorTemp(this->tmp, this->real_time_img, colorTemp);
    this->showImage(real_time_img);
    this->saveImageOrNot = false;
    this->realTimechanged = true;
    this->graychanged = false;
    this->constrastChanged = false;
    this->invertChanged = false;
}

void MainWindow::on_blue_valueChanged(int value)
{
    QVector<int> colorTemp;
    colorTemp.push_back(ui->blue->value());
    colorTemp.push_back(ui->green->value());
    colorTemp.push_back(ui->red->value());
    this->changeColorTemp(this->tmp, this->real_time_img, colorTemp);
    this->showImage(tmp);
    this->saveImageOrNot = false;
    this->realTimechanged = true;
    this->graychanged = false;
    this->constrastChanged = false;
    this->invertChanged = false;
}

void MainWindow::on_grayscale_clicked()
{
    cv:: Mat dst;
    dst.create(cv::Size(real_time_img.cols, real_time_img.rows), CV_8UC1);
    for(int i = 0; i < this->img.rows; i++)
    {
        for(int j = 0; j < this->img.cols; j++)
        {
            dst.at<uchar>(i,j) = (this->real_time_img.at<cv::Vec3b>(i, j)[0] + this->real_time_img.at<cv::Vec3b>(i, j)[1] + this->real_time_img.at<cv::Vec3b>(i, j)[2])/3;
        }
    }
    this->realTimechanged = false;
    this->graychanged = true;
    this->constrastChanged = false;
    this->invertChanged = false;
    this->imgGray = dst.clone();
    this->showImage(dst);
}

void MainWindow::on_blur_clicked()
{

    cv::Mat dst(this->real_time_img);

    for(int i = 0; i < this->real_time_img.rows -2; i++)
    {
        for(int j = 0; j < this->real_time_img.cols -2; j++)
        {
            for(int k = 0; k < this->real_time_img.channels(); k++)
            {
                dst.at<cv::Vec3b>(i + 1, j + 1)[k] = (this->real_time_img.at<cv::Vec3b>(i, j)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i, j + 1)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i, j + 2)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i + 1, j)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i + 1, j + 1)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i + 1, j + 2)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i + 2, j)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i + 2, j + 1)[k] +
                                                      this->real_time_img.at<cv::Vec3b>(i +2, j + 2)[k])/9;
            }
        }
    }
    this->showImage(dst);


}



void MainWindow::on_contrast_valueChanged(int value)
{
    double sharp = (double)value/1000;
    this->img_Constrat = this->imgGray.clone();
    for(int i = 0; i < this->img_Constrat.rows; i++)
    {
        for(int j = 0; j < this->img_Constrat.cols; j++)
        {
            if(imgGray.at<uchar>(i, j) < 0)
                this->img_Constrat.at<uchar>(i, j) = 0;
            else if(imgGray.at<uchar>(i, j) > 255)
                this->img_Constrat.at<uchar>(i, j) = 255;
            else
            {
                this->img_Constrat.at<uchar>(i, j) = (int)(imgGray.at<uchar>(i, j) * sharp);
            }
        }
    }
    this->realTimechanged = false;
    this->graychanged = false;
    this->constrastChanged = true;
    this->invertChanged = false;
    this->showImage(this->img_Constrat);
}

void MainWindow::on_invert_clicked()
{
    this->img_invert.create(cv::Size(this->img.cols, this->img.rows), CV_8UC3);
    for(int i = 0; i < this->img.rows; i++)
    {
        for(int j = 0; j < this->img.cols; j++)
        {
            for(int k = 0; k < this->img.channels(); k++)
            {
                this->img_invert.at<cv::Vec3b>(i, j)[k] = 255 - this->img.at<cv::Vec3b>(i, j)[k];
            }
        }
    }
    this->realTimechanged = false;
    this->graychanged = false;
    this->constrastChanged = false;
    this->invertChanged = true;
    this->showImage(img_invert);
}

void MainWindow::on_actionSave_image_triggered()
{
    QString folder = QFileDialog::getSaveFileName(this, tr("save_image"), "saved_image.bmp", tr("Image(*,bmp)"));
    QString path = folder + "/";
    std::string std_path = folder.toStdString();
    if(this->realTimechanged == true)
        cv::imwrite(std_path, this->real_time_img);
    else if(this->graychanged == true)
        cv::imwrite(std_path, this->imgGray);
    else if(this->constrastChanged == true)
        cv::imwrite(std_path, this->img_Constrat);
    else if(this->invertChanged == true)
        cv::imwrite(std_path, this->img_invert);
    else
        qDebug() << "Please try to modify your image before saving it.";
}

void MainWindow::save_image()
{
    if(saveImageOrNot == true)
    {
        this->tmp = this->real_time_img.clone();
        saveImageOrNot = false;
        qDebug() << "save image";
    }
    else
        saveImageOrNot = true;
}
