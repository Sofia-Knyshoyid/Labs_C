#include <stdio.h>
#include <math.h>

// są komentarze takie

/*
i takie, czyli blokowe
*/

// jako graph 3 stanów:
// kod, komentarz line, komentarz blok

//można stworzyć zmienną enum state:
//                         case_out
//                          in_block
//                          in_line

/*
c = getc()
    switch (state){
        case out:
        (tutaj jeszcze trzeba sprawdzać, czy wczytany znak nie jest
        /, nawet 2 znaki, ten i poprzedni - // lub /*)
        (czy "/"?
        - jesli tak,
                -czy to EOF? (sprawdzamy)
                -czy to "/"?
                -czy to "*"?
                -inny? pisz poprzedni; pisz ten; break;
                )
        pisz
        break

        case in_bl:
        break;

        case in_line:
        break;
    }





*/


int main(void) {
    int c, state;
    FILE *file = fopen( "file.c", "r" );

    c = getc(file);

    char prev = ' ';
    state = 0;
    while (c!=EOF){

        switch(state){
            case 0:
            //outside of comment
            if (c=='/'){
                //
                if (prev=='/'){
                    state=1;
                } else{
                    
                }
                prev = c;
                break;
            }
            else if (c=='*')
            {
                if (prev=='/'){
                    state=2;
                    prev=' ';
                    break;
                } else {
                   printf("%c", c); 
                }
                prev = c;
                break;
            }

            else{
                printf("%c", c);
                prev = c;
                break;
            }
            
            

            case 1:
            //in line comment
            if (c=='\n'){
                state=0;
            }
            prev = c;
            break;



            case 2:
            //in block comment
            if (c=='*'){
                prev=c;
                break;
            }
            else if (prev=='*'){
                if (c=='/'){
                    state=0;
                    prev=' ';
                }
                else{
                    printf("%c", prev);
                    printf("%c", c);
                    prev = c;
                }
            }



        }

        c = getc(file);
    }

    fclose(file); 

    return 0;

}