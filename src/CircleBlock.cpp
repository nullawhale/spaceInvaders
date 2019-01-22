#include "CircleBlock.h"

CircleBlock::CircleBlock() {}

CircleBlock::CircleBlock(Vec2 _center, double _r) {
    center = _center;
    r = _r;
    active = 1;
}

CircleBlock::~CircleBlock() {}

void CircleBlock::drawCircleBlock() {
    glPushMatrix();

    int num_segments = 50;

    glBegin(GL_LINE_LOOP);
        glColor3f(0.3, 0.4, 0.0);
        for (int i = 0; i < num_segments; i++)   {
            double angle = 2 * 3.14 * i / num_segments;
            double x = r * cos(angle);
            double y = r * sin(angle);
            glVertex2f(x + center.x, y + center.y);
        }
    glEnd();

    glPopMatrix();
}

void CircleBlock::update(double _x, double _y, double _r) {
    center = Vec2(_x, _y);
    r = _r;
    
}
