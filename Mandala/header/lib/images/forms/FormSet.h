//
// Created by kubiak on 20/03/19.
//

#ifndef MANDALA_FORMSET_H
#define MANDALA_FORMSET_H

#include <vector>
#include <QtGui/QPainter>

#include "Form.h"

class FormSet : public Form {
public:
	FormSet();

	void draw(QPainter &painter) override;

	void addForm(Form * f);
private:
	std::vector<Form*> *set;
};


#endif //MANDALA_FORMSET_H
