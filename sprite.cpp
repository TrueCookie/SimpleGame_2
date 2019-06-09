#include "sprite.h"

Sprite::Sprite(QObject *parent): QObject(parent), QGraphicsItem(){
    x = -10; y = -10; width = 41; height = 28;

    currentFrame = 0;
    spriteImage = new QPixmap(":/new/prefix1/Sprites/bird.png");

    spriteTimer = new QTimer();
    connect(spriteTimer, &QTimer::timeout, this, &Sprite::nextFrame);

    spriteTimer->start(25);   // Запускаем спрайт на генерацию сигнала с периодичность 25 мс
}

QRectF Sprite::boundingRect() const{
    return QRectF(x, y, width, height);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(x, y, *spriteImage, currentFrame, 0, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Sprite::nextFrame(){
    currentFrame += width;
    if (currentFrame >= 123 ){ currentFrame = 0;}
    this->update(x, y, width, height);
}
