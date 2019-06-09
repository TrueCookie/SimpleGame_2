#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent = nullptr);
    int getScore();
public slots:
    void increase();
private:
    int scoreNum;
};

#endif // SCORE_H
