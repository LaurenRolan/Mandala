#include "header/ui/MandalaPainter.h"
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <iostream>
#include <header/lib/images/DrawerUtility.h>


#define PI 3.14159265

MandalaPainter::MandalaPainter(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
    numberSlices = 2;

    drawable = new DrawerUtility();
}

void MandalaPainter::increaseSlices() {
    numberSlices++;
}

void MandalaPainter::decreaseSlices() {
    numberSlices--;
}

void MandalaPainter::setSlices(int newNumberSlices) {
    numberSlices = newNumberSlices;
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

    drawable->getResult(myWidth, myHeight).save("test", "png");

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
    }
}

void MandalaPainter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
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
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    drawable->setColor(myPenColor);
    drawable->setPenWidth(myPenWidth);

    double angle = 360.0 / numberSlices;

    for(int i = 0; i < numberSlices; i++){
        //painter.translate(QPoint(myWidth / 2, myHeight / 2));
        //painter.rotate(angle);
        painter.drawLine(beginPoint, endPoint);
		drawable->drawLine(beginPoint, endPoint);
        modified = true;

        int rad = (myPenWidth / 2) + 2;
        update(QRect(beginPoint, endPoint).normalized()
                                         .adjusted(-rad, -rad, +rad, +rad));
        beginPoint = endPoint;

        //Partie pour la rotation
        //painter.translate(QPoint(-myWidth / 2, -myHeight / 2));
    }
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
