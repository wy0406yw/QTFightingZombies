#include "person.h"
#include "base.h"
#include "zb.h"
#include <QDebug>

Person::Person()
{
    able = 0;
    //0:可以进行其他动作able = 0静止或者左右跑//sp = 0静止sp = 1跑
    //1:跳跃
    //2:技能中
    //
    power = 50;
    sp = 0;//默认不动
    index = 0;
    index_s = 0;
    index_u = 0;
    index_s1 = 0;
    index_s2 = 0;
    index_s3 = 0;
    step = 24;
    pos = 100;

    dir = 1;
    posy = 780;
    upFlag = 0;
    downFlag = 0;
    keyFlag = 1;
    disappear = 1;
    life = 3000;
    attack = 40;
    Init();
}


void Person::attacked(int attack)//被攻击
{

    life -= attack;
    if(life <= 0)
    {
        disappear = 0;
        //游戏结束
    }
}

void Person::Attacking()
{
    if(dir == 1)
        skill = QRect(pos + 80,posy - 30,130,200);
    else
        skill = QRect(pos-10,posy - 30,130,200);
}

void Person::Attacking1()
{
    if(dir == 1)
        skill = QRect(pos,posy - 100,200,300);
    else
        skill = QRect(pos-100,posy - 100,200,300);
}

void Person::Attacking2()
{
    if(dir == 1)
        skill = QRect(pos+120,posy + 120,50,50);
    else
        skill = QRect(pos-50,posy + 120,50,50);
}

void Person::Attacking3()
{
    if(dir == 1)
        skill = QRect(pos+100,posy - 100,50,350);
    else
        skill = QRect(pos-50,posy - 100,50,350);
}


