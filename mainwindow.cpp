#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageBuffer = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionopen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "OpenImage File",
                                                    qApp->applicationDirPath(), "JPG (*.jpg *.jpeg);;PNG(*.png)");
    if (!fileName.isEmpty())
    {
        imageBuffer = new QPixmap(fileName);
        resizeImage();
    }
}
void MainWindow::resizeImage()
{
    if (imageBuffer != nullptr)
    {
        QSize size = ui->imageDisplay->size();
        QPixmap pixmap = imageBuffer->scaled(size,
        Qt::KeepAspectRatio);
        // Adjust the position of the image to the center
        QRect rect = ui->imageDisplay->rect();
        rect.setX((this->size().width() - pixmap.width()) / 2);
        rect.setY((this->size().height() - pixmap.height()) / 2);
        QPainter painter;
        painter.begin(this);
        painter.drawPixmap(rect, pixmap,
        ui->imageDisplay->rect());
        painter.end();
    }
}
void MainWindow::paintEvent(QPaintEvent *event){
    resizeImage();
}


