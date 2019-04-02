#include "header/lib/images/forms/PixmapForm.h"

PixmapForm::PixmapForm(QColor color, QPixmap pixmap, QPoint origin) :
    color(color), pixmap(pixmap), origin(origin)
{ }

void PixmapForm::draw(QPainter &painter) {
    painter.drawPixmap(origin, pixmap);
}