void Person::Init()//加载图片
{
    int w,h;

    for(int i = 0;i < 9;i ++)
    {
        QString filename = QString(":/image/八神left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_run_l[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }


    for(int i = 0;i < 9;i ++)
    {
        QString filename = QString(":/image/八神 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_run_r[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 13;i ++)
    {
        QString filename = QString(":/image/直跳 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_upr[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 13;i ++)
    {
        QString filename = QString(":/image/直跳left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_upl[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 18;i ++)
    {
        QString filename = QString(":/image/站立 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_star[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 18;i ++)
    {
        QString filename = QString(":/image/站立left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_stal[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 58;i ++)
    {
        QString filename = QString(":/image/八神大招 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s3r[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 58;i ++)
    {
        QString filename = QString(":/image/八神大招left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s3l[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 21;i ++)
    {
        QString filename = QString(":/image/鬼烧 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s1r[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 21;i ++)
    {
        QString filename = QString(":/image/鬼烧left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s1l[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 16;i ++)
    {
        QString filename = QString(":/background/勾手 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s2r[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 16;i ++)
    {
        QString filename = QString(":/background/勾手left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s2l[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 15;i ++)
    {
        QString filename = QString(":/image2/普攻 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s0r[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 15;i ++)
    {
        QString filename = QString(":/image2/普攻left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        p1_s0l[i] = map.scaled(w*1.5,h*1.5,Qt::KeepAspectRatio);
    }
}


void Person::display(QPainter &paint)//显示人物
{
    if(disappear == 1)
    {
        body = QRect(pos,posy,90,150);
        //paint.drawRect(body);
        hp_g = QRect(pos,posy - 30,150,18);
        paint.drawRect(hp_g);
        hp = QRect(pos + 1,posy - 29,(life / 3000) * 150,16);
        paint.setBrush(QBrush(Qt::green));
        paint.drawRect(hp);
        paint.setBrush(QBrush(Qt::transparent));
        paint.drawText(pos + 5,posy - 15,"HP:   " + QString::number(life));




        //if(skill != QRect(0,0,0,0))
         //  paint.drawRect(skill);

        if(able == 1 && dir == 1)//

            paint.drawPixmap(pos,640,p1_upr[index_u]);//跳

        else if(able == 1 && dir == 0)

            paint.drawPixmap(pos,640,p1_upl[index_u]);//跳

        else if(sp == 0 && able == 0 && dir == 1)//没有左右跑也没有跳

            paint.drawPixmap(pos,posy,p1_star[index_s]);//站

        else if(sp == 0 && able == 0 && dir == 0)//没有左右跑也没有跳

            paint.drawPixmap(pos,posy,p1_stal[index_s]);//站

        else if(dir == 1 && sp == 1 && able == 0)//如果方向是右

            paint.drawPixmap(pos,posy+10,p1_run_r[index]);//向右跑的图片

        else if(dir == 0 && sp == 1 && able == 0)

            paint.drawPixmap(pos,posy+10,p1_run_l[index]);//向左跑的图片

        else if(able == 2 && dir == 1)
            paint.drawPixmap(pos - 35,625,p1_s3r[index_s3]);//j技能3
        else if(able == 2 && dir == 0)
            paint.drawPixmap(pos - 290,625,p1_s3l[index_s3]);//j技能3

        else if(able == 3 && dir == 1)//ji2
            paint.drawPixmap(pos - 50,625,p1_s1r[index_s1]);//1技能
        else if(able == 3 && dir == 0)
            paint.drawPixmap(pos - 55,625,p1_s1l[index_s1]);

        else if(able == 4 && dir == 1)//2
            paint.drawPixmap(pos,770,p1_s2r[index_s2]);//2
        else if(able == 4 && dir == 0)
            paint.drawPixmap(pos - 270,770,p1_s2l[index_s2]);

        else if(able == 5 && dir == 1)//普攻
            paint.drawPixmap(pos,770,p1_s0r[index_s0]);//
        else if(able == 5 && dir == 0)
            paint.drawPixmap(pos,770,p1_s0l[index_s0]);


    }
}

void Person::p1s2()
{
    if(able == 0 && power > 5)
    {
        able = 4;
        power-=5;
        attack = 50;
        Attacking2();
    }
}

void Person::p1s1()
{
    if(able == 0 && power > 10)
    {
        power-=10;
        attack = 80;
        able = 3;
        Attacking1();
    }
}


void Person::p1s3()
{
    if(able == 0 && power > 60)
    {
        power -= 70;
        attack = 300;
        able = 2;
        Attacking3();
    }

}

void Person::p1s0()//普攻
{
    if(able == 0)
    {
        able = 5;
        attack = 25;
        Attacking();
    }


}

void Person::up()//跳
{
    if(posy == 780 && able == 0)
    {
        f1 = true;
        able = 1;
        upFlag = 1;
        index_u = 0;
    }
}



void Person::gol()//间接左
{
    if(able == 0)
        dir = 0;
    keyFlag = 0;//设置为按下方向键了
}

void Person::gor()//右
{
    if(able == 0)
        dir = 1;
    keyFlag = 0;//设置为按下方向键了
}

void Person::left()//实现人物往左移动
{

    if(pos > 50 && (able == 0 || able == 1))
    {
        if(dir == 1) index = 0;

        dir = 0;

        pos -= step;
    }
}



void Person::right()//向右走
{
    if(pos < 1800 && (able == 0 || able == 1))
    {
        if(dir == 0) index = 0;

        dir = 1;

        pos += step;
    }
}


void Person::tiao()
{
    if(able == 1 && upFlag == 1)
        {
            posy -= 20;
            if(f1)
            {
                f1 = false;
                posy += 20;
            }

            if(posy < 660)//跳到640
            {
                posy = 660;
                upFlag = 0;
                downFlag = 1;
            }

            index_u++;
            if(index_u >= 13)
                index_u = 0;
        }
    else if(downFlag == 1)
        {
            posy += 20;

            if(posy>=780)
            {
                downFlag = 0;
                able = 0;//跳跃完成
            }
            index_u++;
            if(index_u >= 13)
                index_u = 0;
        }
}



void Person::gameTimer()//时间器
{
    power += 0.1;
    if(power > 100)
        power = 100;

    if(able == 0 || sp == 0)
    {
        index_s++;
        if(index_s>=18)
            index_s = 0;
    }

    if(sp == 1)
    {
        index++;
        if(index >= 9)
            index = 0;
    }

    //动画实现
    if(able == 2)
    {
        index_s3++;//3技能
        if(dir == 1 && index_s3 > 25)
            skill.adjust(8,0,8,0);
        else if(dir == 0 && index_s3 > 25)
            skill.adjust(-8,0,-8,0);

        if(index_s3 >= 58)
        {
            index_s3 = 0;
            skill = QRect(0,0,0,0);
            able = 0;
        }
    }

    if(able == 3)
    {
        index_s1++;//1技能
        if(index_s1 >= 21)
        {
            skill = QRect(0,0,0,0);
            index_s1 = 0;
            able = 0;
        }
    }

    if(able == 4)
    {
        index_s2++;//2
        if(dir == 1)
            skill.adjust(12,0,12,0);
        else
            skill.adjust(-12,0,-12,0);
        if(index_s2 >= 16)
        {
            skill = QRect(0,0,0,0);
            index_s2 = 0;
            able = 0;
        }
    }

    if(able == 5)
    {
        index_s0++;//2
        if(index_s0 >= 15)
        {
            skill = QRect(0,0,0,0);
            index_s0 = 0;
            able = 0;
        }
    }

    //跳跃实现
    tiao();



    //按下左右键跑直到松开ad键
    if(keyFlag != 1)//实现跑
    {
        sp = 1;
        if(dir == 0)
            left();
        if(dir == 1)
            right();
    }
    else
        sp = 0;

}




