#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>

extern Game* game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent){
    //drew the enemy
    setPixmap(QPixmap(":/sprites/Sprites/tube.png"));
    //setTransformOriginPoint(184, 185);
    //setRotation(180);
    setScale(0.5);

    //set random position
    setPos(680,350);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    //move enemy down
    setPos(x()-5, y());

    //delete the enemy
    if(pos().x() < -this->pixmap().width()){
        //decrease the health
        //game->health->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy deleted";
    }
}

