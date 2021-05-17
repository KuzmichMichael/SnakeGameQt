#include "gameboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Snake snake;
    Fruite fruite;
    GameBoard board;

    board.attachSnake(&snake);
    board.attachFruite(&fruite);

    board.setWindowTitle("Snake Game");
    board.show();

    return a.exec();
}
