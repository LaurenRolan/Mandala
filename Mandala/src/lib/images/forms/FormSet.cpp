//
// Created by kubiak on 20/03/19.
//

#include <header/lib/images/forms/FormSet.h>

#include "header/lib/images/forms/FormSet.h"

void FormSet::draw(QPainter &painter) {
	for (auto &it : *set) {
		it->draw(painter);
	}
}

void FormSet::addForm(Form *f) {
	set->emplace_back(f);
}

FormSet::FormSet() {
	set = new std::vector<Form *>();
}

