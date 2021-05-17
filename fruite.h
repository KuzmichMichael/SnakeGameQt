#ifndef FRUITE_H
#define FRUITE_H


class Fruite
{
public:
    Fruite();
    ~Fruite() = default;

    void relocateFruite();

    int coordX;
    int coordY;

    int coordBuffer;
    int remainderBuffer;

    int gridSize;
};

#endif // FRUITE_H
