#include "Block.h"

Block::Block(Vec2 min, Vec2 max) : min{min}, max{max} {}

void Block::drawBlock() const {
    glPushMatrix();

    glBegin(GL_LINES);
    glColor3f(0.3, 0.4, 0.0);
    glVertex3f(min.x, min.y, 0);
    glVertex3f(max.x, min.y, 0);
    glVertex3f(max.x, min.y, 0);
    glVertex3f(max.x, max.y, 0);
    glVertex3f(max.x, max.y, 0);
    glVertex3f(min.x, max.y, 0);
    glVertex3f(min.x, max.y, 0);
    glVertex3f(min.x, min.y, 0);
    glEnd();

    glPopMatrix();
}

void Block::update(GLFWwindow* window) {

}
