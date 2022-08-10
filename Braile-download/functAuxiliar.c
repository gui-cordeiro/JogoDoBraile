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
int newPergunta(int dificuldade, int questao, char letrResp, int pts, int acertos){
    char altResposta;
    int acertoCont = 0;
    char opt;
    char alt[4] = {' ', ' ', ' ', ' '};
    int posCorreta = rand() % 4;
    alt[posCorreta] = letrResp;
    if (posCorreta == 0) {
        altResposta = 'a';
    } else if (posCorreta == 1) {
        altResposta = 'b';
    } else if (posCorreta == 2) {
        altResposta = 'c';
    } else if (posCorreta == 3) {
        altResposta = 'd';
    }
    gerarSeqAlt(dificuldade, alt, letrResp);
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
    printf("\n\t\t\t\t\t      a) --> %c        c) --> %c", alt[0], alt[2]);Sleep(tempo);
    addFade(1, 0, 0);
    printf("\n\t\t\t\t\t      b) --> %c        d) --> %c", alt[1], alt[3]);Sleep(tempo);
    printf("\n\n\t\t\t\t\t       +--------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t\t Insira sua opção: ");
    scanf(" %c", &opt);
    fflush(stdin);
    printf("\n\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    if (tolower(opt) == altResposta) {
        printf("\n\t\t\t\t   |                CERTA RESPOSTA!                | ");Sleep(tempo);
        printf("\n\t\t\t\t   |           VOCÊ GANHOU: +150 PONTOS!           | ");Sleep(tempo);
        acertoCont ++;
    } else {
        printf("\n\t\t\t\t   |     VOCÊ ERROU... RESPOSTA CORRETA: \"%c)\"      | ", altResposta);Sleep(tempo);
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
    getchar();
    fflush(stdin);
    Sleep(200);
    addFade(12, 0, 0);
    addFade(27, 25, 1);
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
int confirmarJogo(char nivel[9]) {
    //int tempo = 50;
    int finalopt = 0, erro = 0;
    char opt[100];
    system("cls");
    titulo(nivel, "Confirmar Dificuldade");
    do{
        if (erro == 0) addFade(4, 50, 0);
        else addFade(2, 50, 0);
        printf("\t\t\t\t\t      * DIFICULDADE SELECIONADA: *\n");Sleep(tempo);
        exibirBannerDificuldade(nivel);
        if (strcmp("FÁCIL", nivel) == 0) {
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | Vamos começar a jornada rumo à maestria no Braile? Nesta dificuldade, você dará |\n");Sleep(tempo);
            printf("\t\t  | os seus primeiros passos com o grupo das \"VOGAIS\". Pode parecer \"melzinho na    |\n");Sleep(tempo);
            printf("\t\t  | chupeta\", mas será fundamental para o seu processo de aprendizado. VAMOS LÁ?    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t\t  +-------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t\t  | GRUPO DO ALFABETO PROPOSTO: \"VOGAIS\" - 5 letras |\n");Sleep(tempo);
            printf("\t\t\t\t  +-------------------------------------------------+\n");Sleep(tempo);
        } else if (strcmp("MÉDIO I", nivel) == 0) {
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +--------------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                      DESCRIÇÃO                                       |\n");Sleep(tempo);
            printf("\t\t  +--------------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | Agora as coisas começam a ficar mais sérias! Nesta dificuldade, você terá o primeiro |\n");Sleep(tempo);
            printf("\t\t  | contato com as \"CONSOANTES\"! Mas para facilitar o aprendizado, dividiremos o grupo   |\n");Sleep(tempo);
            printf("\t\t  | em duas partes, sendo que a 2º parte estará lá no \"NÍVEL MÉDIO II\". VAMOS LÁ?        |\n");Sleep(tempo);
            printf("\t\t  +--------------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t| GRUPO DO ALFABETO PROPOSTO: 1º metade das \"CONSOANTES\" - 10 letras |\n");Sleep(tempo);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
        } else if (strcmp("MÉDIO II", nivel) == 0) {
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                    |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | Você está quase completando o alfabeto inteiro, continue assim! Dando continui- |\n");Sleep(tempo);
            printf("\t\t  | dade ao processo de aprendizagem, nesta dificuldade você verá a 2º parte das    |\n");Sleep(tempo);
            printf("\t\t  | \"CONSOANTES\", sendo que a 1º parte está lá no \"NÍVEL MÉDIO I\". VAMOS LÁ?        |\n");Sleep(tempo);
            printf("\t\t  +---------------------------------------------------------------------------------+\n");Sleep(tempo);
            addFade(1, 50, 1);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t\t| GRUPO DO ALFABETO PROPOSTO: 2º metade das \"CONSOANTES\" - 11 letras |\n");Sleep(tempo);
            printf("\t\t\t+--------------------------------------------------------------------+\n");Sleep(tempo);
        } else if (strcmp("DIFÍCIL", nivel) == 0) {
            if (erro == 0) addFade(3, 50, 1);
            else addFade(2, 50, 0);
            printf("\t\t  +----------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  |                                    DESCRIÇÃO                                     |\n");Sleep(tempo);
            printf("\t\t  +----------------------------------------------------------------------------------+\n");Sleep(tempo);
            printf("\t\t  | [RECOMENDA-SE JOGAR OS OUTROS MODOS ANTES DE JOGAR ESTE AQUI] O teste supremo! O |\n");Sleep(tempo);
            printf("\t\t  | \"Gran Finale\"! Coloque à prova todo o seu conhecimento adquirido até aqui para   |\n");Sleep(tempo);
            printf("\t\t  | provar se você realmente conquistou o domínio do Braile com maestria! VAMOS LÁ?  |\n");Sleep(tempo);
            printf("\t\t  +----------------------------------------------------------------------------------+\n");Sleep(tempo);
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
        if (finalopt == 0) {
            system("cls");
            erro ++;
            addFade(1, 50, 0);
            telaErro();
        } else if (finalopt == 2) {
            addFade(39, 25, 1);
            system("cls");
            return 0;
        }
    } while (finalopt != 1);
    system("cls");
    titulo(nivel, "Entrando no jogo, prepare-se!");
    addFade(4, 0, 0);
    printf("\t\t\t\t\t  +----------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t\t  | Boas vindas ao \"Jogo do Braile\"! |\n", nivel);Sleep(tempo);
    printf("\t\t\t\t\t  +----------------------------------+\n");Sleep(tempo);
    if (strcmp(nivel, "FÁCIL") == 0) {
        exibirBannerDificuldade("FÁCIL");
    } else if (strcmp(nivel, "MÉDIO I") == 0) {
        exibirBannerDificuldade("MÉDIO I");
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        exibirBannerDificuldade("MÉDIO II");
    } else if (strcmp(nivel, "DIFÍCIL") == 0) {
        exibirBannerDificuldade("DIFÍCIL");
    }
    addFade(1, tempo, 1);
    printf("\t\t\t\t   * Olá! É um prazer enorme ter você aqui jogando! *");Sleep(tempo);
    //int tempo = 50;
    //addFade(25, 0, 0);
    //addFade(5, 30, 1);
    //printf("-----------------------------------------------------------------------------------------------------------------------\n");
    addFade(2, 50, 1);
    printf("\t\t\t\t\t\t\t *****");Sleep(tempo);
    addFade(2, 50, 1);
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
    titulo(nivel, "Entrando no jogo, prepare-se!");
    return 1;
}

/* H) FIM DO JOGO (TABELA DE ESTATÍSTICAS) */
void fimJogo(char nivel[9], int pts, int acertos, int numPerg){

    /*Código do sistema de Ranking - Futuro*/

    titulo(nivel, "Resultado Final");
    addFade(6, 0, 0);
    printf("\t\t\t\t\t        * RESULTADO FINAL DO: *\n");Sleep(tempo);
    exibirBannerDificuldade(nivel);
    Sleep(1000);
    addFade(3, tempo, 1);
    printf("\t\t\t\t       +---------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t       |        QUE RUFEM OS TAMBORES!         |\n");Sleep(tempo);
    printf("\t\t\t\t       +---------------------------------------+\n");Sleep(tempo);
    Sleep(1000);
    printf("\t\t\t\t       |                                       |\n");Sleep(250);
    if (numPerg < 10) {
        printf("\t\t\t\t       |        Total de ACERTOS: %d / %d        |\n", acertos, numPerg);
    } else if (acertos < 10) {
        printf("\t\t\t\t       |       Total de ACERTOS: %d / %d        |\n", acertos, numPerg);
    } else {
        printf("\t\t\t\t       |       Total de ACERTOS: %d / %d       |\n", acertos, numPerg);
    }
    Sleep(500);
    printf("\t\t\t\t       |                                       |\n");Sleep(250);
    if(pts < 1000){
    printf("\t\t\t\t       |         Total de PONTOS: %d          |\n", pts);
    }else{
    printf("\t\t\t\t       |         Total de PONTOS: %d         |\n", pts);
    }
    Sleep(500);
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       +---------------------------------------+");Sleep(500);
    addFade(3, tempo, 1);

    if(((strcmp(nivel, "FÁCIL") == 0 && acertos <= 2) || (strcmp(nivel, "MÉDIO I") == 0 && acertos <= 3)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos <= 4) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos <= 8))){
        printf("\t\t\t+----------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t| Não se frustre! Errar faz parte, e é somente errando que se aprende! |\n");Sleep(tempo);
        printf("\t\t\t+----------------------------------------------------------------------+\n");Sleep(tempo);
    }

    else if(((strcmp(nivel, "FÁCIL") == 0 && acertos <= 3) || (strcmp(nivel, "MÉDIO I") == 0 && acertos <= 6)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos <= 7) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos <= 16))){
        printf("\t\t\t  +-----------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t  | Você está indo no caminho certo! Continue firme, você consegue! |\n");Sleep(tempo);
        printf("\t\t\t  +-----------------------------------------------------------------+\n");Sleep(tempo);
    }

    else if(((strcmp(nivel, "FÁCIL") == 0 && acertos <= 4) || (strcmp(nivel, "MÉDIO I") == 0 && acertos <= 9)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos <= 10) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos <= 25))){
        printf("\t\t\t   +---------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t   | Muito bem! A perseverança é a chave, então continue tentando! |\n");
        printf("\t\t\t   +---------------------------------------------------------------+\n");Sleep(tempo);
    }

    else if(((strcmp(nivel, "FÁCIL") == 0 && acertos == 5) || (strcmp(nivel, "MÉDIO I") == 0 && acertos == 10)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos == 11) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos == 26))){
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t | Meus parabéns, você acertou TODAS AS QUESTÕES! É assim que se faz! |\n");Sleep(tempo);
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
    } else {
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t | [ERRO] Dificuldade não condiz com o número de acertos.             |\n");Sleep(tempo);
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
    }

    Sleep(1000);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar **** ");
    getch();
    //addFade(12, 0, 0);
    //addFade(18, 30, 1);
    system("cls");
    titulo("-", "Obrigado por Jogar!");
    addFade(8, 0, 0);
    if (strcmp(nivel, "FÁCIL") == 0 && acertos == 5) {
        printf("\t\t  * ESSA FOI FÁCIL! MAS AGORA AS COISAS VÃO DIFICULTAR UM POUCO: EXPERIMENTE AGORA O: *\n");Sleep(1500);
        exibirBannerDificuldade("MÉDIO I");
        addFade(1, 1000, 1);
        printf("\t\t\t\t\t    * Selecione no menu principal! *");Sleep(1000);
    } else if (strcmp(nivel, "MÉDIO I") == 0 && acertos == 10) {
        printf("\t\t\t\t * SIGA ADIANTE! CONTINUE O SEU APRENDIZADO JOGANDO O: *\n");Sleep(2000);
        exibirBannerDificuldade("MÉDIO II");
        addFade(1, 1000, 1);
        printf("\t\t\t\t\t    * Selecione no menu principal! *");Sleep(1000);
    } else if (strcmp(nivel, "MÉDIO II") == 0 && acertos == 11) {
        printf("\t\t  * BOM TRABALHO, AGORA VÁ ADIANTE AO SEU ÚLTIMO DESAFIO! AO INIGUALÁVEL, AO TEMÍVEL: *\n");Sleep(2000);
        exibirBannerDificuldade("DIFÍCIL");
        addFade(1, 1000, 1);
        printf("\t\t\t\t\t    * Selecione no menu principal! *");Sleep(1000);
    } else if (strcmp(nivel, "DIFÍCIL") == 0 && acertos == 26) {
        printf("\t\t\t  * MEUS PARABÉNS! VOCÊ PROVOU COM MAESTRIA QUE É EXPERT NO BRAILE! *\n");Sleep(2000);
        exibirBannerDificuldade("AGRADECIMENTO");
    } else {
        printf("\t\t\t\t\t  * BOA TENTATIVA. TENTE NOVAMENTE! *\n");Sleep(1000);
        exibirBannerDificuldade("NÃO DESISTA");
        addFade(1, 1000, 1);
        printf("\t\t\t       \"A persistência é o caminho do êxito\". Continue tentando! ");Sleep(1500);
    }
    addFade(4, tempo, 1);
    printf("\t\t\t\t\t\t\t  ***");Sleep(tempo);
    addFade(3, tempo, 1);
    banner();
    addFade(1, tempo, 1);
    printf("\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    if (((strcmp(nivel, "FÁCIL") == 0 && acertos == 5) || (strcmp(nivel, "MÉDIO I") == 0 && acertos == 10)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos == 11) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos == 26))){
        addFade(9, 0, 0);
        addFade(30, 25, 1);
    } else {
        addFade(8, 0, 0);
        addFade(31, 25, 1);
    }
    system("cls");
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
    system("title Tela de título - Jogo do Braile 2.0");
    system("mode con:cols=119 lines=38");

    //Ignorar esta parte:
    /*printf("#######################################################################################################################\n");
    for (int i = 0; i < 36; i ++) {
        if (i == 16) {
            printf("#\t\t\t\t Ajuste a janela do console para uma melhor experiência \t\t\t      #\n");
        } else if (i == 17) {
            printf("#\t\t\t\t      Para isso, utilize as bordas como referência \t\t\t\t      #\n");
        } else if (i == 20) {
            printf("#\t\t\t\t* Feito isso, pressione qualquer tecla para continuar! *\t\t\t      #\n");
        } else {
            printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t      #\n");
        }
    }
    printf("#######################################################################################################################");
    getchar();
    system("cls");*/
}

