//
// Created by valeria on 13.01.20.
//

#include "../include/auxiliaryFuncs.h"

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void merge(int array[], int l, int m, int r){
    int i,
        j,
        k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = array[l + i];
    for(j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

int partition (int array[], int low, int high){
    int pivot = array[high];
    int i = (low - 1);

    for(int j = low; j <= high- 1; j++){
        if (array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
} 