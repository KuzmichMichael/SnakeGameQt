#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QPainter>
#include <QString>
#include <QKeyEvent>

#include "snake.h"
#include "fruite.h"

class GameBoard : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard() = default;

    void attachSnake(Snake* newSnake);
    void attachFruite(Fruite* newFruite);
    void initGame();
    void endGame(QPainter &painter);
    void loadImages();

    void repaintBoard();

    static const int getBoardSizeX();
    static const int getBoardSizeY();

private: 
    Snake* m_snake;
    Fruite* m_fruite;

    static constexpr const int m_boardSizeX = 300;
    static constexpr const int m_boardSizeY = 300;

    int m_gameTimer;
    int m_delay = 100;
    bool isInGame;

    QImage m_cellImage;
    QImage m_headImage;
    QImage m_appleImage;

};

#endif // GAMEBOARD_H
