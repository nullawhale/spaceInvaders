#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Asteroid.h"
#include "DrawBresenhamLine.h"
#include "MainConst.h"

Asteroid::Asteroid(){}

void Asteroid::drawAsteroid(){
	int as = ASTEROID_SIZE;
	
	glPushMatrix();

	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
		glColor3d(1, 0, 0);
		glVertex3f(-as,   -as,   0);
		glVertex3f( 0,     as,   0);
		glVertex3f( as,   -as,   0);
		glVertex3f(-as,   -as,   0);
	glEnd();

	glPopMatrix();
}

void Asteroid::update(){
    if(life == 1) {
    	x -= ASTEROID_SPEED * sin(angle * M_PI / 180);
    	y += ASTEROID_SPEED * cos(angle * M_PI / 180);
    }

    if (life == 1 && (x >= WIDTH_D || x <= 0 || y >= HEIGHT_D || y <= 0)){
		life = 0;
	}
}