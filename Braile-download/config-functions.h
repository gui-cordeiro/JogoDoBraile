/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2022
 */

enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

enum {
    _BLACK=0,
    _BLUE=16,
    _GREEN=32,
    _CYAN=48,
    _RED=64,
    _MAGENTA=80,
    _BROWN=96,
    _LIGHTGRAY=112,
    _DARKGRAY=128,
    _LIGHTBLUE=144,
    _LIGHTGREEN=160,
    _LIGHTCYAN=176,
    _LIGHTRED=192,
    _LIGHTMAGENTA=208,
    _YELLOW=224,
    _WHITE=240
};

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
bool newPergunta(char dificuldade[8], int questao, char letrResp1, char letrResp2, char letrResp3, int *acertos, int *erros, int *pts, int progresso[26]){
    char altResposta;
    bool acertoCont = false;
    int tecla = 0;
    char opt;
    char lista[4][40];
    char alt[4] = {' ', ' ', ' ', ' '};
    int posCorreta = rand() % 4;
    int totAcertos = *acertos;
    int totErros = *erros;
    int totPts = *pts;
    alt[posCorreta] = letrResp2;
    if (posCorreta == 0) {
        altResposta = 'a';
    } else if (posCorreta == 1) {
        altResposta = 'b';
    } else if (posCorreta == 2) {
        altResposta = 'c';
    } else if (posCorreta == 3) {
        altResposta = 'd';
    }
    gerarSeqAlt(dificuldade, alt, letrResp2, letrResp1);
    sprintf(lista[0], " a) Letra %c ", alt[0]);
    sprintf(lista[1], " b) Letra %c ", alt[1]);
    sprintf(lista[2], " c) Letra %c ", alt[2]);
    sprintf(lista[3], " d) Letra %c ", alt[3]);

    cleanScreen(5);
    topBannerContent("-");
    exibirBannerPergunta(questao);

    setlocale(LC_ALL, "C");
    linhaCol(8,72);printf("%c", 197);
    for (int divisoria = 9; divisoria < 32; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(32,72);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese");

    exibirBannerPergunta(0);
    exibirBannerPergunta(27);

    textColor(BROWN, BLACK);
    box(17, 11, 27, 61);
    setlocale(LC_ALL, "C");
    linhaCol(17, 23); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Letra escrita em Braile");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto(letrResp2, 34, false);

    linhaCol(25, 33); printf("ATUAL");

    if (letrResp1 != '-') {
        setlocale(LC_ALL, "C");
        linhaCol(22, 28); printf("%c", 174);
        setlocale(LC_ALL, "Portuguese");
        textColor(DARKGRAY, _BLACK);

        printAlfabeto(letrResp1, 20, true);

        linhaCol(25, 18); printf("Anterior");
    }

    if (letrResp3 != '-') {
        textColor(BROWN, BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(22, 42); printf("%c", 175);
        setlocale(LC_ALL, "Portuguese");
        textColor(DARKGRAY, _BLACK);

        printAlfabeto(letrResp3, 48, false);

        linhaCol(25, 46); printf("Próximo");
    }
    textColor(WHITE, _BLACK);

    opt = modeloMenu(17, 88, 4, lista);

    if (opt - 1 == posCorreta) {
        acertoCont = true;
        totPts += 150;
        totAcertos ++;
        progresso[questao - 1] = 1;
    } else {
        totPts += 50;
        totErros ++;
        progresso[questao - 1] = 0;
    }

    currentProgressionBanner(dificuldade, progresso, totAcertos, totErros, totPts);

    *acertos = totAcertos;
    *erros = totErros;
    *pts = totPts;

    while(1) {
        tecla = getch();
        tecla = (tecla == 0 || tecla == 224) ? getch() : tecla;
        if (tecla == 13) break;
    }
    return acertoCont;
}

/* C) TELA DE APRESENTAÇÃO */
void apresentacao(){
    int tecla;
    system("cls");
    system("title Tela de título - Jogo do Braile 2.0");
    //PlaySound(TEXT("..\\sounds\\intro.wav"), NULL, SND_ASYNC);
    setlocale(LC_ALL, "C");
    linhaCol(12, 35); printf(" %c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Criado por Guilherme Cordeiro (2017, 2023)");
    setlocale(LC_ALL, "C");
    printf(" %c ", 254);
    setlocale(LC_ALL, "Portuguese");

    Sleep(800);
    box(15, 1, 23, 119);
    linhaCol(16, 2); printf("      ##  #######   ######    #######     ########   #######     ########  ########     ###    #### ##       ########");
    linhaCol(17, 2); printf("      ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##     ##   ## ##    ##  ##       ##      ");
    linhaCol(18, 2); printf("      ## ##     ## ##        ##     ##    ##     ## ##     ##    ##     ## ##     ##  ##   ##   ##  ##       ##      ");
    linhaCol(19, 2); printf("      ## ##     ## ##   #### ##     ##    ##     ## ##     ##    ########  ########  ##     ##  ##  ##       ######  ");
    linhaCol(20, 2); printf("##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##   ##   #########  ##  ##       ##      ");
    linhaCol(21, 2); printf("##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##    ##  ##     ##  ##  ##       ##      ");
    linhaCol(22, 2); printf(" ######   #######   ######    #######     ########   #######     ########  ##     ## ##     ## #### ######## ########");
    Sleep(900);
    setlocale(LC_ALL, "C");
    linhaCol(26, 39); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Pressione a tecla ENTER para iniciar");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    while(1) {
        tecla = getch();
        tecla = (tecla == 0 || tecla == 224) ? getch() : tecla;
        if (tecla == 13) break;
    }
    fflush(stdin);
    PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    for(int pulses = 0; pulses < 4; pulses ++) {
        textColor(BLACK, _WHITE);
        setlocale(LC_ALL, "C");
        linhaCol(26, 38); printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione a tecla ENTER para iniciar");
        setlocale(LC_ALL, "C");
        printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        Sleep(80);
        textColor(WHITE, _BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(26, 38); printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione a tecla ENTER para iniciar");
        setlocale(LC_ALL, "C");
        printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        Sleep(80);

    }
    system("cls");
    topBannerDesign();
    bottomBannerDesign();
    return;
}

/* D) ALFABETO EM BRAILE */
void printAlfabeto(char letra, int col, bool isVisible){
    //int tempo = 50;
    int lin1 = 21, lin2 = 22, lin3 = 23;
    box(20, col - 2, 24, col + 4);
    setlocale(LC_ALL, "C");
    switch(tolower(letra)){
        case 'a':
            linhaCol(lin1, col); printf("o %c", 250);
            linhaCol(lin2, col); printf("%c %c", 250, 250);
            linhaCol(lin3, col); printf("%c %c", 250, 250);
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
            linhaCol(lin1 - 2, col + 1); printf("E");
            linhaCol(lin1, col); printf("o %c", 250);
            linhaCol(lin2, col); printf("%c o", 250);
            linhaCol(lin3, col); printf("%c %c", 250, 250);
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
            linhaCol(lin1 - 2, col + 1); printf("I");
            linhaCol(lin1, col); printf("%c o", 250);
            linhaCol(lin2, col); printf("o %c", 250);
            linhaCol(lin3, col); printf("%c %c", 250, 250);
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
            linhaCol(lin1 - 2, col + 1); printf("O");
            linhaCol(lin1, col); printf("o %c", 250);
            linhaCol(lin2, col); printf("%c o", 250);
            linhaCol(lin3, col); printf("o %c", 250);
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
            linhaCol(lin1 - 2, col + 1); printf("U");
            linhaCol(lin1, col); printf("o %c", 250);
            linhaCol(lin2, col); printf("%c %c", 250, 250);
            linhaCol(lin3, col); printf("o o");
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
    setlocale(LC_ALL, "Portuguese");
    linhaCol(lin1 - 2, col + 1);
    if (isVisible == true) printf("%c", letra);
    else printf("?");
}

/* E) TELA DE CONFIRMAÇÃO DE DIFICULDADE */
int confirmarJogo(char nivel[9], int progresso[26]) {
    int opt;
    int acertos = 0, erros = 0, pontos = 0;
    char lista[2][40] = {"SIM, eu quero jogar!", "NÃO, eu quero voltar para o menu."};
    //PlaySound(TEXT("..\\sounds\\confirm-difficulty.wav"), NULL, SND_LOOP | SND_ASYNC);
    cleanScreen(1);
    titulo(nivel, "Confirmar Dificuldade");
    setlocale(LC_ALL, "C");
    linhaCol(8,72);printf("%c", 197);
    for (int divisoria = 9; divisoria < 32; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(32,72);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese");
    topBannerContent(nivel);
    exibirLetras(nivel);
    if (strcmp("FÁCIL", nivel) == 0) {
        box(11, 11, 13, 61);

        linhaCol(12, 13); printf("GRUPO DO ALFABETO PROPOSTO: \"VOGAIS\" - 5 letras");

        linhaCol(35, 5); printf("Vamos começar a jornada rumo à maestria no Braile? Nesta dificuldade, você dará os seus primeiros passos com o");
        linhaCol(36, 4);printf("grupo das \"VOGAIS\". Pode parecer \"melzinho na chupeta\", mas será fundamental para o seu processo de aprendizado.");
    } else if (strcmp("MÉDIO I", nivel) == 0) {
        box(11, 2, 13, 70);

        linhaCol(12, 4); printf("GRUPO PROPOSTO DO ALFABETO: 1º metade de \"CONSOANTES\" - 10 letras");

        linhaCol(35, 6); printf("Agora as coisas começam a ficar mais sérias! Aqui você terá o primeiro contato com as \"CONSOANTES\", mas para");
        linhaCol(36, 4); printf("facilitar o aprendizado, dividiremos o grupo em duas partes, sendo que a 2º parte estará lá no \"NÍVEL MÉDIO II\".");
    } else if (strcmp("MÉDIO II", nivel) == 0) {
        box(11, 2, 13, 70);

        linhaCol(12, 4); printf("GRUPO DO ALFABETO PROPOSTO: 2º metade de \"CONSOANTES\" - 11 letras");

        linhaCol(35, 5); printf("Você está quase completando o alfabeto inteiro, continue assim! Dando continuidade ao processo de aprendizagem,");
        linhaCol(36, 8); printf("nesta dificuldade você verá a 2º parte das \"CONSOANTES\", sendo que a 1º parte está lá no \"NÍVEL MÉDIO I\".");
    } else if (strcmp("DIFÍCIL", nivel) == 0) {
        box(11, 5, 13, 67);

        linhaCol(12, 7); printf("GRUPO DO ALFABETO PROPOSTO: \"ALFABETO COMPLETO\" - 26 letras");

        linhaCol(33, 30); printf("[RECOMENDA-SE JOGAR OS OUTROS MODOS ANTES DE JOGAR ESTE AQUI]");
        linhaCol(35, 5); printf("O teste supremo! O \"Gran Finale\"! Coloque à prova todo o conhecimento adquirido até aqui para provar de uma vez");
        linhaCol(36, 7); printf("por todas se você realmente adquiriu o domínio do Braile com maestria. Ah, não vamos pegar leve dessa vez!");
    }

    linhaCol(13, 77); printf("                                 _____ ");
    linhaCol(14, 77); printf(" _____         ___ _            |___  |");
    linhaCol(15, 77); printf("|     |___ ___|  _|_|___ _____ ___|  _|");
    linhaCol(16, 77); printf("|   --| . |   |  _| |  _|     | .'|_|  ");
    linhaCol(17, 77); printf("|_____|___|_|_|_| |_|_| |_|_|_|__,|_|  ");

    opt = modeloMenu(20, 78, 2, lista);
    if (opt == 2) {
        cleanScreen(1);
        return 0;
    }

    cleanScreen(4);
    topBannerContent(nivel);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    bottomBannerTitle(1);
    setlocale(LC_ALL, "C");
    linhaCol(13, 21); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Boas vindas ao \"Jogo do Braile\"! Pressione Enter para iniciar o jogo agora.");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    box(16, 14, 24, 106);
    linhaCol(17, 16);printf("########  #### ##     ## #### ########  ########    ###             ######  ######## ####");
    linhaCol(18, 16);printf("##     ##  ##  ##     ##  ##  ##     ##    ##      ## ##           ##    ## ##       ####");
    linhaCol(19, 16);printf("##     ##  ##  ##     ##  ##  ##     ##    ##     ##   ##          ##       ##       ####");
    linhaCol(20, 16);printf("##     ##  ##  ##     ##  ##  ########     ##    ##     ## #######  ######  ######    ## ");
    linhaCol(21, 16);printf("##     ##  ##   ##   ##   ##  ##   ##      ##    #########               ## ##           ");
    linhaCol(22, 16);printf("##     ##  ##    ## ##    ##  ##    ##     ##    ##     ##         ##    ## ##       ####");
    linhaCol(23, 16);printf("########  ####    ###    #### ##     ##    ##    ##     ##          ######  ######## ####");

    setlocale(LC_ALL, "C");
    linhaCol(27, 15); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("DICA: Acompanhe o seu progresso de acertos e erros através da barra situada logo abaixo");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    currentProgressionBanner(nivel, progresso, acertos, erros, pontos);
    getchar();
    //PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    cleanScreen(6);
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
    int largura = 89;
    int altura = 8;
    hideCursor();
    setlocale(LC_ALL,"Portuguese");
    system("mode con:cols=119 lines=38");
    //fullScreen();

    int x,y;

    HWND cW = GetConsoleWindow();

    x = GetSystemMetrics(SM_CXSCREEN);   // quantidade de pixel por linhas da tela
    y = GetSystemMetrics(SM_CYSCREEN);   // quantidade de pixel por coluna da tela
	SetWindowPos( cW, 0, x/8, y/15, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
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
void exibirBannerPergunta(int questao){
    setlocale(LC_ALL, "C");
    linhaCol(2, 28); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" VOCÊ ESTÁ NA ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    switch (questao) {
        case 0:
            linhaCol(11, 77); printf(" _____                     _        _ ");
            linhaCol(12, 77); printf("| __  |___ ___ ___ ___ ___| |_ ___ |_|");
            linhaCol(13, 77); printf("|    -| -_|_ -| . | . |_ -|  _| .'| _ ");
            linhaCol(14, 77); printf("|__|__|___|___|  _|___|___|_| |__,||_|");
            linhaCol(15, 77); printf("              |_|                     ");
        break;
        case 27:
            linhaCol(10, 4); printf("                                         __                 _____ ");
            linhaCol(11, 4); printf(" _____            _     _               /_/                |___  |");
            linhaCol(12, 4); printf("|     |_ _ ___   | |___| |_ ___ ___    ___    ___ ___ ___ ___|  _|");
            linhaCol(13, 4); printf("|  |  | | | -_|  | | -_|  _|  _| .'|  | -_|  | -_|_ -|_ -| .'|_|  ");
            linhaCol(14, 4); printf("|__  _|___|___|  |_|___|_| |_| |__,|  |___|  |___|___|___|__,|_|  ");
            linhaCol(15, 4); printf("   |__|                                                           ");
        break;
        case 1:
            linhaCol(3, 6); printf(" _____                     _                       ___ ___   ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |  ");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_| |_ ");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|_____|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 2:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |  _|");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 3:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 4:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | | |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___| |_|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 5:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |  _|");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 6:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |  _|");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | | . |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 7:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   |_  |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | | | |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___| |_|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 8:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | . |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | | . |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 9:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |   | . |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   | | |_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 10:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |   |");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| | |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 11:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___   ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |_  |  ");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_ _| |_ ");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|_____|");
            linhaCol(7, 6); printf("              |___|                                            ");
            break;
        case 12:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |_  |");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|  _|");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 13:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |_  |");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 14:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | | |");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____| |_|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 15:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |  _|");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 16:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | |  _|");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| . |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 17:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|_|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 18:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | . |");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_| . |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 19:
            linhaCol(3, 6); printf(" _____                     _                       ___   ___ ");
            linhaCol(4, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | . |");
            linhaCol(5, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_    _| |_|_  |");
            linhaCol(6, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |_____|___|");
            linhaCol(7, 6); printf("              |___|                                          ");
            break;
        case 20:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |   |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _| | |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 21:
            linhaCol(3, 6); printf(" _____                     _                       ___ ___   ");
            linhaCol(3, 6); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |  ");
            linhaCol(3, 6); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_| |_ ");
            linhaCol(3, 6); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|_____|");
            linhaCol(3, 6); printf("              |___|                                          ");
            break;
        case 22:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|  _|");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 23:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |_  |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 24:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  | | |");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___  |_|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 25:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |  _|");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _|_  |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
        case 26:
            linhaCol(3, 7); printf(" _____                     _                       ___ ___ ");
            linhaCol(4, 7); printf("|  _  |___ ___ ___ _ _ ___| |_ ___    ___ ___     |_  |  _|");
            linhaCol(5, 7); printf("|   __| -_|  _| . | | |   |  _| .'|  |   | . |_   |  _| . |");
            linhaCol(6, 7); printf("|__|  |___|_| |_  |___|_|_|_| |__,|  |_|_|___|_|  |___|___|");
            linhaCol(7, 7); printf("              |___|                                        ");
            break;
    }
}

