//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_LINEFORM_H
#define MANDALA_LINEFORM_H


#include <QtGui/QColor>
#include <QtCore/QPoint>
#include <QtGui/QPainter>

#include "Form.h"

class LineForm : public Form {

public:
	LineForm(const QColor &color, int penWidth, const QPoint &origin, const QPoint &extremity);
	void draw(QPainter &painter) override;

private:
	QColor color;
	int penWidth;
	QPoint origin;
	QPoint extremity;
};


#endif //MANDALA_LINEFORM_H
