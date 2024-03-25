#include <stdio.h>
#include <stdlib.h>





int** czytaj(int rownum, int colnum){
    int** macierz = malloc(sizeof(int*)*rownum);
    int** p;
    for(p=macierz; p<macierz+rownum; p++) {
        *p = malloc(sizeof(int) * colnum);
    }

    for (int row=0; row<rownum; row++){
        for (int col=0; col<colnum; col++){
            int num;
            scanf("%d", &num);
            *(*(macierz)+row*colnum+col) = num;
        }
    }

    return macierz;
}

void pisz(int rownum, int colnum, int** macierz){
    for (int row=0; row<rownum; row++){
        for (int col=0; col<colnum; col++){
            printf("%d ", *(*(macierz)+row*colnum+col));
        }
        printf("\n");
    }
}

int** dodaj(int rownum, int colnum, int** mac1, int** mac2){
    // stworzyć macierz wyników
    int** mac3 = malloc(sizeof(int*)*rownum);
    int** p;
    for(p=mac3; p<mac3+rownum; p++) {
        *p = malloc(sizeof(int) * colnum);
    }

    for (int row=0; row<rownum; row++){
        for (int col=0; col<colnum; col++){
            *(*(mac3)+row*colnum+col) = *(*(mac1)+row*colnum+col) + *(*(mac2)+row*colnum+col);
        }
    }

    return mac3;
}

int** iloczyn(int row1, int row2, int col2, int** mac1, int** mac2){
    // stworzyć macierz wyników
    int** mac3 = malloc(sizeof(int*)*row1);
    int** p;
    for(p=mac3; p<mac3+row1; p++) {
        *p = malloc(sizeof(int) * col2);
    }

    for (int row=0; row<row1; row++){
        for (int col_2=0; col_2<col2; col_2++){
            int sum = 0;
            for (int col_1=0; col_1<row2; col_1++){
                int num1 = *(*(mac1)+row*row2+col_1);       // *(*(mac1)+row*colnum+col);
                int num2 = *(*(mac2)+col_1*col2+col_2);
                int result = num1*num2;
                sum+=result;
                //*(mac2)+

            }
            *(*(mac3)+row*col2+col_2) = sum;
        }  
    }

    return mac3;


}




int main(void){
    int rows1, cols1, rows2, cols2;
    scanf("%d %d", &rows1, &cols1);
    int** mac1 = czytaj(rows1, cols1);
    scanf("%d %d", &rows2, &cols2);
    int** mac2 = czytaj(rows2, cols2);
    // int rows1 = 3; int cols1 = 4;
    // int rows2 = 4; int cols2 = 2;
    

    printf("\n");
    pisz(rows1, cols1, mac1);
    printf("\n");
    pisz(rows2, cols2, mac2);

    int** mac3 = dodaj(rows1, cols1, mac1, mac2);
    printf("\n");
    pisz(rows1, cols1, mac3);

    int** mac4 = iloczyn(rows1, rows2, cols2, mac1, mac2);
    printf("\n");
    pisz(rows1, cols2, mac4);


    
}