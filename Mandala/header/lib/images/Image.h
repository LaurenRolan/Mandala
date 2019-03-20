#ifndef IMAGE_H
#define IMAGE_H


#include <header/lib/images/forms/Form.h>

class Image
{
public:
    Image();

    void drawForm(Form *f);
    void setDimension(int w, int h);

    void undo();
    void redo();

	const QPoint &getDimension() const;

	void clear();

	void drawAll(QPainter &painter);

private:
    FormList *_forms;
    QPoint dimension;

};

#endif // IMAGE_H
