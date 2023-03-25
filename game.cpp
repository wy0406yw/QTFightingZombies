#include "game.h"
#include "ui_game.h"
#include "widget.h"
#include "person.h"
#include <QDebug>
#include <QFont>

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    index = 0;
    able = 0;
    kill = 0;
    radom = 1;
    ui->setupUi(this);
    p1 = new Person;
    num = 0;
    index_g1 = 0;//背景序列
    plen = 22;
    connect(ui->pb1,&QPushButton::clicked,[=](){
        emit this->back();
        time->stop();
    });   

    Init();
    time = new QTimer();
    time->setInterval(40);

    connect(time,SIGNAL(timeout()),this,SLOT(onTimeout()));
    time->start();
    //startTimer(40);
    for(int i = 0; i<100;i++)
    {
        Tzb[i] = NULL;
    }
}

void game::gameinit()
{
    p1->life = 3000;
    p1->disappear = 1;
    kill = 0;
    able = 0;
    num = 0;

    for(int i = 0; i<100;i++)
    {
        if(Tzb[i] != NULL)
        {
            delete Tzb[i];
            Tzb[i] = NULL;
        }

    }
}

void game::background()
{
    if(plen == 40)
    {
        plen = 22;
        index_g1 = 0;
    }
    else if(plen == 22)
    {
        plen = 40;
        index_g1 = 0;
    }
}

game::~game()
{
    delete ui;
}


void game::Init()
{
    int w,h;
    for(int i = 0;i < 22;i ++)
    {

        QString filename = QString(":/background/船 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();

        background1[i] = map.scaled(w*3,h*2);
    }

    for(int i = 0;i < 40;i ++)
    {
        QString filename = QString(":/background/香港 (?).png").replace("?",QString::number(i+1));
        QPixmap map(filename);
        w = map.width();
        h = map.height();
        background2[i] = map.scaled(w*2.4,h*2.35);
    }


}

void game::isatt()
{
       for(int i = 0;i <= num;i++)
       {
             if(Tzb[i] != NULL && Tzb[i]->isable == 1)
             {
                 if(Tzb[i]->body.intersects(p1->skill))
                 {
                     Tzb[i]->attacked(p1->attack);                    
                     Tzb[i]->isable = 0;
                     if(p1->able == 5 || p1->able == 4)
                     {
                        p1->life += 20;
                        p1->power += 10;
                     }
                     if(p1->power > 100)
                         p1->power = 100;
                 }
             }
        }


}

void game::paintEvent(QPaintEvent *event)
{
        Q_UNUSED(event);

        paint.begin(this);

        if(plen == 22)
            paint.drawPixmap(0,0,background1[index_g1]);
        else
            paint.drawPixmap(0,-20,background2[index_g1]);

        paint.drawRect(QRect(5,50,300,18));
        paint.setBrush(QBrush(Qt::yellow));
        paint.drawRect(QRect(6,51,(p1->power/ 100) * 300,16));
        paint.setBrush(QBrush(Qt::transparent));
        paint.drawText(8,65,"能量:   " + QString::number(p1->power));

        paint.drawRect(QRect(5,80,300,18));
        paint.setBrush(QBrush(Qt::red));
        paint.drawRect(QRect(6,81,(kill/ 100) * 300,16));
        paint.setBrush(QBrush(Qt::transparent));
        paint.drawText(8,95,"杀敌/总敌数:   " + QString::number(kill) + "/100");

        //paint.drawPixmap(0,0,pix);


        for(int i = 0;i <= num;i++)
        {
            if(Tzb[i] != NULL)
                Tzb[i]->display(paint);
        }

        p1->display(paint);

        if(able == 9)
        {
            QFont f;
            f.setPointSize(20);
            paint.setFont(f);
            paint.drawText(500,400,"GAME OVER!!!");
            f.setPointSize(5);
            paint.setFont(f);
        }
        paint.end();
}

void game::keyPressEvent(QKeyEvent *event)//捕获键盘
{

    if(event->key() == Qt::Key_A)

    {
        p1->gol();
    }


    if(event->key() == Qt::Key_D)

    {
        p1->gor();
    }


    if(event->key() == Qt::Key_W)
        p1->up();



    if(event->key() == Qt::Key_L)
    {
        if(p1->able == 0)
        {
            for(int i = 0;i <= num;i++)
            {
                  if(Tzb[i] != NULL && Tzb[i]->isable == 0)
                  {
                      Tzb[i]->isable = 1;
                  }
             }
        }
        p1->p1s3();

    }
    if(event->key() == Qt::Key_J)
    {
        if(p1->able == 0)
        {
            for(int i = 0;i <= num;i++)
            {
                  if(Tzb[i] != NULL && Tzb[i]->isable == 0)
                  {
                      Tzb[i]->isable = 1;
                  }
             }
        }
        p1->p1s2();

    }
    if(event->key() == Qt::Key_K)
    {
        if(p1->able == 0)
        {
            for(int i = 0;i <= num;i++)
            {
                  if(Tzb[i] != NULL && Tzb[i]->isable == 0)
                  {
                      Tzb[i]->isable = 1;
                  }
             }
        }

        p1->p1s1();
    }

    if(event->key() == Qt::Key_H)
    {
        if(p1->able == 0)
        {
            for(int i = 0;i <= num;i++)
            {
                  if(Tzb[i] != NULL && Tzb[i]->isable == 0)
                  {
                      Tzb[i]->isable = 1;
                  }
             }
        }

        p1->p1s0();
    }



}

void game::keyReleaseEvent(QKeyEvent *event)//键盘松开
{
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_D)
        p1->keyFlag = 1;
}


void game::onTimeout()//时间器
{

    p1->gameTimer();
    tim ++;
    if((tim > (100 - kill) || num - kill < 2) && num < 100)
    {
        tim = 0;
        zbinit();     
    }

    isatt();//僵尸是否被打到
    zb_isAtt();//反之

    if(p1->disappear == 0)
    {

        able = 9;

    }

    if(able == 9)
    {
        index++;
        if(index >= 20)
        {
            index = 0;
            able = 0;
            emit ggg();
            //
        }
    }

    index_g1++;//背景
    if(index_g1 >= plen)
        index_g1 = 0;

    radom++;
    if(radom == 8)
        radom = 0;

    for(int i = 0;i < num;i++)
    {
        if(Tzb[i] != NULL)
        {
            Tzb[i]->gameTimer(p1->pos);
            if(Tzb[i]->disappear == 0)
            {
            delete Tzb[i];
            Tzb[i] = NULL;
            kill++;
            }
        }

    }
    repaint();

}

void game::zbinit()
{ 
    Tzb[num] = new Zb((radom) % 2,(150 + num * 2.5),(30 + radom + num));
    num++;
}

void game::zb_isAtt()
{
    for(int i = 0;i <= num;i++)
    {
              //if(Tzb[i]->body.intersects(p1->skill))
        if(Tzb[i] != NULL)
        {
            if(p1->body.intersects(Tzb[i]->skill))
                 {
                     p1->attacked(Tzb[i]->attack);
                     Tzb[i]->skill = QRect(0,0,0,0);
                 }
        }

     }



}






