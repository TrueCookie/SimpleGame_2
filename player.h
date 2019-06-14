#ifndef PLAYER_H
#define PLAYER_H

#include "score.h"
//#include "sprite.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include <QTime>

class Player :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    int getPosX();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
public slots:
    void spawn();
    void nextFrame();
    void flight();
    void jump();
private:
    Score* score;
    int width, height;
    int currentFrame;
    QPixmap* spriteImage;
    QTimer* spriteTimer;
    QTimer* gameTimer;
    //QTimer* fallTimer;
    QTime* flightTime;
    double jumpPoint;
    double delta;

    double velocity0;
    double sina;
    double time;
    double g;
    double heightFlight;
};

#endif // PLAYER_H
