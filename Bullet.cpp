#include "Bullet.h"

#include<QDebug>

void Bullet::update()
{

    if(Bullet::position.y()+width()<0)
    {
        destory();

    }

    Sprite::update();
}
