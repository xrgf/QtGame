 #include "Game.h"
#include<QDebug>
#include"Sprite.h"
#include<QCloseEvent>
#include"Map.h"
#include"PlayerPlane.h"
#include"EnemyPlane.h"
#include<qrandom.h>
PlayerPlane *player;
Game::Game(QWidget *parent)
    : QWidget{parent}
{

    QTimer*timer=new QTimer(this);
    timer->callOnTimeout(this,[=]()
    {
        //更新数据
        updateGame();
        //绘图
        update();


    });
    timer->start(1000/60);//游戏是帧率60fps
}

void Game::run()
{

    this->show();
}

void Game::initGame(int w, int h, const QString &title, const QIcon &icon)
{
    setWindowTitle(title);
    setFixedSize(w,h);
    if(!icon.isNull())
    {
        setWindowIcon(icon);
    }

    player=Manager::getInstance()->addEntity(new PlayerPlane(0,0,"://images/hero1.png"));

    WIDTH=w;
    HEIGHT=h;
    map=new Map;//放在一起可能会出现覆盖飞机




}

void Game::cleanGame()
{

}

void Game::drawGame(QPainter *painter)
{
    //qInfo()<<__FUNCTION__;
    //限制飞机的范围
    map->draw(painter);

    mgr->draw(painter);

}

void Game::updateGame()
{

    mgr->refersh();
    mgr->update();
    map->update();
    if(player->position.x()+player->width()/2<0)
    {
        player->position.setX(0-player->width()/2);
    }
    if(player->position.x()>Game::WIDTH-player->width()/2)
    {
        player->position.setX(Game::WIDTH-player->width()/2);
    }
    if(player->position.y()<0)
    {
        player->position.setY(0);
    }
    if(player->position.y()>Game::HEIGHT-player->heigth())
    {
        player->position.setY(Game::HEIGHT-player->heigth());
    }
    //qInfo()<<__FUNCTION__;

     static int i=0;
    //发射子弹
    if(i%30==0)
    {
        player->fire();
    }



    //敌机出场
    if(i%60==0)
    {
        QStringList es={":/images/enemy1_down2.png",":/images/enemy2_down1.png",":/images/enemy3_down3.png"};

        auto e=mgr->addEntity(new EnemyPlane(0,0,es[QRandomGenerator::global()->bounded(0,3)]) );

        e->position.setX(QRandomGenerator::global()->bounded(Game::WIDTH));
        e->position.setY(-e->heigth());
        e->velocity.setY(1);

    }
    qInfo()<<"mgr count"<<mgr->count();

    i++;


}

void Game::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    drawGame(&painter);

}

void Game::closeEvent(QCloseEvent *ev)
{

    cleanGame();
}

void Game::keyPressEvent(QKeyEvent *ev)
{

    switch(ev->key())
    {
    case Qt::Key::Key_Up:
        player->velocity.setY(-1);
        break;
    case Qt::Key::Key_Down:
        player->velocity.setY(1);
        break;
    case Qt::Key::Key_Left:
        player->velocity.setX(-1);
        break;
    case Qt::Key::Key_Right:
        player->velocity.setX(1);
        break;


    }
}

void Game::keyReleaseEvent(QKeyEvent *ev)
{

    //player->velocity={0,0};
    //会判断松开的是那个键
    switch(ev->key())
    {
    case Qt::Key::Key_Up:
        player->velocity.setY(0);
        break;
    case Qt::Key::Key_Down:
        player->velocity.setY(0);
        break;
    case Qt::Key::Key_Left:
        player->velocity.setX(0);
        break;
    case Qt::Key::Key_Right:
        player->velocity.setX(0);
        break;


    }
}
