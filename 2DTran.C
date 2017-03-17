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
  double x, y, angle, scaleXTree, scaleYTree, scaleXHouse, scaleYHouse, shear;
  double traslateXTree, traslateYTree, traslateXHouse, traslateYHouse;
  double shearXTree, shearYTree, shearXHouse, shearYHouse;
  int selectedImage;
  int selectedTransform, traslate;
  int rotateTree, traslateTree, scaleTree, shearTree;
  int rotateHouse, traslateHouse, scaleHouse, shearHouse;
  int charTxt;
  double factorIncrease, factorDecrease, factorTraslate, factorShear;
  BITMAP bitmap;


  SVGA(0x100, 640, 400);
  selectedImage = 1;
  selectedTransform = 0;
  rotateHouse = 0; rotateTree = 0; traslateHouse = 0; traslateTree = 0;
  scaleTree = 0; scaleHouse = 0; shearTree = 0; shearHouse = 0;
  scaleXTree = 1.0; scaleYTree = 1.0; factorIncrease = 1.1; factorDecrease = 0.95;
  scaleXHouse = 1.0; scaleYHouse = 1.0; traslate = 0;
  factorTraslate = 20.0; factorShear = 0.1;
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
            scaleXTree = factorIncrease;
            scaleTree = 1;
          }
          //MOVE TREE
          if (selectedTransform == TRANSLATION) {
            traslateXTree = factorTraslate;
            traslateTree = 1;
          }
          if (selectedTransform == SHEAR) {
            shearXTree = factorShear;
            shearTree = 1;
          } 
        }
        else {
          //rotate house
          if (selectedTransform == ROTATION) {
            angle = -30;
            rotateHouse = 1;
          } 
          //scale house
          if (selectedTransform == SCALE) {
            scaleXHouse = factorIncrease;
            scaleHouse = 1;
          }
          //move house to the right
          if (selectedTransform == TRANSLATION) {
            traslateXHouse = factorTraslate;
            traslateHouse = 1;
          }
          if (selectedTransform == SHEAR) {
            shearXHouse = factorShear;
            shearHouse = 1;
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
            scaleXTree = factorDecrease;
            scaleTree = 1;
          }
          if (selectedTransform == TRANSLATION) {
            traslateXTree = -factorTraslate;
            traslateTree = 1;
          }
          if (selectedTransform == SHEAR) {
            shearXTree = -factorShear;
            shearTree = 1;
          }
        }
        else {
          if (selectedTransform == ROTATION) {
              angle = 30;
              rotateHouse = 1;
          } 
          if (selectedTransform == SCALE) {
            scaleXHouse = factorDecrease;
            scaleHouse = 1;
          }
          //traslate house to the left
          if (selectedTransform == TRANSLATION) {
            traslateXHouse = -factorTraslate;
            traslateHouse = 1;
          }
          if (selectedTransform == SHEAR) {
            shearXHouse = -factorShear;
            shearHouse = 1;
          }
        }
          break;
        case UP:
          if (selectedImage == 1) {
            if (selectedTransform == SCALE) {
              scaleYTree = factorIncrease;
              scaleTree = 1;
            }
            //move tree up
            if (selectedTransform == TRANSLATION) {
              traslateYTree = -factorTraslate;
              traslateTree = 1;
            }
            if (selectedTransform == SHEAR) {
              shearYTree = -factorShear;
              shearTree = 1;
            }
          }
          else {
            if (selectedTransform == SCALE) {
              scaleYHouse = factorIncrease;
              scaleHouse = 1;
            }
            //move house up
            if (selectedTransform == TRANSLATION) {
              traslateYHouse = -factorTraslate;
              traslateHouse = 1;
            }
            if (selectedTransform == SHEAR) {
              shearYHouse = -factorShear;
              shearHouse = 1;
            }
          }
          break;
        case DOWN:
          if (selectedImage == 1) {
            if (selectedTransform == SCALE) {
              scaleYTree = factorDecrease;
              scaleTree = 1;
            }
            if (selectedTransform == TRANSLATION) {
              traslateYTree = factorTraslate;
              traslateTree = 1;
            }
            if (selectedTransform == SHEAR) {
              shearYTree = factorShear;
              shearTree = 1;
            }
          }
          else {
            if (selectedTransform == SCALE) {
              scaleYHouse = factorDecrease;
              scaleHouse = 1;
            }
            if (selectedTransform == TRANSLATION) {
              traslateYHouse = factorTraslate;
              traslateHouse = 1;
            }
            if (selectedTransform == SHEAR) {
              shearYHouse = factorShear;
              shearHouse = 1;
            }
          }
          break;
        case TRANSLATION:
          selectedTransform = TRANSLATION;
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
            selectedTransform = SHEAR;
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
        eraseTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        v1Tree = scale(v1Tree, centerTree, scaleXTree, scaleYTree);
        v2Tree = scale(v2Tree, centerTree, scaleXTree, scaleYTree);
        v3Tree = scale(v3Tree, centerTree, scaleXTree, scaleYTree);
        v4Tree = scale(v4Tree, centerTree, scaleXTree, scaleYTree);
        v5Tree = scale(v5Tree, centerTree, scaleXTree, scaleYTree);
        v6Tree = scale(v6Tree, centerTree, scaleXTree, scaleYTree);
        v7Tree = scale(v7Tree, centerTree, scaleXTree, scaleYTree);
        drawTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        scaleTree = 0;
      }
      if (scaleHouse == 1) {
        eraseHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        v1House = scale(v1House, centerHouse, scaleXHouse, scaleYHouse);
        v2House = scale(v2House, centerHouse, scaleXHouse, scaleYHouse);
        v3House = scale(v3House, centerHouse, scaleXHouse, scaleYHouse);
        v4House = scale(v4House, centerHouse, scaleXHouse, scaleYHouse);
        v5House = scale(v5House, centerHouse, scaleXHouse, scaleYHouse);
        v6House = scale(v6House, centerHouse, scaleXHouse, scaleYHouse);
        v7House = scale(v7House, centerHouse, scaleXHouse, scaleYHouse);
        v8House = scale(v8House, centerHouse, scaleXHouse, scaleYHouse);
        v9House = scale(v9House, centerHouse, scaleXHouse, scaleYHouse);
        v10House = scale(v10House, centerHouse, scaleXHouse, scaleYHouse);
        v11House = scale(v11House, centerHouse, scaleXHouse, scaleYHouse);
        v12House = scale(v12House, centerHouse, scaleXHouse, scaleYHouse);
        v13House = scale(v13House, centerHouse, scaleXHouse, scaleYHouse);
        drawHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        scaleHouse = 0;
      }
      if (traslateTree == 1) {
        eraseTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        v1Tree = traslation(traslateXTree, traslateYTree, v1Tree);
        v2Tree = traslation(traslateXTree, traslateYTree, v2Tree);
        v3Tree = traslation(traslateXTree, traslateYTree, v3Tree);
        v4Tree = traslation(traslateXTree, traslateYTree, v4Tree);
        v5Tree = traslation(traslateXTree, traslateYTree, v5Tree);
        v6Tree = traslation(traslateXTree, traslateYTree, v6Tree);
        v7Tree = traslation(traslateXTree, traslateYTree, v7Tree);
        centerTree = traslation(traslateXTree, traslateYTree, centerTree);
        drawTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        traslateXTree = 0;
        traslateYTree = 0;
        traslateTree = 0;
      }
      if (traslateHouse == 1) {
        eraseHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        v1House = traslation(traslateXHouse, traslateYHouse, v1House);
        v2House = traslation(traslateXHouse, traslateYHouse, v2House);
        v3House = traslation(traslateXHouse, traslateYHouse, v3House);
        v4House = traslation(traslateXHouse, traslateYHouse, v4House);
        v5House = traslation(traslateXHouse, traslateYHouse, v5House);
        v6House = traslation(traslateXHouse, traslateYHouse, v6House);
        v7House = traslation(traslateXHouse, traslateYHouse, v7House);
        v8House = traslation(traslateXHouse, traslateYHouse, v8House);
        v9House = traslation(traslateXHouse, traslateYHouse, v9House);
        v10House = traslation(traslateXHouse, traslateYHouse, v10House);
        v11House = traslation(traslateXHouse, traslateYHouse, v11House);
        v12House = traslation(traslateXHouse, traslateYHouse, v12House);
        v13House = traslation(traslateXHouse, traslateYHouse, v13House);
        centerHouse = traslation(traslateXHouse, traslateYHouse, centerHouse);
        drawHouse(v1House, v2House, v3House, v4House, v5House,
          v6House, v7House, v8House, v9House, v10House, v11House,
          v12House, v13House
        );
        scaleHouse = 0;
        traslateXHouse = 0;
        traslateYHouse = 0;

      }
      if (shearTree == 1) {
        eraseTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        v1Tree = shea(shearXTree, shearYTree, v1Tree);
        v2Tree = shea(shearXTree, shearYTree, v2Tree);
        v3Tree = shea(shearXTree, shearYTree, v3Tree);
        v4Tree = shea(shearXTree, shearYTree, v4Tree);
        v5Tree = shea(shearXTree, shearYTree, v5Tree);
        v6Tree = shea(shearXTree, shearYTree, v6Tree);
        v7Tree = shea(shearXTree, shearYTree, v7Tree);
        drawTree(v1Tree, v2Tree, v3Tree, v4Tree, v5Tree, v6Tree, v7Tree);
        shearTree = 0;
      }

    }//closes khbit
  }//closes while
}//closes main
  