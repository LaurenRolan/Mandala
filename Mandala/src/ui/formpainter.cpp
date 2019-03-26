#include "formpainter.h"

FormPainter::FormPainter(QWidget *parent) : QWidget(parent)
{

}

void FormPainter::setPenColor(const QColor &newColor) { myPenColor = newColor; }
void FormPainter::setHeight(int height) { myHeight = height; }
void FormPainter::setWidth(int width) { myWidth = width; }
