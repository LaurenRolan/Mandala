#include "ShapeViewer.h"
#include <QPainter>
#include <QPen>
#include <iostream>

ShapeViewer::ShapeViewer(QWidget *parent) : QWidget(parent) {
    myHeight = 80;
    myWidth = 80;
    myPenWidth = 5;
}
void ShapeViewer::setHeight(int height) { myHeight = height; }
void ShapeViewer::setWidth(int width) { myWidth = width; }
void ShapeViewer::setPenColor(const QColor &newColor) { }
void ShapeViewer::setPenWidth(int newWidth) { myPenWidth = newWidth; }

void ShapeViewer::paintEvent(QPaintEvent *event) {
    std::cerr << this->accessibleName().toStdString() << std::endl;
    if(QString::compare(this->accessibleName(), "Triangle") == 0)
        drawTriangle(this);
    if(QString::compare(this->accessibleName(), "Circle") == 0)
        drawCircle(this);
}

void ShapeViewer::drawTriangle(QPaintDevice * dev) {
    QPainter painter(dev);

    dev->

    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QPolygon polygon;
    polygon << QPoint(40, 10) << QPoint(10, 70) << QPoint(70, 70);
    painter.setPen(pen);
    painter.drawPolygon(polygon);
}
void ShapeViewer::drawSquare(QPaintDevice * dev) {

}
void ShapeViewer::drawCircle(QPaintDevice * dev) {
    QPainter painter(dev);
    QRectF rectangle(10.0, 10.0, 70.0, 70.0);
    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawEllipse(rectangle);
}
void ShapeViewer::drawHexagon(QPaintDevice * dev) {

}
void ShapeViewer::drawArc(QPaintDevice * dev) {

}
void ShapeViewer::drawImage(QPaintDevice * dev) {

}
void ShapeViewer::resizeImage(QImage *image, const QSize &newSize) {

}
