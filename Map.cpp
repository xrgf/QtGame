#include "Map.h"
#include"Game.h"
Map::Map()
{
    ypos1=-Game::HEIGHT;
    ypos2=0;
    pixmap.load("://images/background.png");

}

void Map::update()
{


    ypos1+=speed;
    if(ypos1>=0)
    {
        ypos1=-Game::HEIGHT;
    }

    ypos2+=speed;
    if(ypos2>=Game::HEIGHT)
    {
        ypos2=0;
    }
}

void Map::draw(QPainter *painter)
{

    painter->drawPixmap(0,ypos1,pixmap);
    painter->drawPixmap(0,ypos2,pixmap);
}
