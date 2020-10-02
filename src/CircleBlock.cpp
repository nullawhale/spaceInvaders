#include "CircleBlock.h"

#include <GL/glew.h>

#include <cmath>

CircleBlock::CircleBlock(Vec2 center, double r) :
        center{center},
        r{r},
        active{true} {}

void CircleBlock::drawCircleBlock() const {
    glPushMatrix();

    int num_segments = 50;

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < num_segments; i++) {
        double angle = 2 * 3.14 * i / num_segments;
        double x = r * std::cos(angle);
        double y = r * std::sin(angle);
        glVertex2f(x + center.x, y + center.y);
    }
    glEnd();

    glPopMatrix();
}

void CircleBlock::update(double _x, double _y, double _r) {
    center = {_x, _y};
    r = _r;
}
