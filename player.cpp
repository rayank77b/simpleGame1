#include "player.h"
#include "game.h"

#include <iostream>


Player::Player(QGraphicsEllipseItem *parent)
    : QObject()
    , QGraphicsEllipseItem(0,0,20,20,parent)
{
    setBrush(QBrush(Qt::green));
    setPos(100,400);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //std::cout << x() << "|"<<y()<< std::endl;
    if ( event->key() == Qt::Key_Left ) {
        if ( x() > 15 )
            setPos(x()-15, y());
    } else if ( event->key() == Qt::Key_Right ) {
        if ( x() < X_MAX-35 )
            setPos(x()+15, y());
    } else if ( event->key() == Qt::Key_Up ) {
        if ( y() > 15 )
            setPos(x(), y()-15);
    } else if ( event->key() == Qt::Key_Down ) {
        if ( y() < Y_MAX-35 )
            setPos(x(), y()+15);
    }
}
