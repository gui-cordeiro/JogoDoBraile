#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main(void) {
    int tempo = 0, a = 0, erroMenu = 0;
    configJogo();
    apresentacao();
    do{
        a = menu(erroMenu);
        fflush(stdin);
        erroMenu = 0;
        switch(a){
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
                a = 0;
                erroMenu ++;
                system("cls");
                addFade(1, 50, 0);
                telaErro();
                //addFade(25, 0, 0);
                //addFade(5, 30, 1);
        };
    }while(a != 7);
    system("cls");
    github();
    printf("\n\t\t      **** Obrigado por jogar! Pressione qualquer tecla para sair do jogo ****");
    getchar();
    //addFade(30, 30, 1);
}
