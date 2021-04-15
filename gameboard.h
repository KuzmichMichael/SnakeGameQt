#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include "snake.h"
#include "fruite.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard() = default;

    void attachSnake(Snake* newSnake);
    void attachFruite(Fruite* newFruite);
    void initGame();
    void endGame(std::string message);

    const int getBoardSizeX() const;
    const int getBoardSizeY() const;

private:
    Snake* m_snake;
    Fruite* m_fruite;

    static constexpr const int m_boardSizeX = 300;
    static constexpr const int m_boardSizeY = 300;


};

#endif // GAMEBOARD_H
