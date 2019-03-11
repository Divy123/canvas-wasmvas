
#include <stdio.h>
#include <emscripten.h>


int main() {

  printf("Init circles\n");
  emscripten_run_script("render()");
}

int getCircles() {
  return 1;
}
