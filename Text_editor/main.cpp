#include <cstdlib>
#include <curses.h>

int main() 
{
  initscr();
  keypad(stdscr, 1);
  noecho();

  while (1) 
  {
    char x = getch();
    
    printw("%c", x);
  }
    endwin();
  return 0;
}
