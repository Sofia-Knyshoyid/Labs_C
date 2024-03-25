#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* adres;
    int krotnosc;
} wyr;

int compar(const void* wsk1, const void* wsk2) {
    wyr* s1 = (wyr*)wsk1;
    wyr* s2 = (wyr*)wsk2;
    
    if (s1->krotnosc == s2->krotnosc) {
        return strcmp(s1->adres, s2->adres);
    } else {
        return s1->krotnosc - s2->krotnosc;
    }
}

char* read_str() {
    char bufor[100];
    scanf("%99s", bufor);
    int len = strlen(bufor) + 1;
    
    char* ptr = (char*)malloc(len * sizeof(char));
    if (ptr == NULL) {
        printf("Błąd w przydziale pamięci");
        exit(1);
    }
    strcpy(ptr, bufor);
    return ptr;
}

int main(void) {
    int n;
    scanf("%d", &n);

    wyr ts[n]; // array of structures

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            char* ptr_1 = read_str();
            wyr wrz1;
            wrz1.adres = ptr_1;
            wrz1.krotnosc = 1;
            ts[i] = wrz1;
        } else {
            char* ptr_1 = read_str();
            wyr* wrz1 = (wyr*)bsearch(ptr_1, ts, i, sizeof(wyr), compar);
            if (wrz1 != NULL) {
                printf("Found the item! ");
                (wrz1->krotnosc)++;
            } else {
                printf("Didn't find the item ");
                // add new item
                wyr wrz_new;
                wrz_new.adres = ptr_1;
                wrz_new.krotnosc = 1;
                ts[i] = wrz_new;
                // sort the array up to the current index
                qsort(ts, i + 1, sizeof(wyr), compar);
            }
        }
    }

    // Print the results
    for (int i = 0; i < n; i++) {
        printf("String: %s, Count: %d\n", ts[i].adres, ts[i].krotnosc);
        free(ts[i].adres);
    }

    return 0;
}
