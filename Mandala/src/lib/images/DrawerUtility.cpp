//
// Created by kubiak on 19/03/19.
//

#include <lib/images/DrawerUtility.h>
#include <header/lib/images/DrawerUtility.h>
#include "header/lib/images/forms/PixelForm.h"
#include "header/lib/images/forms/LineForm.h"

DrawerUtility::DrawerUtility() {
	image = new Image();
}

void DrawerUtility::onDraw(QPoint &p) {
	this->image->drawForm(new PixelForm(color, p));
}

void DrawerUtility::drawLine(QPoint &origin, QPoint &extremity) {
	this->image->drawForm(new LineForm(color, origin, extremity));
}

void DrawerUtility::setColor(QColor &color) {
	this->color = color;
}

Image DrawerUtility::getImage() {
	return *this->image;
}

Image &DrawerUtility::getImageReference() {
	return *this->image;
}
