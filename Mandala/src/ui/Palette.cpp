#include "Palette.h"
#include "ui_Palette.h"

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
}

Palette::~Palette()
{
    delete ui;
}
