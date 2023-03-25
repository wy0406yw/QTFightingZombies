#ifndef BASE_H
#define BASE_H

#include<QRect>
#include<QPainter>

class Base
{
public:
    Base(){}

    virtual void display(QPainter &paint) = 0;//纯虚函数，用于绘制图片
    int step;//步进长
    int attack;//攻击力
    int pos;
    QRect hp;
    QRect hp_g;
    int disappear;//存在状态
    double life;//血量
protected:




};

#endif // BASE_H
