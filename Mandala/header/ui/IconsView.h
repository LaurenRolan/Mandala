#ifndef ICONSVIEW_H
#define ICONSVIEW_H
#include <QGraphicsView>

class IconsView : public QGraphicsView
{
    Q_OBJECT
public:
	explicit IconsView(QFrame * parent);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ICONSVIEW_H
