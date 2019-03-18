#include "header/ui/MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QDir>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    //To show the menu in the application
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    ui->setupUi(this);

    mandalaArea = ui->widget;
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
        std::cout << "SUP"; //Printing when out
        mandalaArea->setPenColor(newColor);
    }
}

void MainWindow::penWidth(int width)
{
    std::cout << "In width";
    mandalaArea->setPenWidth(width);
    std::cout << "Width : " << width;
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
    connect(ui->action_Save, SIGNAL(triggered()),
            this, SLOT(save()));
    connect(ui->action_Open, SIGNAL(triggered()),
            this, SLOT(open()));
    connect(ui->clearButton, SIGNAL(clicked()),
            mandalaArea, SLOT(clearImage()));
    connect(ui->lineSlider, SIGNAL(sliderMoved(int)),
            this, SLOT(penWidth(int);));
    connect(ui->lineColorButton, SIGNAL(clicked()),
            this, SLOT(penColor()));
}


bool MainWindow::maybeSave()
{
    if (mandalaArea->isModified()) {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("Scribble"),
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