/* N) [AINDA EM DESENVOLVIMENTO] ALTERNA ENTRE MODO "JANELA" E MODO "TELA CHEIA" */
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
    strcat(comando, " - Jogo do Braile 2.0");
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

/* R) RETORNA O BANNER CORRESPONDENTE À DIFICULDADE */
void exibirBannerDificuldade(char nivel[9]){
    if (strcmp(nivel, "FÁCIL") == 0) {
        printf("\t\t\t\t         _____ _         _    _____         _ _ \n");Sleep(tempo);
        printf("\t\t\t\t        |   | |_|_ _ ___| |  |   __|___ ___|_| |\n");Sleep(tempo);
        printf("\t\t\t\t        | | | | | | | -_| |  |   __| .'|  _| | |\n");Sleep(tempo);
        printf("\t\t\t\t        |_|___|_|\\_/|___|_|  |__|  |__,|___|_|_|\n");Sleep(tempo);
    } else if (strcmp(nivel, "MÉDIO I") == 0) {
        printf("\t\t\t\t    _____ _         _    _____       _ _        _____ \n");Sleep(tempo);
        printf("\t\t\t\t   |   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|\n");Sleep(tempo);
        printf("\t\t\t\t   | | | | | | | -_| |  | | | | -_| . | | . |   _| |_ \n");Sleep(tempo);
        printf("\t\t\t\t   |_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|\n");Sleep(tempo);
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        printf("\t\t\t        _____ _         _    _____       _ _        _____ _____ \n");Sleep(tempo);
        printf("\t\t\t       |   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|_   _|\n");Sleep(tempo);
        printf("\t\t\t       | | | | | | | -_| |  | | | | -_| . | | . |   _| |_ _| |_ \n");Sleep(tempo);
        printf("\t\t\t       |_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|_____|\n");Sleep(tempo);
    } else if (strcmp(nivel, "DIFÍCIL") == 0) {
        printf("\t\t\t\t       _____ _         _    ____  _ ___ _     _ _ \n");Sleep(tempo);
        printf("\t\t\t\t      |   | |_|_ _ ___| |  |    \\|_|  _|_|___|_| |\n");Sleep(tempo);
        printf("\t\t\t\t      | | | | | | | -_| |  |  |  | |  _| |  _| | |\n");Sleep(tempo);
        printf("\t\t\t\t      |_|___|_|\\_/|___|_|  |____/|_|_| |_|___|_|_|\n");Sleep(tempo);
    } else if (strcmp(nivel, "NÃO DESISTA") == 0) {
        printf("\t\t\t\t                                                 __   \n");Sleep(tempo);
        printf("\t\t\t\t    _____ /\\/        ____          _     _      |  |  \n");Sleep(tempo);
        printf("\t\t\t\t   |   | |___ ___   |    \\ ___ ___|_|___| |_ ___|  |  \n");Sleep(tempo);
        printf("\t\t\t\t   | | | | .'| . |  |  |  | -_|_ -| |_ -|  _| .'|__|  \n");Sleep(tempo);
        printf("\t\t\t\t   |_|___|__,|___|  |____/|___|___|_|___|_| |__,|__|  \n");Sleep(tempo);
    } else if (strcmp(nivel, "AGRADECIMENTO") == 0) {
        printf("\t\t                                                                               __ \n");Sleep(tempo);
        printf("\t\t       _____ _       _           _                          __                |  |\n");Sleep(tempo);
        printf("\t\t      |     | |_ ___|_|___ ___ _| |___    ___ ___ ___    __|  |___ ___ ___ ___|  |\n");Sleep(tempo);
        printf("\t\t      |  |  | . |  _| | . | .'| . | . |  | . | . |  _|  |  |  | . | . | .'|  _|__|\n");Sleep(tempo);
        printf("\t\t      |_____|___|_| |_|_  |__,|___|___|  |  _|___|_|    |_____|___|_  |__,|_| |__|\n");Sleep(tempo);
        printf("\t\t                      |___|              |_|                      |___|           ");Sleep(tempo);
    } else if (strcmp(nivel, "EXEMPLO") == 0) {
        printf("\t    _____                   _          _                         _____                     _       \n");Sleep(tempo);
        printf("\t   |   __|_ _ ___ _____ ___| |___    _| |___    _ _ _____ ___   |  _  |___ ___ ___ _ _ ___| |_ ___ \n");Sleep(tempo);
        printf("\t   |   __|_'_| -_|     | . | | . |  | . | -_|  | | |     | .'|  |   __| -_|  _| . | | |   |  _| .'|\n");Sleep(tempo);
        printf("\t   |_____|_,_|___|_|_|_|  _|_|___|  |___|___|  |___|_|_|_|__,|  |__|  |___|_| |_  |___|_|_|_| |__,|\n");Sleep(tempo);
        printf("\t                       |_|                                                    |___|                ");Sleep(tempo);
    }
}

