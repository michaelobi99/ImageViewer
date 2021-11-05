#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeImage();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_actionopen_file_triggered();

private:
    Ui::MainWindow *ui;
    QPixmap *imageBuffer{nullptr};
};
#endif // MAINWINDOW_H
