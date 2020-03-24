//
// Created by valeria on 13.01.20.
//

#include "../include/sortingAlgorithms.h"


void bubbleSort(int array[], int n){
    int i,
        j;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
}

void insertionSort(int array[], int n){
    int key,
        i = 0;

    for(int j = 1; j < n; j++){
        key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            i = i - 1;
            array[i + 1] = key;
        }
    }
}

void selectionSort(int array[], int n){
    int i,
        j,
        min_index;

    for(i = 0; i < n-1; i++){
        min_index = i;
        for(j = i+1; j < n; j++)
            if(array[j] < array[min_index])
                min_index = j;
        swap(&array[min_index], &array[i]);
    }
}

void mergeSort(int array[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void quickSort(int array[], int low, int high){
    if (low < high){
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
} 
  
