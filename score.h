#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class Score : public QGraphicsTextItem
{
    int score;
public:
    Score(QGraphicsItem * parent=0);
    void increase(qreal v, qreal r);
    void decrease(qreal v, qreal r);
};


#endif // SCORE_H
