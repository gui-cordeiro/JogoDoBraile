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
#include <stdbool.h>

#define _WIN32_WINNT 0x0500
#define tempo 50

#include "config-functions.h"
#include "main-functions.h"

int main() {
    int opt = 0;
    configJogo();
    apresentacao();
    //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
    do {
        char lista [8][40] = {"Jogar - NÍVEL FÁCIL","Jogar - NÍVEL MÉDIO I","Jogar - NÍVEL MÉDIO II","Jogar - NÍVEL DIFÍCIL","Ranking dos Jogadores","Instruções do Jogo","Créditos do Jogo","Sair do Jogo"};
        opt = menu(11, 47, 8, lista);
        fflush(stdin);
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
                //PlaySound(TEXT("..\\sounds\\areyousure.wav"), NULL, SND_LOOP | SND_ASYNC);
                opcao5();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
                break;
            case 6:
                //PlaySound(TEXT("..\\sounds\\areyousure.wav"), NULL, SND_LOOP | SND_ASYNC);
                opcao6();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
                break;
            case 7:
                //PlaySound(TEXT("..\\sounds\\areyousure.wav"), NULL, SND_LOOP | SND_ASYNC);
                opcao7();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
                break;
            case 8:
                continue;
            default:
                apresentacao();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
        };
    } while(opt != 8);
    opcao8();
    return 0;
}
