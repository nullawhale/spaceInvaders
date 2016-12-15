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
Bullet bulletObj(playerObj.x, playerObj.y, playerObj.angle);

string buff;
char array[100];

void KeyboardMove(int key, int _x, int _y){
	switch (key){
		case GLUT_KEY_LEFT:
			//playerObj.x--;
			playerObj.angle += 5;
			break;
		case GLUT_KEY_RIGHT:
			//playerObj.x++;
			playerObj.angle -= 5;
			break;
		case GLUT_KEY_DOWN:
			playerObj.x = playerObj.x + 2 * sin(playerObj.angle * M_PI / 180);
			playerObj.y = playerObj.y - 2 * cos(playerObj.angle * M_PI / 180);
			break;
		case GLUT_KEY_UP:
			playerObj.x = playerObj.x - 2 * sin(playerObj.angle * M_PI / 180);
			playerObj.y = playerObj.y + 2 * cos(playerObj.angle * M_PI / 180);
			break;
		case GLUT_KEY_INSERT:
			bulletObj.drawBullet(playerObj.x, playerObj.y);
			break;
	}
}

void output(GLfloat x, GLfloat y, string text){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(0.1, 0.1, 0);
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

	buff = "x: " + LDToStr(playerObj.x) + "; y: " + LDToStr(playerObj.y) + "; a: " + LDToStr((double)playerObj.angle);
	buff += " sin: " + LDToStr((double)sin(playerObj.angle * 3.14 / 180)) + " cos: " + LDToStr((double)cos(playerObj.angle * 3.14 / 180));
	output(15, WIDTH_D-15, buff);

	glutSwapBuffers();
}

void Update(void) {
	glutPostRedisplay();
}

void Initialize() {
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH_D, 0.0, HEIGHT_D, -5.0, 5.0);
	glutIdleFunc(Update);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Window");
	Initialize();
	glutDisplayFunc(Display);
	glutSpecialFunc(KeyboardMove);
	glutMainLoop();

	getch();

	return 0;
}