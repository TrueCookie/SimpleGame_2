#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent = nullptr);
    void collide();
public slots:
    void move();
signals:
    void collided();
};

#endif // BULLET_H
