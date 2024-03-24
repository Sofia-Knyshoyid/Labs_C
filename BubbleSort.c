#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//scanf("%s", tab); - bedzie czytac do pierwszej spacji
//scanf("%99s", tab); - wpisze 99 zankow i znak zerowy np, nie bedzie pisal poza tablicą
//np abc\0
//NB: jezeli pierwsze idą spacje, scanf bedzie
//czekac na pierwszy znak drukowalny

//mozna stworzyc duza tablice, ale w funkcji
//w tej funkcji uzyc malloc dla przydzielenia pamieci

char* read_str(){
    char bufor[100], *ptr;
    int len;
    scanf("%99s", bufor);
    len = strlen(bufor)+1;
    char c = bufor[len-1];
    // if (c=='\0'){
    //     printf("!!!");
    // }
    
    ptr = (char*) malloc(len*sizeof(char));
    if (ptr == NULL){printf("Bład w przydziale pamięci"); exit(1);}
    strcpy(ptr, bufor); //strcpy(dokąd, skąd)
    return ptr;
    //pamiętać, by potem zwolnić miejsce
    
}

// char* toChar(char * ptr){
//     char dest[] = "";
//     // char chr = *ptr;
//     // char* chpt = ptr;
//     // ptr = ptr+1;
//     size_t num = 1;
//     while (*ptr!='\0'){
//         // char add = *ptr;
//         strncat(dest, ptr, num);
//         ptr = ptr+1;
//     }
//     return dest;
// }


void bubbleSort(int elements[], int n){
    int i,j,sorted;
    for (i=0; i<n-1; i++){
        sorted = 1;
        for (j=0; j<n-i-1; j++){
            if (elements[j]<elements[j+1]){
                int temp = elements[j];
                elements[j]=elements[j+1];
                elements[j+1]=temp;
                sorted = 0;
            } 
        }
        if (sorted) {break;}    
    } 
}


void print_str_no_sort(char ** table, int n){
    for (int j=0; j<n; j++){
        // printf("\n");
        char* ptr = table[j];
        while (*ptr!='\0'){
            printf("%c", *ptr);
            ptr = ptr+1;
        }
    }
}

// 0 1 2 3
// _ _ _ _

// ab
// ad
// bf
// aa

void print_str(char ** table, int n){
    int tab[n];
    for (int k=0; k<n; k++){
        tab[k] = k;
    }


    // bac cab acb
    // 0   1   2


    // lista
    // bac acb cab
    // 0   2   1
    int a,b,sorted;
    for (a=0; a<n-1; a++){
        sorted = 1;
        for (b=0; b<n-a-1; b++){
            char val1 = *table[tab[b]];
            char val2 = *table[tab[b+1]];
            if (val1>val2){
                int temp = tab[b];
                tab[b]=tab[b+1];
                tab[b+1]=temp;
                sorted = 0;
            } 
        }
        if (sorted) {break;}    
    } 


    // 0 1 2 3
    // ab aa ac d

    // 1 0 2 3

    for (int m=0; m<n; m++){
        int j = tab[m];
        char* ptr = table[j];
        while (*ptr!='\0'){
            printf("%c", *ptr);
            ptr = ptr+1;
        }
        printf("\n");
    }
}


int main(void) {
    int n;
    scanf("%d", &n);

    

    // char* table[n];
    	
    char ** table = (char**)malloc(n * sizeof(char*));


    for (int i=0; i<n; i++){
        char *ptr_1 = read_str();
        table[i] = ptr_1;
    }

    print_str(table, n);
    
    for (int f; f<n; f++){
        free(table[f]);
    }
    free(table);
    
    return 0;
}

