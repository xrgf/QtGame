#include "EnemyPlane.h"
#include"Game.h"
EnemyPlane::EnemyPlane()
{

}

void EnemyPlane::update()
{

    if(position.y()>Game::HEIGHT)
    {
        destory();

    }

    Sprite::update();//不使用父类里面的更新函数你子类没有这个函数就不能使用父类更新函数里面的操作
}
