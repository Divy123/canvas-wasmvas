
#include <stdio.h>
#include <emscripten.h>
#include <stdlib.h>
#include <time.h>


#define NUM_CIRCLES 500

struct Circle{
    int x;
    int y;
    int r;
    int cr;
    int cb;
    int cg;
};

struct animationDataArray{
    int x;
    int y;
    int r;
    int xv;
    int yv;
    int xd;
    int yd;
};

struct Circle circles[NUM_CIRCLES];
struct animationDataArray animationData[NUM_CIRCLES];

int getRand(int max){
    return (rand()%max);
}

int main() {
    
    srand(time(NULL));
    for(int i = 0; i< NUM_CIRCLES; i++){
        int radius= getRand(50);
        int x = getRand(1000)+radius;
        int y = getRand(1000)+radius;
        circles[i].x = x;
        circles[i].y = y;
        circles[i].r = radius;
        circles[i].cr = getRand(255);
        circles[i].cb = getRand(255);
        circles[i].cg = getRand(255);

        animationData[i].x = x;
        animationData[i].y = y;
        animationData[i].r = radius;
        animationData[i].xv = getRand(10);
        animationData[i].yv = getRand(10);
        animationData[i].yd = 0;
        animationData[i].xd = 1;

    }

  printf("Init circles\n");
  EM_ASM({render($0,$1);}, NUM_CIRCLES*6, 6);
  
}

struct Circle * getCircles( int canvasWidth, int canvasHeight ) {

  for( int i = 0; i < NUM_CIRCLES; i++ ) {

    if( (animationData[i].x + animationData[i].r) >= canvasWidth ) animationData[i].xd = 0;

    if( (animationData[i].x - animationData[i].r) <= 0 ) animationData[i].xd = 1;

    if( (animationData[i].y - animationData[i].r) <= 0 ) animationData[i].yd = 1;

    if( (animationData[i].y + animationData[i].r) >= canvasHeight ) animationData[i].yd = 0;

    if( animationData[i].xd == 1 ) {
      animationData[i].x += animationData[i].xv;
    } else {
      animationData[i].x -= animationData[i].xv;
    }
    if( animationData[i].yd == 1 ) {
      animationData[i].y += animationData[i].yv;
    } else {
      animationData[i].y -= animationData[i].yv;
    }

    circles[i].x = animationData[i].x;
    circles[i].y = animationData[i].y;
  }

  return circles;
}

