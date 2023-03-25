#include "zb.h"
#include "base.h"

Zb::Zb()
{
     able = 0;
     body = QRect(0,0,0,0);
     skill = QRect(0,0,0,0);
     step = 3;
     isable = 1;
     pos = 1800;
     index = 0;
     index1 = 0;
     index2 = 0;
     disappear = 1;
     life = 200;
     attack = 30;
     Init();
}

Zb::Zb(int dir,int lifex,int attx)
{
     able = 0;
     body = QRect(0,0,0,0);

     skill = QRect(0,0,0,0);

     step = 4;
     isable = 1;

     if(dir == 0)
        pos = 1800;
     else
        pos = 51;

     index = 0;
     index1 = 0;
     index2 = 0;

     disappear = 1;
     life = lifex;
     attack = attx;
     Init();
}

void Zb::Init()//初始化僵尸动画
{
    int w,h;
    for(int i = 0;i < 50;i ++ )
    {
        QString filename = QString(":/zb/普通僵尸 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        pixmapl[i] = map.scaled(w*1.2,h*1.2,Qt::KeepAspectRatio);
    }
    for(int i = 0;i < 50;i ++ )
    {
        QString filename = QString(":/zb/普通僵尸right (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        pixmapr[i] = map.scaled(w*1.2,h*1.2,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 20;i ++ )
    {
        QString filename = QString(":/zb/僵尸攻击 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        zb_sr[i] = map.scaled(w*1.2,h*1.2,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 20;i ++ )
    {
        QString filename = QString(":/zb/僵尸攻击left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        zb_sl[i] = map.scaled(w*1.2,h*1.2,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 20;i ++ )
    {
        QString filename = QString(":/zb/僵尸死 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        zb_dier[i] = map.scaled(w*1.2,h*1.2,Qt::KeepAspectRatio);
    }

    for(int i = 0;i < 20;i ++ )
    {
        QString filename = QString(":/zb/僵尸死left (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        zb_diel[i] = map.scaled(w*1.2,h*1.2,Qt::KeepAspectRatio);
    }
}



void Zb::display(QPainter &paint)//显示僵尸
{
    if(disappear == 1)
    {
        body = QRect(pos,795,80,130);
        //if(skill != QRect(0,0,0,0))
         //   paint.drawRect(skill);
        //paint.drawRect(body);
        //hp_g = QRect(pos,770,150,18);
        paint.drawRect(QRect(pos,770,150,18));
        //hp = QRect(pos + 1,771,(life / 200) * 150,16);
        paint.setBrush(QBrush(Qt::red));
        paint.drawRect(QRect(pos + 1,771,(life / 200) * 150,16));
        paint.setBrush(QBrush(Qt::transparent));
        paint.drawText(pos + 5,785,"HP:   " + QString::number(life));

        if(able == 1 && dir == 0)
            paint.drawPixmap(pos,770,zb_sl[index1]);
        else if(able == 1 && dir == 1)
            paint.drawPixmap(pos,770,zb_sr[index1]);

        else if(able == 0 && dir == 0)
            paint.drawPixmap(pos,770,pixmapl[index]);
        else if(able == 0 && dir == 1)
            paint.drawPixmap(pos,770,pixmapr[index]);

        else if(able == 9 && dir == 0)
            paint.drawPixmap(pos + 50,770,zb_diel[index2]);
        else if(able == 9 && dir == 1)
            paint.drawPixmap(pos + 50,770,zb_dier[index2]);
    }

}


void Zb::left()//僵尸移动//
{
    if(pos > 20 && pos < 1820)
    {
        if(dir == 0)
            pos -= step;
        else
            pos += step;
    }
}

void Zb::gameTimer(int posx)//动画
{

    if((posx-60) < pos && pos < (posx+60) && able == 0)
    {
        if(pos < posx)
            dir = 1;
        else
            dir = 0;
        zb_s1();

    }
    else if(pos < posx && able == 0)
    {
        dir = 1;
        left();
    }
    else if(pos > posx && able == 0)
    {
        dir = 0;
        left();
    }

    if(able == 0)
    {
        index++;
        if(index >= 50)
            index = 0;
    }

    if(able == 1)//gongji
    {
        index1++;
        if(index1 >= 20)
        {
            able = 0;
            skill = QRect(0,0,0,0);
            index1 = 0;
        }
    }

    if(able == 9)
    {
        index2++;
        if(index2 >= 20)
        {
            index2 = 0;
            disappear = 0;
        }
    }


}

void Zb::zb_s1()
{
        able = 1;
        Attacking();
}

void Zb::Attacking()
{
        if(dir == 1)
            skill = QRect(pos + 80,850,100,50);
        else
            skill = QRect(pos-40,850,100,50);
}

void Zb::attacked(int attack)//被攻击
{
    if(able != 9)
    {
        life -= attack;
        if(life <= 0)
        {
            able = 9;//9死亡
        }
    }

}
