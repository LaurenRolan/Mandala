//
// Created by kubiak on 19/03/19.
//

#ifndef MANDALA_PIXEL_H
#define MANDALA_PIXEL_H

#include <QColor>


struct Point {
	int line, column;
};

struct Pixel {
	Point p;
	QColor color;
};


#endif //MANDALA_PIXEL_H
