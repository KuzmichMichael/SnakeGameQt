#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

class Snake //TODO: realise methods
{


public:
    Snake();
    ~Snake() = default;

private:
    enum class directions{
        RIGHT,
        LEFT,
        UP,
        DOWN
    };

    struct Cell
    {
        int x;
        int y;
    };

    std::vector<Cell> m_wholeSnake;

    directions m_currentHeadDirection = directions::RIGHT;

    void addCell();
    void moveSnake();
};


#endif // SNAKE_H
