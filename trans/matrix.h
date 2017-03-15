#define PI 3.14159265

typedef struct pt {
  double x;
  double y;
  double z;
} point;


point multiply(int x, int y, double firstMatrix[3][3])
{
  int i, j, k;
  point p;
  double secondMatrix[3][1];
  double mult[3][1];
  secondMatrix[0][0] = x;
  secondMatrix[1][0] = y; 
  secondMatrix[2][0] = 1;

  // Initializing elements of matrix mult to 0.
  for(i = 0; i < 3; ++i)
  {
    for(j = 0; j < 1; ++j)
    {
      mult[i][j] = 0;
    }
  }

  // Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
  for(i = 0; i < 3; ++i)
  {
    for(j = 0; j < 1; ++j)
    {
      for(k=0; k < 3; ++k)
      {
        mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
      }
    }
  }
  p.x = mult[0][0];
  p.y = mult[1][0];
  p.z = mult[2][0];
  printf("%.6f\n", p.x);
  printf("%.6f\n", p.y);
  printf("%.6f\n", p.z);
  return p;

}

point translation(int x, int y, int x1, int y1) {
  point p;
  p.x = x + x1;
  p.y = y + y1;
  return p;
}

point rotation(int x, int y, int a, int b, int angle) {
  point p;
  double matrix[3][3];
  double val;
  double radians = angle*PI / 180.0;
  matrix[0][0] =  cos(radians);
  matrix[0][1] = -1*sin(radians);
  matrix[0][2] = -a*cos(radians) + b*sin(radians) + a;
  matrix[1][0] = sin(radians);
  matrix[1][1] = cos(radians);
  matrix[1][2] = -a*sin(radians) -b*cos(radians) + b;
  matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
  return multiply(x, y, matrix);
}
