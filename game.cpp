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

    setBackgroundBrush(QBrush(QImage(":/new/prefix1/Sprites/background.png")));

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800, 600);

    //create an item to put into the scene
    player = new Player();
    //setPixmap(QPixmap(":/sprites/Sprites/Player.png"));

    //player->setPos(view->width()/2, view->height()-185);
    player->setPos(64, 64);

    //add the item to the scene
    scene->addItem(player);

    //make rect focusible
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create the score/health
    //score = new Score();
    //scene->addItem(score);

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, player, &Player::spawn);
    timer->start(2000);

    //play background music
    /*QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BGMusic.mp3"));
    music->play();*/

    //show();
}
