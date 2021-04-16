#include "gameboard.h"

//Не рисует


GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:black;");

    resize(m_boardSizeX, m_boardSizeY);
    loadImages();
    initGame();
}

void GameBoard::attachSnake(Snake *newSnake){
    if (!newSnake){
        //endGame("Snake doesn't exist");
    }
    m_snake = newSnake;
}

void GameBoard::attachFruite(Fruite *newFruite){
    if (!newFruite){
       //endGame("Fruite doesn't exist");
    }
    m_fruite = newFruite;
}

void GameBoard::initGame()
{
    //TODO: realise init

    m_gameTimer = startTimer(m_delay);
}

void GameBoard::endGame(QPainter &qp){
       QString message = "message";
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

void GameBoard::loadImages()
{
    m_appleImage.load(":/gameImages/images/apple.png");
    m_headImage.load(":/gameImages/images/head.png");
    m_cellImage.load(":/gameImages/images/cell.png");

}

void GameBoard::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (isInGame) {

        //checkApple();
        //checkCollision();
        m_snake->moveSnake();
    }

    repaint();
}

void GameBoard::keyPressEvent(QKeyEvent *e) {

    int key = e->key();
    m_snake->changeDirection(key);

    QWidget::keyPressEvent(e);
}

void GameBoard::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    repaintBoard();
}


void GameBoard::repaintBoard() {

    QPainter qp(this);

    if (isInGame) {

        //TODO fruite
        //qp.drawImage(fruite_x, fruite_y, m_appleImage);

        for (auto it : m_snake->wholeSnake){
            if(it.x == m_snake->wholeSnake.front().x && it.y == m_snake->wholeSnake.front().y){
               qp.drawImage(it.x, it.y, m_headImage);
            }
            else{
               qp.drawImage(it.x, it.y, m_cellImage);
            }
        }

    } else {

        endGame(qp);
    }
}

const int GameBoard::getBoardSizeX()
{
    return m_boardSizeX;
}

const int GameBoard::getBoardSizeY()
{
    return m_boardSizeY;
}
