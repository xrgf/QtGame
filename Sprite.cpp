#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(int x, int y, const QString &filename)
    :position(x,y)
{
    pixmap.load(filename);

}

void Sprite::update()
{

    //position+=QVector2D(1,1);
    position+=speed*velocity;
    collider=QRect(position.toPoint(),pixmap.size());
}

void Sprite::draw(QPainter *painter)
{

    painter->drawPixmap(position.toPoint(),pixmap);
}

void Sprite::moveBy(int dx, int dy)
{

    position+=QVector2D(dx,dy);
}


