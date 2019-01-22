#include "Block.h"

Block::Block() {}

Block::Block(Vec2 _min, Vec2 _max) {
    min = _min;
    max = _max;
}

void Block::drawBlock() {
    glPushMatrix();

    glBegin(GL_LINES);
        glColor3f(0.3, 0.4, 0.0);
        glVertex3f(min.x, min.y, 0); glVertex3f(max.x, min.y, 0);
        glVertex3f(max.x, min.y, 0); glVertex3f(max.x, max.y, 0);
        glVertex3f(max.x, max.y, 0); glVertex3f(min.x, max.y, 0);
        glVertex3f(min.x, max.y, 0); glVertex3f(min.x, min.y, 0);
    glEnd();

    glPopMatrix();
}

void Block::update(GLFWwindow* window) {
    
}
