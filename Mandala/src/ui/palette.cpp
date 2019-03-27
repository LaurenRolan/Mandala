#include "palette.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);
}

Palette::~Palette()
{
    delete ui;
}
