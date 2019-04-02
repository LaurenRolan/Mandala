#include "header/ui/MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QDir>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>
#include <header/ui/MainWindow.h>
#include <QtCore/QCoreApplication>
#include <QPixmap>
#include <string.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    file(QString("")),
    extension(new char[3])
{
     QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    ui->setupUi(this);

    mandalaArea = ui->widget;
    mandalaArea->setHeight(360);
    mandalaArea->setWidth(640);
    scene = new QGraphicsScene();
    ui->lineView->setScene(scene);

    palette = new Palette();
    ui->arc->setScene((QGraphicsScene*)palette->arc);
    ui->arc->setAccessibleName("arc");

    ui->square->setScene((QGraphicsScene*)palette->square);
    ui->square->setAccessibleName("square");

    ui->circle->setScene((QGraphicsScene*)palette->circle);
    ui->circle->setAccessibleName("circle");

    ui->hexagon->setScene((QGraphicsScene*)palette->hexagon);
    ui->hexagon->setAccessibleName("hexagon");

    ui->triangle->setScene((QGraphicsScene*)palette->triangle);
    ui->triangle->setAccessibleName("triangle");

    connectMenus();

    setWindowTitle(tr("Mandala"));
    onPenWidthChanged(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                   tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty())
            mandalaArea->openImage(fileName);
    }
}

void MainWindow::save()
{
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    if(QString::compare(file, QString("")) == 0) //First save
        saveFile(fileFormat);
    else
        saveToKnown();
}


void MainWindow::saveAs()
{
    saveFile("png");
}
void MainWindow::newImage()
{
    maybeSave();
    mandalaArea->clearImage();
    saveFile("png");
}
 void MainWindow::saveToKnown()
 {
     mandalaArea->saveImage(file, extension);
 }

void MainWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(mandalaArea->penColor());
    if (newColor.isValid()) {
        mandalaArea->setPenColor(newColor);
        palette->setPenColor(newColor);
        onPenWidthChanged(mandalaArea->getMyPenWidth());
    }
}

void MainWindow::backgroundColor(){
    QColor newColor = QColorDialog::getColor(mandalaArea->penColor());
    if (newColor.isValid()) {
        mandalaArea->setBackgroundColor(newColor);
        onPenWidthChanged(mandalaArea->getMyPenWidth());
    }

}

void MainWindow::penWidth(int width)
{
    mandalaArea->setPenWidth(width);
}

void MainWindow::about()
{
    QMessageBox about(this);

    about.setText("Mandala Project");
    about.setInformativeText(tr("ENSICAEN, France\n"
                                "March 2019.\n\n"
                                "By Erik KUBIAK and Lauren ROLAN.\n"));
    about.setStandardButtons(QMessageBox::Ok);
    QPixmap mandala(":/images/mandala.jpg");
    mandala = mandala.scaled(100, 100);
    about.setIconPixmap(mandala);
    about.setDefaultButton(QMessageBox::Ok);
    about.show();
    about.exec();
}

void MainWindow::connectMenus()
{
    connect(ui->actionAbout_this_program, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->action_Save, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(ui->action_New, SIGNAL(triggered()), this, SLOT(newImage()));
    connect(ui->action_Open, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->lineColorButton, SIGNAL(clicked()), this, SLOT(penColor()));

    connect(ui->mirrorBox, SIGNAL(stateChanged(int)), mandalaArea, SLOT(setMirroring(int)));

    connect(ui->lineSlider, SIGNAL(valueChanged(int)), mandalaArea, SLOT(setPenWidth(int)));
    connect(ui->lineSlider, SIGNAL(valueChanged(int)), this, SLOT(onPenWidthChanged(int)));

    connect(ui->slicesCount, SIGNAL(valueChanged(int)), mandalaArea, SLOT(setSlices(int)));
	connect (ui->slicesCountSlider, SIGNAL(valueChanged(int)), mandalaArea, SLOT(setSlices(int)));

    connect(ui->colorChanging, SIGNAL(stateChanged(int)), mandalaArea, SLOT(setColorTurning(int)));
    connect(ui->clearButton, SIGNAL(clicked()), mandalaArea, SLOT(clearImage()));

    connect(ui->showGridBox, SIGNAL(stateChanged(int)), mandalaArea, SLOT(setHasToShowGrid(int)));
    connect(ui->gridIntensitySLider, SIGNAL(valueChanged(int)), mandalaArea, SLOT(setGridIntensity(int)));

    connect(ui->slicesCount, SIGNAL(valueChanged(int)), ui->slicesCountSlider, SLOT(setValue(int)));
    connect(ui->slicesCountSlider, SIGNAL(valueChanged(int)), ui->slicesCount, SLOT(setValue(int)));

    connect(ui->actionRedo, SIGNAL(triggered()), mandalaArea, SLOT(redo()));
    connect(ui->actionUndo, SIGNAL(triggered()), mandalaArea, SLOT(undo()));

    connect(ui->sizeBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(resizeImage(const QString&)));
    connect(ui->backgroundButton, SIGNAL(clicked()), this, SLOT(backgroundColor()));
}

void MainWindow::resizeImage(const QString & newSize) {
    int xIndex = newSize.indexOf('x');
    QString stringWidth = newSize.mid(0, xIndex);
    QString stringHeight = newSize.mid(xIndex + 1);


    int height = stringHeight.toInt(); QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
	
	
	mandalaArea->setHeight(height);
	int width = stringWidth.toInt();
	mandalaArea->setWidth(width);
    mandalaArea->resize(width, height);
    ui->frame_2->resize(width + 128, height + 10);
    resize(width + 128, height + 400);
    //adjustSize();
}

bool MainWindow::maybeSave()
{
    if (mandalaArea->isModified()) {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("Mandala"),
                          tr("The image has been modified.\n"
                             "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard
                          | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            return saveFile("png");
        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}


bool MainWindow::saveFile(const QByteArray &fileFormat)
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString::fromLatin1(fileFormat.toUpper()))
                               .arg(QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty()) {
        return false;
    } else {
        file = fileName;
        strcpy(extension, fileFormat.constData());
        return mandalaArea->saveImage(fileName, fileFormat.constData());
    }
}


void MainWindow::on_lineSlider_sliderMoved(int position)
{
    penWidth(position);
}

void MainWindow::on_sizeBox_currentIndexChanged(const QString &arg1)
{
    resizeImage(arg1);
}

void MainWindow::setColorTurning(bool newValue) {
    mandalaArea->setColorTurning(newValue);

}

void MainWindow::onPenWidthChanged(int newWidth) {
    scene->clear();
    scene->addEllipse(
            scene->width() / 2. - newWidth, scene->height() / 2. - newWidth, newWidth * 2, newWidth * 2,
            QPen(mandalaArea->getMyPenColor()), QBrush(mandalaArea->getMyPenColor()));
    palette->setPenWidth(newWidth);
    palette->drawAll();
}

