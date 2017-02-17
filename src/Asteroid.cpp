#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include "Asteroid.h"
#include "DrawBresLine.h"

Asteroid::Asteroid(){}

void Asteroid::drawAsteroid(){
	int as = ASTEROID_SIZE;
	
	glPushMatrix();

        glColor3f(1.0, 0.0, 0.0);
        BresLine(-as, -as, 0, as);
        BresLine(0, as, as, -as);

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
