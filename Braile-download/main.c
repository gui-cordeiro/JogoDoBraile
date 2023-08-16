/*
 * -> C�digo-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
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
#include <process.h>
#include <processthreadsapi.h>

#define _WIN32_WINNT 0x0500
#define tempo 50

#include "config-functions.h"
#include "main-functions.h"

int main(int argc, char **argv) {
    ShowCursor(FALSE);
    int opt = 0;
    configJogo();
    topBannerDesign();
    bottomBannerDesign();
    fimJogo("DIF�CIL", 3900, 26, 26);
    apresentacao();
    //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
    do {
        topBannerDesign();
        bottomBannerDesign();
        opt = mainMenu();
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
}
