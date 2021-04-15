#include "gameboard.h"

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-colot:black;");

    resize(m_boardSizeX, m_boardSizeY);
    initGame();
}

void GameBoard::attachSnake(Snake *newSnake){
    if (!newSnake){
        endGame("Snake doesn't exist");
    }
    m_snake = newSnake;
}

void GameBoard::attachFruite(Fruite *newFruite){
    if (!newFruite){
        endGame("Fruite doesn't exist");
    }
    m_fruite = newFruite;
}

void GameBoard::initGame()
{
    //TODO: realise init
}

void GameBoard::endGame(std::string message){

}

const int GameBoard::getBoardSizeX() const
{
    return m_boardSizeX;
}

const int GameBoard::getBoardSizeY() const
{
    return m_boardSizeY;
}
