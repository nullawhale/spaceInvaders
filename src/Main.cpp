#include <iostream>
#include <clocale>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "LoadTexture.h"
#include "Player.h"
#include "Bullet.h"
#include "MainConst.h"

struct map_t map;
Player player(true, 50, WIDTH_D / 5.5, HEIGHT_D / 5.5, 0);
Bullet bullets_p[MAX_BULLETS_ON_SCREEN];

static bool shoot_p = false;

std::string buff;

void KeyboardMove(int key, int _x, int _y) {
	switch (key) {
		case GLUT_KEY_LEFT:
			player.left = 1;
			break;
		case GLUT_KEY_RIGHT:
			player.right = 1;
			break;
		case GLUT_KEY_UP:
			player.moving = 1;
			break;
		case GLUT_KEY_DOWN:
			player.slowdown = 1;
			break;
	}
}

void KeyboardMoveUp(int key, int _x, int _y) {
	switch (key) {
		case GLUT_KEY_LEFT:
			player.left = 0;
			break;
		case GLUT_KEY_RIGHT:
			player.right = 0;
			break;
		case GLUT_KEY_UP:
			player.moving = 0;
			break;
		case GLUT_KEY_DOWN:
			player.slowdown = 0;
			break;
	}
}

void keyboardListener(unsigned char c, int x, int y) {
	switch (c) {
		case 'q':
			exit(0);
			break;
		case ' ':
			shoot_p = true;
			break;
		case 'm':
			map = std::string(map.name) == "./map.bmp" ? LoadTexture("./map2.bmp") : LoadTexture("./map.bmp");
			for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++){
				bullets_p[i].active = 0;
			}
			break;
		case 'r':
			player.reset(WIDTH_D / 5.5, HEIGHT_D / 5.5);
			break;
	}
}

void output(GLfloat x, GLfloat y, std::string text) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.08, 0.08, 0);
	for (unsigned int i = 0; i < text.length(); i++) {
		glColor3f(0.0, 0.0, 0.0);
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
	}
	glPopMatrix();
}

std::string toStr(double one) {
	std::stringstream ss;
	ss << one;
	return ss.str();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	// Draw map texture
	GLuint texture;
	texture = map.texture;

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex2f(0.0, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.0, HEIGHT_D);
		glTexCoord2f(1.0, 1.0); glVertex2f(WIDTH_D, HEIGHT_D);
		glTexCoord2f(1.0, 0.0); glVertex2f(WIDTH_D, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	// Draw map per pixel
	// glBegin(GL_POINTS);
	// for (int i = 0; i < HEIGHT_D; ++i) {
	// 	for (int j = 0; j < WIDTH_D; ++j) {
	// 		if (map.data[i * 640 * 3 + j * 3]) {
	// 			glColor3f(1.0f, 1.0f, 1.0f);
	// 		}
	// 		else {
	// 			glColor3f(0.0f, 0.0f, 0.0f);
	// 		}
	// 		glVertex3i(j, i, 0);
	// 	}
	// }
	// glEnd();

	if (player.life){
		player.drawPlayer();
	}

	for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
		if (bullets_p[i].active) {
			bullets_p[i].drawBullet();
		}
	}

	/*Debug on screen*/
	buff = "Map: " + std::string(map.name);
	output(5, HEIGHT_D-10, buff);
	/*End debug on screen*/

	glutSwapBuffers();
}

void update(int value) {
	u8 * data = map.data;

	player.update(data);

	if (shoot_p) {
		for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
			if (bullets_p[i].active == 0) {
				bullets_p[i].shoot(player.x, player.y, player.angle);
				break;
			}
		}
		shoot_p = false;
	}

	for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
		bullets_p[i].update(data);
	}

	glLoadIdentity();

	glutPostRedisplay();
	glutTimerFunc(30, update, 0);
}

void Initialize() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH_D, 0.0, HEIGHT_D, -5.0, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	map = LoadTexture("./map2.bmp");

	glClearColor(0, 0, 0, 1.0);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH_D, HEIGHT_D+50);
	glutCreateWindow("Lab 2");

	Initialize();

	glutDisplayFunc(Display);

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(KeyboardMove);
	glutSpecialUpFunc(KeyboardMoveUp);

	glutTimerFunc(30, update, 0);
	glutMainLoop();
	return 0;
}

