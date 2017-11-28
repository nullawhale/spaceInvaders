#include "Block.h"

Block::Block() {}

Block::Block(Vec2 _min, Vec2 _max) {
    min = _min;
    max = _max;
}

void Block::drawBlock() {
    glPushMatrix();

    glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(min.x);
    glEnd();

    glPopMatrix();
}

void Block::update(GLFWwindow* window) {

}
