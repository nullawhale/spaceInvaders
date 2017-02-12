#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Asteroid.h"
#include "DrawBresLine.h"
#include "MainConst.h"

Asteroid::Asteroid(){}

void Asteroid::drawAsteroid(){
	int as = ASTEROID_SIZE;
	
	glPushMatrix();

        glColor3d(1, 0, 0);
        DrawBresLine(-as, -as, 0, as);
        DrawBresLine(0, as, as, -as);

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
