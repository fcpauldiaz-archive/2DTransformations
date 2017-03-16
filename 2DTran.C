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
  double x, y, angle, scaleX, scaleY, shear, traslate;
  int selectedImage;
  int selectedTransform;
  int rotateTree, traslateTree, scaleTree, shearTree;
  int rotateHouse, traslateHouse, scaleHouse, shearHouse;
  int charTxt;
  double factor;
  BITMAP bitmap;


  SVGA(0x100, 640, 400);
  selectedImage = 1;
  selectedTransform = 0;
  rotateHouse = 0; rotateTree = 0; traslateHouse = 0; traslateTree = 0;
  scaleTree = 0; scaleHouse = 0; shearTree = 0; shearHouse = 0;
  scaleX = 1.0; scaleY = 1.0; factor = 0.1;
  openFileBMP(0, 0, "trans/pfondo.bmp", &bitmap);

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
          if (selectedTransform == SCALE) {
            scaleX += factor;
            scaleTree = 1;
          }
        }
        else {
          if (selectedTransform == ROTATION) {
            angle = -30;
            rotateHouse = 1;
          } 
          if (selectedTransform == SCALE) {
            scaleX += factor;
            scaleHouse = 1;
          }
        }
          break;
        case LEFT:
        if (selectedImage == 1) {
          if (selectedTransform == ROTATION) {
              angle = 30;
              rotateTree = 1;
          }
          if (selectedTransform == SCALE) {
            scaleX -= factor;
            scaleTree = 1;
          }
        }
        else {
          if (selectedTransform == ROTATION) {
              angle = 30;
              rotateHouse = 1;
          } 
          if (selectedTransform == SCALE) {
            scaleX -= factor;
            scaleHouse = 1;
          }
        }
          break;
        case UP:
          if (selectedImage == 1) {
            if (selectedTransform == SCALE) {
              scaleY += factor;
              scaleTree = 1;
            }
          }
          else {
            if (selectedTransform == SCALE) {
              scaleY += factor;
              scaleHouse = 1;
            }
          }
          break;
        case DOWN:
          if (selectedImage == 1) {
            if (selectedTransform == SCALE) {
              scaleY -= factor;
              scaleTree = 1;
            }
          }
          else {
            if (selectedTransform == SCALE) {
              scaleY -= factor;
              scaleHouse = 1;
            }
          }
          break;
        case TRANSLATION:
          printf("%s\n", "translation" );
          break;
        case ROTATION:
          selectedTransform = ROTATION;
          break;
        case SCALE:
          selectedTransform = SCALE;
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
      if (scaleTree == 1) {
        printf("%f\n", scaleX);
        printf("%f\n", scaleY );
        eraseTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        v1Tree = scale(v1Tree, scaleX, scaleY);
        v2Tree = scale(v2Tree, scaleX, scaleY);
        v3Tree = scale(v3Tree, scaleX, scaleY);
        v4Tree = scale(v4Tree, scaleX, scaleY);
        v5Tree = scale(v5Tree, scaleX, scaleY);
        v6Tree = scale(v6Tree, scaleX, scaleY);
        v7Tree = scale(v7Tree, scaleX, scaleY);
        drawTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        scaleTree = 0;
      }
      if (scaleHouse == 1) {
        eraseHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        v1House = scale(v1House, scaleX, scaleY);
        v2House = scale(v2House, scaleX, scaleY);
        v3House = scale(v3House, scaleX, scaleY);
        v4House = scale(v4House, scaleX, scaleY);
        v5House = scale(v5House, scaleX, scaleY);
        v6House = scale(v6House, scaleX, scaleY);
        v7House = scale(v7House, scaleX, scaleY);
        v8House = scale(v8House, scaleX, scaleY);
        v9House = scale(v9House, scaleX, scaleY);
        v10House = scale(v10House, scaleX, scaleY);
        v11House = scale(v11House, scaleX, scaleY);
        v12House = scale(v12House, scaleX, scaleY);
        v13House = scale(v13House, scaleX, scaleY);
        drawHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        scaleHouse = 0;
      }
    }//closes khbit
  }//closes while
}//closes main
  