#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

/* 0) Menu principal */
int menu(int erro){
    int tempo = 50, i = 0, a = 0;
    char opt[100];
    char optMenu [7][24] = {"  Jogar - N?VEL F?CIL  "," Jogar - N?VEL M?DIO I "," Jogar - N?VEL M?DIO II"," Jogar - N?VEL DIF?CIL ","  Instru??es do Jogo   ","   Cr?ditos do Jogo    ","     Sair do Jogo      "};
    titulo("-", "Menu Principal");
    fflush(stdin);
    if (erro == 0) {
        addFade(3, tempo, 0);
    }
    printf("\n\t\t\t\t _____                 _____     _         _         _ \n");Sleep(tempo);
    printf("\t\t\t\t|     |___ ___ _ _    |  _  |___|_|___ ___|_|___ ___| |\n");Sleep(tempo);
    printf("\t\t\t\t| | | | -_|   | | |   |   __|  _| |   |  _| | . | .'| |\n");Sleep(tempo);
    printf("\t\t\t\t|_|_|_|___|_|_|___|   |__|  |_| |_|_|_|___|_|  _|__,|_|\n");Sleep(tempo);
    printf("\t\t\t\t                                            |_|        \n");Sleep(tempo);
    printf("\t\t\t\t      (Insira a op??o desejada e pressione ENTER)");
    addFade(3, 50, 1);
    printf("\t\t\t\t      +-------------------------+---------------+");Sleep(tempo);
    printf("\n\t\t\t\t      |       DESCRI??O         | NUM. DA OP??O | ");Sleep(tempo);
    printf("\n\t\t\t\t      +-------------------------+---------------+ ");Sleep(tempo);
    for (int c = 0; c < 7; c ++) {
        printf("\n\t\t\t\t      +-------------------------+---------------+ ");Sleep(tempo);
        printf("\n\t\t\t\t      | %s |       %d       | ", optMenu[c], c + 1);Sleep(tempo);
    }
    printf("\n\t\t\t\t      +-------------------------+---------------+");addFade(2, 50, 1);
    printf("\t\t\t\t\t          Para onde vamos? -> ");
    fgets(opt, 100, stdin);
    while (opt[i] != '\0') {
        if ((opt[i] == ' ') || ((opt[i] >= 'a' && opt[i] <= 'z') || (opt[i] >= 'A' && opt[i] <= 'Z'))) {
            return 0;
        }
        i ++;
    }
    a = atoi(opt);
    return a;
}

