#include "World.h"

World::World(){}

World::World(map_t _map) {
    map = _map;
}

void World::drawWorld() {
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, map.texture);
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glTexCoord2f(0.0, 0.0); glVertex2f(0.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex2f(0.0, HEIGHT_D);
        glTexCoord2f(1.0, 1.0); glVertex2f(WIDTH_D, HEIGHT_D);
        glTexCoord2f(1.0, 0.0); glVertex2f(WIDTH_D, 0.0);
    glEnd();

    glPopMatrix();
}
