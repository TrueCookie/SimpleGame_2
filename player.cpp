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

    currentFrame = 0;
    spriteImage = new QPixmap(":/new/prefix1/Sprites/bird.png");
    spriteTimer = new QTimer();
    connect(spriteTimer, &QTimer::timeout, this, &Player::nextFrame);
    spriteTimer->start(50);

    gameTimer = new QTimer();
    connect(gameTimer, &QTimer::timeout, this, &Player::flight);
    gameTimer->start(10);

    flightTime = new QTime();
    flightTime->start();
    /*fallTimer = new QTimer();
    connect(fallTimer, &QTimer::timeout, this, &Player::flight);*/
    jumpPoint = 0.0;
    delta = 0.0;
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
    if(event->key() == Qt::Key_Space){
        jump();
        /*Bullet *bullet = new Bullet();
        connect(bullet, &Bullet::collided, score, &Score::increase);
        //bullet->setPos(x()+20, y()+70);
        scene()->addItem(bullet);*/
    }
}

void Player::spawn(){
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::flight(){
    delta += flightTime->elapsed()/100;
    if(delta < jumpPoint){
        setPos(x(), jumpPoint+delta*delta/1000);
    }else{
        setPos(x(), jumpPoint+delta*delta/400000);
    }
}

void Player::jump(){
    jumpPoint = y();
    delta = jumpPoint-256;
    //delta = flightTime->currentTime().msec() - delta;
    flightTime->restart();
    /*delta += flightTime->elapsed();
    if(delta < 0){
        setPos(x(), y()+delta*delta);
    }else{
        setPos(x(), y()+delta*delta/4);
    }*/
}


int Player::getPosX(){
    return static_cast<int>(x());
}
