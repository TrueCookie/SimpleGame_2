#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem (parent){
    sprite = new Sprite();
}

void Player::keyPressEvent(QKeyEvent *event){
    qDebug() << "key is pressed";
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10, y());
        }
    }else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < scene()->width()){//width of the screen is 800
            setPos(x()+10, y());
        }
    }else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }
}

void Player::spawn(){
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spriteUpdate(){

}
