#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* myturn(void* v){
    int* iptr = (int*) v;
    int* iptr2 = malloc(sizeof(int));
    for(int i = 0; i < 10; i++){
        sleep(1);
        printf("My turn, v = %d\n", *iptr);
        (*iptr)++;
        (*iptr2) += 2;
    }
    return iptr2;
}

void yourturn(){
    for(int i = 0; i < 2; i++){
        sleep(1);
        printf("Your turn\n");
    }
}

int main(void){
    pthread_t th1;
    int v = 5;
    pthread_create(&th1, NULL, myturn, &v);
    //myturn();
    yourturn();
    int* result;
    pthread_join(th1, (void**) &result);
    printf("All done, the result is %d\n", *result);

    return 0;
}