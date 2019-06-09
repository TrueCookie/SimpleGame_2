#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "score.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>

//extern Game *game;

Bullet::Bullet(QGraphicsItem *parent) : QObject() ,QGraphicsPixmapItem(parent){
    //drew the rect
    setPixmap(QPixmap(":/sprites/Sprites/Bullet.png"));

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);

    //connect(this, &Bullet::collide; score; &Score::increase);
}

void Bullet::collide(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i]) == typeid(Enemy)){
            emit collided();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}


void Bullet::move(){
    //if bullet collides with enemy
    //...game->score->increase();
    //move bullet up
    setPos(x(), y()-10);
    if(pos().y()+30 < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
