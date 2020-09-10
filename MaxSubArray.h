//
// Created by lucas on 9/10/2020.
//

#ifndef MAXSUBARRAY_MAXSUBARRAY_H
#define MAXSUBARRAY_MAXSUBARRAY_H

typedef struct {
    int low;
    int high;
    int sum;
} ContiguousSum;

ContiguousSum findMaxSubArray(int *array, int low, int high);

#endif //MAXSUBARRAY_MAXSUBARRAY_H
