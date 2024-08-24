#include <cstdlib>
#include <curses.h>
#include <vector>

int main() 
{
  std::vector<char> buffer{};
  
  int cur_x, cur_y;

  initscr();
  keypad(stdscr, 1);
  noecho();


  while (1) 
  {
    getyx(stdscr, cur_y, cur_x);
    char x = getch();

    buffer.insert(buffer.end(), x);
    
    //Clears screen after every display
    clear();
    refresh();

    //Display what is written on the buffer
    for (int i = 0; i < buffer.size(); i++)
    {
      printw("%c", buffer[i]);
    }
  }
  endwin();

  return 0;
}
