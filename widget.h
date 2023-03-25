#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include "game.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    game* ppage2;//保存页面2的实例化对象的地址
    QMessageBox MBox;


private:
    Ui::Widget *ui;

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton2_clicked();
};

#endif // WIDGET_H
