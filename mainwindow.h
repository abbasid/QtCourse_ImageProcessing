#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QImage>
#include <QDebug>
#include <opencv.hpp>
#include <QVector>
#include <QTimer>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_image_triggered();

    void on_brightness_valueChanged(int value);

    void on_red_valueChanged(int value);



    void on_green_valueChanged(int value);

    void on_blue_valueChanged(int value);

    void on_grayscale_clicked();

    void on_blur_clicked();

    void on_contrast_valueChanged(int value);

    void on_invert_clicked();

    void on_actionSave_image_triggered();

    void save_image();

private:
    Ui::MainWindow *ui;
    cv::Mat img;
    QImage Mat2QImage(const cv::Mat &src);
    void showImage(const cv::Mat &src);
    void changeColorTemp(cv::Mat &src, cv::Mat &tmp, QVector<int> color);
    cv::Mat real_time_img;
    cv::Mat imgGray;
    cv::Mat img_Constrat;
    cv::Mat img_invert;
    cv::Mat tmp;
    QTimer *clock;
    bool saveImageOrNot;
    bool realTimechanged;
    bool graychanged;
    bool constrastChanged;
    bool invertChanged;
};

#endif // MAINWINDOW_H
