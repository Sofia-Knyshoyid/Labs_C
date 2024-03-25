#include <stdio.h>

#define OCENIAJ 1 // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 
#define SIZE   10  // rozmiar tablicy
//Wejście: 3  2
//Wyjście: -2 10 11 12 13 14 15 16 -1 -1



void recordNums(int *elements, int n) {
    for (int i=0; i<n; i++){
    elements[i]=-2;
    }
}

void printTable(int *table, int n){ 
    for (int k=0; k<n; k++){
        printf("%d ", table[k]);
    }
    printf("\n");
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1 2 3 4
// 1 2 3 4 5

void swapArr(int* a, int n){
    int half = n/2;
    for (int b=0; b<half; b++){
        int* ptr1=&a[b]; int* ptr2= &a[n-b-1];
        swap(ptr1, ptr2);
    }
}

void w_prawo(int *elements, int n, int p){
    int do_indx = (p-1)+p;
    // printf(" do_ind\n");
    if (p==0){
        return;
    }
    if (do_indx<=n){
        //przesuwamy
        int last_ind = n-p-1; // np last_ind=3 dla p=3 
        for (int ind=last_ind; ind>-1; ind--){
            // printf(" ind=%d, el1=%d, el2=%d\n", ind, elements[ind], elements[ind+p]);
            int* ptr_1 = &elements[ind];
            int* ptr_2 = &elements[ind+p];
            swap(ptr_1, ptr_2);
            elements[ind]=-2;
            // printf(" swapped\n");
        }

    }
    else {
        do_indx = do_indx - (n-1); //tyle wykroczy, dla n=7 to 4
        if (p>n){
            recordNums(elements, n);
            return;
        }
        //zamiana
        for (int ind=p-1-do_indx; ind>-1; ind--){
            // printf(" ind=%d, el1=%d, el2=%d\n", ind, elements[ind], elements[(n-1-((p-1-do_indx)-ind))]);
            int* ptr_1 = &elements[ind];
            int* ptr_2 = &elements[(n-1-((p-1-do_indx)-ind))];
            swap(ptr_1, ptr_2);
            // printf(" swapped\n");
        }
        for (int j=0; j<p; j++){
            elements[j]=-2;
        }

    }
}

void w_lewo(int *elements, int n, int p){
    swapArr(elements, n);
    w_prawo(elements, n, p);
    for (int idx=0; (idx<n)&&(idx<p); idx++){
        elements[idx] = -1;
    }
    swapArr(elements, n);

}

int main(void) {
    int tab[SIZE] = {10,11,12,13,14,15,16,17,18,19};
    int move1, move2;
    if(OCENIAJ == 0) printf("Wpisz wielkosc przesuniecia w prawo: ");
    scanf("%d",&move1);
    if(OCENIAJ == 0) printf("Wpisz wielkosc przesuniecia w lewo: ");
    scanf("%d",&move2);

    w_prawo(tab, SIZE, move1);
    // printTable(tab, 10);
    w_lewo(tab, SIZE, move2);
    printTable(tab, SIZE);

    
    

    return 0;
}