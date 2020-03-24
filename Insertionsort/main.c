/*
 * Um das Programm auszufuehren, muesst es nach dem Kompilieren wie folgt aufrufen:
 * ./programmname numbers.txt
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000 //Konstante

void printArray(int array[], int len);
void insertion_sort(int array[], int len);

int main(int argc, char *argv[]) {

    if(argc != 2){ //Fehlerbehandlung bei falscher Argumentenuebergabe
        perror("Falsche Argumentenuebergabe, Dateiname erforderlich.");
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1]; //Name der Datei abrufen und in filename speichern
    FILE* file = fopen(filename, "r"); //Datei lesen

    if(file == NULL) {
        perror("Datei existiert nicht!");
        exit(EXIT_FAILURE);
    }

    int array[MAXSIZE]; //erstellen einen Array mit Groesse MAXSIZE=1000
    int count = 0; //Zaehlervariabel

    /*
     * Mit fscanf lesen wir die Integer aus der Datei file aus und
     * speichern sie an der entsprechenden Stelle im Array.
     * Das geht so lange bis das Ende der Datei (EOF) erreicht ist oder
     * der Array voll.
     */

    while(count < MAXSIZE && (fscanf(file, "%d", &array[count]) != EOF)){
        count++;
    }

    fclose(file); //File wieder schliessen

    printArray(array, count); //geben den Inhalt der Datei aus, also die unsortierte Zahlenfolge

    insertion_sort(array, count); //rufen insertionsort auf

    printArray(array, count); //geben die sortiere Reihenfolge aus

    return 0;
}

void printArray(int array[], int len){

    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertion_sort(int array[], int len){ //unser implementierter Sortieralgorithmus Insertionsort

    int key,
        i = 0;

    for(int j = 1; j < len; j++){
        key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            i = i - 1;
            array[i + 1] = key;
        }
    }
}
