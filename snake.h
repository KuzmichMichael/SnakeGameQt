#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

class Snake
{
private:
    static constexpr const int m_cellImageSize = 10;

    enum class directions{
        RIGHT,
        LEFT,
        UP,
        DOWN
    };
    directions m_currentHeadDirection;

    struct Cell
    {
        int x;
        int y;
    };

public:
    Snake();
    ~Snake() = default;

     std::vector<Cell> wholeSnake;

     void addCell();
     void moveSnake();
     void changeDirection(int key);
};


#endif // SNAKE_H
