/*
 * BESCHREIBUNG: Dieses Programm misst die Laufzeit von 5 Sortieralgorithmen,
 *               die in sortingAlgorithms.c implementiert sind.
 *
 * AUSFUEHREN:   Kompilieren im Terminal: gcc main.c src/sortingAlgorithms.c src/auxiliaryFuncs.c -o programmname
 *               Es erwartet eine txt-Datei als Parameter, die mit Integern
 *               gefuellt ist (z.B. wie in input.txt).
 *               Ihr koennt euch auch mit einem selbst implementierten
 *               Randomgenerator ganz viele Zahlen generieren lassen.
 *
 * ANMERKUNG:    Insertion Sort wird hier in den meisten Faellen der am schnellsten fertig.
 *               Macht euch Gedanken, woran das liegt, bzw. recherchiert dazu. Dafuer lohnt
 *               es sich genauer die Implementierung der Algorithmen anzuschauen.
 *
 * TIPP:         https://visualgo.net/en/sorting
 */

#include <sys/time.h>
#include <time.h>
#include "./include/sortingAlgorithms.h"

#define MAXSIZE 16000

struct file_information{
    int array[MAXSIZE];
    int count;
};

struct file_information readFile(int argc, char* argv[]);
void startSortingAlgorithms(int array[], int numbers);

int main(int argc, char* argv[]){

    struct file_information file = readFile(argc, argv);
    startSortingAlgorithms(file.array, file.count);

    return 0;
}

struct file_information readFile(int argc, char* argv[]){

    struct file_information fileInfo;

    if(argc != 2){
        perror("Wrong input, filename is required.");
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if(file == NULL) {
        perror("This file doesn't exist!");
        exit(EXIT_FAILURE);
    }

    int array[MAXSIZE];
    int count = 0;

    while(count < MAXSIZE && (fscanf(file, "%d", &array[count]) != EOF)){
        count++;
    }

    for(int i = 0; i < count; i++)
        fileInfo.array[i] = array[i];
    fileInfo.count = count;

    fclose(file);

    return fileInfo;
}

void printTimeDiff(struct timeval t1, struct timeval t2, char sortAlgo[]){
    struct timeval t_result;
    timersub(&t2, &t1, &t_result);
    printf("%s: \n Needed time : %ld.%06ld\n", sortAlgo, t_result.tv_sec, t_result.tv_usec);
}

void startSortingAlgorithms(int array[], int numbers){

    struct timeval t1,
                   t2,
                   t3,
                   t4,
                   t5,
                   t6;

    gettimeofday(&t1, NULL);
    bubbleSort(array, numbers);
    gettimeofday(&t2, NULL);

    insertionSort(array, numbers);
    gettimeofday(&t3, NULL);

    selectionSort(array, numbers);
    gettimeofday(&t4, NULL);

    mergeSort(array, 0, numbers - 1);
    gettimeofday(&t5, NULL);

    quickSort(array, 0, numbers - 1);
    gettimeofday(&t6, NULL);

    printTimeDiff(t1, t2, "Bubble Sort");
    printTimeDiff(t2, t3, "Insertion Sort");
    printTimeDiff(t3, t4, "Selection Sort");
    printTimeDiff(t4, t5, "Merge Sort");
    printTimeDiff(t5, t6, "Quick Sort");
}
