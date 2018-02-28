#ifndef BUBBLELTIPBUTTON_H
#define BUBBLELTIPBUTTON_H
#include <QToolButton>
#define LABEL_WIDTH 12

class BubblelTipToolButton : public QToolButton
{
public:
    BubblelTipToolButton(QWidget *parent);
    virtual void paintEvent(QPaintEvent *event);
    void setNum(int n);
    int getNum();
private:
    int num;
};

#endif // BUBBLELTIPBUTTON_H
