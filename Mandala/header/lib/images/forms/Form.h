#ifndef FORM_H
#define FORM_H

#include <vector>
#include <functional>

#include <header/lib/images/Pixel.h>
#include <QtGui/QPainter>




class Form;


class FormList
{
public:
    FormList();

    void addForm(Form *f);

    void undo();
    void redo();

	void clear();

	void drawAll(QPainter &painter);

private:
    std::vector<Form*> *_data;
    int _index = 0;
    int _maxIndex = 0;
};


class Form
{
public:
    virtual void draw(QPainter &painter) = 0;
};

#endif // FORM_H
