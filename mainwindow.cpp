#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            square[i][j] = 0;
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
     QPainter painter (this);
     QPen pen(QColor (0, 0, 0) );
     pen.setWidth(4);
     painter.setPen(pen);
     //отрисовка пертикальных линий поля
     painter.drawLine(this->start_point.x() + 100,this->start_point.y(), this->start_point.x() + 100,this->start_point.y() + 300);
     painter.drawLine(this->start_point.x() + 200,this->start_point.y(), this->start_point.x() + 200,this->start_point.y() + 300);
     //отрисочка горизонтальных линий поля
     painter.drawLine(this->start_point.x(),this->start_point.y()+100, this->start_point.x()+300,this->start_point.y() + 100);
     painter.drawLine(this->start_point.x(),this->start_point.y()+200, this->start_point.x()+300,this->start_point.y() + 200);

     QPainter painter_1(this);
     pen.setColor(QColor (20, 1, 1) );
     pen.setWidth(3);
     painter_1.setPen(pen);
     for(int i = 0; i < 3; i++)
         for(int j = 0; j < 3; j++)
         {
             if(square[i][j] == 1)
             {
                 painter_1.drawLine((i+1)*100, (j+1)*100, (i+1)*100+100, (j+1)*100+100);
                 painter_1.drawLine((i+1)*100+100, (j+1)*100, (i+1)*100, (j+1)*100+100);
            }
             else{
                 if(square[i][j] == 2)
                     painter_1.drawEllipse(QPoint((i+1)*100 +50, (j+1)*100 +50 ), 47, 47);
             }
         }

//(i+1)*100 +50, (j+1)*100 +50, 47, 47
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint chek = event->pos(); //проверка позиции
    int x;
    int y;
    if ((chek.x() >= 100 && chek.x() <= 400) &&
        (chek.y() >= 100 && chek.y() <= 400))
    {
    x = chek.x()/100;
    y = chek.y()/100;
    if(square[x-1][y-1]!=1 && square[x-1][y-1]!= 2) //проверка, какую из фигур присвоить ячейке
    {
    square[x-1][y-1] = count;
    if(count == 1)
    count = 2;
    else{count = 1;}
    }
    }
    //return_point(chek);
    repaint();

    //проверка на победу
    if ( //строки
         (square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][0]!=0) ||
         (square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][0]!=0) ||
         (square[2][0] == square[2][1] && square[2][1] == square[2][2] && square[2][0]!=0) ||
         //столбцы
         (square[0][0] == square[1][0] && square[1][0] == square[2][0] && square[0][0]!=0) ||
         (square[0][1] == square[1][1] && square[1][1] == square[2][1] && square[0][1]!=0) ||
         (square[0][2] == square[1][2] && square[1][2] == square[2][2] && square[0][2]!=0) ||
         //диагонали
         (square[0][0] == square[1][1] && square[1][1] == square[2][2] && square[0][0]!=0) ||
         (square[0][2] == square[1][1] && square[1][1] == square[2][0] && square[0][2]!=0)
       )
    {
        QMessageBox::information(this, "WIN!!!", "You WIN!");
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                square[i][j] = 0;
            }
        repaint();
    }

    //проверка на ничью
    bool flag = false;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <3; j++)
        {
            if (square[i][j] == 0)
            {
                flag = true;
            }
        }
    if(flag == false)
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                square[i][j] = 0;
            }
         QMessageBox::information(this, "DEAD HEAT!!!", "No WINNER!");
          repaint();
    }
}

void MainWindow::return_point(QPoint chek)
{
    int x;
    int y;
    if ((chek.x() >= 100 && chek.x() <= 400) &&
        (chek.y() >= 100 && chek.y() <= 400))
    {
    x = chek.x()/100;
    y = chek.y()/100;
    square[x-1][y-1] = count%2;
    count++;
    }
}

void MainWindow::paintEventCross()
{
    QPainter painter_cross(this);
    QPen pen(QColor (0, 0, 0) );
    pen.setWidth(3);
    painter_cross.setPen(pen);
//    painter.drawLine(chek.x(), chek.y(), chek.x()+100, chek.y()+100);
//    painter.drawLine(chek.x()+100, chek.y(), chek.x(), chek.y()+100);

    painter_cross.drawLine(100, 100, 100+100, 100+100);
    painter_cross.drawLine(100+100, 100, 100, 100+100);

}



