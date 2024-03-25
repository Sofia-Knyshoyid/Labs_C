#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define OCENIAJ  0
/*Przykład:

Dane wejściowe: :
1 10 10

Dane wyjściowe:
26.80
12 4 0 3 15 0 
5.67
60 56 28 90 
58.50
*/


double average(int* table, int n, int idx){
    int sum=0;
    for (int i=0; i<idx; i++){
        sum += table[i];
    }
    // printf("sum: %d\n", sum);
    double av = (sum*1.0)/idx;
    // printf(" av: %g\n", av);
    return av;
}


void setTable(int* table, int n, int max){
    for (int e=0; e<n; e++){
        int a=rand()%(max+1);
        int b=rand()%(max+1);
        int il = a*b;
        table[e]=il;
    }
    


}

void print_int_table1D(int* table, int n, int idx){ 
    printf("\n");
    for (int k=0; k<idx+1; k++){
        printf("%d ", table[k]);
    }
}

int separate(int* table, int* t_small, int* t_big, int n, int* idxs){
    double av = average(table, n, n);
    int idx_s=0; int idx_b=0;
    for (int h=0; h<n; h++){
        if (table[h]>av){t_big[idx_b]=table[h]; idx_b += 1;}
        if (table[h]<av){t_small[idx_s]=table[h]; idx_s += 1;}
    }
    idxs[0]=idx_b; idxs[1]=idx_s;
    // mozna przekazac adresy zmiennych, tak zmieniac zmienne, nic nie zwracać
}

int main(void) {
    int seed, max, size;
    if(OCENIAJ == 0) printf("Wpisz seed, górną granicę domknietego przedziału losowanych liczb i dlugosc tablicy: ");
    scanf("%d %d %d",&seed,&max,&size);
    srand(seed);

    int tab[size];
    setTable(tab, size, max);
    // print_int_table1D(tab, size, size-1);

    printf("%.2lf", average(tab, size, size));
    int t_small[size]; int t_big[size];
    int idxs[2] = {0};
    int idx_b; int idx_s;
    separate(tab, t_small, t_big, size, idxs);
    idx_b = idxs[0]; idx_s = idxs[1];
    // printf("\nidxs\n");
    // printf("%d, %d\n", idx_b, idx_s);

    print_int_table1D(t_small, size, idx_s-1);
    printf("\n%.2lf", average(t_small, size, idx_s));

    print_int_table1D(t_big, size, idx_b-1);
    printf("\n%.2lf", average(t_big, size, idx_b));

    
    return 0;
}