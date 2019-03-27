#ifndef SHAPEVIEWER_H
#define SHAPEVIEWER_H

#include <QWidget>

class ShapeViewer
{
public:
    ShapeViewer();
    void setHeight(int height);
    void setWidth(int width);
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    void drawIcon(int id);

private:
    void drawTriangle();
    void drawSquare();
    void drawCircle();
    void drawHexagon();
    void drawArc();
    void drawImage();
    void resizeImage(QImage *image, const QSize &newSize);

    int myPenWidth;
    int myWidth;
    int myHeight;

    QColor myPenColor;
    QImage image;
};

#endif // SHAPEVIEWER_H
