#include <cstdlib>
#include <curses.h>
#include <vector>

int main() 
{
  std::vector<char> buffer{};
  
  int pos_x, pos_y;

  initscr();

  keypad(stdscr, 1);
  noecho();
  
  getyx(stdscr, pos_y, pos_x);
  move(pos_y, pos_x);
  refresh();

  while (1) 
  {
    int ch = getch();
    
    switch (ch) {
      case KEY_RIGHT:
        if (unsigned(pos_x) < buffer.size()) 
        {
          pos_x++;
        }
        ch = 0;
        break;
      case KEY_LEFT:
        //Prevents accesing negative number
        if (pos_x != 0) 
        {
          pos_x--;
        }
        ch = 0;
        break;
      case KEY_BACKSPACE:
        if (pos_x != 0) 
        {
          pos_x--;
          buffer.erase(buffer.begin() + pos_x);
        }
        ch = 0;
        break;
      default:
        pos_x++;
        break;
    }
    
    //Prevents from trying to insert at negative position
    if (ch != 0) 
    {
      buffer.insert(buffer.begin() + pos_x - 1, ch);
    }
    
    //Clears screen after every display
    clear();
    refresh();

    //Display what is written on the buffer
    for (unsigned int i = 0; i < buffer.size(); i++)
    {
      printw("%c", buffer[i]);
    }

    move(pos_y, pos_x);
    refresh();
  }
  endwin();

  return 0;
}
