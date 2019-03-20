//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_DRAWERUTILITY_H
#define MANDALA_DRAWERUTILITY_H

#include <QPoint>
#include <lib/images/forms/FormSet.h>

#include "Image.h"

#include "Drawable.h"

class DrawerUtility : public Drawable {
public:
	DrawerUtility();
	void onDraw(QPoint &p) override;
	void drawLine(QPoint &origin, const QPoint &extremity) override;
	void clear() override;
	void setColor(QColor &color) override;

	void setPenWidth(int penWidth) override;

	void beginForm() override;
	void endForm() override;

	QImage & getResult(int width, int height) override;

private:
	void drawForm(Form *f);

	FormSet* currentFormSet;
	QColor color;
	int penWidth;
	Image *image;
};


#endif //MANDALA_DRAWERUTILITY_H
