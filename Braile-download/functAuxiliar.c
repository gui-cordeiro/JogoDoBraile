#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

/* A) TELA DO GITHUB */
void github(){
    int tempo = 50;
    printf("\n\t\t\t  **** O código-fonte deste jogo está disponível gratuitamente **** "); Sleep(tempo);
    printf("\n\t\t\t       no repositório do GitHub de Guilherme Cordeiro. Acesse:  \n\n"); Sleep(tempo);
    printf("\n\t\t\t                         @@@@@@@@@@@@@@@@@@@                        "); Sleep(tempo);
    printf("\n\t\t\t                     @@@@@@@@@@@@@@@@@@@@@@@@@@@                    "); Sleep(tempo);
    printf("\n\t\t\t                  @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@                 "); Sleep(tempo);
    printf("\n\t\t\t                @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@               "); Sleep(tempo);
    printf("\n\t\t\t              @@@@@@@@                         @@@@@@@@             "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@@                         @@@@@@@@@            "); Sleep(tempo);
    printf("\n\t\t\t            @@@@@@@@@                           @@@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t            @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t            @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t            @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t            @@@@@@@@@                           @@@@@@@@@           "); Sleep(tempo);
    printf("\n\t\t\t             @@@@@@@@@@                       @@@@@@@@@@            "); Sleep(tempo);
    printf("\n\t\t\t              @@@@   @@@@@@@@           @@@@@@@@@@@@@@@             "); Sleep(tempo);
    printf("\n\t\t\t               @@@@@   @@@@@@           @@@@@@@@@@@@@@              "); Sleep(tempo);
    printf("\n\t\t\t                 @@@@@                  @@@@@@@@@@@@                "); Sleep(tempo);
    printf("\n\t\t\t                    @@@@@@@@@           @@@@@@@@@                   "); Sleep(tempo);
    printf("\n\t\t\t                       @@@@@@           @@@@@@                  \n\n"); Sleep(tempo);
    printf("\n\t\t\t               +-------------------------------------+              "); Sleep(tempo);
    printf("\n\t\t\t               |   https://github.com/gui-cordeiro   |              "); Sleep(tempo);
    printf("\n\t\t\t               +-------------------------------------+            \n"); Sleep(tempo);
    return;
}

/* B) MODELO DAS PERGUNTAS */
int newPergunta(int questao, char a1, char a2, char a3, char a4, int altResp, char letrResp, int pts, int acertos){
    int tempo = 50;
    int acertoCont;
    int opt;
    printf(" +------------------+");Sleep(tempo);
    printf("\n | ACERTOS | PONTOS |", questao);Sleep(tempo);
    printf("\n +------------------+");Sleep(tempo);
    printf("\n |   ");
    if (acertos < 10) {
        printf("0");
    }
    printf("0%d   |  ", acertos);
    if (pts < 99) {
        printf("000");
    } else if (pts < 99) {
        printf("00");
    } else if (pts < 999) {
        printf("0");
    }
    printf("%d  |", pts);Sleep(tempo);
    printf("\n +------------------+");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                PERGUNTA Nº %d                 ", questao);Sleep(tempo);
    if (questao < 10) {
        printf(" |");
    } else {
        printf("|");
    }
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printAlfabeto(letrResp);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+\n");Sleep(tempo);
    printf("\n Qual é a letra correspondente?\n");Sleep(tempo);
    printf("\n 1) '%c'", a1);Sleep(tempo);
    printf("\n 2) '%c'", a2);Sleep(tempo);
    printf("\n 3) '%c'", a3);Sleep(tempo);
    printf("\n 4) '%c'", a4);Sleep(tempo);
    printf("\n\n Resposta nº: ");
    scanf("%d",&opt);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    if (opt == altResp) {
        printf("\n |                CERTA RESPOSTA!                | ");Sleep(tempo);
        printf("\n |           VOCÊ GANHOU: +150 PONTOS!           | ");Sleep(tempo);
        acertoCont = 1;
    } else {
        printf("\n |     VOCÊ ERROU... RESPOSTA CORRETA: \"%d)\"      | ", altResp);Sleep(tempo);
        printf("\n |           VOCÊ GANHOU: +50 PONTOS!            | ");Sleep(tempo);
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
    system("cls");
    //addFade(8, 0, 0);
    //addFade(22, 32, 1);
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
int confirmarJogo(char nivel[9]){
    int tempo = 50, finalopt = 0, erro = 0;
    char opt[100];
    char nome[40];
    system("cls");
    titulo(nivel, "Confirmar Dificuldade");
    do{
        if (erro == 0) {
            addFade(11, 50, 0);
        } else {
            addFade(4, 50, 1);
        }
        printf("\t\t\t\t      **** DIFICULDADE SELECIONADA: '%s' **** \n", nivel);Sleep(tempo);
        printf("\t\t    (Insira 'S' para \"Confirmar\" ou 'N' para \"Voltar ao Menu\", e pressione ENTER)");
        addFade(3, 50, 1);
        printf("\t\t\t\t\t\t     Opção: ");
        fgets(opt, 100, stdin);
        finalopt = verifyOpt(opt, 1);
        system("cls");
        if (finalopt == 0) {
            erro ++;
            addFade(3, 50, 0);
            telaErro();
        } else if (finalopt == 2) {
            return 0;
        }
    } while (finalopt != 1);
    return 1;
}

/* E) INICIO DO JOGO */
void boasVindas01(char nivel[9]){
    int tempo = 50;
    titulo(nivel, "Boas-vindas ao Jogo do Braile!");
    if (strcmp(nivel, "FÁCIL") == 0) {
        printf("\t\t\t      +-------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t      | Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s' |\n", nivel);Sleep(tempo);
        printf("\t\t\t      +-------------------------------------------------------+\n");Sleep(tempo);
    } else if (strcmp(nivel, "MÉDIO I") == 0 || strcmp(nivel, "DIFÍCIL") == 0) {
        printf(" +---------------------------------------------------------+\n");Sleep(tempo);
        printf(" | Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s' |\n", nivel);Sleep(tempo);
        printf(" +---------------------------------------------------------+\n");Sleep(tempo);
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        printf(" +----------------------------------------------------------+\n");Sleep(tempo);
        printf(" | Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s' |\n", nivel);Sleep(tempo);
        printf(" +----------------------------------------------------------+\n");Sleep(tempo);
    }
    addFade(2, 50, 1);
}

/* E) INICIO DO JOGO */
void boasVindas02(char nome[40]){
    int tempo = 50;
    //addFade(25, 0, 0);
    //addFade(5, 30, 1);
    //printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n -> Olá '%s'! É um prazer enorme ter você aqui jogando!", nome);
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



/* F) FIM DO JOGO (TABELA DE ESTATÍSTICAS) */
void fimJogo(int nivel, char frase[100], char nome[40], int pts, int acertos, int numPerg){
    int tempo = 50;
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
    if(((nivel == 1 && acertos <= 2) || (nivel == 2 && acertos <= 3)) || ((nivel == 3 && acertos <= 3) || (nivel == 4 && acertos <= 8))){
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
    Sleep(1500);
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

/* G) ANIMAÇÃO DE TRANSIÇÃO DE TELA */
void addFade(int rep, int millis, int isLento){
    for(int cont = 0; cont < rep; cont ++){
            printf("\n");
            if(isLento != 0) Sleep(millis);
    }
}

/* H) BANNER DE APRESENTAÇÃO */
void banner(){
    int tempo = 50;
    printf("\n\t\t\t\t     +-------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t     |        Jogo do Braile - 2017, %d        |", obterAnoAtual());Sleep(tempo);
    printf("\n\t\t\t\t     +-------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t     |      Criado por: Guilherme Cordeiro       |");Sleep(tempo);
    printf("\n\t\t\t\t     +-------------------------------------------+\n");Sleep(tempo);
    return;
}

/* I) TELA DE ERRO (AO DIGITAR UMA OPÇÃO ERRADA) */
void telaErro(){
    int tempo = 50;
    printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t      |                       * ATENÇÃO *                       |\n");Sleep(tempo);
    printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t      | Opção inválida. Siga as instruções especificadas abaixo |\n");Sleep(tempo);
    printf("\t\t\t      +---------------------------------------------------------+");Sleep(tempo);
}

/* J) RECUPERA O ANO ATUAL DO SISTEMA */
int obterAnoAtual(){
    int anoAtual = 0;
    time_t data_ano;
    time(&data_ano);
    struct tm *data = localtime(&data_ano);
    anoAtual = (data->tm_year+1900);
    return anoAtual;
}

/* K) CONFIGURAÇÕES INICIAIS DO JOGO  */
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

/* L) ALTERNAR ENTRE MODO "JANELA" E MODO "TELA CHEIA"  */
void fullScreen() {
    keybd_event(VK_MENU  , 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
}

/* M) RETORNA TÍTULO PERSONALIZADO  */
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

/* N) VERIFICA SE A OPÇÃO ESTÁ CORRETA (RETORNO 0=ERRO, 1=SIM, 2=NÃO)  */
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
