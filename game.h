#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "player.h"
#include "score.h"

class Game : public QGraphicsView{
public:
    Game(QWidget *parent = nullptr);
    void overcoming();

    QGraphicsScene *scene;  //make it all private
    Player *player;
    Score *score;
signals:
    void overcomingSignal();
};

#endif // GAME_H
