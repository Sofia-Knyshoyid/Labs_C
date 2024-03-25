#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>

#define BUF_SIZE   512
#define STR_NO_MAX 10000







//________________________________________


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


//------------------------------------------------

typedef struct lancuch{
        char* adres; // adres lańcucha
        int krotnosc; // krotność powtórzenia
    } Lancuch;


int my_compare_str(const void* str1, const void* str2) {
    return strcasecmp(((Lancuch*)str1)->adres, ((Lancuch*)str2)->adres);
}


int main(void) {
    char buffer[BUF_SIZE];
    char *str_tab[STR_NO_MAX];
    FILE *plik;
    plik = fopen("tekst_linux.txt","r");
    if(plik==NULL) {
        printf("Blad w fopen\n");
        exit(1);
        }

    

    Lancuch lancuchy[STR_NO_MAX];
    int liczba_lancuchow = 0;
    int liczba_wczytanych = 0;

    char* ptr = fgets(buffer, BUF_SIZE, plik);
    while (ptr != NULL) {
        // printf("%s", ptr);
        // printf("\n");
        
        
        char* token = strtok(buffer, "  .,():?!\n\"");


        while (token != NULL) {
            liczba_wczytanych+=1;

            // printf("%s", token);
            // printf("\n");

            // Czy lancuch juz byl zapamietany? uzyto bsearch
            Lancuch key;
            key.adres = token;
            qsort(lancuchy, liczba_lancuchow, sizeof(Lancuch), my_compare_str);
            Lancuch* found = bsearch(&key, lancuchy, liczba_lancuchow, sizeof(Lancuch), my_compare_str);

            if (found != NULL) {
                // Juz jest zapamietany, zwiekszyc krotnosc
                found->krotnosc++;
            } else {
                // Nie byl jeszcze zapamietany, zapisac
                char* temp_ptr = malloc(strlen(token) + 1);
                strcpy(temp_ptr, token);


                lancuchy[liczba_lancuchow].adres = temp_ptr;
                lancuchy[liczba_lancuchow].krotnosc = 1;
                liczba_lancuchow++;
            }


            token = strtok(NULL, "  .,():?!\n\"");
            
        }

        ptr = fgets(buffer, BUF_SIZE, plik);

    }

    
    qsort(lancuchy, liczba_lancuchow, sizeof(Lancuch), my_compare_str);
    // for (int i=0; i<liczba_lancuchow; i++) {
    //     printf("%s\n", lancuchy[i].adres);
    // }

    fclose(plik);
    printf("%d %d", liczba_lancuchow, liczba_wczytanych);
    return 0;

}