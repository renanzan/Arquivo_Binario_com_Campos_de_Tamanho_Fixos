#include "../header_interface_functions.h"

int presset_main() {
    const char* TITLE = "Menu Inicial v2.0";
    const int WINDOW_WIDTH = 28;
    const int WINDOW_HEIGHT = 16;

    const char* DYNAMIC_MENU_TITLE = "TRABALHO AEDES II";
    const char* DYNAMIC_MENU_ITEMS = ".Inicializar registros vazios no arquivo.Listar dados.Inserir novo registro.Apagar uma conta.Finalizar programa";
    const int DYNAMIC_MENU_POS_X = 5;
    const int DYNAMIC_MENU_POS_Y = 5;

    presets (TITLE, AZUL_BRANCO, WINDOW_WIDTH, WINDOW_HEIGHT, true);

    boot_sound();

    return dynamic_menu(DYNAMIC_MENU_ITEMS, DYNAMIC_MENU_TITLE,
                        DYNAMIC_MENU_POS_X, DYNAMIC_MENU_POS_Y,
                        (WINDOW_WIDTH-6), (WINDOW_HEIGHT-9));
}

void presset_inicializar_registros_vazios_no_arquivo() {
    const char* TITLE = "Menu Inicial v2.0 - Inicializar";
    const int WINDOW_WIDTH = 28;
    const int WINDOW_HEIGHT = 15;

    const int TEXT_WIDTH = 23;
    const int TEXT_HEIGHT = 5;
    const int TEXT_POS_X = 4;
    const int TEXT_POS_Y = 2;

    presets (TITLE, AZUL_BRANCO, WINDOW_WIDTH, WINDOW_HEIGHT, true);

    textViewBox(TEXT_POS_X, TEXT_POS_Y, TEXT_WIDTH, TEXT_HEIGHT, "Sucesso", AMARELO_PRETO, PRETO_BEJE, true, "Os registros do arquivo foram sobreescritos por arquivos vazios.");

    mgotoxy(2, TEXT_POS_Y + TEXT_HEIGHT + 3);
    system("pause");
}

void presset_listar_dados() {
    const char* TITLE = "Menu Inicial v2.0 - Listar";
    const int WINDOW_WIDTH = 40;
    const int WINDOW_HEIGHT = 2000;

    presets (TITLE, AZUL_BRANCO, WINDOW_WIDTH, WINDOW_HEIGHT, true);
}

void presset_default() {
    const char* TITLE = "Prompt";
    const int WINDOW_WIDTH = 80;
    const int WINDOW_HEIGHT = 40;

    presets (TITLE, PRETO_BRANCO, WINDOW_WIDTH, WINDOW_HEIGHT, true);
}

void presset_iniciar_novo_registro() {
    const char* TITLE = "Menu Inicial v2.0 - Novo Registro";
    const int WINDOW_WIDTH = 40;
    const int WINDOW_HEIGHT = 25;

    presets (TITLE, AZUL_BRANCO, WINDOW_WIDTH, WINDOW_HEIGHT, true);
}

void presset_error(const char* errorText) {
    int numChar = 0;
    while(errorText[numChar]!='\0') numChar++;

    const char* TITLE = "Menu Inicial v2.0 - FATAL ERROR";
    const int WINDOW_WIDTH = (numChar/2) + 2;
    const int WINDOW_HEIGHT = 10;

    presets (TITLE, VERMELHO_PRETO, WINDOW_WIDTH, WINDOW_HEIGHT, true);

    printf("\n  ");
    for(int i=0; i<numChar; i++)
        printf("!");

    printf("\n  %s  ", errorText);

    printf("\n  ");
    for(int i=0; i<numChar; i++)
        printf("!");

    error_sound();
    mgotoxy(2, 5);
    exit(1);
}
