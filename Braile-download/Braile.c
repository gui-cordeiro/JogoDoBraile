#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#define tempo 50

int main(void) {
    int opt = 0, erroMenu = 0;
    configJogo();
    opcao2();
    //confirmarJogo("MÉDIO II");
    //newPergunta(1, 'A', 'I', 'E', 'U', 'c', 'E', 0, 0);
    apresentacao();
    do{
        opt = menu(erroMenu);
        fflush(stdin);
        erroMenu = 0;
        switch(opt){
            case 1:
                opcao1();
                break;
            case 2:
                opcao2();
                break;
            case 3:
                opcao3();
                break;
            case 4:
                opcao4();
                break;
            case 5:
                opcao5();
                break;
            case 6:
                opcao6();
                break;
            case 7:
                continue;
            case 8:
                apresentacao();
                break;
            default:
                opt = 0;
                erroMenu ++;
                system("cls");
                addFade(2, 50, 0);
                telaErro();
                //addFade(25, 0, 0);
                //addFade(5, 30, 1);
        };
    }while(opt != 7);
    system("cls");
    printf("\t\t                                                                               __ \n");Sleep(tempo);
    printf("\t\t       _____ _       _           _                          __                |  |\n");Sleep(tempo);
    printf("\t\t      |     | |_ ___|_|___ ___ _| |___    ___ ___ ___    __|  |___ ___ ___ ___|  |\n");Sleep(tempo);
    printf("\t\t      |  |  | . |  _| | . | .'| . | . |  | . | . |  _|  |  |  | . | . | .'|  _|__|\n");Sleep(tempo);
    printf("\t\t      |_____|___|_| |_|_  |__,|___|___|  |  _|___|_|    |_____|___|_  |__,|_| |__|\n");Sleep(tempo);
    printf("\t\t                      |___|              |_|                      |___|           \n");Sleep(tempo);
    addFade(1, 50, 0);
    exibirTelaGitHub();
    printf("\n\t\t\t\t  **** Pressione qualquer tecla para sair do jogo ****");
    getchar();
    system("cls");
    //addFade(30, 30, 1);
}
