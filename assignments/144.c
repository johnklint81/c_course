# include <stdio.h>

int main(void) {
  unsigned int x, y, z;
  
  printf("Enter x and y, separated by spaces: ");
  scanf("%d %d", &x, &y);
  // shift x y steps left, and shift x sizeof(int) - y steps right
  // the result is formed by bitwise or
  z = (x << y | x >> sizeof(int) - y);
  printf("x shifted y bits is: %d\n", z);

}
