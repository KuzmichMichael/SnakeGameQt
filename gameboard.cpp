#include "gameboard.h"

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:black;");
    resize(m_boardSizeX, m_boardSizeY);
    loadImages();

    isInGame = true;
    initGame();
}

void GameBoard::loadImages()
{
    m_appleImage.load(":/gameImages/images/apple.png");
    m_headImage.load(":/gameImages/images/head.png");
    m_cellImage.load(":/gameImages/images/cell.png");

}

void GameBoard::initGame()
{
    //TODO: realise init

    m_gameTimer = startTimer(m_delay);
}

void GameBoard::timerEvent(QTimerEvent *e)
{

    Q_UNUSED(e);

    if (isInGame)
    {
        if (isSnakeEatApple()) {
            m_snake->addCell();
            m_fruite->relocateFruite();
        }
        //checkCollision();
        m_snake->moveSnake();
    }

    repaint();
}

void GameBoard::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    repaintBoard();
}

void GameBoard::repaintBoard()
{
    QPainter qp(this);

    if (isSnakeBiteItself || isSnakeOutside){
       isInGame = false;
       endGame(qp);
    }

    if (isInGame)
    {
        //TODO fruite
        qp.drawImage(m_fruite->coordX, m_fruite->coordY, m_appleImage);
        for (auto it : m_snake->wholeSnake)
        {
            if(it.x == m_snake->wholeSnake.front().x && it.y == m_snake->wholeSnake.front().y)
            {
               qp.drawImage(it.x, it.y, m_headImage);
            }
            else
            {
               qp.drawImage(it.x, it.y, m_cellImage);
            }
        }

    }
    else
    {
        endGame(qp);
    }
}

void GameBoard::endGame(QPainter &qp)
{
       QString message = "GameOver";
       QFont font("Courier", 15, QFont::DemiBold);
       QFontMetrics fm(font);

       int textWidth = fm.maxWidth() * message.length();

       qp.setPen(QColor(Qt::white));
       qp.setFont(font);
       int h = height();
       int w = width();

       qp.translate(QPoint(w/2, h/2));
       qp.drawText(-textWidth/2, 0, message);
}

void GameBoard::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    m_snake->changeDirection(key);

    QWidget::keyPressEvent(e);
}

void GameBoard::attachSnake(Snake *newSnake)
{
    if (!newSnake){
        //endGame("Snake doesn't exist");
    }
    m_snake = newSnake;
    isSnakeExist = true;
}

void GameBoard::attachFruite(Fruite *newFruite){
    if (!newFruite){
       //endGame("Fruite doesn't exist");
    }
    m_fruite = newFruite;
    m_fruite->gridSize = m_snake->getCellSize();
}

const bool GameBoard::isSnakeBiteTail()
{
    for (auto it = m_snake->wholeSnake.begin() + 1; it != m_snake->wholeSnake.end(); it++)
    {
        if(it->x == m_snake->getHead().x && it->y == m_snake->getHead().y)
        {
           isSnakeBiteItself = true;
           return true;
        }
    }

    return false;
}

const bool GameBoard::isSnakeEatApple()
{
    if ((m_snake->getHead().x > (m_fruite->coordX - 5)) && (m_snake->getHead().x < (m_fruite->coordX + 5)) &&
        (m_snake->getHead().y > (m_fruite->coordY - 5)) && (m_snake->getHead().y < (m_fruite->coordY + 5)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

const bool GameBoard::isSnakeOutOfBounds()
{
    if((m_snake->getHead().x > m_boardSizeX || m_snake->getHead().x < 0) ||
       (m_snake->getHead().y > m_boardSizeY || m_snake->getHead().y < 0)){
        isSnakeOutside = true;
        return true;
    }

    return false;
}

const int GameBoard::getBoardSizeX()
{
    return m_boardSizeX;
}

const int GameBoard::getBoardSizeY()
{
    return m_boardSizeY;
}
