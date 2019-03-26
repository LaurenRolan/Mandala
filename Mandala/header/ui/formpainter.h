#ifndef FORMPAINTER_H
#define FORMPAINTER_H

#include <QObject>
#include <QWidget>

class FormPainter : public QWidget
{
    Q_OBJECT
public:
    explicit FormPainter(QWidget *parent = 0);
    void setPenColor(const QColor &newColor);
    void setHeight(int height);
    void setWidth(int width);
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }
    const QColor &getMyPenColor() const { return myPenColor; }

signals:

public slots:

private:
    int myWidth;
    int myHeight;
    QColor myPenColor;
    int myPenWidth;
};

#endif // FORMPAINTER_H
