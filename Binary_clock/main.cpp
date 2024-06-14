#include <ctime>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
  int binaryArray[6] = {1, 2, 4, 8, 16, 32};

  int storeOutput[6];
  int storeNum = 0;
  
  while (1) {
    clock_t targetNum = clock() / CLOCKS_PER_SEC;
  
    for (int i = 5; i >= 0; i--) {
      if(storeNum + binaryArray[i] <= targetNum) {
        storeNum += binaryArray[i];
        storeOutput[i] = 1;
      } else {
        storeOutput[i] = 0;
      }
    }
    for (int x = 5; x >= 0; x--) {
      cout << storeOutput[x];
    }
    cout << endl;
    storeNum = 0;
  }
  return 0;
}
