#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "funcao.h"

#ifdef _WIN64
    #include <windows.h>
#elif defined(__linux__) 
    #include <unistd.h>
#endif

struct ferramenta{
char nome[50];
int codigo;
float valor;
};

int main()
{
    int opcao = 0;
    char continuar;
    char nome[50];
    int codigo, garantia;
    float valor;
    struct ferramenta ferramenta;

        printf("iniciando o sistema de ferramentas ...\n");
        printf("\n");
        dormir(2);
        printf("[*] conectando o banco de dados do inventario\n");
        dormir(1);
        printf("[*] carregando modulo de leitura de QR code\n");
        dormir(1);
        printf("[*] verificando status e validade das garantias\n");
        dormir(1);
        printf("[*] sincronizando dados...\n");
        dormir(1);

        //limpar_tela();

        loading();
        dormir(2);

    do {
        limpar_tela();

        espaco();
        printf("           sistema ferralog - INVENTARIO\n");
        espaco();

        printf("bem-vindo ao controle logistico de ferramentas\n");

        printf("selecione uma opcao no menu abaixo\n");
        printf("(1) cadastrar nova ferramenta\n");
        printf("(2) consultar ferramenta no setor\n");
        printf("(3) verificar status da ferramenta\n");
        printf("(4) cadastro em lote\n");
        printf("(5) sair do sistema\n");
        espaco();

        printf("digite a opcao desejada: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');
        

        if(opcao > 0 && opcao < 5){
            laoding_opcao();
            limpar_tela();
        }
        

        switch (opcao){

    case 1:{

        while (1)
        {
            espaco();
            printf("         cadastro de ferramentas\n");
            espaco();

            printf("nome da ferramenta: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("codigo QR: ");
            scanf("%d", &codigo);
            while(getchar() != '\n');

            while(codigo <= 0){
                printf("codigo invalido, digite novamente: ");
                scanf("%d", &codigo);
                while(getchar() != '\n');
            }

            printf("valor: R$");
            scanf("%f", &valor);
            while(getchar() != '\n');

            while(valor <= 0){
                printf("valor invalido, digite novamente: R$");
                scanf("%f", &valor);
                while(getchar() != '\n');
            }

            printf("possui geranria? [1 - sim] [2- não] ");
            scanf("%d", &garantia);
            while (getchar() != '\n');


            //nota do cadastro
            limpar_tela();
            printf("<< FERRAMENTA CADASTRADA >>\n");
            printf("nome da ferramenta: %s\n", nome);
            printf("codigo QR da ferramenta: %d\n", codigo);
            printf("valor da ferramenta: %.2f\n", valor);
            printf("\n");

            //continuar
            printf("deseja cadastrar mais alguma ferramenta? [s/n] ");
            scanf(" %c", &continuar);
            while(getchar() != '\n');
            while (continuar != 's' && continuar != 'n'){
                printf("opcao invalida, digite novamente. [s/n] ");
                scanf(" %c", &continuar);
                while(getchar() != '\n');
            }

            if (continuar == 's'){
                continue;
            } else if (continuar == 'n'){
                break;
            }
        }
        break;
    }
        

    case 2:
        printf("consultar ferramenta no setor em desenvolvimento...\n");
        dormir(2);
        break;

    case 3:
        printf("status da ferramenta em desenvolvimento...\n");
        dormir(2);
        break;

    case 4:{
        int quantidade, i;

        printf("quantas ferramentas deseja cadastrar? ");
        scanf("%d", &quantidade);

        if(quantidade <= 0){
            printf("quantidade invalida\n");
        }
        else{
            for(i = 1; i <= quantidade; i++){
                printf("digite o valor da ferramenta: ");
                scanf("%f", &ferramenta.valor);
            }
        //printf("%.2f\n", ferramenta.valor);
        }
        break;
    }
        

    case 5:
        printf("desconectando do banco de dados...\n");
        dormir(2);
        printf("<< VOLTE SEMPRE >>\n");
        break;

    default:
        printf("valor invalido\n");
        printf("pressione a tecla ENTER para tentar de novo\n");
        getchar();
        }
    } while (opcao != 5);

    return 0;
}
