#ifndef IMAGE_H
#define IMAGE_H



#include <lib/images/Form.h>

class Image
{
public:
    Image();

    void drawForm(Form *f);
private:
    FormList *_forms;

};

#endif // IMAGE_H
