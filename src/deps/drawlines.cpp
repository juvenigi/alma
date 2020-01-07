#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void setPixel(int x, int y, unsigned int image[][1001]){ // due to overflow
  //  int cx = abs((int) corr_w * x);
  //  int cy = abs((int) corr_h * y);
  image[x][y] = 0;
}

void line(int x0, int y0, int x1, int y1, unsigned int image[][1001]) {

  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = (dx>dy ? dx : -dy)/2, e2;

  for(;;){
    setPixel(x0,y0, image);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}
