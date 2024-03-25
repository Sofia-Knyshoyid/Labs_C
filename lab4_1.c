/*
Program powinien weryfikować
poprawność wczytywanych danych. 

Przykład
Wejście: 1000  15  3
Wyjście: 2140257223
*/

// castowanie (pl - rzutowanie: (double)34)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OCENIAJ 1  // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 

void recordNums(int *elements, int n, int seed) {
    srand(seed);
    for (int i=0; i<n; i++){
    int randnum = rand();
    elements[i]=randnum;
    }
}

void printTable(int *table, int n){ 
    for (int k=0; k<n; k++){
        printf("%d\n", table[k]);
    }
    printf("\n");
}

void printEl(int *table, int n){ 
    for (int k=0; k<n; k++){
        printf("%d\n", table[k]);
    }
    printf("\n");
}

void printElem(int *table, int m){
    printf("%d", table[m]);
}


void BubbleSort(int elements[], int n)
{
    int i, j, sorted;
    for (i=0; i<n-1; i++) {
        sorted = 1;
        for (j=0; j<n-i-1; j++) {
            if (elements[j] < elements[j+1]) {
                //exchange two elements, smaller to the right
                int temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
                sorted = 0; 
            }
        }

        //check if list is already sorted
        if (sorted) {break;}
    }
}


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}



int main(void) {
    int n, seed, indx;
    if(OCENIAJ == 0) printf("Wpisz rozmiar tablicy: ");
    scanf("%d",&n);
    if(OCENIAJ == 0) printf("Wpisz wartosc zarodka: ");
    scanf("%d",&seed);
    if(OCENIAJ == 0) printf("Wpisz indeks wypisywanego elementu: ");
    scanf("%d",&indx);
    if(n<=0||indx<0) return 0;
    int elements[n];

    recordNums(elements, n, seed);
    BubbleSort(elements, n);
    // printTable(elements, n);
    printf("\n");
    printElem(elements, indx);

    return 0;
}