#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <iostream>
#include <header/lib/images/DrawerUtility.h>
#include <header/ui/MandalaPainter.h>
#include <cmath>


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
    gridIntensity = 100;
    mirroring = false;

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
    drawable->setInitialImage(new QImage(loadedImage));
    modified = false;
    update();
    return true;
}

bool MandalaPainter::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());



    std::cout << visibleImage.width() << " " << visibleImage.height() << std::endl;

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

	QPointF orig(myWidth / 2., myHeight / 2.);
    QPoint endPointTmp = endPoint;


    double angle = 360.0 / numberSlices;
	QTransform rotateTransform;
	rotateTransform.translate(orig.x(), orig.y()).rotate(angle).translate(- orig.x(), - orig.y());


	int h, s, v, a;
	myPenColor.getHsv(&h, &s, &v, &a);

	QColor color = myPenColor;

	drawable->setColor(color);
	drawable->setPenWidth(myPenWidth);
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

		if (mirroring) {

			double lineAngle = (180 - angle * (i + 1) + angle / 2.) * (M_PI / 180);

			QPoint beginPointMirroring = symmetry(beginPoint, lineAngle, orig);
			QPoint endPointMirroring   = symmetry(endPointTmp, lineAngle, orig);


			painter.drawLine(beginPointMirroring, endPointMirroring);
			drawable->drawLine(beginPointMirroring, endPointMirroring);
		}

		beginPoint  = rotateTransform.map(beginPoint);
		endPointTmp = rotateTransform.map(endPointTmp);

    }

	beginPoint = endPointTmp;
	modified = true;
	repaint();
}

QPoint MandalaPainter::symmetry(const QPoint &point, double angle, QPointF &orig) const {
	QPointF vec(std::cos (angle), std::sin (angle));

	double norm = vec.y() * vec.y() + vec.x() * vec.x();
	double temp = vec.y() * point.x() + vec.x() * point.y();

	double sideChanger = (vec.y() * orig.x() + vec.x() * orig.y() - temp) / norm;


	return {
			static_cast<int>(point.x() + 2 * vec.y() * sideChanger),
			static_cast<int>(point.y() + 2 * vec.x() * sideChanger)
	};
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
	QLine line;

	line = QLine(-static_cast<int>(myWidth / 2.), static_cast<int>(myHeight / 2.),
				  static_cast<int>(myWidth / 2.), static_cast<int>(myHeight / 2.));


	double angle = 360.0 / numberSlices;
	QTransform angleRotationTransform;
	angleRotationTransform.translate(myWidth / 2., myHeight / 2.).rotate(angle).translate(-myWidth / 2., -myHeight / 2.);
	QColor color(Qt::gray);
	color.setAlpha(static_cast<int>(gridIntensity / 100. * 255));

	painter.setPen(QPen(color, 5, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
	for(int i = 0; i < numberSlices; i++) {
		painter.drawLine(line);
		line  = angleRotationTransform.map(line);
	}

	if (mirroring) {
		QTransform simpleTransform;
		simpleTransform.translate(myWidth / 2., myHeight / 2.).rotate(angle / 2.).translate(-myWidth / 2., -myHeight / 2.);
		QLine mirroringLine = simpleTransform.map(line);

		painter.setPen(QPen(color, 2, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
		for(int i = 0; i < numberSlices; i++) {
			painter.drawLine(mirroringLine);
			mirroringLine  = angleRotationTransform.map(mirroringLine);
		}
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


void MandalaPainter::setBackgroundColor(const QColor &newColor) { //Same effect of clear

//    QPalette p = this->palette();
//    p.setColor(QPalette::Background, newColor);
//    this->setPalette(p);

    QPainter painter(&image);
    drawable->setBackgroundColor(QColor(newColor));
    painter.fillRect(QRect(QPoint(0,0), QPoint(myWidth, myHeight)), QBrush(newColor));
}

