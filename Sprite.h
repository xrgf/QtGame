#ifndef SPRITE_H
#define SPRITE_H
#include"Entity.h"
#include<QVector2D>
#include<QPixmap>
#include<QPainter>
class Sprite:public Entity
{
public:
    Sprite();
    Sprite(int x,int y,const QString &filename);
    void update()override;
    void draw(QPainter*painter)override;
    void moveBy(int dx,int dy);
    //void setPos(int x,int y);
    int width()const{return pixmap.width();}
    int heigth()const{return pixmap.height();}
public:
    QVector2D position;  //位置
    QPixmap pixmap;     //图片

    QVector2D velocity; //方向

    int speed=3;  //速度

    QRect collider; //碰撞器
    
};

#endif // SPRITE_H
