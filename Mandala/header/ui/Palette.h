#ifndef PALETTE_H
#define PALETTE_H

#include <QWidget>

namespace Ui {
class Palette;
}

class Palette : public QWidget
{
    Q_OBJECT

public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();

private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
