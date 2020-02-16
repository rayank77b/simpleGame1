#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRandomGenerator>

#include "player.h"
#include "score.h"

const int X_MAX = 1000;
const int Y_MAX = 800;

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    QTimer * timer;
    QRandomGenerator *generator;
    Score *score;
public:
    QGraphicsScene *scene;
    Player *player;
public:
     Game(QWidget * parent=0);

public slots:
     void spawnEnemy();
};

#endif // GAME_H
