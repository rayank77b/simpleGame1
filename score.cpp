#include "score.h"

Score::Score(QGraphicsItem *parent)
    : QGraphicsTextItem(parent),
      score{0}
{
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(qreal v, qreal r)
{
    score = score + v*r;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::decrease(qreal v, qreal r)
{
    score = score - 3*v*r;
    setPlainText(QString("Score: ") + QString::number(score));
}
