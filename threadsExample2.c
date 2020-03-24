/*
 * Um die verbrauchte Zeit des Programms zu messen, fuehre es mit "time ./programmname" aus.
 */

#include <stdint.h>
#include <stdio.h>
#include <pthread.h>

#define BIG 1000000000UL

uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* count_to_big(){
    for(int i = 0; i < BIG; i++){
        pthread_mutex_lock(&lock);
        counter = counter + 1;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void count_to_zero(){
    for(int i = 0; i < BIG; i++){
        counter--;
    }
}

int main(void){
    pthread_t th1;
    pthread_create(&th1, NULL, count_to_big, NULL);
    //count_to_big();
    count_to_big();
    //count_to_zero();
    printf("Done, counter = %u\n", counter);
    pthread_join(th1, NULL);
    return 0;
}