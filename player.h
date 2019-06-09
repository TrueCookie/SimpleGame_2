#ifndef PLAYER_H
#define PLAYER_H

#include "score.h"
//#include "sprite.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

class Player :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
public slots:
    void spawn();
    void nextFrame();
private:
    Score* score;

    int width, height;
    int currentFrame;
    QPixmap* spriteImage;
    QTimer* spriteTimer;
};

#endif // PLAYER_H
