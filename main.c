/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2024
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

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define _WIN32_WINNT 0x0500
#define tempo 50

#include "declarations.h"
#include "aux-threads.h"
#include "config-functions.h"
#include "main-functions.h"

int main(int argc, char *args[]) {
    configJogo();
    apresentacao();
    fimJogo("FÁCIL", 750, 5, 5);
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
                opcaoA2();
                break;
            case 3:
                opcaoA3();
                break;
            case 4:
                opcaoA4();
                break;
            case 5:
                opcaoA5();
                break;
            case 6:
                continue;
            default:
                apresentacao();
        };
    } while(opt != 6);
    //opcaoA6();
    system("cls");
    return 0;
}
