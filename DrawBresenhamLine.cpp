#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "DrawBresenhamLine.h"
#include "MainConst.h"

using namespace std;

DrawBresenhamLine::DrawBresenhamLine(){}

double DrawBresenhamLine::sign(double x){
    return (x > 0.0) ? 1.0 : (x < 0.0) ? -1.0 : 0; 
}

void DrawBresenhamLine::drawPoint(double x, double y){
	glBegin(GL_POINTS);
        glVertex3f(x, y, 0.0);
    glEnd();
}

void DrawBresenhamLine::drawLine(double _x0, double _y0, double _x1, double _y1){
    int x, y, dx, dy, incx, incy, pdx, pdy, es, el, err;
    int res[WIDTH_I];

    dx = _x1 - _x0;
    dy = _y1 - _y0;

    incx = sign(dx);
    incy = sign(dy);

    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (dx > dy){
        pdx = incx;
        pdy = 0;
        es = dy;
        el = dx;
    } else {
        pdx = 0;
        pdy = incy;
        es = dx;
        el = dy;
    }

    x = _x0;
    y = _y0;
    err = el / 2;
    drawPoint(x, y);

    for (int t = 0; t < el; t++){
        err -= es;
        if (err < 0){
            err += el;
            x += incx;
            y += incy;
        }
        else{
            x += pdx;
            y += pdy;
        }
        drawPoint(x, y);
    }
}