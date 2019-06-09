#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class Player :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
private:
    Sprite* sprite;
};

#endif // PLAYER_H
