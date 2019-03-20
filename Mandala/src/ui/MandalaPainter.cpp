#include "header/ui/MandalaPainter.h"
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <iostream>
#include <header/lib/images/DrawerUtility.h>
#include <header/ui/MandalaPainter.h>


#define PI 3.14159265

MandalaPainter::MandalaPainter(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
    numberSlices = 2;
    colorTurning = false;
    hasToShowGrid = false;

    drawable = new DrawerUtility();
}

void MandalaPainter::setSlices(int newNumberSlices) {
    numberSlices = newNumberSlices;
    repaint();
}


bool MandalaPainter::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool MandalaPainter::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}

void MandalaPainter::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void MandalaPainter::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void MandalaPainter::setHeight(int height) {
    myHeight = height;
}

void MandalaPainter::setWidth(int width) {
    myWidth = width;
}

void MandalaPainter::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    drawable->clear();
    modified = true;
    update();
}

void MandalaPainter::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
        drawable->beginForm();
    }
}

void MandalaPainter::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}

void MandalaPainter::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
        drawable->endForm();
    }
}

void MandalaPainter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);

    if(hasToShowGrid && gridIntensity != 0) {
		drawGrid(painter);
    }
}

void MandalaPainter::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void MandalaPainter::drawLineTo(const QPoint &endPoint)
{
    drawLine(lastPoint, endPoint);
}

void MandalaPainter::drawLine(QPoint &beginPoint, const QPoint &endPoint) {
    QPainter painter(&image);
    QPen pen = QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    QPoint endPointTmp = endPoint;

    double angle = 360.0 / numberSlices;
	QTransform transform;
	transform.translate(myWidth / 2., myHeight / 2.).rotate(angle).translate(- myWidth / 2., - myHeight / 2.);

	int rad = (myPenWidth / 2) + 2;

	int h, s, v, a;
	myPenColor.getHsv(&h, &s, &v, &a);

	QColor color = myPenColor;
	//drawable->beginForm();
	drawable->setColor(color);
	painter.setPen(pen);
    for(int i = 0; i < numberSlices; i++) {
    	if(colorTurning) {
			color.setHsv(static_cast<int>(h + angle * i), s, v, a);
			pen.setColor(color);
			painter.setPen(pen);
			drawable->setColor(color);
    	}


    	painter.drawLine(beginPoint, endPointTmp);
		drawable->drawLine(beginPoint, endPointTmp);

		beginPoint  = transform.map(beginPoint);
		endPointTmp = transform.map(endPointTmp);
    }

	//drawable->endForm();


	beginPoint = endPointTmp;
	modified = true;
	repaint();
}


void MandalaPainter::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void MandalaPainter::print()
{

    /*
    #if QT_CONFIG(printdialog)

    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
           QPainter painter(&printer);
           QRect rect = painter.viewport();
           QSize size = image.size();
           size.scale(rect.size(), Qt::KeepAspectRatio);
           painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
           painter.setWindow(image.rect());
           painter.drawImage(0, 0, image);
       }
    #endif // QT_CONFIG(printdialog)
*/

}

void MandalaPainter::setColorTurning(int newValue) {
	colorTurning = static_cast<bool>(newValue);
}

void MandalaPainter::setHasToShowGrid(int hasToShowGrid) {
	MandalaPainter::hasToShowGrid = static_cast<bool>(hasToShowGrid);
	repaint();
}

void MandalaPainter::setGridIntensity(int gridIntensity) {
	MandalaPainter::gridIntensity = gridIntensity;
	repaint();
}

void MandalaPainter::drawGrid(QPainter &painter) {
	QLine line(0, static_cast<int>(myHeight / 2.),
			   static_cast<int>(myWidth / 2.), static_cast<int>(myHeight / 2.));
	double angle = 360.0 / numberSlices;
	QTransform transform;
	transform.translate(myWidth / 2., myHeight / 2.).rotate(angle).translate(-myWidth / 2., -myHeight / 2.);
	painter.setPen(QPen(Qt::gray, 5, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));

	for(int i = 0; i < numberSlices; i++) {
		painter.drawLine(line);
		line  = transform.map(line);
	}

}

void MandalaPainter::undo() {
	drawable->undo();
	image = drawable->getResult(image.width(), image.height());
	repaint();
}

void MandalaPainter::redo() {
	drawable->redo();
	image = drawable->getResult(image.width(), image.height());
	repaint();
}

const QColor &MandalaPainter::getMyPenColor() const {
	return myPenColor;
}

int MandalaPainter::getMyPenWidth() const {
	return myPenWidth;
}

void MandalaPainter::setMirroring(int mirroring) {
	MandalaPainter::mirroring = static_cast<bool>(mirroring);
	repaint();
}


