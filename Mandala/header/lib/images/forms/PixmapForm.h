#ifndef PIXMAPFORM_H
#define PIXMAPFORM_H

#include "header/lib/images/forms/Form.h"

class PixmapForm : public Form {
public:
    PixmapForm(QColor color, QPixmap pixmap, QPoint origin);
    void draw(QPainter &painter) override;

private:
    QColor color;
    QPoint origin;
    QPixmap pixmap;
};

#endif // PIXMAPFORM_H
