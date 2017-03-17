point make_point(int a, int b) {
    point f;
    f.x = a;
    f.y = b;
    return f;
}

void drawHouse(point v1, point v2, point v3, point v4, point v5,  point v6, point v7, point v8, point v9, point v10, point v11, point v12, point v13) {
     //draw triangle
     drawLine(v1.x, v1.y, v2.x, v2.y, 14, 1);
     drawLine(v2.x, v2.y, v3.x, v3.y, 14, 1);
     drawLine(v3.x, v3.y, v1.x, v1.y, 14, 1);
     vertex[0][0] = v1.x;
     vertex[0][1] = v1.y;
     vertex[1][0] = v2.x;
     vertex[1][1] = v2.y;
     vertex[2][0] = v3.x;
     vertex[2][1] = v3.y;
     scanLine(3, 14, 1);
     //draw rectangle
     drawLine(v2.x, v2.y, v3.x, v3.y, 200, 1);
     drawLine(v3.x, v3.y, v5.x, v5.y, 200, 1);
     drawLine(v5.x, v5.y, v4.x, v4.y, 200, 1);
     drawLine(v4.x, v4.y, v2.x, v2.y, 200, 1);
     vertex[0][0] = v2.x;
     vertex[0][1] = v2.y;
     vertex[1][0] = v3.x;
     vertex[1][1] = v3.y;
     vertex[2][0] = v5.x;
     vertex[2][1] = v5.y;
     vertex[3][0] = v4.x;
     vertex[3][1] = v4.y;
     scanLine(4, 200, 1);
     //draw door
     drawLine(v8.x, v8.y, v9.x, v9.y, 100, 1);
     drawLine(v9.x, v9.y, v7.x, v7.y, 100, 1);
     drawLine(v7.x, v7.y, v6.x, v6.y, 100, 1);
     drawLine(v6.x, v6.y, v8.x, v8.y, 100, 1);
     vertex[0][0] = v8.x;
     vertex[0][1] = v8.y;
     vertex[1][0] = v9.x;
     vertex[1][1] = v9.y;
     vertex[2][0] = v7.x;
     vertex[2][1] = v7.y;
     vertex[3][0] = v6.x;
     vertex[3][1] = v6.y;
     scanLine(4, 100, 1);
      //draw window
     drawLine(v10.x, v10.y, v11.x, v11.y, 9, 1);
     drawLine(v11.x, v11.y, v13.x, v13.y, 9, 1);
     drawLine(v13.x, v13.y, v12.x, v12.y, 9, 1);
     drawLine(v12.x, v12.y, v10.x, v10.y, 9, 1);
     vertex[0][0] = v10.x;
     vertex[0][1] = v10.y;
     vertex[1][0] = v11.x;
     vertex[1][1] = v11.y;
     vertex[2][0] = v13.x;
     vertex[2][1] = v13.y;
     vertex[3][0] = v12.x;
     vertex[3][1] = v12.y;
     scanLine(4, 9, 1);

}


void eraseHouse(point v1, point v2, point v3, point v4, point v5,  point v6, point v7, point v8, point v9, point v10, point v11, point v12, point v13) {
     //draw triangle
     drawLine(v1.x, v1.y, v2.x, v2.y, 255, 1);
     drawLine(v2.x, v2.y, v3.x, v3.y, 255, 1);
     drawLine(v3.x, v3.y, v1.x, v1.y, 255, 1);
     vertex[0][0] = v1.x;
     vertex[0][1] = v1.y;
     vertex[1][0] = v2.x;
     vertex[1][1] = v2.y;
     vertex[2][0] = v3.x;
     vertex[2][1] = v3.y;
     scanLine(3, 255, 1);
     //draw rectangle
     drawLine(v2.x, v2.y, v3.x, v3.y, 255, 1);
     drawLine(v3.x, v3.y, v5.x, v5.y, 255, 1);
     drawLine(v5.x, v5.y, v4.x, v4.y, 255, 1);
     drawLine(v4.x, v4.y, v2.x, v2.y, 255, 1);
     vertex[0][0] = v2.x;
     vertex[0][1] = v2.y;
     vertex[1][0] = v3.x;
     vertex[1][1] = v3.y;
     vertex[2][0] = v5.x;
     vertex[2][1] = v5.y;
     vertex[3][0] = v4.x;
     vertex[3][1] = v4.y;
     scanLine(4, 255, 1);
     //draw door
     drawLine(v8.x, v8.y, v9.x, v9.y, 255, 1);
     drawLine(v9.x, v9.y, v7.x, v7.y, 255, 1);
     drawLine(v7.x, v7.y, v6.x, v6.y, 255, 1);
     drawLine(v6.x, v6.y, v8.x, v8.y, 255, 1);
     vertex[0][0] = v8.x;
     vertex[0][1] = v8.y;
     vertex[1][0] = v9.x;
     vertex[1][1] = v9.y;
     vertex[2][0] = v7.x;
     vertex[2][1] = v7.y;
     vertex[3][0] = v6.x;
     vertex[3][1] = v6.y;
     scanLine(4, 255, 1);
      //draw window
     drawLine(v10.x, v10.y, v11.x, v11.y, 255, 1);
     drawLine(v11.x, v11.y, v13.x, v13.y, 255, 1);
     drawLine(v13.x, v13.y, v12.x, v12.y, 255, 1);
     drawLine(v12.x, v12.y, v10.x, v10.y, 255, 1);
     vertex[0][0] = v10.x;
     vertex[0][1] = v10.y;
     vertex[1][0] = v11.x;
     vertex[1][1] = v11.y;
     vertex[2][0] = v13.x;
     vertex[2][1] = v13.y;
     vertex[3][0] = v12.x;
     vertex[3][1] = v12.y;
     scanLine(4, 255, 1);

}


