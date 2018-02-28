#include "bubbleltiptoolbutton.h"
#include <QPainter>

BubblelTipToolButton::BubblelTipToolButton(QWidget *parent): QToolButton(parent)
{
    num=0;
}

void BubblelTipToolButton::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);
    QPainter painter(this);
    QRect rt = this->rect();
    QRect rt1 = QRect(rt.right()-LABEL_WIDTH, rt.top(), LABEL_WIDTH, LABEL_WIDTH);
//    QRect rt2 = QRect(rt.left()+BORDER_WIDTH, rt.top()+BORDER_WIDTH,
//                      rt.width()-2*BORDER_WIDTH, rt.height()-2*BORDER_WIDTH);
//    painter.fillRect(rt2, Qt::green);

    painter.setPen(Qt::red);
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(rt1);

    painter.setPen(Qt::white);
    painter.drawText(rt1, Qt::AlignCenter, QString::number(num));
    painter.drawText(rt, Qt::AlignCenter, text());
}

void BubblelTipToolButton::setNum(int n)
{
    num=n;
}

int BubblelTipToolButton::getNum()
{
    return num;
}
