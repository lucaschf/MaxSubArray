//
// Created by lucas on 9/10/2020.
//

#include <limits.h>
#include "MaxSubArray.h"

ContiguousSum findMaxCrossingSubArray(const int *array, int low, int middle, int high) {
    int sum = 0;
    int begin = 0;
    int end = 0;
    int i;

    int leftSum = INT_MIN;
    for (i = middle; i > low; i--) {
        sum += array[i];
        if (sum > leftSum) {
            leftSum = sum;
            begin = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (i = middle + 1; i < high; i++) {
        sum += array[i];
        if (sum > rightSum) {
            rightSum = sum;
            end = i;
        }
    }

    ContiguousSum s;

    s.low = begin;
    s.high = end;
    s.sum = rightSum + leftSum;

    return s;
}

ContiguousSum findMaxSubArray(int *array, int low, int high) {
    ContiguousSum leftContiguousSum;
    ContiguousSum rightContiguousSum;
    ContiguousSum crossingContiguousSum;

    if (low == high) {
        ContiguousSum s;

        s.low = low;
        s.high = high;
        s.sum = array[low];

        return s;
    }

    int middle = (low + high) / 2;

    leftContiguousSum = findMaxSubArray(array, low, middle);
    rightContiguousSum = findMaxSubArray(array, middle + 1, high);
    crossingContiguousSum = findMaxCrossingSubArray(array, low, middle, high);

    if (leftContiguousSum.sum >= rightContiguousSum.sum && leftContiguousSum.sum >= crossingContiguousSum.sum)
        return leftContiguousSum;

    if (rightContiguousSum.sum >= leftContiguousSum.sum && rightContiguousSum.sum >= crossingContiguousSum.sum)
        return rightContiguousSum;

    return crossingContiguousSum;
}