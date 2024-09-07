#include <stdio.h>
#include <ncurses.h>

// f)

int main() {
    initscr();            // Initialize ncurses mode
    cbreak();             // Disable line buffering, pass keypresses directly
    noecho();             // Disable echoing the characters typed by user
    nodelay(stdscr, TRUE); // Make getch() non-blocking
    keypad(stdscr, TRUE); // Enable function keys and arrow keys

    printw("Press any key to stop...\n");
    refresh();

    while (1) {
        int ch = getch();  // Get the key press, non-blocking

        if (ch != ERR) {  // If a key has been pressed
            printw("Key '%c' pressed. Exiting...\n", ch);
            refresh();
            break;
        }
    }

    endwin();  // End ncurses mode
    return 0;
}

// a) /* printf("Skriv ut..."); */
// b) // printf("Skriv */ ut...");
// c) printf("// Skriv ut...");
// d) printf(//"Skriv ut...");
// e) printf(/* Skriv ut... */"");

/* 
 e) and d) gives compilation errors, thus wrong. 
 a) and b) comments the line as intended, but in b) the star, backslash is unnecessary.
 c) prints the statement, which is probably not intended.
 */
