#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Sprite: public QObject, public QGraphicsItem{
    Q_OBJECT
private:
    int x, y, width, height;

    int currentFrame;
    QPixmap* spriteImage;
    QTimer* spriteTimer;
public:
    explicit Sprite(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;//move to player?
public slots:
    void nextFrame();
};

#endif // SPRITE_H
