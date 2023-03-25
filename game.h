#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include "person.h"
#include "zb.h"
#include <QRect>
#include <QTimer>
#include <QTimerEvent>
#include <QKeyEvent>

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    void gameinit();
    explicit game(QWidget *parent = 0);
    ~game();
    QPixmap background1[22];//船
    QPixmap background2[40];//香港
    void Init();
    QTimer * time;
    double kill;

public slots:
   void onTimeout();

signals:
    void back();
    void ggg();

private:
    Ui::game *ui;

protected:


    int radom;
    int tim;
    int able;
    int index;

    void zbinit();
    void zb_isAtt();



    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int index_g1;
    Person * p1;
    Zb * p2;
    Zb *Tzb[100];//僵尸们
    int num;
    QPainter paint;
    int plen;
    void background();
    void isatt();


};

#endif // GAME_H
