#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"
#include "models.h"

FILE* openFile(const char* fileMode) {
    FILE* file = fopen(FILE_NAME, fileMode);

    if(file == NULL)
        presset_error("FATAL_ERROR: Nao foi possivel abrir o arquivo.");

    return file;
}

void initializeEmptyFile(const unsigned int numberOfRecords) {
    FILE* file = openFile("wb");
    Cliente nullValues = {0, "", 0.0};

    for(int count = 1; count <= numberOfRecords; count++)
        fwrite(&nullValues, sizeof(Cliente), 1, file);

    fclose(file);
}

void addCliente() {
    FILE* file = openFile("rb+");
    Cliente cliente = {0, "", 0.0};

    printf("Digite o numero da conta (1-100): ");
        scanf("%d", &cliente.numeroConta);
        fflush(stdin);

    while(cliente.numeroConta>=1 && cliente.numeroConta<=100) {
        printf("Digite o nome do cliente: ");
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            fflush(stdin);

            int i = 0;
            while(cliente.nome[i] != '\0') i++;
            cliente.nome[i-1] = '\0';

        printf("Digite o saldo da conta: ");
            scanf("%lf", &cliente.saldo);
            fflush(stdin);

        writeInSeekPosition(file, cliente);

        system("cls");
        printf("Digite o numero da conta (1-100): ");
            scanf("%d", &cliente.numeroConta);
            fflush(stdin);
    };

    fclose(file);
    main();
}

void printAllClientes() {
    FILE* file = openFile("rb+");
    Cliente cliente = {0, "", 0.0};

    fseek(file, 0, SEEK_SET);
    fread((char *)(&cliente), sizeof(Cliente), 1, file);

    int x=15, y=10;
    while(!feof(file)) {
        if(cliente.numeroConta != 0) {
            char text[250], aux[30];

            strcpy(text, "NUMERO DA CONTA: ");
            snprintf(aux, sizeof(aux), "%d", cliente.numeroConta);
                strcat(text, aux);

            strcat(text, "\nNOME: ");
            strcat(text, cliente.nome);

            strcat(text, "\nSALDO: R$");
            snprintf(aux, sizeof(aux), "%.2f", cliente.saldo);
                strcat(text, aux);

            textViewBox(x, y, 25, 5, cliente.nome, VERMELHO_AMARELO, AMARELO_PRETO, true, text);
            y+=7;

        } fread((char *)(&cliente), sizeof(Cliente), 1, file);
    }

    int opc_menu = dynamic_menu (".Voltar.Finalizar Programa", "Opções", 25, 3, 15, 4);

    switch(opc_menu) {
        case 1:
            main();
            break;
        case 2:
            exit(1);
    }
}

void erase() {
    int numConta;
    FILE* file = openFile("rb+");
    Cliente nullValue = {0, "", 0.0};

    while(numConta>=1 && numConta<=100) {
        system("cls");
        printf("Digite o numero da conta (1-100): ");
            scanf("%d", &numConta);
            fflush(stdin);
        fseek(file, (numConta - 1) * sizeof(Cliente), SEEK_SET);
        fwrite(&nullValue, sizeof(Cliente), 1, file);

        if(numConta<=0)
            break;
        else {
            printf("Conta removida com sucesso!\n\n");
            system("pause");
        }
    }

    fclose(file);
    main();
}

void writeInSeekPosition(FILE* file, Cliente cliente) {
    fseek(file, (cliente.numeroConta - 1) * sizeof(Cliente), SEEK_SET);
    fwrite(&cliente, sizeof(Cliente), 1, file);
}
