#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "game.h"
#include "score.h"

class Enemy: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
private:
    qreal v;
    qreal r;
    QTimer * timer;
    Score *score;
public:
    Enemy(qreal y, qreal r, qreal v, Score *s,QGraphicsEllipseItem *parent=0);
public slots:
    void move();
};

#endif // ENEMY_H
