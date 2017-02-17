#ifndef __CONSTS__
#define __CONSTS__

const double WIDTH_D  = 640.0;
const double HEIGHT_D = 480.0;
const int WIDTH_I  = 640;
const int HEIGHT_I = 480;

const int PLAYER_SPEED = 4;
const int ROTATE_SPEED = 7;
const int BULLET_SPEED = 7;
const int CAMERA_SPEED = 7;
const int ASTEROID_SPEED = 2;

const int PLAYER_SIZE = 10;
const int BULLET_SIZE = 3;
const int ASTEROID_SIZE = 3;

const int MAX_BULLETS_ON_SCREEN = 100;
const int MAX_ASTEROIDS_ON_SCREEN = 2;

#define M_PI 3.14159265358979323846

/*using u8 = unsigned char;
using u16 = unsigned short;
using u32 =  unsigned int;*/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#endif // __CONSTS__
