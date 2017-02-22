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
#include "Asteroid.h"
#include "MainConst.h"

struct map_t map;
Player player1(true, 50, WIDTH_D / 5.5, HEIGHT_D / 5.5, 0);
Player player2(true, 50, WIDTH_D / 2, HEIGHT_D / 2, 0);
Bullet bullets_p1[MAX_BULLETS_ON_SCREEN];
Bullet bullets_p2[MAX_BULLETS_ON_SCREEN];
Asteroid asteroids[MAX_ASTEROIDS_ON_SCREEN];

static bool shoot_p1 = false;
static bool shoot_p2 = false;

std::string buff;

void KeyboardMove(int key, int _x, int _y) {
	switch (key) {
		case GLUT_KEY_LEFT:
			player1.left = 1;
			break;
		case GLUT_KEY_RIGHT:
			player1.right = 1;
			break;
		case GLUT_KEY_UP:
			player1.moving = 1;
			break;
		case GLUT_KEY_DOWN:
			player1.slowdown = 1;
			break;
	}
}

void KeyboardMoveUp(int key, int _x, int _y) {
	switch (key) {
		case GLUT_KEY_LEFT:
			player1.left = 0;
			break;
		case GLUT_KEY_RIGHT:
			player1.right = 0;
			break;
		case GLUT_KEY_UP:
			player1.moving = 0;
			break;
		case GLUT_KEY_DOWN:
			player1.slowdown = 0;
			break;
	}
}

void keyboardListener(unsigned char c, int x, int y) {
	switch (c) {
		case 'q':
			exit(0);
			break;
		case ' ':
			shoot_p2 = true;
			break;
		case '0':
			shoot_p1 = true;
			break;
		case 'm':
			map = std::string(map.name) == "./map.bmp" ? LoadTexture("./map2.bmp") : LoadTexture("./map.bmp");
			for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++){
				bullets_p1[i].active = 0;
				bullets_p2[i].active = 0;
			}
			break;
		case 'r':
			player1.reset(WIDTH_D / 5.5, HEIGHT_D / 5.5);
			player2.reset(WIDTH_D / 2, HEIGHT_D / 2);
			break;
		case 'a':
			player2.left = 1;
			break;
		case 'd':
			player2.right = 1;
			break;
		case 'w':
			player2.moving = 1;
			break;
		case 's':
			player2.slowdown = 1;
			break;
	}
}

void keyboardUpListener(unsigned char c, int x, int y) {
	switch (c) {
		case 'a':
			player2.left = 0;
			break;
		case 'd':
			player2.right = 0;
			break;
		case 'w':
			player2.moving = 0;
			break;
		case 's':
			player2.slowdown = 0;
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

	if (player1.life){
		player1.drawPlayer();
	}
	if (player2.life){
		player2.drawPlayer();
	}

	for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
		if (bullets_p1[i].active) {
			bullets_p1[i].drawBullet();
		}
		if (bullets_p2[i].active) {
			bullets_p2[i].drawBullet();
		}
	}

	/*Debug on screen*/
	buff = "Map: " + toStr(player1.hp) + " " + toStr(player2.hp) + " " + toStr(player1.angle);
	output(5, HEIGHT_D-10, buff);
	/*End debug on screen*/

	glutSwapBuffers();
}

void update(int value) {
	u8 * data = map.data;

	player1.update(data);
	player2.update(data);

	if (shoot_p1) {
		for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
			if (bullets_p1[i].active == 0) {
				bullets_p1[i].shoot(player1.x, player1.y, player1.angle);
				break;
			}
		}
		shoot_p1 = false;
	}

	if (shoot_p2) {
		for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
			if (bullets_p2[i].active == 0) {
				bullets_p2[i].shoot(player2.x, player2.y, player2.angle);
				break;
			}
		}
		shoot_p2 = false;
	}

	for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
		bullets_p1[i].update(data);
		bullets_p2[i].update(data);
	}

	glLoadIdentity();

	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
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
	glutKeyboardUpFunc(keyboardUpListener);
	glutSpecialFunc(KeyboardMove);
	glutSpecialUpFunc(KeyboardMoveUp);

	glutTimerFunc(1, update, 0);
	glutMainLoop();
	return 0;
}

