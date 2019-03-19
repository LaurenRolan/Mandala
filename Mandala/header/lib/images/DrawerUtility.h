//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_DRAWERUTILITY_H
#define MANDALA_DRAWERUTILITY_H

#include <QImage>

#include "Pixel.h"
#include "Image.h"

class DrawerUtility {
public:
	DrawerUtility();
	void onDrawEvent(Point &p);
	void setColor(QColor &color);
	QImage  getImage();
	QImage& getImageReference();
private:

};


#endif //MANDALA_DRAWERUTILITY_H
