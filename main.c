#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
 * Alexander Allis
 * Finds the minimum and maximum value of an array.
 * The size of the array must be a power of 2.
 */


struct pair {
    int min;
    int max;
};

struct pair Min_Max(int * A, int i, int j) {

    // The Trivial Case
    if( j - i == 1 ) {  // size of A = 2
        struct pair result;
        if(A[i] > A[j]) {
            result.min = A[j];
            result.max = A[i];
        }
        else {
            result.min = A[i];
            result.max = A[j];
        }
        return result;
    }

    struct pair a = Min_Max(A, i,(int) floor( (double) (j - i) / 2) + i);
    struct pair b = Min_Max(A, (int) floor( (double) (j - i) / 2) + i + 1, j);
    struct pair result;

    if(a.min > b.min) result.min = b.min;
    else result.min = a.min;
    if(a.max > b.max) result.max = a.max;
    else result.max = b.max;

    return result;

}

int main() {
    printf("Running the min-max program!\n");

    int A[] = {4, 14, 11, 9, 1, 3};

    struct pair result = Min_Max(A, 0, 6);

    printf("%d\n", result.min);
    printf("%d\n", result.max);

    return 0;
}

