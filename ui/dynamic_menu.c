#include "../header_interface_functions.h"

int dynamic_menu (const char* OPCS, const char* TITLE, int x, const int y, const int WIDTH, const int HEIGHT) {
    int i, auxY, numOpcs=0, d, req=0, linhas=1, numLetras=0;

    if(x<3)
        x=3;

    for(i=0; OPCS[i]!='\0'; i++)
        if(OPCS[i]=='.')
            numOpcs++;

    simple_box((x-1)-1, (y-1)-1, (WIDTH)+2, (HEIGHT)+2, TITLE, CINZA_PRETO, CINZA_PRETO, true);

    auxY = y;

    for(i=0; OPCS[i]!='\0'; i++) {
        if(OPCS[i]=='.') {
            for(numLetras=1; OPCS[i+numLetras]!='.' && OPCS[i+numLetras]!='\0'; numLetras++);
            mgotoxy(x, auxY);
            printf ("( ) ");
            auxY+=linhas;
        } else {
            printf ("%c", OPCS[i]);
        }
    }

    auxY = y;

    char tecla = 'P';

    while(1) {
        if (tecla=='H' && auxY-1>y) {
            d=1;
        } else if(tecla=='P' && auxY<y+numOpcs) {
            d=2;
        } else if(tecla==13) {
            d=3;
        } else {
            d=0;
        }

        if(d!=0 && auxY!=y) {
            mgotoxy(x, auxY-1);
            printf("( )");
        }

        switch(d) {
            case 1:
                req--;
                mgotoxy(x, --auxY-1);
                printf("[>]");
                break;
            case 2:
                req++;
                mgotoxy(x, ++auxY-1);
                printf("[>]");
                break;
            case 3:
                return req;
        }

        tecla = getch();
    }
}
