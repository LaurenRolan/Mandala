#ifndef MANDALAPAINTER_H
#define MANDALAPAINTER_H

#include <QWidget>
#include <QMouseEvent>
#include <header/lib/images/Drawable.h>

class MandalaPainter : public QWidget
{
    Q_OBJECT

public:
    explicit MandalaPainter(QWidget *parent = nullptr);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    void setHeight(int height);
    void setWidth(int width);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage();
    void print();
    void setSlices(int newNumberSlices);
	void setColorTurning(int colorTurning);

	void setHasToShowGrid(int hasToShowGrid);

	void setGridIntensity(int gridIntensity);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void drawLine(QPoint &beginPoint, const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool scribbling;
    int myPenWidth;
    int numberSlices;
    int myWidth;
    int myHeight;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;


    Drawable *drawable;

	bool colorTurning;

	bool hasToShowGrid;
	int gridIntensity;

	void drawGrid(QPainter &painter);
};

#endif // MANDALAPAINTER_H
