#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include "DrawBresLine.h"
#include "MainConst.h"

using namespace std;

void DrawBresLine(double _x0, double _y0, double _x1, double _y1){
    int dx = abs(_x1 - _x0);
    int sx = _x0 < _x1 ? 1 : -1;
    int dy = abs(_y1 - _y0);
    int sy = _y0 < _y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while(true) { 
        glBegin(GL_POINTS);
            glVertex3f(_x0, _y0, 0.0);
        glEnd();

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
}
