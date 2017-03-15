/**
 * Pablo Diaz 6/02/2017
 * Universidad del Valle de Guatemala
 * Paint en C++ y assembler de Intel
 */

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>

#define MAX_VERTICES 100
int vertex[MAX_VERTICES][2];
int undoCounter = 0;
int redoCounter = 0;

#include "trans/graphic.h";
#include "trans/bmpfiles.h";
#include "trans/mouse.h";

void main() {
  int i, j;
  BITMAP bitmap;
  SVGA(0x100, 640, 400);
  initMouse();
  adaptMouse(640, 400);
  //openFileBMP(0, 0, "trans/pfondo.bmp", &bitmap);
  
  //draw house
  for (i=0; i < 640; i++) {
    for (j=0; j < 400; j++) {
      putPixel(i, j, 255);
    }
  }
  while(1) {

  }
  
  
  //draw tree

}
  