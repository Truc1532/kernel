#include "include/variables.h"

// variables
char *video_mem = (char *)0xB8000;
int cursor_x = 0;
int cursor_y = 0;
const unsigned int screenWidth = 80;
const unsigned int screenHeight = 25;

// colors
const unsigned char blue = 0x01;
const unsigned char green = 0x02;
const unsigned char red = 0x04;
const unsigned char yellow = 0x0E;
const unsigned char gray = 0x07;
unsigned char color = gray;

