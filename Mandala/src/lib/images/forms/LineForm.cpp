//
// Created by kubiak on 19/03/19.
//

#include <lib/images/forms/LineForm.h>
#include <header/lib/images/forms/LineForm.h>
#include <QtGui/QPainter>
#include <iostream>


void LineForm::draw(QPainter &painter) {
	painter.setPen(QPen(color, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	painter.drawLine(origin, extremity);
}

LineForm::LineForm(const QColor &color, int penWidth, const QPoint &origin, const QPoint &extremity)
	: color(color), penWidth(penWidth), origin(origin), extremity(extremity) {}
