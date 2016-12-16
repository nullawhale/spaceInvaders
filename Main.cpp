#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "Player.h"
#include "Bullet.h"
#include "DrawBresenhamLine.h"
#include "MainConst.h"

using namespace std;

Player playerObj(50, 50, 0);
Bullet bulletObj(playerObj.x, playerObj.y, playerObj.angle, 0);

string buff;
string sincos_buff;
string bullet_buff;

void update(int value);

void KeyboardMove(int key, int _x, int _y){
	switch (key){
		case GLUT_KEY_LEFT:
			//playerObj.x--;
			playerObj.angle += ROTATE_SPEED;
			break;
		case GLUT_KEY_RIGHT:
			//playerObj.x++;
			playerObj.angle -= ROTATE_SPEED;
			break;
		case GLUT_KEY_DOWN:
			playerObj.x = playerObj.x + PLAYER_SPEED * sin(playerObj.angle * M_PI / 180);
			playerObj.y = playerObj.y - PLAYER_SPEED * cos(playerObj.angle * M_PI / 180);
			break;
		case GLUT_KEY_UP:
			playerObj.x = playerObj.x - PLAYER_SPEED * sin(playerObj.angle * M_PI / 180);
			playerObj.y = playerObj.y + PLAYER_SPEED * cos(playerObj.angle * M_PI / 180);
			break;
		case GLUT_KEY_INSERT:
			bulletObj.active = 1;
			break;
	}
}

void output(GLfloat x, GLfloat y, string text){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(0.08, 0.08, 0);
    for(int i = 0; i < text.length(); i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    }
    glPopMatrix();
}

string LDToStr(double one){
    std::stringstream ss;
    ss << one;
    return ss.str();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	playerObj.drawPlayer(playerObj.x, playerObj.y, playerObj.angle);
	
	if (bulletObj.active == 0)
		bulletObj.drawBullet(playerObj.x, playerObj.y, playerObj.angle);
	else
		bulletObj.drawBullet(bulletObj.x, bulletObj.y, playerObj.angle);

	/*Debug on screen*/
	buff = "x: " + LDToStr(bulletObj.x) + "; y: " + LDToStr(bulletObj.y) + "; a: " + LDToStr((double)bulletObj.angle);
	bullet_buff = "a: " + LDToStr(bulletObj.active)+ "; sin: " + LDToStr((double)sin(bulletObj.angle * 3.14 / 180));
	bullet_buff += "; cos: " + LDToStr((double)cos(bulletObj.angle * 3.14 / 180));
	output(5, HEIGHT_D-10, buff);
	output(5, HEIGHT_D-25, bullet_buff);
	/*End debug on screen*/

	glutSwapBuffers();
}

void update(int value){
	playerObj.update();
	bulletObj.update(playerObj.x, playerObj.y);
	
	glutPostRedisplay();
	glutTimerFunc(33, update, 0);
}

void Initialize() {
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH_D, 0.0, HEIGHT_D, -5.0, 5.0);
	//glutIdleFunc(update);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH_D, HEIGHT_D);
	glutCreateWindow("Window");
	Initialize();
	glutDisplayFunc(Display);
	glutSpecialFunc(KeyboardMove);
	glutTimerFunc(33, update, 0);
	glutMainLoop();
	return 0;
}