/* S) GERA A SEQUÊNCIA DE EXIBIÇÃO DAS PERGUNTAS DE MANEIRA ALEATÓRIA */
void gerarSeqPerguntas(int *ordem, int numPerguntas){
    srand(time(NULL));
    int numOrdem = 0;
    int numGerado = 0;
    int i = 0;
    for (i = 0; i < numPerguntas; i ++) {
        ordem[i] = 0;
    }
    while (numOrdem <= numPerguntas - 1) {
        numGerado = rand() % (numPerguntas + 1);
        // O número gerado foi o 0? Se sim, descarta.
        if (numGerado == 0) {
            continue;
        }
        // Verifica se o vetor já contém tal número gerado. Se tiver, descarta. Se não tiver, armazena.
        for (i = 0; i < numPerguntas; i ++) {
            if (ordem[i] == numGerado) {
                break;
            }
        }
        if (i == numPerguntas) {
            ordem[numOrdem] = numGerado;
            numOrdem ++;
        }
    }
}

/* T) GERA UMA LETRA ALEATORIA PARA FORMAR AS OPÇÕES DAS ALTERNATIVAS, DE ACORDO COM A DIFICULDADE SELECIONADA */
char gerarLetra(int dificuldade){
    if (dificuldade == 1) {
        char letras[5] = {'a', 'e', 'i', 'o', 'u'};
        return letras[rand() % 5];
    } else if (dificuldade == 2 || dificuldade == 3) {
        char letras[21] = {'b', 'c', 'd', 'f', 'g',
            'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q',
            'r', 's' ,'t', 'v', 'w', 'x', 'y', 'z'};
        return letras[rand() % 21];
    } else if (dificuldade == 4) {
        char letras[26] = {'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's' ,'t', 'u',
            'v', 'w', 'x', 'y', 'z'};
        return letras[rand() % 26];
    }
    return ' ';
}

/* U) GERA A SEQUÊNCIA DE ALTERNATIVAS DAS PERGUNTAS DE MANEIRA ALEATÓRIA */
void gerarSeqAlt(int dificuldade, char *alt, char letrResp){
    int c = 0;
    char altGerada;
    int cont = 0;
    int controle = 0;
    int pos = 0;
    do {
        altGerada = toupper(gerarLetra(dificuldade));
        //printf("Caractere gerado: %c\n", altGerada);
        if (altGerada == letrResp) {
            //printf("Descartado! A letra gerada é igual a da resposta!\n");
            continue;
        }
        for (c = 0; c < 3; c ++) {
            if (alt[c] == toupper(altGerada)) {
                //printf("Descartado! A letra gerada já existe no vetor!\n");
                break;
            }
        }
        if (c == 3) {
            controle = 0;
            pos = 0;
            do{
                if (alt[pos] == ' ') {
                    alt[pos] = toupper(altGerada);
                    controle ++;
                } else {
                    pos ++;
                }
            }while(controle < 1);
            cont ++;
        }
    }while(cont < 3);
}

