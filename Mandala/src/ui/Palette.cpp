#include "Palette.h"
#include <QGraphicsEllipseItem>
#include <iostream>
#include <QStyleOptionGraphicsItem>

int Palette::mySpanAngle = 120;
int Palette::myStartAngle = 30;
int Palette::myPenWidth = 3;
QColor Palette::myPenColor = QColor(Qt::blue);

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
    QGraphicsEllipseItem* arcDraw = new QGraphicsEllipseItem(10.0, 10.0, 40.0, 40.0);
    arcDraw->setStartAngle(myStartAngle * 16);
    arcDraw->setSpanAngle(mySpanAngle * 16);
    arcDraw->setPen(pen);
    arc->addItem(arcDraw);
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

QPixmap Palette::QPixmapFromItem(QGraphicsItem * item){
    QPixmap pixmap(QSize(60, 60));
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QStyleOptionGraphicsItem opt;
    item->paint(&painter, &opt);
    return pixmap;
}
