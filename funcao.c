#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

#ifdef _WIN64
    #include <windows.h>
#elif defined(__linux__) 
    #include <unistd.h>
#endif

void mensagem(const char texto[]){
printf("===================================================\n");
printf("                %s\n", texto);
printf("===================================================\n");

}

void limpar_tela(void){

    #ifdef _WIN64
        system("cls");
    #elif defined(__linux__)
        system("clear");
    #endif
}

void dormir(unsigned int segundos){

    #ifdef _WIN64
        Sleep(segundos * 1000);
    #elif defined(__linux__)
        sleep(segundos);
    #endif
}

void loading(void){
    int i;

    printf("progresso: [");
    for(i = 0; i <= 10; i++){
        dormir(1);
        printf("#");
    }

    printf("] sistema inicializado...\n");
}

void laoding_opcao(void){
    for(int i = 0; i <= 8; i++){

        // \r serve para sobrescrever os prints

        // sleep serve para da um pause entre cada print

        printf("\r[|] autenticando dados do sistema...");
        dormir(1);
        printf("\r[/] autenticando dados do sistema...");
        dormir(1);
        printf("\r[-] autenticando dados do sistema...");
        dormir(1);
        printf("\r[\\] autenticando dados do sistema...");
        dormir(1);
    }
    printf("\ndados autenticados\n");
    dormir(1);
}