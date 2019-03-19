#ifndef FORM_H
#define FORM_H

#include <vector>
#include <functional>

#include <lib/images/Pixel.h>

typedef std::function<void(void)> drawer;


class Form;


class FormList
{
public:
    FormList();

    void addForm(Form *f);

    void undo();
    void redo();

private:
    std::vector<Form*> *_data;
    int _index = 0;
    int _maxIndex = 0;
};


class Form
{
public:
    virtual void draw() = 0;
};

#endif // FORM_H
