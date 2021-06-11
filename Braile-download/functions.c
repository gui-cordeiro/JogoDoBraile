#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

/* ******************** FUNÇÕES AUXILIARES ******************** */

/* A) TELA DO GITHUB */
void github(){
    int tempo = 50;
    printf("\n **** O código-fonte deste jogo está disponível gratuitamente ****"); Sleep(tempo);
    printf("\n      no repositório do GitHub de Guilherme Cordeiro. Acesse:\n\n "); Sleep(tempo);
    printf("\n                        @@@@@@@@@@@@@@@@@@@                       "); Sleep(tempo);
    printf("\n                    @@@@@@@@@@@@@@@@@@@@@@@@@@@                   "); Sleep(tempo);
    printf("\n                 @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@                "); Sleep(tempo);
    printf("\n               @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@              "); Sleep(tempo);
    printf("\n             @@@@@@@@                         @@@@@@@@            "); Sleep(tempo);
    printf("\n            @@@@@@@@@                         @@@@@@@@@           "); Sleep(tempo);
    printf("\n           @@@@@@@@@                           @@@@@@@@@          "); Sleep(tempo);
    printf("\n           @@@@@@@@                             @@@@@@@@          "); Sleep(tempo);
    printf("\n           @@@@@@@@                             @@@@@@@@          "); Sleep(tempo);
    printf("\n           @@@@@@@@                             @@@@@@@@          "); Sleep(tempo);
    printf("\n           @@@@@@@@@                           @@@@@@@@@          "); Sleep(tempo);
    printf("\n            @@@@@@@@@@                       @@@@@@@@@@           "); Sleep(tempo);
    printf("\n             @@@@   @@@@@@@@           @@@@@@@@@@@@@@@            "); Sleep(tempo);
    printf("\n              @@@@@   @@@@@@           @@@@@@@@@@@@@@             "); Sleep(tempo);
    printf("\n                @@@@@                  @@@@@@@@@@@@               "); Sleep(tempo);
    printf("\n                   @@@@@@@@@           @@@@@@@@@                  "); Sleep(tempo);
    printf("\n                      @@@@@@           @@@@@@                 \n\n"); Sleep(tempo);
    printf("\n              +-------------------------------------+             "); Sleep(tempo);
    printf("\n              |   https://github.com/gui-cordeiro   |             "); Sleep(tempo);
    printf("\n              +-------------------------------------+           \n"); Sleep(1000);
    return;
}

/* B) MODELO DAS PERGUNTAS */
int newPergunta(int questao, char l1, char l2, char l3, char l4, char altResp, char letrResp, int pts, int acertos){
    int tempo = 50;
    int acertoCont;
    char opt;
    printf("\n * SEUS PONTOS: %d", pts);Sleep(tempo);
    printf("\n * SEUS ACERTOS: %d\n", acertos);Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                PERGUNTA Nº %d                  |", questao);Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printAlfabeto(letrResp);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+\n");Sleep(tempo);
    printf("\n Qual é a letra correspondente?\n");Sleep(tempo);
    printf("\n a) '%c'", l1);Sleep(tempo);
    printf("\n b) '%c'", l2);Sleep(tempo);
    printf("\n c) '%c'", l3);Sleep(tempo);
    printf("\n d) '%c'", l4);Sleep(tempo);
    printf("\n\n Alternativa: ");
    scanf(" %c",&opt);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    if(tolower(opt) == altResp){
        printf("\n |                CERTA RESPOSTA!                | ");Sleep(tempo);
        printf("\n |           VOCÊ GANHOU: 150 PONTOS!            | ");Sleep(tempo);
        acertoCont = 1;
    }else{
        printf("\n |     VOCÊ ERROU... RESPOSTA CORRETA: \"%c)\"      | ", tolower(altResp));Sleep(tempo);
        printf("\n |           VOCÊ GANHOU: 50 PONTOS.             | ");Sleep(tempo);
        acertoCont = 0;
    }
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    return acertoCont;
}

