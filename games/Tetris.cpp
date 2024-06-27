#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

char table[8][5] = {
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
  {'.','.','.','.','.'},
};

int main() {
  int y = 0;
  int x = 2;

  while(1) {
    system("clear");
    for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 5; j++) {
        if(j == x && i == y) {
          table[i][j] = '*';
        } else {
          table[i][j] = '.';
        }
        std::cout << table[i][j];
      }
      std::cout << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    y++;

  };

  return 0;
}
