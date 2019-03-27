#include "Palette.h"
#include "ui_Palette.h"
#include <QColorDialog>

Palette::Palette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);

    ui->triangle = new ShapeViewer(this);
    ui->triangle->setAccessibleName("Triangle");

    ui->circle = new ShapeViewer(this);
    ui->circle->setAccessibleName("Circle");

    ui->hexagon = new ShapeViewer(this);
    ui->hexagon->setAccessibleName("Hexagon");

    ui->square = new ShapeViewer(this);
    ui->square->setAccessibleName("Square");

    ui->image = new ShapeViewer(this);
    ui->image->setAccessibleName("Image");

    ui->arc = new ShapeViewer(this);
    ui->arc->setAccessibleName("Arc");

    connect(ui->colorButton, SIGNAL(clicked()), this, SLOT(penColor()));

    update();
}

Palette::~Palette()
{
    delete ui;
}

void Palette::penColor()
{
    QColor newColor = QColorDialog::getColor(ShapeViewer::penColor());
    if (newColor.isValid()) {
        ShapeViewer::setPenColor(newColor);
        ui->arc->repaint();
        ui->circle->repaint();
        ui->square->repaint();
        ui->hexagon->repaint();
        ui->triangle->repaint();
    }
}
