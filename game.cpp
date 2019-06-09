#include "game.h"
#include "player.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>


Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //setBackgroundBrush(QBrush(QImage(":/new/prefix1/Sprites/background.png")));

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800, 600);
    //create an item to put into the scene
    player = new Player();
    player->setPos(scene->height()/4, scene->height()/4);
    scene->addItem(player);

    //make rect focusible
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create the score/health
    score = new Score();
    scene->addItem(score);
    connect(this, &Game::overcomingSignal, score, &Score::increase);//!!

    //spawn enemies
    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout, player, &Player::spawn);
    timer->start(2000);

    //play background music
    /*QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BGMusic.mp3"));
    music->play();*/
}

void Game::overcoming(){
    if(player->getPosX() > 50/*firstTubeCouple*/){
        emit overcomingSignal();
    }
}
