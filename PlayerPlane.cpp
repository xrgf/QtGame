#include "PlayerPlane.h"
#include"Manager.h"
#include"Bullet.h"

void PlayerPlane::fire()
{

    //添加子弹
    auto b=mgr->addEntity(new Bullet(position.x()+width()/2,position.y(),"://images/bullet1.png"));
    b->velocity.setY(-1);//让子弹像上走
}


