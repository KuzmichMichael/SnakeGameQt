#include "snake.h"
#include "gameboard.h"

Snake::Snake()
{
    Cell head;
    head.x = GameBoard::getBoardSizeX()/2;
    head.y = GameBoard::getBoardSizeY()/2;
    m_currentHeadDirection = directions::RIGHT;

    wholeSnake.push_back(head);
    addCell();
    addCell();
    addCell();
}

const int Snake::getCellSize()
{
    return m_cellImageSize;
}

void Snake::addCell()
{
    Cell newCell;
    newCell.x = getHead().x + m_cellImageSize;
    newCell.y = getHead().y + m_cellImageSize;

    wholeSnake.push_back(newCell);
}

const Snake::Cell Snake::getHead()
{
    if (wholeSnake.empty())
    {
        exit(123);
    }
    return wholeSnake.front();
}

void Snake::moveSnake()
{
    if (wholeSnake.empty())
    {
        return;
    }

    //move every cell
    for (auto it = wholeSnake.rbegin(); it != wholeSnake.rend(); it++)
    {
        if ((*it).x == wholeSnake.front().x && (*it).y == wholeSnake.front().y)
        {
            switch (m_currentHeadDirection)
            {
            case directions::UP:
                (*it).y -= m_cellImageSize;
                break;

            case directions::DOWN:
                (*it).y += m_cellImageSize;
                break;

            case directions::RIGHT:
                (*it).x += m_cellImageSize;
                break;

            case directions::LEFT:
                (*it).x -= m_cellImageSize;
                break;
            }
        }
        else
        {
            (*it).x = (*(it+1)).x;
            (*it).y = (*(it+1)).y;
        }
    }
}

void Snake::changeDirection(int key)
{
    if (wholeSnake.empty())
    {
        return;
    }

    switch (key)
    {
    case Qt::Key_W:
        if (m_currentHeadDirection == directions::DOWN)
        {
            break;
        }
        m_currentHeadDirection = directions::UP;
        break;

    case Qt::Key_S:
        if (m_currentHeadDirection == directions::UP)
        {
            break;
        }
        m_currentHeadDirection = directions::DOWN;
        break;

    case Qt::Key_A:
        if (m_currentHeadDirection == directions::RIGHT)
        {
            break;
        }
        m_currentHeadDirection = directions::LEFT;
        break;

    case Qt::Key_D:
        if (m_currentHeadDirection == directions::LEFT)
        {
            break;
        }
        m_currentHeadDirection = directions::RIGHT;
        break;

    default:
        break;
    }
}
