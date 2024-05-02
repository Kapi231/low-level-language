#include <stdio.h>

int digits[] = {4, 3, 2, 1};

void plusOne() {
    int x, digitsSize = (sizeof(digits) / 4);
    printf("size of array: %d\n", digitsSize);
    //Before
    printf("Before: ");
    for (x = 0; x < digitsSize; x++) {
        printf("%d", digits[x]);
    }
    if (digits[digitsSize - 1] != 9) {
        digits[digitsSize - 1] += 1;
    } 
    else {
        digits[digitsSize - 1] = 0;
        digits[digitsSize - 2] += 1;
    }
    //After
    printf("\nAfter: ");
    for (x = 0; x < digitsSize; x++) {
        printf("%d", digits[x]);
    }
}

int main() {
    plusOne();
    return 0;
}