/* R) RETORNA O BANNER CORRESPONDENTE À DIFICULDADE */
void exibirBannerDificuldade(char nivel[20]){
    if (strcmp(nivel, "MENU") == 0) {
        setlocale(LC_ALL, "C");
        linhaCol(2, 28); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" VOCÊ ESTÁ NO ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(3, 9); printf(" _____                 _____     _         _         _ ");
        linhaCol(4, 9); printf("|     |___ ___ _ _    |  _  |___|_|___ ___|_|___ ___| |");
        linhaCol(5, 9); printf("| | | | -_|   | | |   |   __|  _| |   |  _| | . | .'| |");
        linhaCol(6, 9); printf("|_|_|_|___|_|_|___|   |__|  |_| |_|_|_|___|_|  _|__,|_|");
        linhaCol(7, 9); printf("                                            |_|        ");
    } else if (strcmp(nivel, "FÁCIL") == 0) {
        setlocale(LC_ALL, "C");
        linhaCol(2, 24); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" DIFICULDADE SELECIONADA ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(3, 17); printf(" _____ _         _    _____         _ _ ");
        linhaCol(4, 17); printf("|   | |_|_ _ ___| |  |   __|___ ___|_| |");
        linhaCol(5, 17); printf("| | | | | | | -_| |  |   __| .'|  _| | |");
        linhaCol(6, 17); printf("|_|___|_|\\_/|___|_|  |__|  |__,|___|_|_|");
    } else if (strcmp(nivel, "MÉDIO I") == 0) {
        setlocale(LC_ALL, "C");
        linhaCol(2, 24); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" DIFICULDADE SELECIONADA ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(3, 11); printf(" _____ _         _    _____       _ _        _____ ");
        linhaCol(4, 11); printf("|   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|");
        linhaCol(5, 11); printf("| | | | | | | -_| |  | | | | -_| . | | . |   _| |_ ");
        linhaCol(6, 11); printf("|_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|");
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        setlocale(LC_ALL, "C");
        linhaCol(2, 24); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" DIFICULDADE SELECIONADA ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(3, 8); printf(" _____ _         _    _____       _ _        _____ _____ ");
        linhaCol(4, 8); printf("|   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|_   _|");
        linhaCol(5, 8); printf("| | | | | | | -_| |  | | | | -_| . | | . |   _| |_ _| |_ ");
        linhaCol(6, 8); printf("|_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|_____|");
    } else if (strcmp(nivel, "DIFÍCIL") == 0) {
        setlocale(LC_ALL, "C");
        linhaCol(2, 24); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" DIFICULDADE SELECIONADA ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(3, 15); printf(" _____ _         _    ____  _ ___ _     _ _ ");
        linhaCol(4, 15); printf("|   | |_|_ _ ___| |  |    \\|_|  _|_|___|_| |");
        linhaCol(5, 15); printf("| | | | | | | -_| |  |  |  | |  _| |  _| | |");
        linhaCol(6, 15); printf("|_|___|_|\\_/|___|_|  |____/|_|_| |_|___|_|_|");
    } else if (strcmp(nivel, "NÃO DESISTA") == 0) {
        linhaCol(3, 9); printf("                                              __   ");
        linhaCol(4, 9); printf(" _____ /\\/        ____          _     _      |  |  ");
        linhaCol(5, 9); printf("|   | |___ ___   |    \\ ___ ___|_|___| |_ ___|  |  ");
        linhaCol(6, 9); printf("| | | | .'| . |  |  |  | -_|_ -| |_ -|  _| .'|__|  ");
        linhaCol(7, 9); printf("|_|___|__,|___|  |____/|___|___|_|___|_| |__,|__|  ");
    } else if (strcmp(nivel, "AGRADECIMENTO") == 0) {
        linhaCol(3, 9); printf("                                                                         __ ");
        linhaCol(4, 9); printf(" _____ _       _           _                          __                |  |");
        linhaCol(5, 9); printf("|     | |_ ___|_|___ ___ _| |___    ___ ___ ___    __|  |___ ___ ___ ___|  |");
        linhaCol(6, 9); printf("|  |  | . |  _| | . | .'| . | . |  | . | . |  _|  |  |  | . | . | .'|  _|__|");
        linhaCol(7, 9); printf("|_____|___|_| |_|_  |__,|___|___|  |  _|___|_|    |_____|___|_  |__,|_| |__|");
        linhaCol(8, 9); printf("                |___|              |_|                      |___|           ");
    } else if (strcmp(nivel, "EXEMPLO") == 0) {
        linhaCol(3, 9); printf(" _____                   _          _                         _____                     _       ");
        linhaCol(4, 9); printf("|   __|_ _ ___ _____ ___| |___    _| |___    _ _ _____ ___   |  _  |___ ___ ___ _ _ ___| |_ ___ ");
        linhaCol(5, 9); printf("|   __|_'_| -_|     | . | | . |  | . | -_|  | | |     | .'|  |   __| -_|  _| . | | |   |  _| .'|");
        linhaCol(6, 9); printf("|_____|_,_|___|_|_|_|  _|_|___|  |___|___|  |___|_|_|_|__,|  |__|  |___|_| |_  |___|_|_|_| |__,|");
        linhaCol(7, 9); printf("                    |_|                                                    |___|                ");
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
char gerarLetra(char dificuldade[8]){
    if (dificuldade == "FÁCIL") {
        char letras[5] = {'a', 'e', 'i', 'o', 'u'};
        return letras[rand() % 5];
    } else if (dificuldade == "MÉDIO I") {
        char letras[10] = {'b', 'c', 'd', 'f', 'g',
            'h', 'j', 'k', 'l', 'm'};
        return letras[rand() % 10];
    } else if (dificuldade == "MÉDIO II") {
        char letras[11] = {'n', 'p', 'q', 'r', 's',
            't', 'v', 'w', 'x', 'y', 'z'};
        return letras[rand() % 11];
    } else if (dificuldade == "DIFÍCIL") {
        char letras[26] = {'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's' ,'t', 'u',
            'v', 'w', 'x', 'y', 'z'};
        return letras[rand() % 26];
    }
    return ' ';
}

/* U) GERA A SEQUÊNCIA DE ALTERNATIVAS DAS PERGUNTAS DE MANEIRA ALEATÓRIA */
void gerarSeqAlt(char dificuldade[8], char *alt, char letrResp1, char letrResp2){
    int c = 0;
    char altGerada;
    int cont = 0;
    int controle = 0;
    int pos = 0;
    do {
        altGerada = toupper(gerarLetra(dificuldade));
        //printf("Caractere gerado: %c\n", altGerada);
        if (altGerada == letrResp1 || altGerada == letrResp2) {
            //printf("Descartado! A letra gerada é igual a da resposta ou foi selecionada na pergunta anterior!\n");
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

void hideCursor() {
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void showCursor() {
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void linhaCol(int lin, int col) {
    int colFS = 0, linFS = 0; //16 e 1
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){(colFS + col) - 1, (linFS + lin) - 1});
    //Escondendo cursor
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void textColor(int letras, int fundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + fundo);
}

void box(int lin1, int col1, int lin2, int col2) {
    int contColuna, contLinha, tamlin, tamcol;

    setlocale(LC_ALL, "C");
    //Tamanho total da caixa
    tamlin = lin2 - lin1;
    tamcol = col2 - col1;

    //Desenhando as linhas de cima e de baixo da caixa
    for (contColuna = col1; contColuna <= col2; contColuna ++) {
        linhaCol(lin1, contColuna);
        printf("%c", 196);
        linhaCol(lin2, contColuna);
        printf("%c", 196);
    }

    //Desenhando as colunas da esquerda e da direita da caixa
    for (contLinha = lin1; contLinha <= lin2; contLinha ++) {
        linhaCol(contLinha, col1);
        printf("%c", 179);
        linhaCol(contLinha, col2);
        printf("%c", 179);
    }

    //Preenchendo o fundo da caixa
    for (contLinha = lin1 + 1; contLinha < lin2; contLinha ++) {
        for (contColuna = col1 + 1; contColuna < col2; contColuna ++) {
            linhaCol(contLinha, contColuna);
            printf(" ");
        }
    }

    //Definindo os vértices da caixa
    linhaCol(lin1, col1);
    printf("%c", 218);
    linhaCol(lin1, col2);
    printf("%c", 191);
    linhaCol(lin2, col1);
    printf("%c", 192);
    linhaCol(lin2, col2);
    printf("%c", 217);

    setlocale(LC_ALL, "Portuguese");
}

void topBannerDesign() {

    box(1, 1, 8, 119);
    setlocale(LC_ALL, "C");
    linhaCol(1,72);printf("%c", 194);
    for (int divisoria = 2; divisoria < 9; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(8,72);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese");
}

void topBannerContent(char titulo[20]) {
    exibirBannerDificuldade(titulo);

    setlocale(LC_ALL, "C");
    linhaCol(2, 80); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" AÇÕES DISPONÍVEIS NESTA TELA ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);

    int refer = 75;

    box(3, refer + 4, 5, refer + 8);
    box(5, refer + 4, 7, refer + 8);
    box(5, refer, 7, refer + 4); //Seta pra esquerda
    box(5, refer + 8, 7, refer + 12);

    //Junções
    setlocale(LC_ALL, "C");
    linhaCol(5, refer + 4);printf("%c", 197);
    linhaCol(5, refer + 8);printf("%c", 197);
    linhaCol(7, refer + 4);printf("%c", 193);
    linhaCol(7, refer + 8);printf("%c", 193);

    linhaCol(4, refer + 6);printf("%c", 30);  //Cima
    linhaCol(6, refer + 6);printf("%c", 31);  //Baixo
    linhaCol(6, refer + 2);printf("%c", 17);  //Esquerda
    linhaCol(6, refer + 10);printf("%c", 16); //Direita
    setlocale(LC_ALL, "Portuguese");

    linhaCol(6, refer + 13);printf(" ou ");

    box(3, refer + 21, 5, refer + 25);
    box(5, refer + 21, 7, refer + 25);
    box(5, refer + 17, 7, refer + 21); //Seta pra esquerda
    box(5, refer + 25, 7, refer + 29);

    setlocale(LC_ALL, "C");
    linhaCol(5, refer + 21);printf("%c", 197);
    linhaCol(5, refer + 25);printf("%c", 197);
    linhaCol(7, refer + 21);printf("%c", 193);
    linhaCol(7, refer + 25);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese");

    linhaCol(4, refer + 23);printf("W");  //Cima
    linhaCol(6, refer + 23);printf("S");  //Baixo
    linhaCol(6, refer + 19);printf("A");  //Esquerda
    linhaCol(6, refer + 27);printf("D"); //Direita

    linhaCol(6, refer + 30);printf("  e  ");


    box(3, refer + 35, 7, refer + 41);
    setlocale(LC_ALL, "C");
    linhaCol(5, refer + 35); printf("%c", 191);
    linhaCol(5, refer + 34); printf("%c", 196);
    linhaCol(5, refer + 33); printf("%c", 192);
    linhaCol(4, refer + 33); printf("%c", 179);
    linhaCol(3, refer + 33); printf("%c", 218);
    linhaCol(3, refer + 34); printf("%c%c", 196, 196);
    linhaCol(4, refer + 34); printf(" ");
    linhaCol(4, refer + 35); printf("Enter");
    setlocale(LC_ALL, "Portuguese");
}

void bottomBannerDesign() {
    box(32, 1, 38, 119);
    bottomBannerTitle(0);
}

void bottomBannerTitle(int opt) {
    linhaCol(33, 2);
    if (opt == 0) {
        printf(" Descrição:           ");
    } else {
        printf(" Seu progresso atual:");
    }
}

void bottomBannerContent(int opt) {
    for (int descLinha = 34; descLinha <= 36; descLinha ++) {
        linhaCol(descLinha, 2);
        for (int limpar = 2; limpar < 117; limpar ++) {
            printf(" ");
        }
    }
    switch(opt) {
        case 1:
            linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade \"Fácil\".");
            break;
        case 2:
            linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade \"Médio I\".");
            break;
        case 3:
            linhaCol(35, 36); printf("Jogue o Jogo do Braile na dificuldade \"Médio II\".");
            break;
        case 4:
            linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade \"Difícil\".");
            break;
        case 5:
            linhaCol(35, 31); printf("Consulte a pontuação de todos os jogadores salvos no seu PC.");
            break;
        case 6:
            linhaCol(35, 40); printf("Consulte as instruções do Jogo do Braile");
            linhaCol(36, 37); printf("(e veja também um passo-a-passo de como jogar).");
            break;
        case 7:
            linhaCol(35, 32); printf("Acesse os créditos do projeto \"Jogo do Braile\". Você verá:");
            linhaCol(36, 8); printf("1) O motivo inicial do projeto; 2) As pessoas envolvidas na época; e 3) Contato do desenvolvedor do jogo.");
            break;
        case 8:
            linhaCol(35, 38); printf("Feche o Jogo do Braile. Obrigado por jogar!");
            break;
    }
}

void cleanScreen(int opt) { // 1) Tudo; 2) Superior + Meio; 3) Superior + Inferior; 4) Meio + Inferior; 5) Superior; 6) Meio; 7) Inferior
    int linha, coluna;

    //Banner Superior
    if ((opt == 1 || opt == 2) || (opt == 3 || opt == 5)) {
        for (linha = 2; linha < 8; linha ++) {
            for (coluna = 2; coluna < 119; coluna ++) {
                if (coluna != 72) { // Divisória do Banner
                    linhaCol(linha, coluna); printf(" ");
                }
            }
        }
    }

    //Conteúdo do Meio
    if ((opt == 1 || opt == 2) || (opt == 4 || opt == 6)) {
        setlocale(LC_ALL, "C");
        linhaCol(8,72);printf("%c", 193);

        for (linha = 9; linha < 32; linha ++) {
            for (coluna = 1; coluna <= 119; coluna ++) {
                linhaCol(linha, coluna); printf(" ");
            }
        }

        linhaCol(32,72);printf("%c", 196);
        setlocale(LC_ALL, "Portuguese");
    }

    //Banner Inferior (Rodapé)
    if ((opt == 1 || opt == 3) || (opt == 4 || opt == 7)) {
        for (linha = 33; linha < 37; linha ++) {
            for (coluna = 2; coluna < 119; coluna ++) {
                if (linha == 33 && coluna < 23) { // Título do Banner
                    continue;
                } else {
                    linhaCol(linha, coluna); printf(" ");
                }
            }
        }
    }
}

void exibirLetras(char nivel[9]) {
    int contLetras = 0;
    char letras[] = {'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's' ,'t', 'u',
            'v', 'w', 'x', 'y', 'z'};

    for (int linha = 16; linha < 26; linha += 5) {
        for (int coluna = 2; coluna < 70; coluna += 8) {
            if (strcmp(nivel, "FÁCIL") == 0) {
                switch(contLetras) {
                    case 0:
                    case 4:
                    case 8:
                    case 14:
                        textColor(BLACK, _WHITE);
                        break;
                    default:
                        textColor(WHITE, _BLACK);
                }
            } else if (strcmp(nivel, "MÉDIO I") == 0) {
                switch(contLetras) {
                    case 1:
                    case 2:
                    case 3:
                    case 5:
                    case 6:
                    case 7:
                    case 9:
                    case 10:
                    case 11:
                    case 12:
                        textColor(BLACK, _WHITE);
                        break;
                    default:
                        textColor(WHITE, _BLACK);
                }
            } else if (strcmp(nivel, "MÉDIO II") == 0) {
                switch(contLetras) {
                    case 13:
                    case 15:
                    case 16:
                    case 17:
                        textColor(BLACK, _WHITE);
                        break;
                    default:
                        textColor(WHITE, _BLACK);
                }
            } else if (strcmp(nivel, "DIFÍCIL") == 0) {
                textColor(BLACK, _WHITE);
            }
            box(linha, coluna, linha + 2, coluna + 4);
            linhaCol(linha + 1, coluna + 2); printf("%c", toupper(letras[contLetras]));
            contLetras ++;
        }
    }
    for (int coluna = 6; coluna < 65; coluna += 8) {
        if (strcmp(nivel, "FÁCIL") == 0) {
            switch(contLetras) {
                case 20:
                    textColor(BLACK, _WHITE);
                    break;
                default:
                    textColor(WHITE, _BLACK);
            }
        } else if (strcmp(nivel, "MÉDIO II") == 0) {
            switch(contLetras) {
                case 18:
                case 19:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                    textColor(BLACK, _WHITE);
                    break;
                default:
                    textColor(WHITE, _BLACK);
            }
        } else if (strcmp(nivel, "DIFÍCIL") == 0) {
                textColor(BLACK, _WHITE);
        }
        box(26, coluna, 26 + 2, coluna + 4);
        linhaCol(27, coluna + 2); printf("%c", toupper(letras[contLetras]));
        contLetras ++;
    }
    textColor(WHITE, _BLACK);
}

int modeloMenu(int lin1, int col1, int qtd, char lista[][40]) {
    int opt = 1, lin2, col2, linhaSelecionada, i, tamMaxItem, tecla, limpar, espacamento;

    //Calculando as coordenadas
    tamMaxItem = strlen(lista[0]);

    //Tamanho máximo dos itens
    for(i = 1; i < qtd; i ++) {
        tamMaxItem = (strlen(lista[i]) > tamMaxItem) ? strlen(lista[i]) : tamMaxItem;
    }

    lin2 = lin1 + (qtd * 2 + 2);
    col2 = col1 + tamMaxItem + 3;

    //Montando a tela do menu
    textColor(WHITE, _BLUE);

    box(lin1, col1, lin2, col2);


    //Laço das opções
    while(1){
        linhaSelecionada = lin1 + 2;
        for(i = 0; i < qtd; i ++) {
            if((i + 1) == opt) {
                textColor(BLUE, _WHITE);
                //PlaySound(TEXT("..\\sounds\\select.wav"), NULL, SND_ASYNC);
            } else {
                textColor(WHITE, _BLUE);
            }
            espacamento = (tamMaxItem - strlen(lista[i])) / 2; //Criar espaçamento para centralizar opções no menu
            linhaCol(linhaSelecionada, col1 + 2 + espacamento);
            printf("%s", lista[i]);
            linhaSelecionada += 2;
        }

        textColor(WHITE, _BLACK);

        //Aguarda teclas
        linhaCol(1,1);
        tecla = getch();
        if (tecla == 0 || tecla == 224) tecla = getch();
        if (tecla == 72 || (tecla == 119) || (tecla == 87)) { //Seta pra cima
            if(opt == 1) opt = qtd;
            else if (opt > 1) opt --;
        } else if (tecla == 80 || (tecla == 115) || (tecla == 83)) { //Seta pra baixo
            if (opt == qtd) opt = 1;
            else if (opt < qtd) opt ++;
        } else if (tecla == 13) { //ENTER
            break;
        } else if (tecla == 27) { //ESC
            opt = 2;
            break;
        }
    }
    //PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    textColor(WHITE, _BLACK);
    return opt;
}

void currentProgressionBanner(char difficulty[8], int currentProgression[26], int acertos, int erros, int pontos) {
    int cont, numColuna, numPerg, numBar, colAtual;
    setlocale(LC_ALL, "C");
    if (strcmp(difficulty, "FÁCIL") == 0) {
        numPerg = 5;
        numBar = 16;
        numColuna = 28;
    } else if (strcmp(difficulty, "MÉDIO I") == 0) {
        numPerg = 10;
        numBar = 8;
        numColuna = 24;
    } else if (strcmp(difficulty, "MÉDIO II") == 0) {
        numPerg = 11;
        numBar = 8;
        numColuna = 20;
    } else if (strcmp(difficulty, "DIFÍCIL") == 0) {
        numPerg = 26;
        numColuna = 10;
    }

    for (cont = 0; cont < numPerg; cont ++) {
        if (strcmp(difficulty, "DIFÍCIL") == 0) {
            colAtual = numColuna + (4 * cont);
        } else {
            colAtual = numColuna + ((numBar) * cont);
        }

        linhaCol(33, colAtual);

        if (currentProgression[cont] == 0) {
            textColor(RED, _BLACK);
            printf("X");
        } else if (currentProgression[cont] == 1) {
            textColor(GREEN, _BLACK);
            printf("%c", 2);
        } else {
            textColor(WHITE, _BLACK);
            printf("%c", 4);
        }

        if (strcmp(difficulty, "DIFÍCIL") == 0) {
            if (cont == 0) {
                linhaCol(34, colAtual);
            } else {
                linhaCol(34, colAtual - 1);
            }
        } else {
            if (cont == 0) {
                linhaCol(34, colAtual);
            } else {
                linhaCol(34, colAtual - (numBar/2));
            }
        }


        if (cont != 0) {
            if (strcmp(difficulty, "DIFÍCIL") == 0) {
                printf("%c", 205);
            } else {
                for (int barras = 0; barras < numBar / 2; barras ++) {
                    printf("%c", 205);
                }
            }
        }

        printf("%c", 254);

        if (cont != numPerg - 1) {
            if (strcmp(difficulty, "DIFÍCIL") == 0) {
                printf("%c", 205);
                printf("%c", 205);
            } else {
                for (int barras = 0; barras < numBar / 2; barras ++) {
                    printf("%c", 205);
                }
            }
        }
    }
    textColor(WHITE, _BLACK);
    box(36, 39, 38, 80);

    linhaCol(37, 40); printf(" ACERTOS: 0%d | ERROS: 0%d | PONTOS: 000%d", acertos, erros, pontos);

    setlocale(LC_ALL, "C");
    linhaCol(38, 39); printf("%c", 193);
    linhaCol(38, 53); printf("%c", 193);
    linhaCol(38, 65); printf("%c", 193);
    linhaCol(38, 80); printf("%c", 193);

    linhaCol(36, 53); printf("%c", 194);
    linhaCol(36, 65); printf("%c", 194);

    linhaCol(37, 53); printf("%c", 179);
    linhaCol(37, 65); printf("%c", 179);
    setlocale(LC_ALL, "Portuguese");
}
