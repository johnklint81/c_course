# include <stdio.h>
#include <limits.h>

void PrintBits32(unsigned int u)
{
	char str[34];
	str[32] = '\n';
	str[33] = 0;
	for (int i = 31; i >= 0; i--)
	{
		str[i] = '0' + (u & 1);
		u >>= 1;
	}

	printf("%s", str);
}

int main(void) {
  unsigned int x, y, z1, z2, z3;  // 4 byte = 32 bits in an unsigned int
  
  printf("Enter unsigned ints x and y, separated by spaces: ");
  scanf("%d %d", &x, &y);
  // shift x y steps left, and shift x sizeof(int) - y steps right
  // the result is formed by bitwise or of these two numbers. CHAR_BIT 
  // gives the number of bits in a char
  z1 = x << y;
  z2 = x >> CHAR_BIT * sizeof(unsigned int) - y;
  z3 = z1 | z2;
  printf("%d\n", CHAR_BIT);
  PrintBits32(x);
  PrintBits32(CHAR_BIT * sizeof(unsigned int) - y);
  PrintBits32(z1);
  PrintBits32(z2);
  PrintBits32(z3);
  //z = x << y | x >> CHAR_BIT * sizeof(unsigned int) - y;
  printf("%u, %u, %u\n", z1, z2, z3);
  printf("x = %u shifted y = %u bits to the left is: %u\n", x, y, z3);

}
