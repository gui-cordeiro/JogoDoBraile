#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#define tempo 50

/* A) TELA DO GITHUB */
void exibirTelaGitHub(){
    //int tempo = 50;
    printf("\n\t\t\t   **** O código-fonte deste jogo está disponível gratuitamente **** "); Sleep(tempo);
    printf("\n\t\t\t        no repositório do GitHub de Guilherme Cordeiro. Acesse:  \n\n"); Sleep(tempo);
    printf("\n\t\t\t                          @@@@@@@@@@@@@@@@@@@                        "); Sleep(tempo);
    printf("\n\t\t\t                      @@@@@@@@@@@@@@@@@@@@@@@@@@@                    "); Sleep(tempo);
    printf("\n\t\t\t                   @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@                 "); Sleep(tempo);
    printf("\n\t\t\t                 @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@               "); Sleep(tempo);
    printf("\n\t\t\t               @@@@@@@@                         @@@@@@@@             "); Sleep(tempo);
    printf("\n\t\t\t              @@@@@@@@@                         @@@@@@@@@            "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@@                           @@@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@@                           @@@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t              @@@@@@@@@@                       @@@@@@@@@@            "); Sleep(tempo);
    printf("\n\t\t\t               @@@@   @@@@@@@@           @@@@@@@@@@@@@@@             "); Sleep(tempo);
    printf("\n\t\t\t                @@@@@   @@@@@@           @@@@@@@@@@@@@@              "); Sleep(tempo);
    printf("\n\t\t\t                  @@@@@                  @@@@@@@@@@@@                "); Sleep(tempo);
    printf("\n\t\t\t                     @@@@@@@@@           @@@@@@@@@                   "); Sleep(tempo);
    printf("\n\t\t\t                        @@@@@@           @@@@@@                  \n\n"); Sleep(tempo);
    printf("\n\t\t\t                +-------------------------------------+              "); Sleep(tempo);
    printf("\n\t\t\t                |   https://github.com/gui-cordeiro   |              "); Sleep(tempo);
    printf("\n\t\t\t                +-------------------------------------+            \n"); Sleep(tempo);
    return;
}

/* B) MODELO DAS PERGUNTAS */
int newPergunta(int questao, char a1, char a2, char a3, char a4, char altResp, char letrResp, int pts, int acertos){
    int acertoCont = 0;
    char opt;

    printf("\t\t\t\t   +-------------+ \t\t    +--------------+\n");Sleep(tempo);
    printf("\t\t\t\t   | ACERTOS: ");
    if (acertos < 10) printf("0");
    printf("%d | \t\t    | PONTOS: ", acertos);
    if (pts < 10) {
        printf("000");
    } else if (pts < 100) {
        printf("00");
    } else if (pts < 1000) {
        printf("0");
    }
    printf("%d |\n", pts);Sleep(tempo);
    printf("\t\t\t\t   +-------------+ \t\t    +--------------+\n\n");Sleep(tempo);

    exibirbannerPergunta(questao);

    printf("\n\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t   |            Letra escrita em Braile            |");Sleep(tempo);
    printf("\n\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto(letrResp);
    printf("\n\t\t\t\t   |                                               |");Sleep(tempo);
    printf("\n\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t  * Qual é a letra correspondente? *\n\n");Sleep(tempo);
    printf("\n\t\t\t\t\t      a) --> %c        c) --> %c ", a1, a3);Sleep(tempo);
    //printf("\n\t\t\t\t\t\t      b) --> '%c'", a2);Sleep(tempo);
    printf("\n\t\t\t\t\t                   ", a2);Sleep(tempo);
    printf("\n\t\t\t\t\t      b) --> %c        d) --> %c ", a2, a4);Sleep(tempo);
    //printf("\n\t\t\t\t\t\t      d) --> '%c'", a4);Sleep(tempo);

    /*printf("\n\t\t\t\t   +--------------+-----+-----+-----+-----+");Sleep(tempo);
    printf("\n\t\t\t\t   | Alternativas |  1  |  2  |  3  |  4  |");Sleep(tempo);
    printf("\n\t\t\t\t   +--------------+-----+-----+-----+-----+");Sleep(tempo);
    printf("\n\t\t\t\t   |    Opções    | '%c' | '%c' | '%c' | '%c' |", a1, a2, a3, a4);Sleep(tempo);
    printf("\n\t\t\t\t   +--------------+-----+-----+-----+-----+");Sleep(tempo);*/
    printf("\n\n\t\t\t\t\t       +--------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t\t Insira sua opção: ");
    scanf(" %c", &opt);
    printf("\n\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    if (tolower(opt) == altResp) {
        printf("\n\t\t\t\t   |                CERTA RESPOSTA!                | ");Sleep(tempo);
        printf("\n\t\t\t\t   |           VOCÊ GANHOU: +150 PONTOS!           | ");Sleep(tempo);
        acertoCont ++;
    } else {
        printf("\n\t\t\t\t   |     VOCÊ ERROU... RESPOSTA CORRETA: \"%c)\"      | ", altResp);Sleep(tempo);
        printf("\n\t\t\t\t   |           VOCÊ GANHOU: +50 PONTOS!            | ");Sleep(tempo);
    }
    printf("\n\t\t\t\t   +----------------------------------------------+");Sleep(tempo);
    printf("\n\n\t\t\t\t   **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    return acertoCont;
}

/* C) TELA DE APRESENTAÇÃO */
void apresentacao(){
    //int tempo = 50;
    system("cls");
    addFade(12, 0, 0);
    printf("                                 **** Criado por Guilherme Cordeiro (2017-%d) ****                                \n\n", obterAnoAtual());
    printf("+---------------------------------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("|      ##  #######   ######    #######     ########   #######     ########  ########     ###    #### ##       ########|\n");Sleep(tempo);
    printf("|      ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##     ##   ## ##    ##  ##       ##      |\n");Sleep(tempo);
    printf("|      ## ##     ## ##        ##     ##    ##     ## ##     ##    ##     ## ##     ##  ##   ##   ##  ##       ##      |\n");Sleep(tempo);
    printf("|      ## ##     ## ##   #### ##     ##    ##     ## ##     ##    ########  ########  ##     ##  ##  ##       ######  |\n");Sleep(tempo);
    printf("|##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##   ##   #########  ##  ##       ##      |\n");Sleep(tempo);
    printf("|##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##    ##  ##     ##  ##  ##       ##      |\n");Sleep(tempo);
    printf("| ######   #######   ######    #######     ########   #######     ########  ##     ## ##     ## #### ######## ########|\n");Sleep(tempo);
    printf("+---------------------------------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(2, 50, 1);
    printf("                                   **** Pressione qualquer tecla para iniciar ****");
    getch();
    Sleep(200);
    //addFade(12, 0, 0);
    //addFade(27, 32, 1);
    system("cls");
    return;
}

/* D) ALFABETO EM BRAILE */
void printAlfabeto(char letra){
    //int tempo = 50;
    switch(tolower(letra)){
        case 'a':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'b':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'c':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'd':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'e':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'f':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'g':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'h':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'i':
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'j':
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            break;
        case 'k':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'l':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'm':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'n':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'o':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'p':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'q':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'r':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 's':
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 't':
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            break;
        case 'u':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'v':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'w':
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            break;
        case 'x':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |    |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'y':
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'z':
            printf("\n\t\t\t\t   |                   |o   |                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |   o|                      |");Sleep(tempo);
            printf("\n\t\t\t\t   |                   |o  o|                      |");Sleep(tempo);
            break;
    }
}

/* E) TELA DE CONFIRMAÇÃO DE DIFICULDADE */
int confirmarJogo(char nivel[9]){
    //int tempo = 50;
    int finalopt = 0, erro = 0;
    char opt[100];
    char nome[40];
    system("cls");
    titulo(nivel, "Confirmar Dificuldade");
    do{
        if (erro == 0) addFade(4, 50, 0);
        else addFade(2, 50, 0);
        printf("\t\t\t\t\t      * DIFICULDADE SELECIONADA: *\n");Sleep(tempo);
        if (strcmp("FÁCIL", nivel) == 0) {
            printf("\t\t\t\t         _____ _         _    _____         _ _ \n");Sleep(tempo);
            printf("\t\t\t\t        |   | |_|_ _ ___| |  |   __|___ ___|_| |\n");Sleep(tempo);
            printf("\t\t\t\t        | | | | | | | -_| |  |   __| .'|  _| | |\n");Sleep(tempo);
            printf("\t\t\t\t        |_|___|_|\\_/|___|_|  |__|  |__,|___|_|_|\n");Sleep(tempo);
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | Vamos começar a jornada rumo à maestria no Braile? Nesta dificuldade, você dará |\n");Sleep(tempo);
            printf("\t\t  | os seus primeiros passos tentando adivinhar as \"vogais\". Pode parecer fácil,    |\n");Sleep(tempo);
            printf("\t\t  | mas será fundamental para o seu processo de aprendizado. VAMOS LÁ?              |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t\t  +-------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t\t  | GRUPO DO ALFABETO PROPOSTO: \"VOGAIS\" - 5 letras |\n");Sleep(tempo);
            printf("\t\t\t\t  +-------------------------------------------------+\n");Sleep(tempo);
        } else if (strcmp("MÉDIO I", nivel) == 0) {
            printf("\t\t\t\t    _____ _         _    _____       _ _        _____ \n");Sleep(tempo);
            printf("\t\t\t\t   |   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|\n");Sleep(tempo);
            printf("\t\t\t\t   | | | | | | | -_| |  | | | | -_| . | | . |   _| |_ \n");Sleep(tempo);
            printf("\t\t\t\t   |_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|\n");Sleep(tempo);
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | Agora as coisas começam a ficar mais sérias! Nesta dificuldade, você enfrentará |\n");Sleep(tempo);
            printf("\t\t  | o grupo das \"CONSOANTES\", mas calma! Para facilitar o aprendizado, este grupo   |\n");Sleep(tempo);
            printf("\t\t  | será separado em dois (o 2º grupo se encontra no \"NÍVEL MÉDIO II\"). VAMOS LÁ?   |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t| GRUPO DO ALFABETO PROPOSTO: 1º metade das \"CONSOANTES\" - 10 letras |\n");Sleep(tempo);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
        } else if (strcmp("MÉDIO II", nivel) == 0) {
            printf("\t\t\t         _____ _         _    _____       _ _        _____ _____ \n");Sleep(tempo);
            printf("\t\t\t        |   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|_   _|\n");Sleep(tempo);
            printf("\t\t\t        | | | | | | | -_| |  | | | | -_| . | | . |   _| |_ _| |_ \n");Sleep(tempo);
            printf("\t\t\t        |_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|_____|\n");Sleep(tempo);
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | Você está quase completando o alfabeto inteiro, continue assim! Dando continui- |\n");Sleep(tempo);
            printf("\t\t  | dade ao processo de aprendizagem, nesta dificuldade você enfrentará o 2º grupo  |\n");Sleep(tempo);
            printf("\t\t  | das \"CONSOANTES\" (o 1º grupo se encontra no \"NÍVEL MÉDIO I\"). VAMOS LÁ?         |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t| GRUPO DO ALFABETO PROPOSTO: 2º metade das \"CONSOANTES\" - 11 letras |\n");Sleep(tempo);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
        } else if (strcmp("DIFÍCIL", nivel) == 0) {
            printf("\t\t\t\t       _____ _         _    ____  _ ___ _     _ _ \n");Sleep(tempo);
            printf("\t\t\t\t      |   | |_|_ _ ___| |  |    \\|_|  _|_|___|_| |\n");Sleep(tempo);
            printf("\t\t\t\t      | | | | | | | -_| |  |  |  | |  _| |  _| | |\n");Sleep(tempo);
            printf("\t\t\t\t      |_|___|_|\\_/|___|_|  |____/|_|_| |_|___|_|_|\n");Sleep(tempo);
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | [RECOMENDA-SE JOGAR OS OUTROS MODOS ANTES DE JOGAR ESTE MODO] O teste supremo! O|\n");Sleep(tempo);
            printf("\t\t  | \"Gran Finale\"! Coloque à prova todo o seu conhecimento adquirido até agora para |\n");Sleep(tempo);
            printf("\t\t  | ver se você realmente merece receber o título de \"Mestre do Braile\"! VAMOS LÁ?  |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t    +-------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t    | GRUPO DO ALFABETO PROPOSTO: \"ALFABETO COMPLETO\" - 26 letras |\n");Sleep(tempo);
            printf("\t\t\t    +-------------------------------------------------------------+\n");Sleep(tempo);
        }
        addFade(1, 50, 1);
        printf("\t\t\t\t\t                                 _____ \n");Sleep(tempo);
        printf("\t\t\t\t\t _____         ___ _            |___  |\n");Sleep(tempo);
        printf("\t\t\t\t\t|     |___ ___|  _|_|___ _____ ___|  _|\n");Sleep(tempo);
        printf("\t\t\t\t\t|   --| . |   |  _| |  _|     | .'|_|  \n");Sleep(tempo);
        printf("\t\t\t\t\t|_____|___|_|_|_| |_|_| |_|_|_|__,|_|  \n");Sleep(tempo);
        addFade(1, 50, 1);
        printf("\t\t\t\t       (Digite 'S' para \"Sim\" ou 'N' para \"Não\")\n");Sleep(tempo);
        addFade(2, 50, 1);
        printf("\t\t\t\t\t\t       Opção: ");
        fgets(opt, 100, stdin);
        finalopt = verifyOpt(opt, 1);
        system("cls");
        if (finalopt == 0) {
            erro ++;
            addFade(1, 50, 0);
            telaErro();
        } else if (finalopt == 2) {
            return 0;
        }
    } while (finalopt != 1);
    return 1;
}

/* F) TELA DE BOAS-VINDAS 1 - RECEBE O NOME DO JOGADOR*/
void boasVindas01(char nivel[9]){
    //int tempo = 50;
    titulo(nivel, "Boas-vindas ao Jogo do Braile!");
    printf("\n\n\n\n\n");
    if (strcmp(nivel, "FÁCIL") == 0) {
        printf("\t\t\t       +-------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t       | Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s' |\n", nivel);Sleep(tempo);
        printf("\t\t\t       +-------------------------------------------------------+\n");Sleep(tempo);
    } else if (strcmp(nivel, "MÉDIO I") == 0 || strcmp(nivel, "DIFÍCIL") == 0) {
        printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t      | Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s' |\n", nivel);Sleep(tempo);
        printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        printf("\t\t\t      +----------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t      | Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s' |\n", nivel);Sleep(tempo);
        printf("\t\t\t      +----------------------------------------------------------+\n");Sleep(tempo);
    }
    addFade(2, 50, 1);
}

/* G) TELA DE BOAS-VINDAS 2 - OBSERVAÇÕES FINAIS */
void boasVindas02(char nome[40]){
    //int tempo = 50;
    //addFade(25, 0, 0);
    //addFade(5, 30, 1);
    //printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t       -> Olá '%s'! É um prazer enorme ter você aqui jogando!", nome);
    addFade(3, 50, 1);
    printf("\t      +-----------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t      |########  #### ##     ## #### ########  ########    ###             ######  ######## ####|\n");Sleep(tempo);
    printf("\t      |##     ##  ##  ##     ##  ##  ##     ##    ##      ## ##           ##    ## ##       ####|\n");Sleep(tempo);
    printf("\t      |##     ##  ##  ##     ##  ##  ##     ##    ##     ##   ##          ##       ##       ####|\n");Sleep(tempo);
    printf("\t      |##     ##  ##  ##     ##  ##  ########     ##    ##     ## #######  ######  ######    ## |\n");Sleep(tempo);
    printf("\t      |##     ##  ##   ##   ##   ##  ##   ##      ##    #########               ## ##           |\n");Sleep(tempo);
    printf("\t      |##     ##  ##    ## ##    ##  ##    ##     ##    ##     ##         ##    ## ##       ####|\n");Sleep(tempo);
    printf("\t      |########  ####    ###    #### ##     ##    ##    ##     ##          ######  ######## ####|\n");Sleep(tempo);
    printf("\t      +-----------------------------------------------------------------------------------------+\n");Sleep(tempo);
    addFade(2, 50, 1);
    printf("\t\t\t  +---------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t  |                         * ATENÇÃO! *                          |\n");Sleep(tempo);
    printf("\t\t\t  +---------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t  | As letras em braile aparecerão na próxima tela. Preparado(a)? |\n");Sleep(tempo);
    printf("\t\t\t  +---------------------------------------------------------------+");
    addFade(2, 50, 1);
    printf("\t\t\t\t  **** Pressione qualquer tecla para continuar ****");
    getchar();
    //addFade(5, 0, 0);
    //addFade(25, 30, 1);
    system("cls");
}

/* H) FIM DO JOGO (TABELA DE ESTATÍSTICAS) */
void fimJogo(int nivel, char frase[100], char nome[40], int pts, int acertos, int numPerg){
    //int tempo = 50;
    printf("\n +--------------------------------------+");Sleep(tempo);
    if (nivel == 1) {
        printf("\n |   RESULTADO FINAL - NÍVEL 'FÁCIL'    |");Sleep(tempo);
    } else if(nivel == 2){
        printf("\n |  RESULTADO FINAL - NÍVEL 'MÉDIO I'   |");Sleep(tempo);
    } else if(nivel == 3){
        printf("\n |  RESULTADO FINAL - NÍVEL 'MÉDIO II'  |");Sleep(tempo);
    } else {
        printf("\n |  RESULTADO FINAL - NÍVEL 'DIFÍCIL'   |");Sleep(tempo);
    }
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    if(numPerg < 10){
        printf("\n |         Nº de acertos: %d / %d         |", acertos, numPerg);
    }else if(acertos < 10){
        printf("\n |         Nº de acertos: %d / %d        |", acertos, numPerg);
    }else{
        printf("\n |        Nº de acertos: %d / %d        |", acertos, numPerg);
    }
    Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    if(pts < 1000){
    printf("\n |        Nº total de pontos: %d       |", pts);
    }else{
    printf("\n |       Nº total de pontos: %d       |", pts);
    }
    Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n +--------------------------------------+");
    Sleep(1000);
    /*if(((nivel == 1 && acertos <= 2) || (nivel == 2 && acertos <= 3)) || ((nivel == 3 && acertos <= 3) || (nivel == 4 && acertos <= 8))){
        printf("\n\n\n Não se frustre, %s! Errar faz parte, e é somente errando que você irá aprender!", nome);
    }
    else if(((nivel == 1 && acertos <= 3) || (nivel == 2 && acertos <= 6)) || ((nivel == 3 && acertos <= 6) || (nivel == 4 && acertos <= 15))){
        printf("\n\n\n Você está indo no caminho certo, %s! Continue firme, você consegue!", nome);
    }
    else if(((nivel == 1 && acertos <= 4) || (nivel == 2 && acertos <= 9)) || ((nivel == 3 && acertos <= 9) || (nivel == 4 && acertos <= 22))){
        printf("\n\n\n Muito bem, %s! Você realmente mandou bem, mas um pouquinho mais de empenho não faz mal para ninguém!", nome);
    }
    else if(((nivel == 1 && acertos == 5) || (nivel == 2 && acertos == 10)) || ((nivel == 3 && acertos == 11) || (nivel == 4 && acertos == 26))){
        printf("\n\n\n Meus parabéns, %s! Você acertou todas as questões e provou do que é capaz!", nome);
    }
    Sleep(1500);*/
    addFade(3, tempo, 1);
    printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getch();
    //addFade(12, 0, 0);
    //addFade(18, 30, 1);
    system("cls");
    printf("\n   * %s *", frase);Sleep(tempo);

    if (acertos != 26) {
        printf("\n\n                         Selecione-o no menu!\n\n");Sleep(tempo);
    }

    printf("\n                     **** OBRIGADO POR JOGAR! ****\n");
    addFade(5, 50, 1);
    banner();
    addFade(5, 50, 1);
    printf("         **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    system("cls");
    //addFade(6, 0, 0);
    //addFade(24, 30, 1);
    return;
}

/* I) ANIMAÇÃO DE TRANSIÇÃO DE TELA */
void addFade(int rep, int millis, int isLento){
    for(int cont = 0; cont < rep; cont ++){
            printf("\n");
            if(isLento != 0) Sleep(millis);
    }
}

/* J) BANNER DE APRESENTAÇÃO */
void banner(){
    //int tempo = 50;
    printf("\n\t\t\t\t     +-------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t     |        Jogo do Braile - 2017, %d        |", obterAnoAtual());Sleep(tempo);
    printf("\n\t\t\t\t     +-------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t     |      Criado por: Guilherme Cordeiro       |");Sleep(tempo);
    printf("\n\t\t\t\t     +-------------------------------------------+\n");Sleep(tempo);
    return;
}

/* K) TELA DE ERRO (AO DIGITAR UMA OPÇÃO ERRADA) */
void telaErro(){
    //int tempo = 50;
    printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t      |                       * ATENÇÃO *                       |\n");Sleep(tempo);
    printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t      | Opção inválida. Siga as instruções especificadas abaixo |\n");Sleep(tempo);
    printf("\t\t\t      +---------------------------------------------------------+");Sleep(tempo);
}

/* L) RECUPERA O ANO ATUAL DO SISTEMA */
int obterAnoAtual(){
    int anoAtual = 0;
    time_t data_ano;
    time(&data_ano);
    struct tm *data = localtime(&data_ano);
    anoAtual = (data->tm_year+1900);
    return anoAtual;
}

/* M) CONFIGURAÇÕES INICIAIS DO JOGO  */
void configJogo(){
    setlocale(LC_ALL,"Portuguese");
    system("title Tela de título - Jogo do Braile 1.0.0");
    system("mode con:cols=119 lines=38");

    //Ignorar esta parte:
    /*printf("#######################################################################################################################\n");
    for (int i = 0; i <= 27; i ++) {
        if (i == 12) {
            printf("#\t\t\t\t Ajuste a janela do console para uma melhor experiência \t\t\t      #\n");
        } else if (i == 13) {
            printf("#\t\t\t\t      Para isso, utilize as bordas como referência \t\t\t\t      #\n");
        } else if (i == 16) {
            printf("#\t\t\t\t* Feito isso, pressione qualquer tecla para continuar! *\t\t\t      #\n");
        } else {
            printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t      #\n");
        }
    }
    printf("#######################################################################################################################");
    getchar();
    system("cls");*/
}

/* N) ALTERNAR ENTRE MODO "JANELA" E MODO "TELA CHEIA" */
void fullScreen() {
    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
}

/* O) RETORNA TÍTULO DO CONSOLE PERSONALIZADO */
void titulo(char nivel[9], char frase[50]){
    char comando[100] = "title ";
    if (strncmp(nivel, "-", 1) != 0) {
        strcat(comando, "[");
        strcat(comando, nivel);
        strcat(comando, "] ");
    }
    strcat(comando, frase);
    strcat(comando, " - Jogo do Braile 1.0.0");
    system(comando);
}

/* P) VERIFICA SE A OPÇÃO ESTÁ CORRETA (RETORNO 0=ERRO, 1=SIM, 2=NÃO) */
int verifyOpt(char opt[100], int mode){
    int i = 0, espaco = 0;
    while (opt[i] != '\0') {
        if (opt[i] == ' ') {
           espaco ++;
        }
        i ++;
    }
    if ((strlen(opt) - 1) == 1 && espaco == 0) {
        if (mode == 1) {
            if (strncmp(opt, "n", 1) == 0 || strncmp(opt, "N", 1) == 0) {
                return 2;
            } else if (strncmp(opt, "s", 1) != 0 && strncmp(opt, "S", 1) != 0) {
                return 0;
            }
        } else if (mode == 2) {
            //W.I.P....
        }
    } else {
        //addFade(30, 25, 1);
        return 0;
    }
    return 1;
}

/* Q) RETORNA O BANNER CORRESPONDENTE AO NÚMERO DA PERGUNTA */
void exibirbannerPergunta(int questao){
    switch (questao) {
        case 1:
            printf("\t\t\t      _____                     _                       ___ ___   \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |  \n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_| |_ \n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|_____|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 2:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |  _|\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 3:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 4:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | | |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___  |_|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 5:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |  _|\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 6:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |  _|\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | | . |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 7:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | | | |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___| |_|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 8:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | . |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | | . |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 9:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | . |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 10:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |   |\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| | |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 11:
            printf("\t\t\t     _____                     _                       ___   ___   \n");Sleep(tempo);
            printf("\t\t\t    |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |_  |  \n");Sleep(tempo);
            printf("\t\t\t    |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_ _| |_ \n");Sleep(tempo);
            printf("\t\t\t    |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|_____|\n");Sleep(tempo);
            printf("\t\t\t                  |___|                                            \n");Sleep(tempo);
            break;
        case 12:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |_  |\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|  _|\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 13:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |_  |\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 14:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | | |\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____| |_|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 15:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |  _|\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 16:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |  _|\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| . |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 17:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|_|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 18:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | . |\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| . |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 19:
            printf("\t\t\t      _____                     _                       ___   ___ \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | . |\n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |\n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 20:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |   |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _| | |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 21:
            printf("\t\t\t      _____                     _                      ___ ___   \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___    |_  |_  |  \n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_  |  _|_| |_ \n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_| |___|_____|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                         \n");Sleep(tempo);
            break;
        case 22:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|  _|\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 23:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 24:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___  |_|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 25:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |  _|\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 26:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |  _|\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _| . |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
    }
}

/* Q) RETORNA O BANNER CORRESPONDENTE AO NÚMERO DA PERGUNTA */
void exibirBannerDificuldade(int dificuldade){
    switch(dificuldade) {
        case 1:
            printf("\t\t\t      _____                     _                       ___ ___   \n");Sleep(tempo);
            printf("\t\t\t     |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |  \n");Sleep(tempo);
            printf("\t\t\t     |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_| |_ \n");Sleep(tempo);
            printf("\t\t\t     |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|_____|\n");Sleep(tempo);
            printf("\t\t\t                   |___|                                          \n");Sleep(tempo);
            break;
        case 2:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |  _|\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 3:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
        case 4:
            printf("\t\t\t       _____                     _                       ___ ___ \n");Sleep(tempo);
            printf("\t\t\t      |  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | | |\n");Sleep(tempo);
            printf("\t\t\t      |   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |\n");Sleep(tempo);
            printf("\t\t\t      |__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___  |_|\n");Sleep(tempo);
            printf("\t\t\t                    |___|                                        \n");Sleep(tempo);
            break;
    }
}
