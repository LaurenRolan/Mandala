
#include <lib/images/Image.h>

Image::Image()
{
    _forms = new FormList();
    dimension = QPoint(0, 0);
}

void Image::drawForm(Form *f) {
    _forms->addForm(f);
}

void Image::setDimension(int w, int h) {
	dimension = QPoint(w, h);
}

const QPoint &Image::getDimension() const {
	return dimension;
}

void Image::undo() {
	_forms->undo();
}

void Image::redo() {
	_forms->redo();
}

void Image::clear() {
	_forms->clear();
}

void Image::drawAll(QPainter &painter) {
	_forms->drawAll(painter);
}


