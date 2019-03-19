#ifndef IMAGE_H
#define IMAGE_H


#include <header/lib/images/forms/Form.h>

class Image
{
public:
    Image();

    void drawForm(Form *f);
private:
    FormList *_forms;

};

#endif // IMAGE_H
