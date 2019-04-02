#ifndef PALETTE_H
#define PALETTE_H

#include <QColor>
#include <QFrame>
#include <QPixmap>
#include "IconsView.h"

class Palette : public QFrame
{
public:
    Palette();
    static void setPenWidth(int newWidth);
    static void setPenColor(QColor newColor);
    static QPixmap QPixmapFromItem(QGraphicsItem * item);
    void drawAll();

    QGraphicsScene *square;
    QGraphicsScene *circle;
    QGraphicsScene *arc;
    QGraphicsScene *triangle;
    QGraphicsScene *hexagon;

private:
    void drawTriangle();
    void drawSquare();
    void drawCircle();
    void drawArc();
    void drawHexagon();

    static int myStartAngle;
    static int mySpanAngle;

    static int myPenWidth;
    static QColor myPenColor;

};

#endif // PALETTE_H
