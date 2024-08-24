#include <cstdlib>
#include <curses.h>
#include <vector>

int main() 
{
  std::vector<char> buffer{};
  
  int cur_x, cur_y;
  int pos_x, pos_y;

  initscr();
  keypad(stdscr, 1);
  noecho();
  getyx(stdscr, pos_x, pos_y);

  while (1) 
  {
    getyx(stdscr, cur_y, cur_x);
    int x = getch();

    switch (x) {
      case KEY_LEFT:
        pos_x--;
        x = 0;
        break;
      case KEY_RIGHT:
        pos_x++;
        x = 0;
        break;
      case KEY_UP:
        pos_y++;
        x = 0;
        break;
      case KEY_DOWN:
        pos_y--;
        x = 0;
        break;
      default:
        pos_x++;
        break;
    }
    move(pos_x, pos_y);

    refresh();   
    buffer.insert(buffer.begin() + pos_x - 1, x);
    
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
