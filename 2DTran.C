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
#define ESCAPE 27
#define LOAD_IMAGE_1 49
#define LOAD_IMAGE_2 50
#define TRANSLATION 116
#define ROTATION 114
#define SCALE 115
#define REFLECTION 101
#define SHEAR 121
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
double vertex[10][2];
typedef struct pt {
  double x;
  double y;
  double z;
} point;
point v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree;
point v1House, v2House, v3House, v4House, v5House, v6House;
point v7House, v8House, v9House, v10House, v11House, v12House, v13House;
point centerTree, centerHouse;

#include "trans/graphic.h";
#include "trans/bmpfiles.h";
#include "trans/matrix.h";
#include "trans/buttons.h";
#include "trans/shapes.h";
#include "trans/figures.h";


void main() {
  int i, j, pixelColor;
  double x, y, angle;
  int selectedImage;
  int selectedTransform;
  int rotateTree;
  int rotateHouse;
  int charTxt;
  BITMAP bitmap;
  SVGA(0x100, 640, 400);
  selectedImage = 1;
  selectedTransform = 0;
  rotateHouse = 0;
  rotateTree = 0;
  openFileBMP(0, 0, "trans/pfondo.bmp", &bitmap);
  //rotation(2,2,2,1, 45);

  initFig();
  
  charTxt = 0;
  while (charTxt != ESCAPE) {
    if (kbhit()) { //wait for char to be click
      charTxt = getch();
      switch(charTxt) {
        case LOAD_IMAGE_1:
          selectedImage = 1;
          break;
        case LOAD_IMAGE_2:
          selectedImage = 2;
          break;
        case RIGHT:
        if (selectedImage == 1) {
          if (selectedTransform == ROTATION) {
            angle = -30;
            rotateTree = 1;
          }
        }
        else {
          if (selectedTransform == ROTATION) {
            angle = -30;
            rotateHouse = 1;
          } 
        }
          break;
        case LEFT:
        if (selectedImage == 1) {
          if (selectedTransform == ROTATION) {
              angle = 30;
              rotateTree = 1;
          }
        }
        else {
          if (selectedTransform == ROTATION) {
              angle = 30;
              rotateHouse = 1;
          } 
        }
          break;
        case UP:
          printf("%s\n", "up" );
          break;
        case DOWN:
          printf("%s\n", "down" );
          break;
        case TRANSLATION:
          printf("%s\n", "translation" );
          break;
        case ROTATION:
          selectedTransform = ROTATION;
          break;
        case SCALE:
          printf("%s\n", "scale" );
          v1House = scale(v1House, 1.1, 1);
          v2House = scale(v2House, 1.1, 1);
          v3House = scale(v3House, 1.1, 1);
          v4House = scale(v4House, 1.1, 1);
          v5House = scale(v5House, 1.1, 1);
          v6House = scale(v6House, 1.1, 1);
          v7House = scale(v7House, 1.1, 1);
          v8House = scale(v8House, 1.1, 1);
          v9House = scale(v9House, 1.1, 1);
          v10House = scale(v10House, 1.1, 1);
          v11House = scale(v11House, 1.1, 1);
          v12House = scale(v12House, 1.1, 1);
          v13House = scale(v13House, 1.1, 1);

          break;
        case REFLECTION:
          printf("%s\n", "reflection" );
          break;
        case SHEAR:
            printf("%s\n", "shear" );
          break;
      }//closes switch
      if (rotateTree == 1) {
        eraseTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        v1Tree = rotation(v1Tree, centerTree, angle);
        v2Tree = rotation(v2Tree, centerTree, angle);
        v3Tree = rotation(v3Tree, centerTree, angle);
        v4Tree = rotation(v4Tree, centerTree, angle);
        v5Tree = rotation(v5Tree, centerTree, angle);
        v6Tree = rotation(v6Tree, centerTree, angle);
        v7Tree = rotation(v7Tree, centerTree, angle);
        drawTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        rotateTree = 0;
      } 
      if (rotateHouse == 1) {
        eraseHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        v1House = rotation(v1House, centerHouse, angle);
        v2House = rotation(v2House, centerHouse, angle);
        v3House = rotation(v3House, centerHouse, angle);
        v4House = rotation(v4House, centerHouse, angle);
        v5House = rotation(v5House, centerHouse, angle);
        v6House = rotation(v6House, centerHouse, angle);
        v7House = rotation(v7House, centerHouse, angle);
        v8House = rotation(v8House, centerHouse, angle);
        v9House = rotation(v9House, centerHouse, angle);
        v10House = rotation(v10House, centerHouse, angle);
        v11House = rotation(v11House, centerHouse, angle);
        v12House = rotation(v12House, centerHouse, angle);
        v13House = rotation(v13House, centerHouse, angle);
        drawHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        rotateHouse = 0;
      } 
    }//closes khbit
  }//closes while
}//closes main
  