#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "header/ui/MandalaPainter.h"
#include "header/ui/Palette.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void open();
    void save();
    void saveAs();
    void newImage();
    void penColor();
    void backgroundColor();
    void penWidth(int width);
    void about();
    void resizeImage(const QString & newSize);
    void onPenWidthChanged(int newWidth);
    void setColorTurning(bool);
    void on_lineSlider_sliderMoved(int position);
    void on_sizeBox_currentIndexChanged(const QString &arg1);

private:
    void connectMenus();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);
    void saveToKnown();

    QString file;
    char * extension;

    MandalaPainter *mandalaArea;

    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    Palette * palette;
};

#endif // MAINWINDOW_H
