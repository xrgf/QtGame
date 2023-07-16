#ifndef MANAGER_H
#define MANAGER_H

#include"Entity.h"
#include<QSet>
#include<QPainter>
#include<QDebug>
#define mgr Manager::getInstance()
class Manager
{
public:

    template<typename T>
    T*addEntity(T*e)
    {
        entitys.insert(e);
        return e;
    }
    void update()
    {
        for(auto&e:entitys)
        {
            e->update();
        }
    }
    void draw(QPainter*painter)
    {
        for(auto&e:entitys)
        {
            e->draw(painter);
        }
    }
    qsizetype count()const{return entitys.count();}
    void refersh()
    {
        entitys.removeIf([](Entity*e)
         {
            if(!e->isActive())//被销毁了就是!假
            {

                delete e;
                qInfo()<<"destory";
                return true;
            }

            return false;
        });
    }
public:
    //获取管理的单例
    static Manager*getInstance()
    {
        static Manager*ins=nullptr;
        if(!ins)
        {
            ins=new Manager;
        }
        return ins;
    }
private:
    QSet<Entity*>entitys; //所有实体
    Manager(){};

};

#endif // MANAGER_H
