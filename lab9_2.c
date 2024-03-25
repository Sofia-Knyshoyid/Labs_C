#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*

+ init_vector() – dynamicznie alokuje tablicę danych na zadaną pojemność początkową i inicjalizuje pozostałe pola.
+ reserve() – realokuje tablicę danych tak, żeby miała co najmniej zadaną pojemność. Jeżeli zadana pojemność nie przekracza aktualnej, funkcja nic nie robi.
+ shrink_to_fit() – dopasuj rozmiar tablicy do aktualnej liczby elementów wektora,
+ push_back() – dodaj element o zadanej wartości na koniec wektora,
+ push_front() - dodaj element o zadanej wartości na początek wektora.
+ dump_data() - wyprowadź na ekran wszystkie dane zapisane w wektorze.
+ clear() – usuń wszystkie elementy z wektora.
+ insert() – dodaj element na zadanej pozycji.
+ erase() – usuń element wektora na zadanej pozycji.
+ erase_value() – usuń wszystkie elementy wektora o zadanej wartości.

*/


typedef struct vector{
        void* wsk_na_tabl;
        size_t el_size;
        int n;
        size_t pojemnosc; //ile jest zaalokowano
    } vect;


vect init_vector(size_t poj_pocz, size_t el_size_pocz){
    void* data = malloc(poj_pocz);
    if (data==NULL){
        printf("Blad w przydziale pamieci");
        exit(-1);
    }

    vect vct1;
    vct1.wsk_na_tabl = data;
    vct1.pojemnosc = poj_pocz;

    vct1.n = 0;
    vct1.el_size = el_size_pocz;

    return vct1;
}


void reserve(size_t nowa_poj, vect* vct){
    if (nowa_poj>vct->pojemnosc){    // couls also write (*vct).pojemnosc
        size_t nowa_pojemnosc;
        if (vct->pojemnosc==0){
            nowa_pojemnosc = nowa_poj;
        }
        else{
            nowa_pojemnosc = vct->pojemnosc*2; 
        }

        vct->wsk_na_tabl = realloc(vct->wsk_na_tabl, nowa_pojemnosc);
        vct->pojemnosc=nowa_pojemnosc;
    }
}

void shrink_to_fit(vect* vct){
    if (vct->pojemnosc>vct->el_size*vct->n){
        // shrink with realloc
        vct->wsk_na_tabl = realloc(vct->wsk_na_tabl, vct->el_size*vct->n);
        vct->pojemnosc = vct->el_size*vct->n;
    }
}

void dump_data(vect* vct){
    printf("\n");
    for (int i=0; i<vct->n; i++){
        void* wsk = vct->wsk_na_tabl + vct->el_size*i;
        printf("%f ", *(double*)wsk);
    }
    printf("\n");
}

void push_back(vect* vct, void* elem){
    reserve(vct->pojemnosc+1, vct);
    memmove(vct->wsk_na_tabl+(vct->n*vct->el_size), elem, vct->el_size);
    vct->n+=1;
}

void push_front(vect* vct, void* elem){
    reserve(vct->pojemnosc+1, vct);
    memmove(vct->wsk_na_tabl+vct->el_size, vct->wsk_na_tabl, vct->n*vct->el_size);
    memmove(vct->wsk_na_tabl, elem, vct->el_size);
    vct->n+=1;
}

void clear(vect* vct){
    if (vct->wsk_na_tabl != NULL){
        free(vct->wsk_na_tabl);
    }
    vct->n = 0;
    vct->pojemnosc = 0;
}

void insert(vect* vct, void* elem, int idx){
    /*
    8 4 5 3 2 _ _
          |
    8 4 5   3 2 _ _     
    */

    reserve(vct->pojemnosc+1, vct);
    if (idx<=vct->n){
       size_t shift1 = idx*vct->el_size;
       size_t shift2 = (idx+1)*vct->el_size;
       int el_to_move = vct->n-idx;
       memmove(vct->wsk_na_tabl+shift2, vct->wsk_na_tabl+shift1, (el_to_move)*vct->el_size);
       memmove(vct->wsk_na_tabl+shift1, elem, vct->el_size);
       vct->n+=1;
    }
}

void erase(vect* vct, int idx){

    /*
    8 4 5 3 2 1 _ _
          |
    8 4 5 2 1 _ _ --    
    */

    if (idx<vct->n){
        size_t shift1 = idx*vct->el_size;
        size_t shift2 = (idx+1)*vct->el_size;
        int el_to_move = vct->n-idx-1;
        memmove(vct->wsk_na_tabl+shift1, vct->wsk_na_tabl+shift2, (el_to_move)*vct->el_size);
        vct->n-=1;
    }

}


int find_value (vect* vct, void* elem){
    for (int i=0; i<vct->n; i++){
        void* curr_wsk = vct->wsk_na_tabl+i*sizeof(vct->el_size);
        double curr_val = *((double*)curr_wsk);
        if (curr_val == *((double*)elem)){
            return i;
        }
    }
    // if nothing was found
    return -1;
}

void erase_value(vect* vct, void* val){
    int flag = find_value(vct, val);
    while (flag!=-1)
    {
        erase(vct, flag);
        flag = find_value(vct, val);
    }
    
}



int main(void){

    vect V1 = init_vector(5*sizeof(double), sizeof(double));
    double el = 1.;

    push_front(&V1, &el);
    el = 2.;
    push_front(&V1, &el);

    el=10.;
    push_back(&V1, &el);
    el=2.;
    push_back(&V1, &el);
    el=14.;
    push_back(&V1, &el);
    el=16.;
    push_back(&V1, &el);

    el=100.;
    push_front(&V1, &el);

    reserve(sizeof(double)*15, &V1);
    shrink_to_fit(&V1);

    clear(&V1);

    reserve(sizeof(double)*15, &V1);
    el=1.;
    push_back(&V1, &el);
    el=2.;
    push_back(&V1, &el);
    el=3.;
    push_back(&V1, &el);
    el=-1.;
    push_front(&V1, &el);
    

    el=8;
    insert(&V1, &el, 1);

    erase(&V1, 2);

    el=2.;
    push_back(&V1, &el);

    erase_value(&V1, &el);


    dump_data(&V1);



}