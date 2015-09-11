#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv.hpp>
#include <QFileDialog>
#include <QString>
#include <QImage>

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

private:
    Ui::MainWindow *ui;
    QImage Mat2QImage(const cv::Mat src);
};

#endif // MAINWINDOW_H
