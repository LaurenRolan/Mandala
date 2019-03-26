//
// Created by kubiak on 19/03/19.
//

#include <lib/images/DrawerUtility.h>
#include <lib/images/forms/PixelForm.h>
#include <lib/images/forms/LineForm.h>
#include <header/lib/images/DrawerUtility.h>
#include <iostream>


DrawerUtility::DrawerUtility() {
	image = new Image();
	currentFormSet = nullptr;
	initialImage = nullptr;

}

void DrawerUtility::onDraw(QPoint &p) {
	drawForm(new PixelForm(color, p));
}

void DrawerUtility::drawLine(QPoint &origin, const QPoint &extremity) {

	drawForm(new LineForm(color, penWidth, origin, extremity));
}

void DrawerUtility::setColor(QColor &color) {
	this->color = color;
}

void DrawerUtility::beginForm() {
	if(currentFormSet != nullptr) {
		//throw "Already a form set initialized";
	}

	currentFormSet = new FormSet();
}

void DrawerUtility::endForm() {
	if (currentFormSet == nullptr) {
		//throw "No form set initialized";
	}

	image->drawForm(currentFormSet);
	currentFormSet = nullptr;
}

QImage & DrawerUtility::getResult(int width, int height) {


	QImage *image = nullptr;
	if(!initialImage) {
		image = new QImage(width, height, QImage::Format_RGB32);
		image->fill(qRgb(255, 255, 255));
	} else {
		image = new QImage(*initialImage);
	}


	QPainter painter(image);

	this->image->drawAll(painter);

	return *image;
}

void DrawerUtility::drawForm(Form *f) {
	if (currentFormSet == nullptr) {
		image->drawForm(f);
	} else {
		currentFormSet->addForm(f);
	}
}

void DrawerUtility::clear() {
	image->clear();
}

void DrawerUtility::setPenWidth(int penWidth) {
	DrawerUtility::penWidth = penWidth;
}

void DrawerUtility::undo() {
	image->undo();
}

void DrawerUtility::redo() {
	image->redo();
}

void DrawerUtility::setInitialImage(QImage *image) {
	initialImage = image;
}
