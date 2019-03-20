#include "header/lib/images/forms/Form.h"

FormList::FormList() {
    _data = new std::vector<Form*>();
}

void FormList::addForm(Form *f) {
    _maxIndex = _index;
    _data->insert(_data->begin() + _index++, f);

}

void FormList::redo() {
    if (_index > _maxIndex) {
        //throw "Can't redo the action if there is no action to redo";
    } else {
        _index++;
    }
}

void FormList::undo() {
    if (_index == 0) {
        //throw "Can't undo the action if there is no action to undo";
    } else {
        _index--;
    }
}

void FormList::clear() {
    _data->clear();
    _index = 0;
    _maxIndex = 0;
}

void FormList::drawAll(QPainter &painter) {

    for (int i = 0; i < _index; i++) {
        (*_data)[i]->draw(painter);
    }
    /*
	for(auto *f :  *_data) {
		f->draw(painter);
	}*/
}
