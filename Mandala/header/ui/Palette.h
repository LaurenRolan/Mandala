#ifndef PALETTE_H
#define PALETTE_H


#include <QGraphicsScene>

class Palette
{
public:
    Palette();
    void drawTriangle();

private:
    QGraphicsScene *square;
    QGraphicsScene *circle;
    QGraphicsScene *arc;
    QGraphicsScene *triangle;
    QGraphicsScene *hexagon;
};

#endif // PALETTE_H
