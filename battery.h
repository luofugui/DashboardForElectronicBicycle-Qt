#ifndef BATTERY_H
#define BATTERY_H


//class battery
//{
//public:
//    battery();
//};
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
class Battery : public QMainWindow

{
    Q_OBJECT

public:
    Battery(QWidget *parent = nullptr);
    ~Battery();

    void SetValue(int currentValue);
    int  GetValue();

protected:
    void paintEvent(QPaintEvent *);
    void drawBorder(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawText(QPainter *painter);

private slots:
    void inputValue();

private:

    double _currentValue;
    int _margin;
    double _minValue;                //最小值
    double _maxValue;                //最大值
    bool _isForward;                 //是否往前移
    int _batteryWidth;
    int _batteryHeight;

    QRectF batteryRect;             //电池主体区域
    QTimer *inputTimer;                  //绘制定时器
};

#endif // BATTERY_H
