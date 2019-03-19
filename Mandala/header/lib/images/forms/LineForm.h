//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_LINEFORM_H
#define MANDALA_LINEFORM_H


#include <QtGui/QColor>
#include <QtCore/QPoint>

#include "Form.h"

class LineForm : public Form {

public:
	LineForm(QColor color, QPoint &origin, QPoint &extremity);
	void draw() override;

private:
	QColor color;
	QPoint origin;
	QPoint extremity;
};


#endif //MANDALA_LINEFORM_H
