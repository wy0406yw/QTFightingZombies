#ifndef PERSON_H
#define PERSON_H

#include "base.h"
#include <QPixmap>
#include <QRect>

class Person : public Base
{


public:

    Person();
    void Init();
    virtual void display(QPainter &paint);
    void up();
    void left();
    void right();
    void gameTimer();//时间执行
    void gol();
    void gor();
    void attacked(int attack);
    void Attacking();
    void Attacking1();
    void Attacking2();
    void Attacking3();
    void tiao();//跳
    bool f1;//
    QRect body;
    QRect skill;
    int keyFlag;
    int dir;
    void p1s1();
    void p1s2();
    void p1s3();
    void p1s0();
    int index_s1;
    int index_s2;
    int index_s3;
    int index_s0;
    int able;
    double power;

protected:

    int index;//动画序列
    int posy;//y坐标
    int upFlag;//是否在跳跃过程中
    int downFlag;//xialuo
    int s3Flag;


    QPixmap p1_s0r[15];//
    QPixmap p1_s0l[15];


    QPixmap p1_s1r[21];//技能3个
    QPixmap p1_s1l[21];
    QPixmap p1_s2r[16];
    QPixmap p1_s2l[16];
    QPixmap p1_s3r[58];
    QPixmap p1_s3l[58];


    QPixmap p1_star[18];//静态
    QPixmap p1_stal[18];

    QPixmap p1_run_r[9];//右跑
    QPixmap p1_run_l[9];//左pao
    QPixmap p1_upr[13];//tiao
    QPixmap p1_upl[13];
    int index_s;

    int sp;//动
    int index_u;//跳

};

#endif
