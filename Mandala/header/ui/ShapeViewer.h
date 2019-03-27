#ifndef SHAPEVIEWER_H
#define SHAPEVIEWER_H

#include <QWidget>

class ShapeViewer : public QWidget
{
Q_OBJECT

public:
    explicit ShapeViewer(QWidget *parent = nullptr);
    void setHeight(int height);
    void setWidth(int width);
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

private:
    void paintEvent(QPaintEvent *event);
    void drawTriangle(QPaintDevice * dev);
    void drawSquare(QPaintDevice * dev);
    void drawCircle(QPaintDevice * dev);
    void drawHexagon(QPaintDevice * dev);
    void drawArc(QPaintDevice * dev);
    void drawImage(QPaintDevice * dev);
    void resizeImage(QImage *image, const QSize &newSize);

    int myPenWidth;
    int myWidth;
    int myHeight;

    QColor myPenColor;
    QImage image;
};

#endif // SHAPEVIEWER_H
