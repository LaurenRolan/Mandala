#ifndef IMAGE_H
#define IMAGE_H


#include <header/lib/images/forms/Form.h>

class Image
{
public:
    Image();

    void drawForm(Form *f);

    void undo();
    void redo();

	void clear();

	void drawAll(QPainter &painter);

private:
    FormList *_forms;


};

#endif // IMAGE_H
