#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QDebug>

class Player : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Player(QGraphicsEllipseItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
