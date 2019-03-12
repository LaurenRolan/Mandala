#ifndef FORM_H
#define FORM_H

#include <vector>


class Form;


class FormList
{
public:
    FormList();

    void addForm(Form *f);

    void undo();
    void redo();


private:
    std::vector<Form*> data;
    int index = 0;
};


class Form
{
public:
    virtual void Draw() = 0;
};

#endif // FORM_H
