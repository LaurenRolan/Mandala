//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_DRAWABLE_H
#define MANDALA_DRAWABLE_H

#include <QPoint>
#include <QImage>

#include "Image.h"

class Drawable {
public:
	virtual void drawLine(QPoint &origin, const QPoint &extremity) = 0;
    virtual void drawPixmap(QPoint &origin, QPixmap & pixmap) = 0;
	virtual void setColor(QColor &color) = 0;
	virtual void setPenWidth(int penWidth) = 0;
	virtual void clear() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;

	virtual void beginForm() = 0;
	virtual void endForm() = 0;

	virtual QImage & getResult(int width, int height) = 0;

	virtual void setInitialImage(QImage *image) = 0;
	virtual void setBackgroundColor (QColor color) = 0;
};


#endif //MANDALA_DRAWABLE_H
