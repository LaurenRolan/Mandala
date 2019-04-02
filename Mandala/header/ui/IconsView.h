#ifndef ICONSVIEW_H
#define ICONSVIEW_H
#include <QGraphicsView>

class IconsView : public QGraphicsView
{
    Q_OBJECT
public:
    IconsView(QFrame * parent);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // ICONSVIEW_H
