/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define tempo 50

int main(void) {
    int opt = 0, erroMenu = 0;
    configJogo();
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
    opcao7();
}
