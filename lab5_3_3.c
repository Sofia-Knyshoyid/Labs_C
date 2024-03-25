#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4             // liczba lancuchow
#define STR_LEN_MAX 100 // maksymalna dlugosc lancucha (liczona z '\0')

/*
C strcmp() Prototype
The function prototype of strcmp() is:

int strcmp (const char* str1, const char* str2);
*/



char* read_string_2D(){
    char bufor[STR_LEN_MAX], *ptr;
    int len;
    scanf("%99s", bufor);
    len = strlen(bufor)+1;
    char c = bufor[len-1];
    
    ptr = (char*) malloc(len*sizeof(char));
    if (ptr == NULL){printf("Bład w przydziale pamięci"); exit(1);}
    strcpy(ptr, bufor); //strcpy(dokąd, skąd)
    return ptr;
    
}


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

int is_bigger(char* chr1, char* chr2, int num){
    char val1 = *(chr1+num); char val2 = *(chr2+num);
    if (val1>=65 && val1<=90){val1=val1+32;}
    else{val1=val1;}
    if (val2>=65 && val2<=90){val2=val2+32;}
    else{val2=val2;}

    if ((val1 == '\0')||(val2 == '\0')){
        if (val1 == '\0'){val2=91;}
        else {val1 == 91;}}
    
    if ((val1) == (val2)){return is_bigger(chr1, chr2, num+1);}

    if (val1>val2){return 1;}
    else{return 0;}
}


void print_str_no_sort(char ** table, int n){
    for (int j=0; j<n; j++){
        char* ptr = table[j];
        while (*ptr!='\0'){
            printf("%c", *ptr);
            ptr = ptr+1;
        }
    }
}


int sortf(int n, char **table, int *tab, int letter){
    int a,b,sorted, same;
    for (a=0; a<n-1; a++){
        sorted = 1; same = 1;
        for (b=0; b<n-a-1; b++){
            char val1 = *table[tab[b]];
            char val2 = *table[tab[b+1]];
            char val_por1, val_por2;
            if (val1>=65 && val1<=90){val_por1=val1+32;}
            else{val_por1=val1;}
            if (val2>=65 && val2<=90){val_por2=val2+32;}
            else{val_por2=val2;}

            if ((val_por1 == '\0')||(val_por2 == '\0')){
                if (val_por1 == '\0'){val_por2=91;}
                else {val_por1 == 91;}
            
                }
            if (val_por1 == val_por2){same += 1; printf("\nsame +1!\n");}
            if (val_por1>val_por2){
                int temp = tab[b];
                tab[b]=tab[b+1];
                tab[b+1]=temp;
                sorted = 0;
            
            printf("\n");
            for (int e=0;a<4;e++){printf("%d ",tab[e]);}
            } 
        }
        if (sorted) {return same;}    
    }
    return same;
}


void print_str(char* table[], int n){
    int tab[n];
    for (int k=0; k<n; k++){
        tab[k] = k;
    }

    int letter = 0;




    int a,b,sorted, same;
    for (a=0; a<n-1; a++){
        sorted = 1;
        for (b=0; b<n-a-1; b++){
            char* val01 = table[tab[b]];
            char* val02 = table[tab[b+1]];
            char val1 = *table[tab[b]];
            char val2 = *table[tab[b+1]];
            char val_por1=val1; char val_por2 = val2;

            if (val1>=65 && val1<=90){val_por1=val1+32;}
            else{val_por1=val1;}
            if (val2>=65 && val2<=90){val_por2=val2+32;}
            else{val_por2=val2;}

            if (val_por1 == val_por2){
                int is = is_bigger(val01, val02,0);
                if (is==1){
                    int temp = tab[b];
                    tab[b]=tab[b+1];
                    tab[b+1]=temp;
                    sorted = 0;
                }}
    
            if (val_por1>val_por2){
                int temp = tab[b];
                tab[b]=tab[b+1];
                tab[b+1]=temp;
                sorted = 0;
            
            } 
        
    }
}


    for (int m=0; m<n; m++){
        int j = tab[m];
        char* ptr = table[j];
        while (*ptr!='\0'){
            printf("%c", *ptr);
            ptr = ptr+1;
        }
        printf(" ");
    }
}



int main(void) {

    

    char** table = (char**)malloc(N * sizeof(char*));
    int i=0;
    char str[STR_LEN_MAX*N];
    for (i; i<N; i++){
        char *ptr_1 = read_string_2D();
        table[i] = ptr_1;
    }

    print_str(table, N);



    for (int f; f<N; f++){
        free(table[f]);
    }
    free(table);

    return 0;
}

