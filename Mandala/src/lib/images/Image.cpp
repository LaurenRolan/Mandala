
#include <lib/images/Image.h>

Image::Image()
{
    _forms = new FormList();
}

void Image::drawForm(Form *f) {
    _forms->addForm(f);
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


