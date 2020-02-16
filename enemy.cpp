#include "enemy.h"
#include "player.h"

#include <QTimer>
#include <QList>
#include <QGraphicsItem>

Enemy::Enemy(qreal y, qreal r, qreal v, Score *s,QGraphicsEllipseItem *parent)
    : QObject()
    , QGraphicsEllipseItem(0,0,r,r,parent)
    , v{v}
    , r{r}
    , score{s}
{
    setBrush(QBrush(Qt::red));
    setPos(X_MAX, y);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(25);
}

void Enemy::move(){
    // test for colliding with the player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for( auto &el : colliding_items) {
        if ( typeid(*el) == typeid(Player))
        {
            score->decrease(v, r);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()-v,y());
    if (pos().x() + rect().width() < 0){
        score->increase(v,r);
        scene()->removeItem(this);
        delete this;
    }
}
