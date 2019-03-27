#ifndef SHAPEVIEWER_H
#define SHAPEVIEWER_H

#include <QWidget>

class ShapeViewer : public QWidget
{
Q_OBJECT

public:
    explicit ShapeViewer(QWidget *parent = nullptr);
    static void setHeight(int height);
    static void setWidth(int width);
    static QColor penColor() { return myPenColor; }
    static int penWidth() { return myPenWidth; }
    static void setStartAngle(int angle);
    static void setSpanAngle(int angle);
    static void setPenColor(const QColor &newColor);
    static void setPenWidth(int newWidth);

private:
    void paintEvent(QPaintEvent *event);
    void drawTriangle(QPaintDevice * dev);
    void drawSquare(QPaintDevice * dev);
    void drawCircle(QPaintDevice * dev);
    void drawHexagon(QPaintDevice * dev);
    void drawArc(QPaintDevice * dev);
    void drawImage(QPaintDevice * dev);
    void resizeImage(QImage *image, const QSize &newSize);

    static int myPenWidth;
    static int myWidth;
    static int myHeight;

    static int myStartAngle;
    static int mySpanAngle;

    static QColor myPenColor;
    QImage image;
};

#endif // SHAPEVIEWER_H
