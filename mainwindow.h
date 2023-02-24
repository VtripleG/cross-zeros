#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPainter"
#include "QMouseEvent"
#include "class.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int square [3][3];

    void paintEvent (QPaintEvent*) override;
    void paintEventCross();

    void mousePressEvent(QMouseEvent *event) override ;
//    void mouseMoveEvent(QMouseEvent *event)override;
//    void mouseReleaseEvent(QMouseEvent *event) override;

    void return_point(QPoint chek);



    QPoint start_point = QPoint (100, 100);
    int count = 1;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
