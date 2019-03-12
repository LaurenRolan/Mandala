#include "header/lib/images/Image.h"

Image::Image()
{
    _forms = new FormList();
}

void Image::drawForm(Form *f) {
    _forms->addForm(f);
}

