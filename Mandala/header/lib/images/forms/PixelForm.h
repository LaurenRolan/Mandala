//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_PIXELFORM_H
#define MANDALA_PIXELFORM_H


#include <QtGui/QColor>
#include "Form.h"

class PixelForm : public Form {
public:
	PixelForm(QColor color, QPoint pixel);
	void draw() override;

private:
	QColor color;
	QPoint pos;
};


#endif //MANDALA_PIXELFORM_H
