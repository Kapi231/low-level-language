#include <stdio.h>

int main() {
  int array[] = {4, 7, 8, 6, 5, 1, 0, 9, 3, 2};
  int arrayLenght = sizeof(array) / sizeof(array[0]);
  int current, lowest, checkIndex, i, j;

  printf("Unsorted:\n");
  //Print array before sorting
  for (i = 0; i < arrayLenght; i++) {
    printf("> %d\n", array[i])  ; 
  }
  //sorting...
  for (i = 0; i < arrayLenght - 1; i++) {
    current = array[i];
    lowest = array[i];

    for (j = i + 1; j < arrayLenght; j++) {
      if (array[j] < lowest) {
        lowest = array[j];
        checkIndex = j;
      }
    }
    if (array[i] != lowest) {
      array[i] = lowest;
      array[checkIndex] = current;
    }
  } 
  
  printf("\n<------------------------->\n\nSorted:\n");
  //Print array after sorting
  for (i = 0; i < arrayLenght; i++) {
    printf("> %d\n", array[i]);
  }
}
