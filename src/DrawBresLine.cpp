#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include <cstdio>

#include "DrawBresLine.h"

std::vector<pair_t> BresLine(double _x0, double _y0, double _x1, double _y1, bool draw) {
    std::vector<pair_t> line;
    pair_t pair;
    int dx = fabs(_x1 - _x0);
    int sx = _x0 < _x1 ? 1 : -1;
    int dy = fabs(_y1 - _y0);
    int sy = _y0 < _y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

   while (true) {
        pair.x = _x0; pair.y = _y0;
        line.insert(line.end(), pair);

        if (draw){
            glBegin(GL_POINTS);
                glVertex3f(_x0, _y0, 0.0);
            glEnd();
        }

        if (_x0==_x1 && _y0==_y1) {
            break;
        }
        e2 = err;
        if (e2 >-dx) {
            err -= dy;
            _x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            _y0 += sy;
        }
    }
    return line;
}
