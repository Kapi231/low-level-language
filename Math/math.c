#include <math.h>

int factorial(int i) {
    int j = i;
    for (i--; i > 0; i--) {
        j *= i;
    }
    return j;
}