/* C) TELA DE APRESENTAÇÃO */
void apresentacao(){
    int tempo = 50;
    printf("\n\n\n\n\n\n\n");
    printf("+---------------------------------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("|      ##  #######   ######    #######     ########   #######     ########  ########     ###    #### ##       ########|\n");Sleep(tempo);
    printf("|      ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##     ##   ## ##    ##  ##       ##      |\n");Sleep(tempo);
    printf("|      ## ##     ## ##        ##     ##    ##     ## ##     ##    ##     ## ##     ##  ##   ##   ##  ##       ##      |\n");Sleep(tempo);
    printf("|      ## ##     ## ##   #### ##     ##    ##     ## ##     ##    ########  ########  ##     ##  ##  ##       ######  |\n");Sleep(tempo);
    printf("|##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##   ##   #########  ##  ##       ##      |\n");Sleep(tempo);
    printf("|##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##    ##  ##     ##  ##  ##       ##      |\n");Sleep(tempo);
    printf("| ######   #######   ######    #######     ########   #######     ########  ##     ## ##     ## #### ######## ########|\n");Sleep(tempo);
    printf("+---------------------------------------------------------------------------------------------------------------------+");Sleep(tempo);
    printf("\n                                         * Criado por Guilherme Cordeiro *                                           ");
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n                                  **** Pressione qualquer tecla para iniciar ****");
    getch();
    system("cls");
    return;
}

/* D) ALFABETO EM BRAILE */
void printAlfabeto(char letra){
    int tempo = 50;
    switch(tolower(letra)){
        case 'a':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'b':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'c':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'd':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'e':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'f':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'g':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'h':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'i':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'j':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'k':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'l':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'm':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'n':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'o':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'p':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'q':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'r':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 's':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 't':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'u':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'v':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'w':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            break;
        case 'x':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'y':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'z':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
    }
}

/* E) INICIO DO JOGO */
int inicioJogo(char nivel[100]){
    int tempo = 50;
    int opt = 0;
    char nome[40];
    system("cls");Sleep(tempo);
    printf("\n     **** OPÇÃO SELECIONADA : '%s' **** \n", nivel);Sleep(tempo);
    printf("\n           Confirma? ('1' para Sim, '2' para Não): ");Sleep(tempo);
    scanf("%d",&opt);
    if(opt == 2){
        return 0;
    }
    system("cls");
    printf("\n * Digite o seu nome : ");
    scanf(" %s",&nome);
    system("cls");
    Sleep(tempo);
    printf("\n Bem-vindo(a) '%s'! \n\n",nome);Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf(" Prepare-se! As letras em braile aparecerão em breve...");
    Sleep(500);
    system("cls");
    return 1;
}

/* F) FIM DO JOGO (ESTATÍSTICAS) */
void fimJogo(char frase[100], int pts, int acertos){
    int tempo = 50;
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |           SEU DESEMPENHO             |");Sleep(tempo);
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n |         Nº de acertos: %d / 5         |",acertos);Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n |        Nº total de pontos: %d       |",pts);Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n +--------------------------------------+");
    Sleep(1000);
    if((acertos <= 2)){
        printf("\n\n\n Bom. . . Você precisa aprender um pouco mais de braile. Não desanime, tente novamente!");
    }
    else if(acertos == 3){
        printf("\n\n\n Você tem potencial, mas precisa se esforçar um pouco mais!");
    }
    else if(acertos == 4){
        printf("\n\n\n Muito bem! Você realmente mandou bem, mas um pouquinho mais de empenho não faz mal para ninguém!");
    }
    else if(acertos == 5){
        printf("\n\n\n Meus parabéns! Você acertou todas as questões e provou do que é capaz!");
    }
    Sleep(1500);
    printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getch();
    system("cls");
    printf("\n   * %s *", frase);Sleep(tempo);
    printf("\n\n                         Selecione-o no menu!\n\n");Sleep(tempo);
    printf("\n                     **** OBRIGADO POR JOGAR! ****\n");
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n                        +---------------------+");Sleep(tempo);
    printf("\n                        |    Jogo do Braile   |");Sleep(tempo);
    printf("\n                        |Trabalho final - 2017|");Sleep(tempo);
    printf("\n                        |IFPR - Campus Colombo|");Sleep(tempo);
    printf("\n                        +---------------------+\n");
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("         **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    return;
}


/* ******************** FUNÇÕES PRINCIPAIS ******************** */

/* 0) Menu principal */
int menu(){
    int tempo = 50;
    int a = 0;
    char optMenu [7][24] = {"  Jogar - NÍVEL FÁCIL  "," Jogar - NÍVEL MÉDIO I "," Jogar - NÍVEL MÉDIO II"," Jogar - NÍVEL DIFÍCIL ","  Instruções do Jogo   ","   Créditos do Jogo    ","     Sair do Jogo      "};
    printf("\n\n          **** SELECIONE UMA OPÇÃO **** \n");Sleep(tempo);
    printf("\n       +-----------------------+---------+");Sleep(tempo);
    printf("\n       |      Descrição da     | Num. da | ");Sleep(tempo);
    printf("\n       |         Opção         |  Opção  | ");Sleep(tempo);
    printf("\n       +-----------------------+---------+ \n");Sleep(tempo);
    for(int c = 0; c < 7; c ++){
        printf("\n       +-----------------------+---------+ ");Sleep(tempo);
        printf("\n       |%s|    %d    | ", optMenu[c], c + 1);Sleep(tempo);
    }
    printf("\n       +-----------------------+---------+ \n");Sleep(tempo);
    printf("\n\n       Digite a opção: ");
    scanf("%d",&a);
    return(a);
}

/* 1) Jogar - NÍVEL FÁCIL */
void opcao1(){
    int tempo = 50;
    int conf = 0, pts = 0, acertos = 0;
    if(inicioJogo("Jogar - NÍVEL FÁCIL") == 0) return 0;
    for(int a = 10; a > 0; a --){
        printf("\n           As letras em braille nesta dificuldade são:     \n");
        printf("\n          A          E          I          O          U    \n");
        printf("\n        |o   |     |o   |     |   o|     |o   |     |o   |   ");
        printf("\n        |    |     |   o|     |o   |     |   o|     |    |   ");
        printf("\n        |    |     |    |     |    |     |o   |     |o  o| \n");
        if(a != 1){
            printf("\n              * Tempo restante : %d segundos  *",a);
        }else{
            printf("\n              * Tempo restante : %d segundo *",a);
        }
        Sleep(100);
        system("cls");
    }
    if(newPergunta(1, 'A', 'I', 'E', 'U', 'c', 'E', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(2, 'U', 'I', 'O', 'A', 'a', 'U', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(3, 'U', 'O', 'I', 'A', 'd', 'A', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(4, 'O', 'I', 'U', 'E', 'b', 'I', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(5, 'O', 'A', 'U', 'E', 'a', 'O', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    fimJogo("TENTE DIFICULTAR UM POUQUINHO MAIS! EXPERIMENTE O NÍVEL 'MÉDIO I'!", pts, acertos);
    return;
}

/* 2) Jogar - NÍVEL MÉDIO I */
void opcao2(){
    int tempo = 50;
    int conf = 0, pts = 0, acertos = 0;
    if(inicioJogo("Jogar - NÍVEL MÉDIO I") == 0) return 0;
    for(int a = 15; a > 0; a --){
        printf("\n           As letras em braille nesta dificuldade são:     \n");
        printf("\n          B          C          D          F          G    \n");
        printf("\n        |o   |     |o  o|     |o  o|     |o  o|     |o  o|   ");
        printf("\n        |o   |     |    |     |   o|     |o   |     |o  o|   ");
        printf("\n        |    |     |    |     |    |     |    |     |    | \n");
        printf("\n          H          J          K          L          M    \n");
        printf("\n        |o   |     |   o|     |o   |     |o   |     |o  o|   ");
        printf("\n        |o  o|     |o  o|     |    |     |o   |     |    |   ");
        printf("\n        |    |     |    |     |o   |     |o   |     |o   | \n");
        if(a == 1){
            printf("\n              * Tempo restante : %d segundo  *",a);
        }
        else{
            printf("\n              * Tempo restante : %d segundos *",a);
        }
        Sleep(100);
        system("cls");
    }
    if(newPergunta(1, 'G', 'D', 'M', 'J', 'a', 'G', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(2, 'C', 'H', 'L', 'B', 'c', 'L', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(3, 'B', 'F', 'J', 'C', 'd', 'C', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(4, 'G', 'J', 'D', 'M', 'b', 'J', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(5, 'D', 'B', 'M', 'H', 'c', 'M', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(6, 'B', 'J', 'H', 'D', 'a', 'B', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(7, 'K', 'F', 'B', 'H', 'a', 'K', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(8, 'M', 'D', 'C', 'H', 'd', 'H', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(9, 'G', 'D', 'K', 'F', 'b', 'D', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(10, 'F', 'M', 'B', 'J', 'a', 'F', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    fimJogo("VAMOS UM POUQUINHO MAIS ADIANTE! QUE TAL JOGAR O NÍVEL 'MÉDIO II'?", pts, acertos);
    return;
}

/* 3) Jogar - NÍVEL MÉDIO II */
void opcao3(){
    int tempo = 50;
    int conf = 0, pts = 0, acertos = 0;
    if(inicioJogo("Jogar - NÍVEL MÉDIO II") == 0) return 0;
    for(int a = 15; a > 0; a --){
        printf("\n           As letras em braille nesta dificuldade são:     \n");
        printf("\n          N          P          Q          R          S    \n");
        printf("\n        |o  o|     |o  o|     |o  o|     |o   |     |   o|   ");
        printf("\n        |   o|     |o   |     |o  o|     |o  o|     |o   |   ");
        printf("\n        |o   |     |o   |     |o   |     |o   |     |o   | \n");
        printf("\n          T          V          W          X          Y    \n");
        printf("\n        |   o|     |o   |     |   o|     |o  o|     |o  o|   ");
        printf("\n        |o  o|     |o   |     |o  o|     |    |     |   o|   ");
        printf("\n        |o   |     |o  o|     |   o|     |o  o|     |o  o| \n");
        printf("\n                                Z     \n");
        printf("\n                              |o   |    ");
        printf("\n                              |   o|    ");
        printf("\n                              |o  o| \n\n");
        if(a == 1){
            printf("\n              * Tempo restante : %d segundo *",a);
        }else{
            printf("\n              * Tempo restante : %d segundos *",a);
        }
        Sleep(100);
        system("cls");
    }
    if(newPergunta(1, 'V', 'W', 'T', 'N', 'a', 'V', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(2, 'P', 'S', 'Q', 'R', 'c', 'Q', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(3, 'N', 'P', 'T', 'Y', 'd', 'Y', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(4, 'Z', 'T', 'S', 'Y', 'b', 'T', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(5, 'R', 'Z', 'P', 'W', 'b', 'Z', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(6, 'V', 'W', 'Z', 'N', 'd', 'N', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(7, 'N', 'S', 'P', 'Y', 'b', 'S', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(8, 'S', 'Q', 'W', 'Y', 'c', 'W', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(9, 'R', 'Q', 'P', 'Y', 'a', 'R', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(10, 'Z', 'X', 'P', 'T', 'b', 'X', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(11, 'X', 'W', 'S', 'P', 'd', 'P', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    fimJogo("QUER PROVAR QUE REALMENTE SABE BRAILE? ENTÃO VÁ AO NÍVEL 'DIFÍCIL'!", pts, acertos);
    return;
}

/* 4) Jogar - NÍVEL DIFÍCIL */
void opcao4(){
    int tempo = 50;
    int conf = 0, pts = 0, acertos = 0;
    if(inicioJogo("Jogar - NÍVEL DIFÍCIL") == 0) return 0;
    for(int a = 30; a > 0; a --){
        printf("\n                                                  As letras em braille nesta dificuldade são:\n");
        printf("\n          A          B          C          D          E          F          G          H          I           J          K          L     \n");
        printf("\n        |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|      |   o|     |o   |     |o   |    ");
        printf("\n        |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |      |o  o|     |    |     |o   |    ");
        printf("\n        |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |      |    |     |o   |     |o   |  \n");
        printf("\n          M          N          O          P          Q          R          S          T          U           V          W          X     \n");
        printf("\n        |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|     |   o|     |o   |      |o   |     |   o|     |o  o|    ");
        printf("\n        |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |    |      |o   |     |o  o|     |    |    ");
        printf("\n        |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o  o|      |o  o|     |   o|     |o  o|   \n");
        printf("\n                                                                 Y          Z     \n");
        printf("\n                                                               |o  o|     |o   |    ");
        printf("\n                                                               |   o|     |   o|    ");
        printf("\n                                                               |o  o|     |o  o|\n\n");
        if(a != 1){
            printf("\n              * Tempo restante : %d segundos *",a);
        }else{
            printf("\n              * Tempo restante : %d segundo  *",a);
        }
        Sleep(100);
        system("cls");
    }

    if(newPergunta(1, 'G', 'D', 'M', 'J', 'a', 'G', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(2, 'V', 'W', 'T', 'N', 'a', 'V', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(3, 'Q', 'S', 'P', 'R', 'a', 'Q', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(4, 'C', 'H', 'L', 'B', 'c', 'L', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(5, 'A', 'I', 'E', 'U', 'c', 'E', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(6, 'B', 'F', 'J', 'C', 'd', 'C', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(7, 'N', 'P', 'T', 'Y', 'd', 'Y', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(8, 'Z', 'T', 'S', 'Y', 'b', 'T', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(9, 'G', 'J', 'D', 'M', 'b', 'J', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(10, 'U', 'I', 'O', 'A', 'a', 'U', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(11, 'D', 'B', 'M', 'H', 'c', 'M', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(12, 'R', 'Z', 'P', 'W', 'b', 'Z', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(13, 'V', 'W', 'Z', 'N', 'd', 'N', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(14, 'B', 'J', 'H', 'D', 'a', 'B', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(15, 'A', 'O', 'I', 'U', 'a', 'A', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(16, 'K', 'F', 'B', 'H', 'a', 'K', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(17, 'N', 'S', 'F', 'W', 'b', 'S', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(18, 'S', 'W', 'Q', 'Y', 'b', 'W', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(19, 'M', 'D', 'C', 'H', 'd', 'H', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(20, 'O', 'I', 'U', 'E', 'b', 'I', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(21, 'G', 'D', 'K', 'F', 'b', 'D', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(22, 'R', 'Q', 'P', 'Y', 'a', 'R', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(23, 'Z', 'X', 'P', 'T', 'b', 'X', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(24, 'F', 'M', 'B', 'J', 'a', 'F', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(25, 'O', 'A', 'U', 'E', 'a', 'O', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;
    if(newPergunta(26, 'P', 'W', 'S', 'X', 'a', 'P', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50;

    if(acertos == 26){
        fimJogo("MEUS SINCEROS PARABÉNS! VOCÊ PROVOU QUE MANDA VER NO BRAILE!!!", pts, acertos);
    }else{
        fimJogo("NÃO DESISTA! TENTE NOVAMENTE EM OUTROS MODOS PARA MELHORAR SEUS CONHECIMENTOS!", pts, acertos);
    }
    return;
}

/* 5) Instruções do Jogo */
void opcao5(){
    int tempo = 50, a = 0;
    system("cls");
    printf("\n **** INSTRUÇÕES DO JOGO **** \n");Sleep(tempo);
    printf("\n     O jogador deve memorizar as letras escritas em braille que estarão impressas na tela por um certo");Sleep(tempo);
    printf("\n período de tempo e responder as perguntas que irão aparecer na mesma. Cada pergunta terá uma das letras");Sleep(tempo);
    printf("\n apresentadas anteriormente e o jogador terá que responder qual é a letra correspondente, selecionando");Sleep(tempo);
    printf("\n umas das 4 alternativas propostas.");Sleep(tempo);
    printf("\n\n\n VOCÊ DESEJA VER O EXEMPLO? ('1' para Sim, '2' para Não): ");
    scanf("%d",&a);
    if(a == 2) return 0;
    system("cls");
    printf("\n **** EXEMPLO DO JOGO **** \n");Sleep(tempo);
    printf("\n Após o jogador memorizar as letras escritas em braille, correspondentes à dificuldade selecionada");Sleep(tempo);
    printf("\n uma pergunta irá aparecer na tela, contendo: ");Sleep(tempo);
    printf("\n\n 1) Uma das letras já mostradas anteriormente em destaque; ");Sleep(tempo);
    printf("\n 2) 4 possíveis respostas para a pergunta (alternativas).\n");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual é a letra correspondente?                 ");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n Alternativa: ___ ");Sleep(tempo);
    printf("\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso o jogador acerte a questão, ele ganhará 150 pontos:");Sleep(tempo);
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
    printf("\n\n Qual é a letra correspondente?");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n\n Alternativa: d ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                CERTA RESPOSTA!                |");Sleep(tempo);
    printf("\n |           VOCÊ GANHOU: 150 PONTOS!            |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso contrário, ganhará apenas 50 : \n");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual é a letra correspondente?");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n\n Opção : b ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |     VOCÊ ERROU... RESPOSTA CORRETA: \"d)\"      | ");Sleep(tempo);
    printf("\n |           VOCÊ GANHOU: 50 PONTOS.             | ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n No final do jogo, algumas estatísticas irão aparecer na tela em relação ao desempenho do jogador : \n\n\n");Sleep(tempo);
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |           SEU DESEMPENHO             |");Sleep(tempo);
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n |         Nº de acertos : 8 / 10       |");Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n |       Nº total de pontos : 1200      |");Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n         **** BOA DIVERSÃO! **** \n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n **** Pressione qualquer tecla para retornar ao menu **** ");
    getche();
    return;
}

/* 6) Créditos do Jogo */
void opcao6(){
    int tempo = 50;
    system("cls");
    printf("\n **** CRÉDITOS (VERSÃO ORIGINAL) **** \n");Sleep(tempo);
    printf("\n  +-----------------------------------------------------------------------------------+ ");Sleep(tempo);
    printf("\n  | Tema do trabalho original: 'Acessibilidade dos deficientes visuais na atualidade' | ");Sleep(tempo);
    printf("\n  +-----------------------------------------------------------------------------------+ \n\n");Sleep(tempo);
    printf("\n Equipe original formada por : \n");Sleep(tempo);
    printf("\n     - Arthur Ogg - github.com/Arthur-Diesel\n");Sleep(tempo);
    printf("\n     - Guilherme Cordeiro - github.com/gui-cordeiro\n");Sleep(tempo);
    printf("\n     - João Lucas - *contato não encontrado*\n");Sleep(tempo);
    printf("\n     - Lucas Pereira - facebook.com/luca.lima.9674\n");Sleep(tempo);
    printf("\n     - Matheus Delay - twitter.com/DelayMath\n\n");Sleep(tempo);
    printf("\n     +---------------------+");Sleep(tempo);
    printf("\n     |   Jogo do Braille   |");Sleep(tempo);
    printf("\n     |Trabalho final - 2017|");Sleep(tempo);
    printf("\n     |IFPR - Campus Colombo|");Sleep(tempo);
    printf("\n     +---------------------+");Sleep(tempo);
    printf("\n\n\n   **** Pressione qualquer tecla para continuar ****");
    getch();
    system("cls");
    github();
    printf("\n   **** Pressione qualquer tecla para retornar ao menu ****      ");
    getch();
    return;
}