/* 1) Jogar - N?VEL F?CIL */
void opcao1(){
    int cont = 10, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    if(confirmarJogo("F?CIL") == 0) return 0;
    addFade(13, 50, 0);
    printf("\t\t\t\t      As letras em braile nesta dificuldade s?o:    \n");Sleep(tempo);
    printf("\n\t\t\t\t    A          E          I          O          U \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o   |     |   o|     |o   |     |o   |\n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |   o|     |o   |     |   o|     |    |\n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |    |     |    |     |o   |     |o  o|  ");addFade(3, 50, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("\t\t\t\t              Tempo restante: %d segundos",cont);Sleep(tempo);
    Sleep(800);
    system("cls");
    cont --;
    do{
        addFade(13, 50, 0);
        printf("\t\t\t\t      As letras em braile nesta dificuldade s?o:    \n");
        printf("\n\t\t\t\t    A          E          I          O          U \n");
        printf("\t\t\t\t  |o   |     |o   |     |   o|     |o   |     |o   |\n");
        printf("\t\t\t\t  |    |     |   o|     |o   |     |   o|     |    |\n");
        printf("\t\t\t\t  |    |     |    |     |    |     |o   |     |o  o|\n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! * \n\n");
        if(cont != 1){
            printf("\t\t\t\t              Tempo restante: %d segundos",cont);
        }else{
            printf("\t\t\t\t              Tempo restante: %d segundo",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    if(newPergunta(1, 'A', 'I', 'E', 'U', 'c', 'E', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'U', 'I', 'O', 'A', 'a', 'U', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'E', 'O', 'I', 'A', 'd', 'A', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'I', 'O', 'U', 'E', 'a', 'I', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'O', 'A', 'U', 'E', 'a', 'O', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    fimJogo("F?CIL", pts, acertos, numPerg);
    return;
}

/* 2) Jogar - N?VEL M?DIO I */
void opcao2(){
    int cont = 20, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    if(confirmarJogo("M?DIO I") == 0) return 0;
    addFade(11, 50, 0);
    printf("\t\t\t\t      As letras em braile nesta dificuldade s?o:      \n");Sleep(tempo);
    printf("\n\t\t\t\t    B          C          D          F          G   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o  o|     |o  o|     |o  o|     |o  o|  \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |    |     |   o|     |o   |     |o  o|  \n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |    |     |    |     |    |     |    |  \n");Sleep(tempo);
    printf("\n\t\t\t\t    H          J          K          L          M   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |   o|     |o   |     |o   |     |o  o|  \n");Sleep(tempo);
    printf("\t\t\t\t  |o  o|     |o  o|     |    |     |o   |     |    |  \n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |    |     |o   |     |o   |     |o   |    ");addFade(3, 50, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("\t\t\t\t              Tempo restante: %d segundos",cont);Sleep(tempo);
    Sleep(1000);
    system("cls");
    cont --;
    do{
        addFade(11, 50, 0);
        printf("\t\t\t\t      As letras em braile nesta dificuldade s?o:     \n");
        printf("\n\t\t\t\t    B          C          D          F          G  \n");
        printf("\t\t\t\t  |o   |     |o  o|     |o  o|     |o  o|     |o  o| \n");
        printf("\t\t\t\t  |o   |     |    |     |   o|     |o   |     |o  o| \n");
        printf("\t\t\t\t  |    |     |    |     |    |     |    |     |    | \n");
        printf("\n\t\t\t\t    H          J          K          L          M  \n");
        printf("\t\t\t\t  |o   |     |   o|     |o   |     |o   |     |o  o| \n");
        printf("\t\t\t\t  |o  o|     |o  o|     |    |     |o   |     |    | \n");
        printf("\t\t\t\t  |    |     |    |     |o   |     |o   |     |o   | \n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *  \n\n");
        if(cont == 1){
            printf("\t\t\t\t              Tempo restante: %d segundo",cont);
        }
        else{
            printf("\t\t\t\t              Tempo restante: %d segundos",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    if(newPergunta(1, 'G', 'D', 'M', 'J', 'a', 'G', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'C', 'H', 'L', 'B', 'c', 'L', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'B', 'F', 'J', 'C', 'd', 'C', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'G', 'J', 'D', 'M', 'b', 'J', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'D', 'B', 'M', 'H', 'c', 'M', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(6, 'B', 'J', 'H', 'D', 'a', 'B', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(7, 'K', 'F', 'B', 'H', 'a', 'K', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(8, 'M', 'D', 'C', 'H', 'd', 'H', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(9, 'G', 'D', 'K', 'F', 'b', 'D', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(10, 'F', 'M', 'B', 'J', 'a', 'F', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    fimJogo("M?DIO I", pts, acertos, numPerg);
    return;
}

/* 3) Jogar - N?VEL M?DIO II */
void opcao3(){
    int cont = 25, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    if(confirmarJogo("M?DIO II") == 0) return 0;
    addFade(8, 0, 0);
    printf("\t\t\t\t      As letras em braile nesta dificuldade s?o:       \n");Sleep(tempo);
    printf("\n\t\t\t\t    N          P          Q          R          S    \n");Sleep(tempo);
    printf("\t\t\t\t  |o  o|     |o  o|     |o  o|     |o   |     |   o|   \n");Sleep(tempo);
    printf("\t\t\t\t  |   o|     |o   |     |o  o|     |o  o|     |o   |   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o   |     |o   |     |o   |     |o   |   \n");Sleep(tempo);
    printf("\n\t\t\t\t    T          V          W          X          Y    \n");Sleep(tempo);
    printf("\t\t\t\t  |   o|     |o   |     |   o|     |o  o|     |o  o|   \n");Sleep(tempo);
    printf("\t\t\t\t  |o  o|     |o   |     |o  o|     |    |     |   o|   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o  o|     |   o|     |o  o|     |o  o|   \n");Sleep(tempo);
    printf("\n\t\t\t\t                          Z \n");Sleep(tempo);
    printf("\t\t\t\t                        |o   |\n");Sleep(tempo);
    printf("\t\t\t\t                        |   o|\n");Sleep(tempo);
    printf("\t\t\t\t                        |o  o|  ");addFade(3, 50, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("\t\t\t\t              Tempo restante: %d segundos",cont);
    Sleep(800);
    system("cls");
    cont --;
    do{
        addFade(8, 0, 0);
        printf("\t\t\t\t      As letras em braile nesta dificuldade s?o:       \n");
        printf("\n\t\t\t\t    N          P          Q          R          S    \n");
        printf("\t\t\t\t  |o  o|     |o  o|     |o  o|     |o   |     |   o|   \n");
        printf("\t\t\t\t  |   o|     |o   |     |o  o|     |o  o|     |o   |   \n");
        printf("\t\t\t\t  |o   |     |o   |     |o   |     |o   |     |o   |   \n");
        printf("\n\t\t\t\t    T          V          W          X          Y    \n");
        printf("\t\t\t\t  |   o|     |o   |     |   o|     |o  o|     |o  o|   \n");
        printf("\t\t\t\t  |o  o|     |o   |     |o  o|     |    |     |   o|   \n");
        printf("\t\t\t\t  |o   |     |o  o|     |   o|     |o  o|     |o  o|   \n");
        printf("\n\t\t\t\t                          Z     \n");
        printf("\t\t\t\t                        |o   |    \n");
        printf("\t\t\t\t                        |   o|    \n");
        printf("\t\t\t\t                        |o  o|\n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *\n\n");
        if(cont != 0){
            printf("\t\t\t\t              Tempo restante: %d segundos",cont);
        }else{
            printf("\t\t\t\t              Tempo restante: %d segundo",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    if(newPergunta(1, 'V', 'W', 'T', 'N', 'a', 'V', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'P', 'S', 'Q', 'R', 'c', 'Q', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'N', 'P', 'T', 'Y', 'd', 'Y', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'Z', 'T', 'S', 'Y', 'b', 'T', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'R', 'Z', 'P', 'W', 'b', 'Z', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(6, 'V', 'W', 'Z', 'N', 'd', 'N', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(7, 'N', 'S', 'P', 'Y', 'b', 'S', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(8, 'S', 'Q', 'W', 'Y', 'c', 'W', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(9, 'R', 'Q', 'P', 'Y', 'a', 'R', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(10, 'Z', 'X', 'P', 'T', 'b', 'X', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(11, 'X', 'W', 'S', 'P', 'd', 'P', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    fimJogo("M?DIO II", pts, acertos, numPerg);
    return;
}

/* 4) Jogar - N?VEL DIF?CIL */
void opcao4(){
    int cont = 30, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    if(confirmarJogo("DIF?CIL") == 0) return 0;
    addFade(8, 0, 0);
    printf("\t\t\t\t      As letras em braille nesta dificuldade s?o:\n");
    printf("\n\t      A          B          C          D          E          F          G          H          I     \n");Sleep(tempo);
    printf("\t    |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|    \n");Sleep(tempo);
    printf("\t    |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |    \n");Sleep(tempo);
    printf("\t    |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |    \n");Sleep(tempo);
    printf("\n\t      J          K          L          M          N          O          P          Q          R     \n");Sleep(tempo);
    printf("\t    |   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |    \n");Sleep(tempo);
    printf("\t    |o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|    \n");Sleep(tempo);
    printf("\t    |    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |    \n");Sleep(tempo);
    printf("\n\t\t    S          T          U          V          W          X          Y          Z                \n");Sleep(tempo);
    printf("\t\t  |   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |               \n");Sleep(tempo);
    printf("\t\t  |o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|               \n");Sleep(tempo);
    printf("\t\t  |o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|                 ");addFade(3, tempo, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, tempo, 1);
    printf("\t\t\t\t            Tempo restante: %d segundos",cont);
    getche();
    Sleep(800);
    system("cls");
    cont --;
    do{
        addFade(8, 0, 0);
        printf("\t\t\t\t      As letras em braille nesta dificuldade s?o:\n");
        printf("\n\t      A          B          C          D          E          F          G          H          I   \n");
        printf("\t    |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|  \n");
        printf("\t    |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |  \n");
        printf("\t    |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |  \n");
        printf("\n\t      J          K          L          M          N          O          P          Q          R   \n");
        printf("\t    |   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |  \n");
        printf("\t    |o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|  \n");
        printf("\t    |    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |  \n");
        printf("\n\t\t    S          T          U          V          W          X          Y          Z              \n");
        printf("\t\t  |   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |             \n");
        printf("\t\t  |o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|             \n");
        printf("\t\t  |o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|         \n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *\n\n");
        if(cont != 1){
            printf("\t\t\t\t            Tempo restante: %d segundos",cont);
        }else{
            printf("\t\t\t\t            Tempo restante: %d segundo",cont);
        }
        Sleep(950);
        system("cls");
        cont --;
    }while(cont > 0);

    if(newPergunta(1, 'G', 'D', 'M', 'A', 'a', 'G', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'V', 'I', 'U', 'N', 'a', 'V', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'Q', 'S', 'P', 'R', 'a', 'Q', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'C', 'H', 'L', 'E', 'c', 'L', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'A', 'H', 'E', 'Z', 'c', 'E', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(6, 'B', 'F', 'J', 'C', 'd', 'C', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(7, 'N', 'U', 'T', 'Y', 'd', 'Y', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(8, 'Z', 'T', 'S', 'Y', 'b', 'T', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(9, 'G', 'J', 'A', 'O', 'b', 'J', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(10, 'U', 'C', 'H', 'P', 'a', 'U', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(11, 'D', 'B', 'M', 'O', 'c', 'M', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(12, 'R', 'Z', 'P', 'A', 'b', 'Z', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(13, 'I', 'W', 'E', 'N', 'd', 'N', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(14, 'B', 'J', 'H', 'U', 'a', 'B', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(15, 'A', 'K', 'I', 'B', 'a', 'A', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(16, 'K', 'F', 'B', 'O', 'a', 'K', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(17, 'N', 'S', 'F', 'W', 'b', 'S', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(18, 'A', 'W', 'Q', 'U', 'b', 'W', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(19, 'M', 'D', 'E', 'H', 'd', 'H', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(20, 'O', 'I', 'M', 'Y', 'b', 'I', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(21, 'G', 'D', 'K', 'I', 'b', 'D', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(22, 'R', 'A', 'P', 'I', 'a', 'R', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(23, 'E', 'X', 'P', 'T', 'b', 'X', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(24, 'F', 'M', 'J', 'P', 'a', 'F', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(25, 'O', 'J', 'U', 'P', 'a', 'O', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(26, 'P', 'E', 'S', 'O', 'a', 'P', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    fimJogo("DIF?CIL", pts, acertos, numPerg);
    return;
}

/* 5) Instru??es do Jogo */
int opcao5(){
    int tempo = 50, finalopt = 0, erro = 0;
    char opt[100];
    system("cls");
    do {
        if (erro == 0) {
            addFade(4, 50, 0);
        }
        printf("\t\t\t\t     _____                     __                 \n");Sleep(tempo);
        printf("\t\t\t\t    |     |___ _____ ___    __|  |___ ___ ___ ___ \n");Sleep(tempo);
        printf("\t\t\t\t    |   --| . |     | . |  |  |  | . | . | .'|  _|\n");Sleep(tempo);
        printf("\t\t\t\t    |_____|___|_|_|_|___|  |_____|___|_  |__,|_|  \n");Sleep(tempo);
        printf("\t\t\t\t                                     |___|        \n");Sleep(tempo);

        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     |                               O QUE ? O 'JOGO DO BRAILE'?                                |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     | O 'Jogo do Braile' ? um simples jogo de mem?ria sob a forma de quiz, cujo objetivo do(a) |\n");Sleep(tempo);
        printf("\t     | jogador(a) ? acertar o m?ximo de perguntas poss?veis. Ele tem o intuito de ensinar o     |\n");Sleep(tempo);
        printf("\t     | sistema de escrita t?til 'Braile', de forma simples e l?dica, para pessoas sem           |\n");Sleep(tempo);
        printf("\t     | defici?ncia visual.                                                                      |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     |                                  COMO O JOGO FUNCIONA?                                   |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     | Neste jogo, cada pergunta ? composta por:                                                |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | * Uma letra que ser? exibida em destaque, escrita de acordo com a grafia do 'Braile'; e  |\n");Sleep(tempo);
        printf("\t     | * Quatro outras letras (alternativas) escritas de acordo com o alfabeto latino.          |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | Para responder tais perguntas, ? necess?rio memorizar as letras que aparecer?o na tela   |\n");Sleep(tempo);
        printf("\t     | por alguns segundos.                                                                     |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
        addFade(3, 50, 1);
        printf("\t\t\tDESEJA VER UM EXEMPLO DE UMA PERGUNTA? ('S' para Sim, 'N' para N?o): ");
        fgets(opt, 100, stdin);
        finalopt = verifyOpt(opt, 1);
        system("cls");
        if (finalopt == 0) {
            erro ++;
            printf("\n");
            telaErro();
            addFade(1, 50, 1);
        } else if (finalopt == 2) {
            return 0;
        }
    } while (finalopt != 1);
    printf("\n **** EXEMPLO DE UMA PERGUNTA **** \n");Sleep(tempo);
    printf("\n Esta tela mostra um exemplo de uma pergunta. Como dito anteriormente, cada pergunta apresenta: ");Sleep(tempo);
    printf("\n\n 1) Uma letra que ficar? em destaque, escrita de acordo com a grafia do 'Braile'; e ");Sleep(tempo);
    printf("\n 2) Quatro outras letras (alternativas) escritas de acordo com o alfabeto latino.\n");Sleep(tempo);
    printf("\n Observe esta pergunta: ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual ? a letra correspondente?                 ");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n Alternativa: ___ ");Sleep(tempo);
    printf("\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso o(a) jogador(a) acerte a quest?o, ganhar? 150 pontos!");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual ? a letra correspondente?");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n\n Alternativa: d ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                CERTA RESPOSTA!                | ");Sleep(tempo);
    printf("\n |           VOC? GANHOU: +150 PONTOS!           | ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso contr?rio, ganhar? apenas 50 pontos: \n");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual ? a letra correspondente?");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n\n Op??o : b ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |     VOC? ERROU... RESPOSTA CORRETA: \"d)\"      | ");Sleep(tempo);
    printf("\n |           VOC? GANHOU: +50 PONTOS!            | ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n No final do jogo, a tela de estat?sticas ser? exibida. Nele, ? poss?vel observar:\n");Sleep(tempo);
    printf("\n   * O n?mero total de acertos do(a) jogador(a); e");Sleep(tempo);
    printf("\n   * A pontua??o final referente ao(?) mesmo(a).\n\n");Sleep(tempo);
    printf("\n                +--------------------------------------+");Sleep(tempo);
    printf("\n                |           SEU DESEMPENHO             |");Sleep(tempo);
    printf("\n                +--------------------------------------+");Sleep(tempo);
    printf("\n                |                                      |");Sleep(tempo);
    printf("\n                |        N? de acertos : 8 / 10        |");Sleep(tempo);
    printf("\n                |                                      |");Sleep(tempo);
    printf("\n                |       N? total de pontos : 1200      |");Sleep(tempo);
    printf("\n                |                                      |");Sleep(tempo);
    printf("\n                +--------------------------------------+");Sleep(tempo);
    addFade(2, 50, 1);
    banner();
    addFade(2, 50, 1);
    printf("\n **** Pressione qualquer tecla para retornar ao menu **** ");
    getche();
    system("cls");
    //addFade(30, 25, 1);
    return 0;
}

/* 6) Cr?ditos do Jogo */
void opcao6(){
    int tempo = 50;
    system("cls");
    printf("\t\t\t\t\t               ___                  \n");Sleep(tempo);
    printf("\t\t\t\t\t    _____     /__/  _ _ _           \n");Sleep(tempo);
    printf("\t\t\t\t\t   |     |___ ___ _| |_| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t\t\t   |   --|  _| -_| . | |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t\t\t   |_____|_| |___|___|_|_| |___|___|");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t +-----------------------------------------------------------------------------------+ ");Sleep(tempo);
    printf("\n\t\t | Este jogo foi originalmente desenvolvido como forma de avalia??o parcial para o   | ");Sleep(tempo);
    printf("\n\t\t | trabalho final do 1? ano do Curso T?cnico em Inform?tica, ofertado pelo Instituto | ");Sleep(tempo);
    printf("\n\t\t | Federal do Paran? - Campus Colombo. Tal trabalho foi apresentado no ano de 2017   | ");Sleep(tempo);
    printf("\n\t\t | sob o nome 'Acessibilidade das pessoas com defici?ncia visual na atualidade'.     | ");Sleep(tempo);
    printf("\n\t\t +-----------------------------------------------------------------------------------+ \n");Sleep(tempo);


    printf("\t\t\t      _____               _         _               _           \n");Sleep(tempo);
    printf("\t\t\t     |  _  |___ ___ ___ _| |___ ___|_|_____ ___ ___| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t     |     | . |  _| .'| . | -_|  _| |     | -_|   |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t     |__|__|_  |_| |__,|___|___|___|_|_|_|_|___|_|_|_| |___|___|\n");Sleep(tempo);
    printf("\t\t\t           |___|                                                \n");Sleep(tempo);
    printf("\t\t\t      (Membros da equipe original - Obrigado por todo o apoio!) \n");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n     -> Arthur Ogg - 'https://github.com/Arthur-Diesel'\n");Sleep(tempo);
    printf("\n     -> Guilherme Cordeiro - 'https://github.com/gui-cordeiro'\n");Sleep(tempo);
    printf("\n     -> Jo?o Lucas - Nenhum contato dele foi encontrado, mas fica aqui registrado o enorme agradecimento a ele!\n");Sleep(tempo);
    printf("\n     -> Lucas Pereira - 'https://github.com/Luc45-Pereira'\n");Sleep(tempo);
    printf("\n     -> Matheus Delay - 'https://twitter.com/DelayMath'\n");Sleep(tempo);
    banner();
    printf("\n\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getch();
    system("cls");
    addFade(4, 50, 0);
    exibirTelaGitHub();
    printf("\n\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    //addFade(30, 25, 1);
    system("cls");
}

