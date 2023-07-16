#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include<QIcon>
#include"Manager.h"
#include<QPainter>
#include<QTimer>
#include<QKeyEvent>
#include"Map.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    //运行游戏
    void run();
    //初始化游戏
    void initGame(int w,int h,const QString &title,const QIcon&icon=QIcon());
    //清空游戏
    void cleanGame();
    //绘制游戏
    void drawGame(QPainter*painter);
    //更新游戏
    void updateGame();
protected:
    void paintEvent(QPaintEvent*ev)override;
    void closeEvent(QCloseEvent*ev)override;
    void keyPressEvent(QKeyEvent*ev)override;
    void keyReleaseEvent(QKeyEvent*ev)override;
private:

    Map *map;
public:
    inline static int  WIDTH;
    inline static int  HEIGHT;




};

#endif // GAME_H
