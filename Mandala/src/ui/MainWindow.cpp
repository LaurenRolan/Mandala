#include "header/ui/MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QDir>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>
#include <header/ui/MainWindow.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    //To show the menu in the application
    //QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    ui->setupUi(this);

    mandalaArea = ui->widget;
    mandalaArea->setHeight(360);
    mandalaArea->setWidth(640);

    connectMenus();

    setWindowTitle(tr("Mandala"));
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
    saveFile(fileFormat);
}

void MainWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(mandalaArea->penColor());
    if (newColor.isValid()) {
        mandalaArea->setPenColor(newColor);
    }
}

void MainWindow::penWidth(int width)
{
    mandalaArea->setPenWidth(width);
}


//TODO : modify the info
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Mandala"),
            tr("ENSICAEN 2019 <br> By <br>"
               "Erik KUBIAK and Lauren ROLAN"));
}

void MainWindow::connectMenus()
{
    connect(ui->action_Save, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->action_Open, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->lineColorButton, SIGNAL(clicked()), this, SLOT(penColor()));

    connect(ui->slicesCount, SIGNAL(valueChanged(int)), mandalaArea, SLOT(setSlices(int)));
    connect(ui->colorChanging, SIGNAL(stateChanged(int)), mandalaArea, SLOT(setColorTurning(int)));
    connect(ui->clearButton, SIGNAL(clicked()), mandalaArea, SLOT(clearImage()));

    connect (ui->slicesCount, SIGNAL(valueChanged(int)), ui->slicesCountSlider, SLOT(setValue(int)));
    connect (ui->slicesCountSlider, SIGNAL(valueChanged(int)), ui->slicesCount, SLOT(setValue(int)));

    /*
    connect(ui->addSliceButton, SIGNAL(clicked()),
            mandalaArea, SLOT(increaseSlices()));
    connect(ui->removeSliceButton, SIGNAL(clicked()),
            mandalaArea, SLOT(decreaseSlices()));
    connect(ui->slicesEdit, SIGNAL(textChanged(QString)),
            this, SLOT(slicesChanged(QString)));
    */


}

void MainWindow::resizeImage(const QString & newSize) {
    int xIndex = newSize.indexOf('x');
    QString stringWidth = newSize.mid(0, xIndex);
    QString stringHeight = newSize.mid(xIndex + 1);
    mandalaArea->setHeight(stringHeight.toInt());
    mandalaArea->setWidth(stringWidth.toInt());
    mandalaArea->resize(stringWidth.toInt(), stringHeight.toInt());
    adjustSize();
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

void MainWindow::slicesChanged(QString slicesText) {
    //TODO
}

void MainWindow::setColorTurning(bool newValue) {
    mandalaArea->setColorTurning(newValue);

}
