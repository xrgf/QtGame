#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H


#include"Sprite.h"
class EnemyPlane:public Sprite
{
public:
    EnemyPlane();
    using Sprite::Sprite;
    void update()override;
};

#endif // ENEMYPLANE_H
