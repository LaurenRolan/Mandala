#include "Palette.h"
#include <QGraphicsEllipseItem>


int Palette::mySpanAngle = 120;
int Palette::myStartAngle = 30;
int Palette::myPenWidth = 3;
QColor Palette::myPenColor = QColor(Qt::black);

Palette::Palette() {
    triangle = new QGraphicsScene();
    circle = new QGraphicsScene();
    square = new QGraphicsScene();
    arc = new QGraphicsScene();
    hexagon = new QGraphicsScene();
}

void Palette::drawTriangle() {
    triangle->clear();

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPolygon polygon;
    polygon << QPoint(30, 10) << QPoint(10, 50) << QPoint(50, 50);

    triangle->addPolygon(polygon, pen);
}

void Palette::drawSquare() {
    square->clear();

    QRectF rectangle(10.0, 10.0, 40.0, 40.0);
    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    square->addRect(rectangle, pen);
}

void Palette::drawCircle() {
    circle->clear();

    QRectF rectangle(10.0, 10.0, 40.0, 40.0);
    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    circle->addEllipse(rectangle, pen);
}

void Palette::drawHexagon() {
    hexagon->clear();

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPolygon polygon;
    polygon << QPoint(20, 10) << QPoint(40, 10);
    polygon << QPoint(50, 25) << QPoint(40, 40);
    polygon << QPoint(20, 40) << QPoint(10, 25);

    hexagon->addPolygon(polygon, pen);
}

void Palette::drawArc() {
    arc->clear();

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QGraphicsEllipseItem* item = new QGraphicsEllipseItem(10.0, 10.0, 40.0, 40.0);
    item->setStartAngle(myStartAngle * 16);
    item->setSpanAngle(mySpanAngle * 16);
    item->setPen(pen);

    arc->addItem(item);
}

void Palette::drawAll(){
    drawCircle();
    drawSquare();
    drawTriangle();
    drawHexagon();
    drawArc();
}

void Palette::setPenWidth(int newWidth) { myPenWidth = newWidth; }
void Palette::setPenColor(QColor newColor) { myPenColor = newColor; }
