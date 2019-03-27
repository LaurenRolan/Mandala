#include "ShapeViewer.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <iostream>

int ShapeViewer::myPenWidth;
int ShapeViewer::myWidth;
int ShapeViewer::myHeight;
int ShapeViewer::myStartAngle;
int ShapeViewer::mySpanAngle;
QColor ShapeViewer::myPenColor;

ShapeViewer::ShapeViewer(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_StaticContents);
    myHeight = 80;
    myWidth = 80;
    myPenWidth = 5;
    mySpanAngle = 150;
    myStartAngle = 30;
}
void ShapeViewer::setHeight(int height) { myHeight = height; }
void ShapeViewer::setWidth(int width) { myWidth = width; }
void ShapeViewer::setPenColor(const QColor &newColor) { myPenColor = newColor; }
void ShapeViewer::setPenWidth(int newWidth) { myPenWidth = newWidth; }
void ShapeViewer::setStartAngle(int angle) { myStartAngle = angle; }
void ShapeViewer::setSpanAngle(int angle) { mySpanAngle = angle; }

void ShapeViewer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);

    if(QString::compare(this->accessibleName(), "Circle") == 0) {
        this->move(40, 80);
        drawCircle(this);
    }
    else if(QString::compare(this->accessibleName(), "Square") == 0) {
        this->move(160, 80);
        drawSquare(this);
    }
    else if(QString::compare(this->accessibleName(), "Triangle") == 0){
        this->move(280, 80);
        drawTriangle(this);
    }
    else if(QString::compare(this->accessibleName(), "Hexagon") == 0) {
        this->move(40, 190);
        drawHexagon(this);
    }
    else if(QString::compare(this->accessibleName(), "Arc") == 0) {
        this->move(160, 190);
        drawArc(this);
    }
    else if(QString::compare(this->accessibleName(), "Image") == 0) {
        this->move(280, 190);
        drawImage(this);
    }
}

void ShapeViewer::drawTriangle(QPaintDevice * dev) {
    QPainter painter(dev);

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QPolygon polygon;
    polygon << QPoint(40, 10) << QPoint(10, 70) << QPoint(70, 70);
    painter.setPen(pen);
    painter.drawPolygon(polygon);
}
void ShapeViewer::drawSquare(QPaintDevice * dev) {
    QPainter painter(dev);
    QRectF rectangle(5.0, 5.0, 70.0, 70.0);
    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawRect(rectangle);
}
void ShapeViewer::drawCircle(QPaintDevice * dev) {
    QPainter painter(dev);
    QRectF rectangle(5.0, 5.0, 70.0, 70.0);
    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawEllipse(rectangle);
}
void ShapeViewer::drawHexagon(QPaintDevice * dev) {
    QPainter painter(dev);

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QPolygon polygon;
    polygon << QPoint(25, 8) << QPoint(55, 8);
    polygon << QPoint(73, 39) << QPoint(55, 72);
    polygon << QPoint(25, 72) << QPoint(7, 39);
    painter.setPen(pen);
    painter.drawPolygon(polygon);
}
void ShapeViewer::drawArc(QPaintDevice * dev) {
    QRectF rectangle(10.0, 10.0, 70.0, 70.0);
    int startAngle = myStartAngle * 16;
    int spanAngle = mySpanAngle * 16;

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QPainter painter(dev);
    painter.setPen(pen);
    painter.drawArc(rectangle, startAngle, spanAngle);
}
void ShapeViewer::drawImage(QPaintDevice * dev) {

}
void ShapeViewer::resizeImage(QImage *image, const QSize &newSize) {

}
