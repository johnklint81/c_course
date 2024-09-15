#include <stdio.h>


int fun1(void) {
  int a = 2;
  a *= 2;
  return a;
}

int fun2(void) {
  int b = 2;
  b *= 3;
  return b;
}

int fun3(void) {
  int c = 2;
  c *= 4;
  return c;
}

int main(void) {
  int (*ipFunks[3])(void);
  ipFunks[0] = fun1;
  ipFunks[1] = fun2;
  ipFunks[2] = fun3;
  
  printf("%d\n", ipFunks[0]());
  printf("%d\n", ipFunks[1]());
  printf("%d\n", ipFunks[2]());


}
