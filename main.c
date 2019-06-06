#include <stdio.h>
#include "models.h"
#include "header_interface_functions.h"

int main() {

    int opc = presset_main();

    switch(opc) {
        case 1:
            inicializar_registros_vazios_no_arquivo();
            break;
        case 2:
            listar_dados();
            break;
        case 3:
            inserir_novo_registro();
            break;
        case 4:
            apagar_registro();
            break;
        case 5:
            exit(0);
            break;
    }

    return 0;
}

void inicializar_registros_vazios_no_arquivo() {
    presset_inicializar_registros_vazios_no_arquivo();
    initializeEmptyFile(MAX_NUM_RECORDS);
    success_sound();
    main();
}

void listar_dados() {
    presset_listar_dados();
    printAllClientes();
}

void inserir_novo_registro() {
    presset_default();
    addCliente();
    getch();
}

void apagar_registro() {
    presset_default();
    erase();
}
