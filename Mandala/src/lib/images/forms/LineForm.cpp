//
// Created by kubiak on 19/03/19.
//

#include <lib/images/forms/LineForm.h>
#include <header/lib/images/forms/LineForm.h>

LineForm::LineForm(QColor color, QPoint &origin, QPoint &extremity) {
	this->color = color;
	this->origin = origin;
	this->extremity = extremity;
}

void LineForm::draw() {

}
