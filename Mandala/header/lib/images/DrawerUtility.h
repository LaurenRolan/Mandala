//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_DRAWERUTILITY_H
#define MANDALA_DRAWERUTILITY_H

#include <QPoint>

#include "Image.h"

#include "Drawable.h"

class DrawerUtility : Drawable {
public:
	DrawerUtility();
	void onDraw(QPoint &p) override;
	void drawLine(QPoint &origin, QPoint &extremity) override;
	void setColor(QColor &color) override;
	Image  getImage();
	Image& getImageReference();
private:
	QColor color;
	Image *image;
};


#endif //MANDALA_DRAWERUTILITY_H
