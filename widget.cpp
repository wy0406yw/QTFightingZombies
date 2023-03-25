#include "widget.h"
#include "ui_widget.h"
#include "game.h"
#include <QPushButton>
#include <ctime>
#include <sstream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

void fileop(int killx)
{

    time_t t = time(nullptr);
    struct tm* now = localtime(&t);


    QString time;

    time += QString::number(now->tm_year + 1900) + "年";
    time += QString::number(now->tm_mon + 1) + "月";
    time += QString::number(now->tm_mday) + "日 ";
    time += QString::number(now->tm_hour) + ":";
    time += QString::number(now->tm_min) + "   -->击败数: ";


    //创建 QFile 对象，同时指定要操作的文件
    QFile file("D:/demo.txt");
    //对文件进行写操作
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)){
        qDebug()<<"文件打开失败";
    }
    QTextStream out(&file);
    //向文件中写入两行字符串

    out << time + QString::number(killx) + "\n";
    //关闭文件
    file.close();

    return;
}



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->ppage2 = new game;//实例化页面2
    this->ppage2->time->stop();

    MBox.setWindowTitle("GAMEDEMO");


    connect(ui->pushButton,&QPushButton::clicked,[=](){

        this->hide();//对象并没有释放
        ui->pushButton->setText("继续游戏");

        //切换窗口，隐藏主窗口，显示页面2
        this->ppage2->showMaximized();
        this->ppage2->time->start();

    } );
    connect(ui->pushButton3,&QPushButton::clicked,[=](){
        this->close();
    } );
    connect(this->ppage2,&game::back,[=]()
    {
        this->ppage2->hide();
        this->show();
    });

    connect(this->ppage2,&game::ggg,[=]()
    {
        this->ppage2->hide();
        fileop(this->ppage2->kill);
        this->ppage2->gameinit();
        this->ppage2->time->stop();
        ui->pushButton->setText("开始游戏");


        this->show();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QPixmap pix2;
    pix2.load(":/image/加载动画.png");
    painter->drawPixmap(0,0,pix2);

}


void Widget::on_pushButton2_clicked()
{
    QFile file("D:/demo.txt");

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }
    QTextStream in(&file);
    //一直读，直至读取失败
    QString time,temp;
    while(!in.atEnd()){
        //从文件中读取一个字符串
        in >> temp;
        time += temp;
    }
    file.close();

    MBox.setText(time);
    MBox.show();
}
