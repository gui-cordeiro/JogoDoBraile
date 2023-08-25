/*
 * -> Código-Fonte do Jogo do Braile
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
    configJogo();
    //topBannerDesign();
    //bottomBannerDesign();
    //fimJogo("DIFÍCIL", 3900, 26, 26);
    apresentacao();
    PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
    topBannerDesign();
    bottomBannerDesign();
    int opt = 0;
    do {
        opt = mainMenu();
        switch(opt){
            case 1:
                do {
                    opt = modeSelect();
                    switch (opt) {
                        case 1:
                            opcaoB1();
                        break;
                        case 2:
                            opcaoB2();
                        break;
                        case 3:
                            opcaoB3();
                        break;
                        case 4:
                            opcaoB4();
                        break;
                        case 5:
                            opcaoB5();
                        break;
                        default:
                            cleanScreen(2, false);
                    }
                } while(opt != 6);
                opt = 0;
                break;
            case 2:
                //PlaySound(TEXT("..\\sounds\\areyousure.wav"), NULL, SND_LOOP | SND_ASYNC);
                opcaoA2();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
                break;
            case 3:
                //PlaySound(TEXT("..\\sounds\\areyousure.wav"), NULL, SND_LOOP | SND_ASYNC);
                opcaoA3();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
                break;
            case 4:
                //PlaySound(TEXT("..\\sounds\\areyousure.wav"), NULL, SND_LOOP | SND_ASYNC);
                opcaoA4();
                //PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
                break;
            case 5:
                opcaoA5();
                break;
            case 6:
                continue;
            default:
                apresentacao();
                topBannerDesign();
                bottomBannerDesign();
                PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
        };
    } while(opt != 6);
    opcaoA6();
}
