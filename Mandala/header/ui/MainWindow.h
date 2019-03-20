#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "header/ui/MandalaPainter.h"

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
    void penColor();
    void penWidth(int width);
    void about();
    void resizeImage(const QString & newSize);

    void setColorTurning(bool);

    void on_lineSlider_sliderMoved(int position);

    void on_sizeBox_currentIndexChanged(const QString &arg1);

private:
    void connectMenus();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);

    MandalaPainter *mandalaArea;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
