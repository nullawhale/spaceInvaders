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
	//unsigned int width, height;
	unsigned int imageSize;   // width*height*3
	unsigned char * rgb_data; // RGB data
	int counter = 0;

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

	imageSize = *(int*)&(header[0x22]); // data position at 0x0A
	pekish_var.width = *(int*)&(header[0x12]);
	pekish_var.height = *(int*)&(header[0x16]);
	pekish_var.data = new unsigned char * [pekish_var.width];
	for(unsigned int i = 0; i < pekish_var.width; i++){
		pekish_var.data[i] = new unsigned char[pekish_var.height];
	}

	rgb_data = new unsigned char[imageSize];

	fread(rgb_data, 1, imageSize, file);
	fclose(file);

	for (unsigned int i = 0; i < pekish_var.width; i++){
		for (unsigned int j = 0; j < pekish_var.height; j++){
			pekish_var.data[i][j] = rgb_data[counter];
			counter++;
		}
	}

	glGenTextures(1, &pekish_var.texture);
	glBindTexture(GL_TEXTURE_2D, pekish_var.texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
              pekish_var.width, pekish_var.height,
              0, GL_BGR, GL_UNSIGNED_BYTE, rgb_data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //TODO: Understand how it works!
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return pekish_var;
}
