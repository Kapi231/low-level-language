#include <cstdlib>
#include <curses.h>
#include <vector>

int main() 
{
  std::vector<char> buffer;
  
  int pos_x, pos_y;
  int lines = 0;

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
      case 259: //Arrow up
        if (unsigned(pos_y) > 0)
        {
          pos_y--;
        for (int i = pos_x; i > 0; i--)
          {
            if (buffer[i] == 10)
            {
              pos_x = pos_x - i;
              break;
            }
          }
        }
        
        ch = 0;
        break;
      case 258: //Arrow down
        if (pos_y < lines) 
        {
          pos_y++;
          for (int i = pos_x; i > 0; i++)
          {
            if (buffer[i] == 10)
            {
              pos_x = pos_x + i;
              break;
            }
          }
        }
        
        ch = 0;
        break;
      case 261: //Arrow right
        if (unsigned(pos_x) < buffer.size()) 
        {
          pos_x++;
        }
        ch = 0;
        break;
      case 260: //Arrow left
        //Prevents accesing negative number
        if (pos_x != 0) 
        {
          pos_x--;
        }
        ch = 0;
        break;
      case KEY_BACKSPACE:
        if (pos_x > 0) 
        {
          pos_x--;
          buffer.erase(buffer.begin() + pos_x);
        }
        ch = 0;
        break;
      case 10: // Return key
        pos_x++;
        //pos_y++;
        lines++;
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

    //We need to zero lines before every counting to not count same line twice or more
    lines = 0;

    //Display what is written on the buffer
    for (unsigned int i = 0; i < buffer.size(); i++)
    {
      printw("%c", buffer[i]);
      
      if (buffer[i] == 10) 
      {
        lines++;
      }
    }
    move(pos_y, pos_x);
    refresh();
  }
  endwin();
  
  exit(0);

  return 0;
}
