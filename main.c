#include <stdio.h>

#include "MaxSubArray.h"

#define MAXIMUM_CONTIGUOUS_SUM "Soma maxima contigua"
#define INTERVAL_BETWEEN "Intervalo entre"
#define AND "e"


void printContiguousSum(ContiguousSum contiguousSum){
    printf(
            "\n%s %d \n%s %d %s %d\n\n",
            MAXIMUM_CONTIGUOUS_SUM,
            contiguousSum.sum,
            INTERVAL_BETWEEN,
            contiguousSum.low,
            AND,
            contiguousSum.high
    );
}

void printArray(int array[], int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}

void test() {
    int firstArray[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int firstSize = 9;

    int secondArray[] = {10, 5, -17, 20, 50, -1, 3, -30, 10};
    int secondSize = 9;

    int thirdArray[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int thirdSize = 8;

    printArray(firstArray, firstSize);
    printContiguousSum(findMaxSubArray(firstArray, 0, firstSize - 1));

    printArray(secondArray, secondSize);
    printContiguousSum(findMaxSubArray(secondArray, 0, secondSize - 1));

    printArray(thirdArray, thirdSize);
    printContiguousSum(findMaxSubArray(thirdArray, 0, thirdSize - 1));
}

int main() {
    test();
    return 0;
}