#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <locale.h>
#include <stdio.h>
#include "LoadTexture.h"
#include "MainConst.h"
	
struct Pekish LoadTexture(const char* filename){
        struct Pekish pekish_var;
	//GLuint texture;
	unsigned char header[54]; // Every BMP starts with 54bit header
	unsigned int width, height;
	unsigned int imageSize;   // width*height*3
	//unsigned char * data; // RGB data

	FILE* file = fopen(filename, "rb");
	if (!file) {
		printf("Image could not be opened");
	}

	if (fread(header, 1, 54, file) != 54) { // reading 54 bites
		printf("Not a correct BMP file\n");
	}

	if(header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
	}

	imageSize  = *(int*)&(header[0x22]); // data position at 0x0A
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);


	pekish_var.data = new unsigned char[imageSize];
	fread(pekish_var.data, 1, imageSize, file);
	fclose(file);

        glGenTextures(1, &pekish_var.texture);

	glBindTexture(GL_TEXTURE_2D, pekish_var.texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, pekish_var.data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //TODO: Understand how it works!
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return pekish_var;
}
