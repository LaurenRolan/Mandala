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
    void drawPixmap(QPoint &origin, QPixmap & pixmap) override;
	void clear() override;
	void setColor(QColor &color) override;

	void undo() override;
	void redo() override;

	void setPenWidth(int penWidth) override;

	void beginForm() override;
	void endForm() override;

	QImage & getResult(int width, int height) override;

	void setInitialImage(QImage *image) override;

	void setBackgroundColor (QColor color) override;

private:
	void drawForm(Form *f);

	FormSet* currentFormSet;
	QColor color;
	int penWidth;
	Image *image;
	QImage *initialImage;
	QColor background;
};


#endif //MANDALA_DRAWERUTILITY_H
