#ifndef ZB_H
#define ZB_H

#include <base.h>
#include <QPixmap>
#include <QRect>

class Zb : public Base
{

public:
    Zb();
    Zb(int dir,int lifex,int attx);
    void Init();
    virtual void display(QPainter &paint);
    int index;
    int index1;
    int index2;//死亡序列
    void zb_s1();
    void left();
    void gameTimer(int posx);
    void attacked(int attack);
    void Attacking();
    QRect body;
    QRect skill;
    int dir;
    int isable;//能否被公鸡
    int able;


protected:
    QPixmap pixmapl[50];//普通僵尸50帧
    QPixmap pixmapr[50];
    QPixmap zb_sr[20];//僵尸5gongji20帧
    QPixmap zb_sl[20];
    QPixmap zb_dier[20];
    QPixmap zb_diel[20];

};

#endif // ZB_H
