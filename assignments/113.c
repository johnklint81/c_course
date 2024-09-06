#include <stdio.h>
#include <conio.h>

// f)
int main()
{
    while (!kbhit())
        printf("Press a key\n");
 
    return 0;
}
/* 
 e) and d) gives compilation errors, thus wrong. 
 a) and b) comments the line as intended, but in b) the star, backslash is unnecessary.
 c) prints the statement, which is probably not intended.
 */

int main(void) {
/* printf("Skriv ut..."); */
// printf("Skriv */ ut...");
printf("// Skriv ut...");
//printf(//"Skriv ut...");
//printf(/* Skriv ut... */"");
}
