#ifndef MAP_H
#define MAP_H
#include"Entity.h"
#include<QPainter>

class Map:public Entity
{
public:
    Map();
    void update()override;
    void draw(QPainter*painter)override;
private:
    QPixmap pixmap;
    int ypos1;
    int ypos2;
    int speed=2;
};

#endif // MAP_H
