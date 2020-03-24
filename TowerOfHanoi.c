/*
 * This program solves recursively the tower of hanoi problem.
 * It tells you how to move every disk step by step.
 * The smallest disk is number 1 and the largest n.
 *
 * Help: https://www.youtube.com/watch?v=fffbT41IuB4&t=441s
 */

#include <stdio.h>

#define DISKS 4     // Number of disks

void towerOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod);

int main(void){

    int n = DISKS;
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}


void towerOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod){

    if (n == 1){
        printf("Move disk 1 from rod %c to rod %c.\n", source_rod, destination_rod);
        return;
    }

    towerOfHanoi(n-1, source_rod, auxiliary_rod, destination_rod);

    printf("Move disk %d from rod %c to rod %c.\n", n, source_rod, destination_rod);

    towerOfHanoi(n-1, auxiliary_rod, destination_rod, source_rod);
}