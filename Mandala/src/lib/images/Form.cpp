#include "header/lib/images/Form.h"

FormList::FormList() {
    data = new vector();
}

void FormList::addForm(Form *f) {
   data[index++] = f;
}

void FormList::redo() {
    if (index == data.size() - 1) {
        throw ;
    } else {
        index++;
    }
}

void FormList::undo() {

}
