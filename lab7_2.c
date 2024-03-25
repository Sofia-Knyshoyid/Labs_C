#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* read_str(){
    char bufor[100], *ptr;
    int len;
    scanf("%99s", bufor);
    len = strlen(bufor)+1;
    char c = bufor[len-1];
    
    ptr = (char*) malloc(len*sizeof(char));
    if (ptr == NULL){printf("Bład w przydziale pamięci"); exit(1);}
    strcpy(ptr, bufor); //strcpy(dokąd, skąd)
    return ptr;
    
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


int is_bigger(const void* chr1_1, const void* chr2_1){
    char* chr1 = (char*)chr1_1;
    char* chr2 = (char*)chr2_1;
    char val1 = *(chr1); // char val1 = *(chr1+num);
    char val2 = *(chr2); // char val2 = *(chr2+num);
    if (val1>=65 && val1<=90){val1=val1+32;}
    else{val1=val1;}
    if (val2>=65 && val2<=90){val2=val2+32;}
    else{val2=val2;}

    if ((val1 == '\0')||(val2 == '\0')){
        if (val1 == '\0'){val2=91;}
        else {val1 == 91;}}
    
    if ((val1) == (val2)){
        chr1 += 1;
        chr2 += 1;
        return is_bigger(chr1, chr2);
        // return is_bigger(chr1, chr2, num+1)
        }

    if (val1>val2){return 1;}
    else{return -1;} // return 0;}
}


void print_str2(char* table[], int n){
    int tab[n];
    for (int k=0; k<n; k++){
        tab[k] = k;
    }

    // char tabl[n];
    // for (int t=0; t<n; t++){
    //     tabl[t] = " ";
    // }

    // for (int l=0; l<n; l++){
    //     int depth = 0;
    //     char zm = *(*(table+l)+depth);
    //     while (*(*(table+l)+depth)!='\0'){
    //         strcat(tabl[l], *(*(table+l)+depth));
    //         depth += 1;
    //     }
    //     // tabl[l] = **table;
    // }

    qsort(table, n, (size_t) sizeof(char*), is_bigger);

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
                int is = is_bigger(val01, val02); // ... val2, 0)
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




void print_str(char ** table, int n){
    int tab[n];
    for (int k=0; k<n; k++){
        tab[k] = k;
    }

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

    

    // qsort(table, n, (size_t) sizeof(char*), ) 



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

    	
    char ** table = (char**)malloc(n * sizeof(char*));


    for (int i=0; i<n; i++){
        char *ptr_1 = read_str();
        table[i] = ptr_1;
    }

    print_str2(table, n);
    
    for (int f; f<n; f++){
        free(table[f]);
    }
    free(table);
    
    return 0;
}


