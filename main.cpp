#include "gameboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameBoard board;

    board.setWindowTitle("Snake Game");
    board.show();

    return a.exec();
}
