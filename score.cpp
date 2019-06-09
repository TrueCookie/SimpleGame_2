#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    scoreNum = 0;

    setPlainText(QString("Score: ") + QString::number(scoreNum));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(){
    scoreNum++;
    setPlainText(QString("Score: ") + QString::number(scoreNum));
}

int Score::getScore(){
    return scoreNum;
}