void drawTree(point v1, point v2, point v3, point v4, point v5, point v6, point v7) {
     //draw rectangle
     drawLine(v4.x, v4.y, v6.x, v6.y, 120, 1);
     drawLine(v6.x, v6.y, v5.x, v5.y, 120, 1);
     drawLine(v5.x, v5.y, v7.x, v7.y, 120, 1);
     drawLine(v7.x, v7.y, v4.x, v4.y, 120, 1);
     vertex[0][0] = v4.x;
     vertex[0][1] = v4.y;
     vertex[1][0] = v6.x;
     vertex[1][1] = v6.y;
     vertex[2][0] = v5.x;
     vertex[2][1] = v5.y;
     vertex[3][0] = v7.x;
     vertex[3][1] = v7.y;
     scanLine(4, 120, 1);
     //draw triangle
     vertex[0][0] = v1.x;
     vertex[0][1] = v1.y;
     vertex[1][0] = v2.x;
     vertex[1][1] = v2.y;
     vertex[2][0] = v3.x;
     vertex[2][1] = v3.y;
     scanLine(3, 60, 1);
     drawLine(v1.x, v1.y, v2.x, v2.y, 60, 3);
     drawLine(v2.x, v2.y, v3.x, v3.y, 60, 3);
     drawLine(v3.x, v3.y, v1.x, v1.y, 60, 3);
}


void eraseTree(point v1, point v2, point v3, point v4, point v5, point v6, point v7) {
     //draw rectangle
     drawLine(v4.x, v4.y, v6.x, v6.y, 255, 1);
     drawLine(v6.x, v6.y, v5.x, v5.y, 255, 1);
     drawLine(v5.x, v5.y, v7.x, v7.y, 255, 1);
     drawLine(v7.x, v7.y, v4.x, v4.y, 255, 1);
     vertex[0][0] = v4.x;
     vertex[0][1] = v4.y;
     vertex[1][0] = v6.x;
     vertex[1][1] = v6.y;
     vertex[2][0] = v5.x;
     vertex[2][1] = v5.y;
     vertex[3][0] = v7.x;
     vertex[3][1] = v7.y;
     scanLine(4, 255, 1);
     vertex[0][0] = v1.x;
     vertex[0][1] = v1.y;
     vertex[1][0] = v2.x;
     vertex[1][1] = v2.y;
     vertex[2][0] = v3.x;
     vertex[2][1] = v3.y;
     scanLine(3, 255, 1); 
     //draw triangle
     drawLine(v1.x, v1.y, v2.x, v2.y, 255, 3);
     drawLine(v2.x, v2.y, v3.x, v3.y, 255, 3);
     drawLine(v3.x, v3.y, v1.x, v1.y, 255, 3);
}


void initFig() {
  v1Tree = make_point(200,100);
  v2Tree = make_point(130,236);
  v3Tree = make_point(266,236);
  v4Tree = make_point(183,236);
  v5Tree = make_point(215,289);
  v6Tree = make_point(215, 236);
  v7Tree = make_point(183, 289);
  centerTree = make_point(200, 168);

  v1House = make_point(400, 100);
  v2House = make_point(330, 180);
  v3House = make_point(465, 180);
  v4House = make_point(330, 306);
  v5House = make_point(465, 306);
  v6House = make_point(377, 306);
  v7House = make_point(420, 306);
  v8House = make_point(377, 260);
  v9House = make_point(420, 260);
  v10House = make_point(340, 210);
  v11House = make_point(370, 210);
  v12House = make_point(340, 236);
  v13House = make_point(370, 236);
  centerHouse = make_point(400, 203);
  drawTree(
    v1Tree,
    v2Tree,
    v3Tree,
    v4Tree,
    v5Tree,
    v6Tree,
    v7Tree
  );

   drawHouse(
    v1House, v2House,
    v3House, v4House,
    v5House, v6House,
    v7House, v8House,
    v9House, v10House,
    v11House,v12House,
    v13House
  );
}
