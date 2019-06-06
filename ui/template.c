#include <string.h>
#include "../header_interface_functions.h"

void simple_box(int const X, int const Y, int const WIDTH, int const HEIGTH, const char* TITLE, int const color_body, int const color_title, bool shadow) {
    int i, j, Yaux=Y;

    mgotoxy(X, Y);
    setColor(color_body);

    for (i=0; i<HEIGTH; i++) {
        mgotoxy (X, Yaux);
        for (j=0; j<WIDTH*2; j++) {
            printf (" ");
        }
        Yaux++;
    }

    thin_edge(WIDTH, HEIGTH, X, Y, TITLE, color_body, color_title);

    if(shadow) {
        setColor(PRETO_BRANCO);
        for (i=0; i<HEIGTH; i++) {
            mgotoxy(X+(WIDTH*2), (Y+1)+i);
            printf ("  ");
        }
        for (i=0; i<(WIDTH*2)-2; i++) {
            mgotoxy((X+2)+i, Y+HEIGTH);
            printf ("  ");
        }
        setColor(color_body);
    }
}

void textViewBox (int const X, int const Y, int const WIDTH, int const HEIGTH, const char* TITLE, int const color_body, int const color_title, bool shadow, const char* text) {
    int i=0, contLetras=0, auxY=Y, auxX=X;
    simple_box (X, Y, WIDTH, HEIGTH, TITLE, color_body, color_title, shadow);
    setlocale(LC_ALL, "English");
    while (text[i]!='\0') {
        mgotoxy (auxX+1, auxY+1);
        printf ("%c", text[i]);
        i++;
        contLetras++;
        if (contLetras==(WIDTH*2)-2) {
            contLetras=0;
            if (text[i]==' ') i++;
            auxY++;
            auxX=X-1;
        }
        if (text[i]=='\n') {
            contLetras=0;
            auxY++;
            auxX=X-2;
        }
        auxX++;
    }
    setlocale(LC_ALL, "C");
}

char* textBox (int const X, int const Y, int const WIDTH, int const HEIGTH, char const TITLE[], int const color_body, int const color_title, bool shadow) {
    thick_edge(WIDTH, HEIGTH, X, Y, TITLE, color_body, color_title);

    char* field = malloc(30 * sizeof(char));
    int count=0;
    do {
        char ch = getch();
        if(ch==13) {
            mgotoxy(3, 3);
            field[count] = '\0';
            printf("%s\n", field);
            return field;
        } else if(ch==8) {
            field[count-1] = '\0';
            mgotoxy(X+(count), Y+1);
            printf(" ");
            mgotoxy(X+(count), Y+1);
            count--;
        } else {
            printf("%c", ch);
            field[count] = ch;
            count++;
        }
    } while(count<sizeof(field));
}

char* editTextBox(const int X, const int Y, const char* varChar, const int charLimit, char* text, int const color_current_background) {
    thick_edge((charLimit/2)+3, 3, X, Y, text, color_current_background, PRETO_BRANCO);

    char value[charLimit];
    int auxX = X;
    int tecla;

    do {
        tecla = getch();

        switch(tecla) {
            case 8:
                if(auxX>0) {
                    mgotoxy(auxX, Y+1);
                    printf(" ");
                    auxX--;
                    value[auxX] = '\0';
                }
                break;
            default:
                if(auxX<charLimit) {
                    mgotoxy(++auxX, Y+1);
                    printf("%c", tecla);
                    value[auxX] = tecla;
                }
                break;
        }
    } while(tecla!=13);

    varChar = "teste";

    return value;
}

void thin_edge (int const WIDTH, int const HEIGHT, int const X, int const Y, const char* TITLE, int const color_body, int const color_title) {
    int tam=0, numLetras=0;
    setlocale(LC_ALL, "C");
    setColor(color_body);

    mgotoxy(X, Y);
        printf ("%c", 218);
    mgotoxy(X, Y+(HEIGHT-1));
        printf ("%c", 192);
    mgotoxy(X+(WIDTH*2-1), Y);
        printf ("%c", 191);
    mgotoxy(X+(WIDTH*2-1), Y+(HEIGHT-1));
        printf ("%c", 217);

    for (tam=1; tam<=HEIGHT-2; tam++) {
        mgotoxy(X, Y+tam);
        printf ("%c", 179);
    }

    for (tam=1; tam<=HEIGHT-2; tam++) {
        mgotoxy(X+(WIDTH*2-1), Y+tam);
        printf ("%c", 179);
    }

    for (tam=1; tam<=WIDTH*2-2; tam++) {
        mgotoxy(X+tam, Y);
        printf ("%c", 196);
    }

    for (tam=1; tam<=WIDTH*2-2; tam++) {
        mgotoxy(X+tam, Y+(HEIGHT-1));
        printf ("%c", 196);
    }

    setlocale(LC_ALL, "English");

    for (numLetras=0; TITLE[numLetras]!='\0'; numLetras++);

    if(TITLE[0]!='\0') {
        mgotoxy(X+((WIDTH*2)-(numLetras+2))/2, Y);
        setColor(color_title);
        printf (" %s ", TITLE);
    }

    setColor(color_body);
}

void thick_edge(int const WIDTH, int const HEIGTH, int const X, int const Y, char TITLE[], int const color_body, int const color_title) {
    int tam=0, numLetras=0;
    setlocale(LC_ALL, "C");
    setColor(color_body);
    mgotoxy(X, Y);
        printf ("%c", 220);
    mgotoxy(X, Y+(HEIGTH-1));
        printf ("%c", 223);
    mgotoxy(X+(WIDTH*2-1), Y);
        printf ("%c", 220);
    mgotoxy(X+(WIDTH*2-1), Y+(HEIGTH-1));
        printf ("%c", 223);
    for (tam=1; tam<=HEIGTH-2; tam++) {
        mgotoxy(X, Y+tam);
            printf ("%c", 219);
    }
    for (tam=1; tam<=HEIGTH-2; tam++) {
        mgotoxy(X+(WIDTH*2-1), Y+tam);
            printf ("%c", 219);
    }
    for (tam=1; tam<=WIDTH*2-2; tam++) {
        mgotoxy(X+tam, Y);
            printf ("%c", 220);
    }
    for (tam=1; tam<=WIDTH*2-2; tam++) {
        mgotoxy(X+tam, Y+(HEIGTH-1));
            printf ("%c", 223);
    }
    setlocale(LC_ALL, "English");
        for (numLetras=0; TITLE[numLetras]!='\0'; numLetras++);
        if(TITLE[0]!='\0') {
            mgotoxy(X+((WIDTH*2)-(numLetras+2))/2, Y);
                setColor(color_title);
                    printf (" %s ", TITLE);
        }

    setColor(BRANCO_PRETO);
    for(tam=1l; tam<(WIDTH*2)-1; tam++) {
        mgotoxy(X+tam, Y+1);
        printf(" ");
    }

    mgotoxy(X+1, Y+1);
}
