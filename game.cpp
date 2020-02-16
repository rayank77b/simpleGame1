#include "game.h"
#include "enemy.h"

#include <QGraphicsLineItem>
#include <iostream>
#include <QtMath>
#include <QTimer>
#include <time.h>

Game::Game(QWidget *parent)
{
    generator = new QRandomGenerator();
    generator->seed(time(NULL));

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,X_MAX,Y_MAX);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(X_MAX,Y_MAX);

    // draw the midle
    QGraphicsLineItem *line = new QGraphicsLineItem(0,Y_MAX/2+10, X_MAX, Y_MAX/2+10);
    scene->addItem(line);

    // create the score
    score = new Score();
    scene->addItem(score);

    player = new Player();
    scene->addItem(player);

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    timer->start(1000);

    show();
}

void Game::spawnEnemy()
{
    qreal y = static_cast<qreal>(generator->bounded(0,Y_MAX));
    qreal r = static_cast<qreal>(generator->bounded(30, 300));
    qreal v = static_cast<qreal>(generator->bounded(1, 15));

    Enemy *enemy = new Enemy(y,r, v, score);
    scene->addItem(enemy);

    qreal py = qFabs(player->pos().y() - Y_MAX/2);

    score->decrease(py,0.33);

    if ( timer->interval() > 750)
        timer->setInterval(timer->interval()-10);
}
