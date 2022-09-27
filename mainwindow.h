#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtMath>
#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>
#include <QRadialGradient>

#include <QTimer>
#include <QKeyEvent>
#include"battery.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#define TURN_NONE   0
#define TURN_LEFT   1
#define TURN_RIGHT   2
#define DOUBLE_LIGHT   3
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *myTimer;
    QTimer *inputTimer;

    int radius;//仪表盘的中心位置
    int direction;//指针运动的方向,1为前进，0为后退

protected:
    void paintEvent(QPaintEvent*);
private:
    int degRotate =0;
    int battery_value = 0;
    int direction_Value = 0;

private:
    void DrawPoint(QPainter&,int);
    void DrawDigital(QPainter&,int);
    void DrawCircle(QPainter&,int);
    void DrawSmallScale(QPainter&,int);
    void DrawBigScale(QPainter&,int);
    void DrawUnit(QPainter&,int);
    void DrawNum(QPainter&,int);
    void DrawPointer(QPainter&,int);
    void drawIndicator(QPainter *painter);
    void DrawCircle_line(QPainter& painter,int radius);
    void DrawCircle_bom(QPainter& painter,int radius);
    void DrawCircle_bom_big(QPainter& painter,int radius);
    void DrawCircle_bom_shine(QPainter& painter,int radius);
    void DrawCircle_bom_small(QPainter& painter,int radius);
    void DrawCircle_arc(QPainter& painter,int radius);
    void sls_setValue(int value);
    void DrawGrar(QPainter& painter,int radius);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void DrawCircle_outline(QPainter& painter,int radius);
    void DrawDerection(QPainter& painter,int radius);
private slots:
    void slot_speed_changed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
