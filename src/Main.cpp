#include <iostream>
#include <clocale>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
//#include <opencv/cv.h>
#include "LoadTexture.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "MainConst.h"

GLfloat gCameraX = 0.f, gCameraY = 0.f;

struct map_t map;
Player player(WIDTH_D / 2, HEIGHT_D / 2, 0);
Bullet bullets[MAX_BULLETS_ON_SCREEN];
Asteroid asteroids[MAX_ASTEROIDS_ON_SCREEN];

static int shoot = 0;

std::string buff;

void update(int value);

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
	}
}

void keyboardListener(unsigned char c, int x, int y) {
	switch (c) {
		case 'q':
			exit(0);
			break;
		case ' ':
			shoot = 1; //TODO: Optimise bullets
			break;
		case 'm':
			map = std::string(map.name) == "./map.bmp" ? LoadTexture("./map2.bmp") : LoadTexture("./map.bmp");
			break;
	}
}

void output(GLfloat x, GLfloat y, std::string text) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.08, 0.08, 0);
	for (unsigned int i = 0; i < text.length(); i++) {
		glColor3f(0.0, 0.0, 0.0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
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

	glPopMatrix();
	//TODO: Understand (fix) the workings of this part
	glPushMatrix();

	//glTranslatef(WIDTH_D / 2.0, HEIGHT_D / 2.0, 0.0);

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

	if (player.angle >= 360) {
		player.angle = 0;
	}
	if (player.angle <= -360) {
		player.angle = 0;
	}
	player.drawPlayer();

	for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
		if (bullets[i].active) {
			bullets[i].drawBullet();
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

	player.update();

	if (player.left) {
		player.angle += ROTATE_SPEED;
	}
	if (player.right) {
		player.angle -= ROTATE_SPEED;
	}
	if (player.moving) {
		player.x = player.x - PLAYER_SPEED * sin(player.angle * M_PI / 180);
		player.y = player.y + PLAYER_SPEED * cos(player.angle * M_PI / 180);
		//gCameraX = player.x - CAMERA_SPEED * sin(player.angle * M_PI / 180);
		//gCameraY = player.y + CAMERA_SPEED * cos(player.angle * M_PI / 180);
	}
	if (shoot == 1) {
		for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
			if (bullets[i].active == 0) {
				bullets[i].active = 1;
				bullets[i].x = player.x;
				bullets[i].y = player.y;
				bullets[i].angle = player.angle;
				break;
			}
		}
		shoot = 0;
	}
	for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
		if (bullets[i].active == 1) {
			bullets[i].update(data);
		}
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();

	//glTranslatef(-gCameraX, -gCameraY, 0.0);

	glPushMatrix();

	glutPostRedisplay();
	glutTimerFunc(33, update, 0);
}

void Initialize() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, WIDTH_D, 0.0, HEIGHT_D, -5.0, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	map = LoadTexture("./map2.bmp");

	glClearColor(0, 0, 0, 1.0);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH_D-1, HEIGHT_D);
	glutCreateWindow("Lab 2");

	Initialize();

	glutDisplayFunc(Display);

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(KeyboardMove);
	glutSpecialUpFunc(KeyboardMoveUp);

	glutTimerFunc(33, update, 0);
	glutMainLoop();
	return 0;
}

