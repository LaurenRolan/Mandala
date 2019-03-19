//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_DRAWABLE_H
#define MANDALA_DRAWABLE_H

#include <QPoint>

#include "Image.h"

class Drawable {
	virtual void onDraw(QPoint &p) = 0;
	virtual void drawLine(QPoint &origin, QPoint &extremity) = 0;
	virtual void setColor(QColor &color) = 0;
};


#endif //MANDALA_DRAWABLE_H
