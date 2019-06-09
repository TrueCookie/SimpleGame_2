#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem (parent){
    width = 41;
    height = 28;

    score = new Score();
    //scene()->addItem(score);

    currentFrame = 0;
    spriteImage = new QPixmap(":/new/prefix1/Sprites/bird.png");
    spriteTimer = new QTimer();
    connect(spriteTimer, &QTimer::timeout, this, &Player::nextFrame);
    spriteTimer->start(300);

    //connect(bullet, &Bullet::collide; score; &Score::increase);
}

QRectF Player::boundingRect() const{
    return QRectF(pos().x(), pos().y(), width, height);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(static_cast<int>(pos().x()), static_cast<int>(pos().y()), *spriteImage, currentFrame, 0, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Player::nextFrame(){
    currentFrame += width;
    if (currentFrame >= 3*width){ currentFrame = 0;}
    this->update(pos().x(), pos().y(), width, height);
}

void Player::keyPressEvent(QKeyEvent *event){
    qDebug() << "key is pressed";
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10, y());
        }
    }else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < scene()->width()){
            setPos(x()+10, y());
        }
    }else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        connect(bullet, &Bullet::collided, score, &Score::increase);
        bullet->setPos(x()+20, y()+70);
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
