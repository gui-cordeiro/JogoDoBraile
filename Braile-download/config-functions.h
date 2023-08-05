/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
 */

bool mudar = false;
bool mudarRedes = true;
bool isFullScreen = false;

//Declaração das threads
DWORD WINAPI e1(LPVOID params);
DWORD WINAPI letra(LPVOID params);
DWORD WINAPI redes(LPVOID params);

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
    _GREEN=32, //32
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
void exibirTelaRedes(int endOfGame){

    DWORD threadId;
    HANDLE hThread;

    if (endOfGame == 0) {
        textColor(BROWN, _BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(35, 36); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione Enter para retornar ao Menu Principal");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        textColor(WHITE, _BLACK);
    }

    hThread = CreateThread(NULL, 0x0, redes, NULL, 0, &threadId);

    if (endOfGame == 1){
        Sleep(2750);
        textColor(BROWN, _BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(35, 38); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione Enter para sair do Jogo do Braile");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        textColor(WHITE, _BLACK);

    }
    pressEnter();

    if (mudarRedes != true) Sleep(100);
    TerminateThread(hThread, 0x0);
    CloseHandle(hThread);

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
    topBannerContent("-", 0, 0, "-", 0, 0);
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
    box(17, 10, 29, 62);
    setlocale(LC_ALL, "C");
    linhaCol(17, 23); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Letra escrita em Braile");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);

    linhaCol(29, 17); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Marque a resposta correta à direita");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto(letrResp2, 22, 35, false);

    linhaCol(26, 34); printf("ATUAL");

    if (letrResp1 != '-') {
        setlocale(LC_ALL, "C");
        linhaCol(23, 29); printf("%c", 174);
        setlocale(LC_ALL, "Portuguese");
        textColor(DARKGRAY, _BLACK);

        printAlfabeto(letrResp1, 22, 21, true);

        linhaCol(26, 19); printf("Anterior");
    }

    if (letrResp3 != '-') {
        textColor(BROWN, BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(23, 43); printf("%c", 175);
        setlocale(LC_ALL, "Portuguese");
        textColor(DARKGRAY, _BLACK);

        printAlfabeto(letrResp3, 22, 49, false);

        linhaCol(26, 47); printf("Próximo");
    }
    textColor(WHITE, _BLACK);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    linhaCol(17, 96); printf("\u25b2");
    linhaCol(29, 96); printf("\u25bc");
    textColor(WHITE, _BLUE);
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese");

    opt = modeloMenu(18, 88, 4, lista);
    cleanScreen(6);
    if (opt - 1 == posCorreta) {
        acertoCont = true;
        totPts += 150;
        totAcertos ++;
        progresso[questao - 1] = 1;

        PlaySound(TEXT("..\\sounds\\win.wav"), NULL, SND_ASYNC);

        textColor(LIGHTGREEN, _BLACK);
        box(9, 18, 31, 102);

        linhaCol(11, 29); printf("                                                           __ ");
        linhaCol(12, 29); printf(" _____         _                                  _       |  |");
        linhaCol(13, 29); printf("|     |___ ___| |_ ___    ___ ___ ___ ___ ___ ___| |_ ___ |  |");
        linhaCol(14, 29); printf("|   --| -_|  _|  _| .'|  |  _| -_|_ -| . | . |_ -|  _| .'||__|");
        linhaCol(15, 29); printf("|_____|___|_| |_| |__,|  |_| |___|___|  _|___|___|_| |__,||__|");
        linhaCol(16, 29); printf("                                     |_|                      ");

        setlocale(LC_ALL, "C");
        linhaCol(28, 42); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione ENTER para continuar");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");

        box(18, 29, 25, 90);
        linhaCol(21, 32); printf(" Sua resposta: ");
        printAlfabeto(letrResp2, 21, 51, true);
        setlocale(LC_ALL, "C");

        linhaCol(18, 59); printf("%c", 194);
        for (int cont = 0; cont <= 6; cont ++) {
            linhaCol(19 + cont, 59); printf("%c", 179);
        }
        linhaCol(25, 59); printf("%c", 193);

        linhaCol(20, 67); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Você recebeu");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(22, 62); printf("+1 ACERTO  E  +150 PONTOS!");
    } else {
        totPts += 50;
        totErros ++;
        progresso[questao - 1] = 0;

        PlaySound(TEXT("..\\sounds\\lose.wav"), NULL, SND_ASYNC);

        textColor(LIGHTRED, _BLACK);
        box(9, 11, 31, 109);

        linhaCol(10, 16); printf("                                                          ___                           ");
        linhaCol(11, 16); printf("                                                         / _ \\                          ");
        linhaCol(12, 16); printf(" _____                                      _____       /_/ \\_\\                         ");
        linhaCol(13, 16); printf("|     |_ _ ___    ___ ___ ___ ___          |  |  |___ ___ ___    ___ ___ ___ ___ _ _    ");
        linhaCol(14, 16); printf("|  |  | | | -_|  | . | -_|   | .'| _ _ _   |  |  | . |  _| -_|  | -_|  _|  _| . | | | _ ");
        linhaCol(15, 16); printf("|__  _|___|___|  |  _|___|_|_|__,||_|_|_|   \\___/|___|___|___|  |___|_| |_| |___|___||_|");
        linhaCol(16, 16); printf("   |__|          |_|                                                                    ");

        setlocale(LC_ALL, "C");
        linhaCol(28, 42); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione ENTER para continuar");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");

        box(18, 14, 25, 104);
        linhaCol(21, 17); printf("Você escolheu: ");
        printAlfabeto(alt[opt - 1], 21, 36, true);
        setlocale(LC_ALL, "C");

        linhaCol(18, 44); printf("%c", 194);
        linhaCol(18, 74); printf("%c", 194);
        for (int cont = 0; cont <= 6; cont ++) {
            linhaCol(19 + cont, 44); printf("%c", 179);
            linhaCol(19 + cont, 74); printf("%c", 179);
        }
        linhaCol(25, 44); printf("%c", 193);
        linhaCol(25, 74); printf("%c", 193);

        linhaCol(21, 48); printf(" A resposta");
        linhaCol(22, 48); printf("correta era:");
        printAlfabeto(letrResp2, 21, 66, true);

        setlocale(LC_ALL, "C");
        linhaCol(20, 81); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Você recebeu");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(22, 78); printf("+1 ERRO  E  +50 PONTOS.");
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
    cleanScreen(6);
    textColor(WHITE, _BLACK);
    return acertoCont;
}

/* C) TELA DE APRESENTAÇÃO */
void apresentacao(){
    int tecla;
    system("cls");
    system("title Tela de título - Jogo do Braile 2.0");
    //PlaySound(TEXT("..\\sounds\\intro.wav"), NULL, SND_ASYNC);
    setlocale(LC_ALL, "C");
    linhaCol(12, 36); printf(" %c ", 254);
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
    linhaCol(26, 40); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Pressione a tecla ENTER para iniciar");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    pressEnter();

    PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    for(int pulses = 0; pulses < 4; pulses ++) {
        textColor(BLACK, _WHITE);
        setlocale(LC_ALL, "C");
        linhaCol(26, 39); printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione a tecla ENTER para iniciar");
        setlocale(LC_ALL, "C");
        printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        Sleep(80);
        textColor(WHITE, _BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(26, 39); printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione a tecla ENTER para iniciar");
        setlocale(LC_ALL, "C");
        printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        Sleep(80);

    }
    system("cls");
    return;
}

/* D) ALFABETO EM BRAILE */
void printAlfabeto(char letra, int lin1, int col, bool isVisible){
    //int tempo = 50;
    int lin2 = lin1 + 1, lin3 = lin1 + 2;
    box(lin1 - 1, col - 2, lin1 + 3, col + 4);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "C");
    linhaCol(lin1 - 2, col + 1);
    switch(tolower(letra)){
        case 'a':
            printf("A");
            linhaCol(lin1, col); printf("\u25cf \u25cb"); //cf de Full, cb de Branco
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'b':
            printf("B");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'c':
            printf("C");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'd':
            printf("D");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'e':
            printf("E");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'f':
            printf("F");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'g':
            printf("G");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'h':
            printf("H");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'i':
            printf("I");
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'j':
            printf("J");
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'k':
            printf("K");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'l':
            printf("L");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'm':
            printf("M");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'n':
            printf("N");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'o':
            printf("O");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'p':
            printf("P");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'q':
            printf("Q");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'r':
            printf("R");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 's':
            printf("S");
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 't':
            printf("T");
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'u':
            printf("U");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'v':
            printf("V");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'w':
            printf("W");
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cf");
            break;
        case 'x':
            printf("X");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'y':
            printf("Y");
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'z':
            printf("Z");
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
    }
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(lin1 - 2, col + 1);
    if (isVisible == true) printf("%c", letra);
    else printf("?");
}

/* E) TELA DE CONFIRMAÇÃO DE DIFICULDADE */
int confirmarJogo(char nivel[9], int progresso[26]) {
    int opt;
    int acertos = 0, erros = 0, pontos = 0;
    int colBanner = 0;
    char lista[2][40] = {"SIM, eu quero jogar!", "NÃO, eu quero voltar para o menu."};
    int tecla = 0, i = 0;
    char seqTeclas[10];
    char stringCopiada[10];
    int seqTeclasLength = 0;

    DWORD threadId;
    DWORD threadId2;

    HANDLE hThread;
    HANDLE hThread2;


    //PlaySound(TEXT("..\\sounds\\confirm-difficulty.wav"), NULL, SND_LOOP | SND_ASYNC);
    cleanScreen(1);
    titulo(nivel, "Confirmar Dificuldade");
    setlocale(LC_ALL, "C");
    linhaCol(8,72);printf("%c", 197);
    for (int divisoria = 9; divisoria < 32; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(32,72);printf("%c", 193);

    if (strcmp("FÁCIL", nivel) == 0) colBanner = 17;
    else if (strcmp("MÉDIO I", nivel) == 0) colBanner = 11;
    else if (strcmp("MÉDIO II", nivel) == 0) colBanner = 8;
    else if (strcmp("DIFÍCIL", nivel) == 0) colBanner = 15;
    topBannerContent("DIFICULDADE SELECIONADA:", 2, 23, nivel, 3, colBanner);

    setlocale(LC_ALL, "Portuguese");
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

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    linhaCol(19, 96); printf("\u25b2");
    linhaCol(27, 96); printf("\u25bc");
    textColor(WHITE, _BLUE);
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese");

    opt = modeloMenu(20, 78, 2, lista);

    if (opt == 2 || opt == 9) {
        cleanScreen(1);
        return 0;
    }

    cleanScreen(4);
    topBannerContent("DIFICULDADE SELECIONADA:", 2, 23, nivel, 3, colBanner);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    //PlaySound(TEXT("..\\sounds\\getready.wav"), NULL, SND_ASYNC);
    bottomBannerTitle(1);
    setlocale(LC_ALL, "C");
    linhaCol(12, 21); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Boas vindas ao \"Jogo do Braile\"! Pressione Enter para iniciar o jogo agora.");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    textColor(_BLACK, LIGHTCYAN);
    box(15, 13, 25, 107);
    linhaCol(17, 16);printf("########  #### ##     ## #### ########  ########    ###             ######  ######## ####");
    linhaCol(18, 16);printf("##     ##  ##  ##     ##  ##  ##     ##    ##      ## ##           ##    ## ##       ####");
    linhaCol(19, 16);printf("##     ##  ##  ##     ##  ##  ##     ##    ##     ##   ##          ##       ##       ####");
    linhaCol(20, 16);printf("##     ##  ##  ##     ##  ##  ########     ##    ##     ## #######  ######  ######    ## ");
    linhaCol(21, 16);printf("##     ##  ##   ##   ##   ##  ##   ##      ##    #########               ## ##           ");
    linhaCol(22, 16);printf("##     ##  ##    ## ##    ##  ##    ##     ##    ##     ##         ##    ## ##       ####");
    linhaCol(23, 16);printf("########  ####    ###    #### ##     ##    ##    ##     ##          ######  ######## ####");
    textColor(_BLACK, WHITE);

    setlocale(LC_ALL, "C");
    linhaCol(28, 15); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("DICA: Acompanhe o seu progresso de acertos e erros através da barra situada logo abaixo");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    currentProgressionBanner(nivel, progresso, acertos, erros, pontos);
    //linhaCol(37, 41);
    //getchar();


    /*if (strcmp(stringCopiada, "vasco") == 0) {
        titulo("-", "Easter Egg \"VASCO\" desbloqueado!");

        setlocale(LC_ALL, "C");
        linhaCol(36, 53); printf("%c", 196);
        linhaCol(36, 65); printf("%c", 196);
        linhaCol(38, 53); printf("%c", 196);
        linhaCol(38, 65); printf("%c", 196);
        setlocale(LC_ALL, "Portuguese");

        textColor(_BLACK, BROWN);
        linhaCol(37, 40); printf("    Easter Egg \"VASCO\" desbloqueado!    ");
        textColor(_BLACK, WHITE);
        hThread = CreateThread(NULL, 0x0, e1, NULL, 0, &threadId);
        hThread2 = CreateThread(NULL, 0x0, letra, NULL, 0, &threadId2);
        PlaySound(TEXT("..\\sounds\\e1.wav"), NULL, SND_ASYNC);
        while(1){
            tecla = getch();
            if (tecla == 0 || tecla == 224) tecla = getch();
            if (tecla == 13 && mudar == false) break;
        }
        PlaySound(TEXT("..\\sounds\\nosound.wav"), NULL, SND_ASYNC);
        currentProgressionBanner(nivel, progresso, acertos, erros, pontos);

        TerminateThread(hThread, 0x0);
        TerminateThread(hThread2, 0x0);

        CloseHandle(hThread);
        CloseHandle(hThread2);
    }
    else if (strcmp(stringCopiada, "kasino") == 0) {
        linhaCol(4, 10); printf("KASINO!");
        Sleep(3000);
    }*/
    pressEnter();
    cleanScreen(6);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    return 1;
}

/* H) FIM DO JOGO (TABELA DE ESTATÍSTICAS) */
void fimJogo(char nivel[9], int pts, int acertos, int numPerg){
    int tecla = 0;
    /*
     * Código do sistema de Ranking - Futuro
     */
    cleanScreen(2);
    titulo(nivel, "Resultado final");
    topBannerContent("RESULTADO FINAL DO: ", 2, 20, nivel, 5, 20);

    setlocale(LC_ALL, "C");
    linhaCol(13, 37); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" DE ACORDO COM SEU DESEMPENHO, VOCÊ OBTEU O ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);
    linhaCol(26, 45); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" Aguardando resultado final ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");

    Sleep(3500);

    if(((strcmp(nivel, "FÁCIL") == 0 && acertos <= 2) || (strcmp(nivel, "MÉDIO I") == 0 && acertos <= 3)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos <= 4) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos <= 8))){
        textColor(_BLACK, LIGHTRED);
        exibirBannerResultado(0);
        box(21, 24, 23, 95);
        linhaCol(22, 26); printf("Não se frustre! Errar faz parte, e é somente errando que se aprende!");
    } else if(((strcmp(nivel, "FÁCIL") == 0 && acertos <= 3) || (strcmp(nivel, "MÉDIO I") == 0 && acertos <= 6)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos <= 7) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos <= 16))){
        textColor(_BLACK, LIGHTBLUE);
        exibirBannerResultado(1);
        box(21, 27, 23, 93);
        linhaCol(22, 29); printf("Você está indo no caminho certo! Continue firme, você consegue!");
    } else if(((strcmp(nivel, "FÁCIL") == 0 && acertos <= 4) || (strcmp(nivel, "MÉDIO I") == 0 && acertos <= 9)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos <= 10) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos <= 25))){
        textColor(_BLACK, LIGHTMAGENTA);
        exibirBannerResultado(2);
        box(21, 28, 23, 92);
        linhaCol(22, 30); printf("Muito bem! A perseverança é a chave, então continue tentando!");
    } else if(((strcmp(nivel, "FÁCIL") == 0 && acertos == 5) || (strcmp(nivel, "MÉDIO I") == 0 && acertos == 10)) || ((strcmp(nivel, "MÉDIO II") == 0 && acertos == 11) || (strcmp(nivel, "DIFÍCIL") == 0 && acertos == 26))){
        textColor(_BLACK, LIGHTGREEN);
        exibirBannerResultado(3);
        box(21, 26, 23, 95);
        linhaCol(22, 28); printf("Meus parabéns, você acertou TODAS AS QUESTÕES! É assim que se faz!");
    } else {
        exibirBannerResultado(69);
        box(21, 41, 23, 79);
        linhaCol(22, 43); printf("[ERRO] Dados informados incorretos.");
    }
    textColor(_BLACK, WHITE);
    setlocale(LC_ALL, "C");
    linhaCol(26, 43); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" Pressione ENTER para continuar ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    pressEnter();
    //cleanScreen(2);

    if(acertos == numPerg) { // Todas as respostas respondidas corretamente
        int linCad = 10, colCad = 33;

        box(9, 28, 31, 92);

        textColor(LIGHTRED, _BLACK);
        linhaCol(linCad, colCad); printf("                                 ");
        linhaCol(linCad + 1, colCad); printf("                                 ");
        linhaCol(linCad + 2, colCad); printf("                                 ");
        linhaCol(linCad + 3, colCad); printf("          #############           ");
        linhaCol(linCad + 4, colCad); printf("       ##################        ");
        linhaCol(linCad + 5, colCad); printf("     ######          ######      ");
        linhaCol(linCad + 6, colCad); printf("    #####              #####     ");
        linhaCol(linCad + 7, colCad); printf("    #####               ####     ");
        linhaCol(linCad + 8, colCad); printf("    ####/               ####     ");
        linhaCol(linCad + 9, colCad); printf("                                 ");
        linhaCol(linCad + 10, colCad); printf("  #########.         ##(#(##(##  ");
        linhaCol(linCad + 11, colCad); printf(" ##############################  ");
        linhaCol(linCad + 12, colCad); printf(" ############################### ");
        linhaCol(linCad + 13, colCad); printf(",##############  ############### ");
        linhaCol(linCad + 14, colCad); printf(" #############    #############  ");
        linhaCol(linCad + 15, colCad); printf(" ##############  ##############  ");
        linhaCol(linCad + 16, colCad); printf("  (############  #############   ");
        linhaCol(linCad + 17, colCad); printf("    ########################     ");
        linhaCol(linCad + 18, colCad); printf("      ####################       ");
        linhaCol(linCad + 19, colCad); printf("          (###########           ");
        textColor(WHITE, _BLACK);
        exibirBannerDificuldade("-", 0, 0, "OH", 14, 71);
        setlocale(LC_ALL, "C");
        linhaCol(21, 77); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" Pressione Enter ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        pressEnter();

        textColor(LIGHTGREEN, _BLACK);
        linhaCol(linCad, colCad); printf("               ############      ");
        linhaCol(linCad + 1, colCad); printf("            ##################   ");
        linhaCol(linCad + 2, colCad); printf("           #####          ###### ");
        linhaCol(linCad + 3, colCad); printf("                            #####");
        linhaCol(linCad + 4, colCad); printf("                            .####");
        linhaCol(linCad + 5, colCad); printf("                            #####");
        linhaCol(linCad + 6, colCad); printf("                           ##### ");
        linhaCol(linCad + 7, colCad); printf("                         ######  ");
        linhaCol(linCad + 8, colCad); printf("                          ###    ");
        linhaCol(linCad + 9, colCad); printf("                                 ");
        linhaCol(linCad + 10, colCad); printf("  ((#(#(####         ##########  ");
        linhaCol(linCad + 11, colCad); printf(" (###(###(#(##(################# ");
        linhaCol(linCad + 12, colCad); printf(" ############################### ");
        linhaCol(linCad + 13, colCad); printf(" ##############( .############## ");
        linhaCol(linCad + 14, colCad); printf(" #############     ############# ");
        linhaCol(linCad + 15, colCad); printf("  #############(  #############  ");
        linhaCol(linCad + 16, colCad); printf("   ############(  ############   ");
        linhaCol(linCad + 17, colCad); printf("    ,########################    ");
        linhaCol(linCad + 18, colCad); printf("       ###################       ");
        linhaCol(linCad + 19, colCad); printf("           ###########           ");
        PlaySound(TEXT("..\\sounds\\padlock.wav"), NULL, SND_ASYNC);
        Sleep(500);

        textColor(WHITE, _BLACK);
        box(9, 7, 31, 113);
        colCad -= 18;
        PlaySound(TEXT("..\\sounds\\unlocked.wav"), NULL, SND_ASYNC);
        textColor(LIGHTGREEN, _BLACK);
        linhaCol(linCad, colCad); printf("               ############      ");
        linhaCol(linCad + 1, colCad); printf("            ##################   ");
        linhaCol(linCad + 2, colCad); printf("           #####          ###### ");
        linhaCol(linCad + 3, colCad); printf("                            #####");
        linhaCol(linCad + 4, colCad); printf("                            .####");
        linhaCol(linCad + 5, colCad); printf("                            #####");
        linhaCol(linCad + 6, colCad); printf("                           ##### ");
        linhaCol(linCad + 7, colCad); printf("                         ######  ");
        linhaCol(linCad + 8, colCad); printf("                          ###    ");
        linhaCol(linCad + 9, colCad); printf("                                 ");
        linhaCol(linCad + 10, colCad); printf("  ((#(#(####         ##########  ");
        linhaCol(linCad + 11, colCad); printf(" (###(###(#(##(################# ");
        linhaCol(linCad + 12, colCad); printf(" ############################### ");
        linhaCol(linCad + 13, colCad); printf(" ##############( .############## ");
        linhaCol(linCad + 14, colCad); printf(" #############     ############# ");
        linhaCol(linCad + 15, colCad); printf("  #############(  #############  ");
        linhaCol(linCad + 16, colCad); printf("   ############(  ############   ");
        linhaCol(linCad + 17, colCad); printf("    ,########################    ");
        linhaCol(linCad + 18, colCad); printf("       ###################       ");
        linhaCol(linCad + 19, colCad); printf("           ###########           ");

        textColor(WHITE, _BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(13, 71); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" MEUS PARABÉNS! ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);

        if (strcmp(nivel, "FÁCIL") == 0) {
            exibirBannerDificuldade("-", 0, 0, "MÉDIO I", 15, 52);
        } else if (strcmp(nivel, "MÉDIO I") == 0 && acertos == 10) {
            exibirBannerDificuldade("-", 0, 0, "MÉDIO II", 15, 51);
        } else if (strcmp(nivel, "MÉDIO II") == 0 && acertos == 11) {
            exibirBannerDificuldade("-", 0, 0, "DIFÍCIL", 15, 58);
        } else if (strcmp(nivel, "DIFÍCIL") == 0 && acertos == 26) {
            exibirBannerDificuldade("-", 0, 0, "AGRADECIMENTO", 15, 50);
        }

        exibirBannerDificuldade("-", 0, 0, "DESBLOQUEADA", 20, 35);

        Sleep(1700);
        linhaCol(27, 63); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" Pressione ENTER para continuar ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        pressEnter();
    }
    cleanScreen(1);
    topBannerContent("OBRIGADO POR JOGAR O:", 2, 20, "AGRADECIMENTO", 5, 20);



    exibirTelaRedes(0);
    cleanScreen(1);
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

/* M) CONFIGURAÇÕES INICIAIS DA JANELA DO CONSOLE (BUFFER, DIMENSÕES, CORES E ENTRE OUTROS) */
void configJogo(){
    int colunas = 119;
    int linhas = 38;
    hideCursor();
    setlocale(LC_ALL,"Portuguese");

    //Definindo as cores e as dimensões da janela do console
    system("color 0f");
    system("mode con:cols=119 lines=38");

    //Definindo o tamanho do buffer do console (definido APÓS o redimensionamento da janela do console)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.Y = 120;
    bufferSize.X = 39;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    //Definindo o posicionamento central da janela do console
    HWND cW = GetConsoleWindow();
    int x = GetSystemMetrics(SM_CXSCREEN); // quantidade de pixel por linhas da tela
    int y = GetSystemMetrics(SM_CYSCREEN); // quantidade de pixel por coluna da tela
	SetWindowPos( cW, 0, x/8, y/15, colunas-1, linhas-1, SWP_NOSIZE | SWP_NOZORDER );

    //Definindo o tamanho da fonte das informações do console
    CONSOLE_FONT_INFOEX fontInfo = { sizeof(CONSOLE_FONT_INFOEX) };
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    if (isFullScreen == true) fontInfo.dwFontSize.Y = 16 + 4;  // aumenta o tamanho vertical da fonte em 2 pontos
    else fontInfo.dwFontSize.Y = 16;  // aumenta o tamanho vertical da fonte em 2 pontos
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    //Bloqueando o redimensionamento da janela do console
    LONG_PTR style = GetWindowLongPtr(cW, GWL_STYLE);
    style &= ~WS_SIZEBOX;
    style &= ~WS_MAXIMIZEBOX;
    SetWindowLongPtr(cW, GWL_STYLE, style);
}

/* N) [AINDA EM DESENVOLVIMENTO] ALTERNA ENTRE MODO "JANELA" E MODO "TELA CHEIA" */
void changeScreenMode() {
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
    strcat(comando, " - Jogo do Braile 3.0");
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
void exibirBannerDificuldade(char titulo1[40], int lin1, int col1, char nivel[20], int lin2, int col2) { //"lin1" e "col1" são coordenadas relacionadas ao "titulo1"; "lin2" e "col2", ao "titulo2".
    if (strcmp(titulo, "-") != 0) {
        setlocale(LC_ALL, "C");
        linhaCol(lin1, col1); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("%s", titulo1);
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
    }
    int linha = lin2, coluna = col2;
    /*if ((titleMode >= 0 && titleMode <= 4) || (titleMode == 7 || titleMode == 8)) {
        linha = lin2;
        coluna = col2;
        if (titleMode == 1) {
            linhaCol(2, 28); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" VOCÊ ESTÁ NO ");
        } else if (titleMode == 2){
            linhaCol(2, 24); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" DIFICULDADE SELECIONADA ");
        } else if (titleMode == 3){
            linhaCol(2, 25); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" RESULTADOS FINAIS DO ");
        } else if (titleMode == 8) {
            linhaCol(2, 25); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" VOCÊ ESTÁ CONSULTANDO ");
        } else if (titleMode == 4 || titleMode == 7){
            if(titleMode == 7) {
                linhaCol(2, 47);
                linha = 3;
                coluna = 33;
            } else linhaCol(2, 22);
            printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" MUITO OBRIGADO POR JOGAR O ");
        }
        if (titleMode != 0 && titleMode != 5) {
            setlocale(LC_ALL, "C");
            printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
        }
    } else if (titleMode >= 4 && titleMode <= 6){
        linha = 15;
        coluna = 52;
    }*/

    if (strcmp(nivel, "MENU") == 0) {
        linhaCol(linha, coluna); printf(" _____                 _____     _         _         _ ");
        linhaCol(linha + 1, coluna); printf("|     |___ ___ _ _    |  _  |___|_|___ ___|_|___ ___| |");
        linhaCol(linha + 2, coluna); printf("| | | | -_|   | | |   |   __|  _| |   |  _| | . | .'| |");
        linhaCol(linha + 3, coluna); printf("|_|_|_|___|_|_|___|   |__|  |_| |_|_|_|___|_|  _|__,|_|");
        linhaCol(linha + 4, coluna); printf("                                            |_|        ");
    } else if (strcmp(nivel, "COMO JOGAR") == 0){
        linhaCol(linha, coluna); printf(" _____                     __                 ");
        linhaCol(linha + 1, coluna); printf("|     |___ _____ ___    __|  |___ ___ ___ ___ ");
        linhaCol(linha + 2, coluna); printf("|   --| . |     | . |  |  |  | . | . | .'|  _|");
        linhaCol(linha + 3, coluna); printf("|_____|___|_|_|_|___|  |_____|___|_  |__,|_|   (o Jogo do Braile)");
        linhaCol(linha + 4, coluna); printf("                                 |___|        ");
    } else if (strcmp(nivel, "NÃO DESISTA") == 0) {
        linhaCol(linha, coluna); printf("                                              __ ");
        linhaCol(linha, coluna); printf(" _____ /\\/        ____          _     _      |  |");
        linhaCol(linha, coluna); printf("|   | |___ ___   |    \\ ___ ___|_|___| |_ ___|  |");
        linhaCol(linha, coluna); printf("| | | | .'| . |  |  |  | -_|_ -| |_ -|  _| .'|__|");
        linhaCol(linha, coluna); printf("|_|___|__,|___|  |____/|___|___|_|___|_| |__,|__|");
    } else if (strcmp(nivel, "AGRADECIMENTO") == 0) {
        linhaCol(linha, coluna + 55); printf("__");
        linhaCol(linha + 1, coluna); printf("    __                  _        _____         _ _    |  | ");
        linhaCol(linha + 2, coluna); printf(" __|  |___ ___ ___    _| |___   | __  |___ ___|_| |___|  |");
        linhaCol(linha + 3, coluna); printf("|  |  | . | . | . |  | . | . |  | __ -|  _| .'| | | -_|__|");
        linhaCol(linha + 4, coluna); printf("|_____|___|_  |___|  |___|___|  |_____|_| |__,|_|_|___|__|");
        linhaCol(linha + 5, coluna); printf("          |___|                                        ");

    } else if (strcmp(nivel, "EXEMPLO") == 0) {
        linhaCol(linha, coluna);     printf(" _____                   _     ");
        linhaCol(linha + 1, coluna); printf("|   __|_ _ ___ _____ ___| |___ ");
        linhaCol(linha + 2, coluna); printf("|   __|_'_| -_|     | . | | . |");
        linhaCol(linha + 3, coluna); printf("|_____|_,_|___|_|_|_|  _|_|___|");
        linhaCol(linha + 4, coluna); printf("                    |_|        ");
    } else if (strcmp(nivel, "OH") == 0) {
        linhaCol(linha, coluna);     printf("         _____ ");
        linhaCol(linha + 1, coluna); printf(" _____  |___  |");
        linhaCol(linha + 2, coluna); printf("|  _  |___|  _|");
        linhaCol(linha + 3, coluna); printf("|     |   |_|  ");
        linhaCol(linha + 4, coluna); printf("|__|__|_|_|_|  ");
    } else if (strcmp(nivel, "FÁCIL") == 0) {
        linhaCol(linha, coluna); printf(" _____ _         _    _____         _ _ ");
        linhaCol(linha + 1, coluna); printf("|   | |_|_ _ ___| |  |   __|___ ___|_| |");
        linhaCol(linha + 2, coluna); printf("| | | | | | | -_| |  |   __| .'|  _| | |");
        linhaCol(linha + 3, coluna); printf("|_|___|_|\\_/|___|_|  |__|  |__,|___|_|_|");
    } else if (strcmp(nivel, "MÉDIO I") == 0) {
        linhaCol(linha, coluna); printf(" _____ _         _    _____       _ _        _____ ");
        linhaCol(linha + 1, coluna); printf("|   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|");
        linhaCol(linha + 2, coluna); printf("| | | | | | | -_| |  | | | | -_| . | | . |   _| |_ ");
        linhaCol(linha + 3, coluna); printf("|_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|");
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        linhaCol(linha, coluna); printf(" _____ _         _    _____       _ _        _____ _____ ");
        linhaCol(linha + 1, coluna); printf("|   | |_|_ _ ___| |  |     |___ _| |_|___   |_   _|_   _|");
        linhaCol(linha + 2, coluna); printf("| | | | | | | -_| |  | | | | -_| . | | . |   _| |_ _| |_ ");
        linhaCol(linha + 3, coluna); printf("|_|___|_|\\_/|___|_|  |_|_|_|___|___|_|___|  |_____|_____|");
    } else if (strcmp(nivel, "DIFÍCIL") == 0) {
        linhaCol(linha, coluna); printf(" _____ _         _    ____  _ ___ _     _ _ ");
        linhaCol(linha + 1, coluna); printf("|   | |_|_ _ ___| |  |    \\|_|  _|_|___|_| |");
        linhaCol(linha + 2, coluna); printf("| | | | | | | -_| |  |  |  | |  _| |  _| | |");
        linhaCol(linha + 3, coluna); printf("|_|___|_|\\_/|___|_|  |____/|_|_| |_|___|_|_|");
    } else if(strcmp(nivel, "DESBLOQUEADA") == 0) {
        textColor(LIGHTGREEN, _BLACK);
        linhaCol(linha, coluna); printf("                                                 __ ");
        linhaCol(linha + 1, coluna); printf(" ____          _   _                       _    |  |");
        linhaCol(linha + 2, coluna); printf("|    \\ ___ ___| |_| |___ ___ _ _ ___ ___ _| |___|  |");
        linhaCol(linha + 3, coluna); printf("|  |  | -_|_ -| . | | . | . | | | -_| .'| . | . |__|");
        linhaCol(linha + 4, coluna); printf("|____/|___|___|___|_|___|_  |___|___|__,|___|___|__|");
        linhaCol(linha + 5, coluna); printf("                          |_|                       ");
        textColor(WHITE, _BLACK);
    }

}

void exibirBannerResultado(int bannerOpt) { //0) 0-25%; 1) 26-50%; 2) 51-75%; 3) 76-100%
    if (bannerOpt == 1) {
        linhaCol(14, 12); printf("                                                                                             __ ");
        linhaCol(15, 12); printf(" _____         _      _____           _____         _   _                            _      |  |");
        linhaCol(16, 12); printf("| __  |___ ___| |_   | __  |   ___   |     |___ ___| |_|_|___ _ _ ___    ___ ___ ___|_|_____|  |");
        linhaCol(17, 12); printf("|    -| .'|   | '_|  | __ -|  |___|  |   --| . |   |  _| |   | | | -_|  | .'|_ -|_ -| |     |__|");
        linhaCol(18, 12); printf("|__|__|__,|_|_|_,_|  |_____|         |_____|___|_|_|_| |_|_|_|___|___|  |__,|___|___|_|_|_|_|__|");
    } else if(bannerOpt == 2) {
        linhaCol(14, 21); printf("                                                                           __ ");
        linhaCol(15, 21); printf(" _____         _      _____           _____     _ _          _            |  |");
        linhaCol(16, 21); printf("| __  |___ ___| |_   |  _  |   ___   |     |_ _|_| |_ ___   | |_ ___ _____|  |");
        linhaCol(17, 21); printf("|    -| .'|   | '_|  |     |  |___|  | | | | | | |  _| . |  | . | -_|     |__|");
        linhaCol(18, 21); printf("|__|__|__,|_|_|_,_|  |__|__|         |_|_|_|___|_|_| |___|  |___|___|_|_|_|__|");
    } else if (bannerOpt == 3) {
        linhaCol(14, 13); printf("                                                                                            __ ");
        linhaCol(15, 13); printf(" _____         _      _____           _____ _____ _____ _____ _____ _____ _____ _____ __   |  |");
        linhaCol(16, 13); printf("| __  |___ ___| |_   |   __|   ___   |     |     |  _  |   __|     |  _  |  |  |   __|  |  |  |");
        linhaCol(17, 13); printf("|    -| .'|   | '_|  |__   |  |___|  |-   -| | | |   __|   __|   --|     |  |  |   __|  |__|__|");
        linhaCol(18, 13); printf("|__|__|__,|_|_|_,_|  |_____|         |_____|_|_|_|__|  |_____|_____|__|__|\\___/|_____|_____|__|");
    } else if (bannerOpt == 0){
        linhaCol(15, 9); printf(" _____         _      _____           _____             _                      _ _                         ");
        linhaCol(16, 9); printf("| __  |___ ___| |_   |     |   ___   |  _  |___ ___ ___|_|___ ___    _____ ___| | |_ ___ ___ ___ ___       ");
        linhaCol(17, 9); printf("|    -| .'|   | '_|  |   --|  |___|  |   __|  _| -_|  _| |_ -| .'|  |     | -_| |   | . |  _| .'|  _|_ _ _ ");
        linhaCol(18, 9); printf("|__|__|__,|_|_|_,_|  |_____|         |__|  |_| |___|___|_|___|__,|  |_|_|_|___|_|_|_|___|_| |__,|_| |_|_|_|");
    } else {
        linhaCol(14, 8); printf(" ___                         ___                                                                         ");
        linhaCol(15, 8); printf("|  _|_____ _____ _____ _____|_  |   _____         _      ____                      _           _   _     ");
        linhaCol(16, 8); printf("| | |   __| __  | __  |     | | |  | __  |___ ___| |_   |    \\ ___ ___ ___ ___ ___| |_ ___ ___|_|_| |___ ");
        linhaCol(17, 8); printf("| | |   __|    -|    -|  |  | | |  |    -| .'|   | '_|  |  |  | -_|_ -|  _| . |   |   | -_|  _| | . | . |");
        linhaCol(18, 8); printf("| |_|_____|__|__|__|__|_____|_| |  |__|__|__,|_|_|_,_|  |____/|___|___|___|___|_|_|_|_|___|___|_|___|___|");
        linhaCol(19, 8); printf("|___|                       |___|                                                                        ");

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
            //printf("Descartado! A letra gerada é igual a da resposta ou já foi apresentada na pergunta anterior!\n");
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
    int colFS, linFS;
    if (isFullScreen == true) colFS = 16;
    else colFS = 0;
    linFS = 0; //16 e 1
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
    SetConsoleOutputCP(CP_UTF8);

    linhaCol(lin1, col1);
    printf("\u256d");
    linhaCol(lin1, col2);
    printf("\u256e");
    linhaCol(lin2, col1);
    printf("\u2570");
    linhaCol(lin2, col2);
    printf("\u256f");

    SetConsoleOutputCP(850);
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

void topBannerContent(char titulo1[40], int lin1, int col1, char nivel[20], int lin2, int col2) { //"lin1" e "col1" são coordenadas relacionadas ao "titulo1"; "lin2" e "col2", ao "titulo2".
    exibirBannerDificuldade(titulo1, lin1, col1, nivel, lin2, col2);

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

    SetConsoleOutputCP(CP_UTF8);
    linhaCol(4, refer + 6); printf("\u25b2");  //Cima
    linhaCol(6, refer + 6); printf("\u25bc");  //Baixo
    linhaCol(6, refer + 2); printf("\u25c4");  //Esquerda
    linhaCol(6, refer + 10); printf("\u25ba"); //Direita
    SetConsoleOutputCP(850);
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
    linhaCol(5, refer + 34); printf("%c", 196);
    linhaCol(4, refer + 33); printf("%c", 179);
    linhaCol(3, refer + 34); printf("%c%c", 196, 196);

    SetConsoleOutputCP(CP_UTF8);
    linhaCol(5, refer + 35); printf("\u256e");
    linhaCol(5, refer + 33); printf("\u2570");
    linhaCol(3, refer + 33); printf("\u256d");
    SetConsoleOutputCP(850);

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
        printf(" Descrição:");
    } else {
        printf("           ");
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
        for (linha = 33; linha < 38; linha ++) {
            for (coluna = 2; coluna < 119; coluna ++) {
                if (linha == 33 && coluna < 23) { // Título do Banner
                    continue;
                } else {
                    linhaCol(linha, coluna); printf(" ");
                }
            }
        }
        setlocale(LC_ALL, "C");
        linhaCol(38, 39); printf("%c", 196);
        linhaCol(38, 53); printf("%c", 196);
        linhaCol(38, 65); printf("%c", 196);
        linhaCol(38, 80); printf("%c", 196);
        setlocale(LC_ALL, "Portuguese");
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
    bool enterPressed = false;

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
    while(!enterPressed){
        linhaSelecionada = lin1 + 2;
        for(i = 0; i < qtd; i ++) {
            if((i + 1) == opt) {
                textColor(BLUE, _WHITE);
                //PlaySound(TEXT("..\\sounds\\select.wav"), NULL, SND_ASYNC);
            } else {
                if (strcmp(lista[i], "???") == 0) {
                    textColor(DARKGRAY, _BLUE);
                } else {
                    textColor(WHITE, _BLUE);
                }
            }
            espacamento = (tamMaxItem - strlen(lista[i])) / 2; //Criar espaçamento para centralizar opções no menu
            linhaCol(linhaSelecionada, col1 + 2 + espacamento);
            printf("%s", lista[i]);
            linhaSelecionada += 2;
            textColor(WHITE, _BLACK);
        }


        if (qtd >= 7) {
            bottomBannerContent(opt);
        }

        //linhaCol(35, 10); printf("Opção selecionada: %d", opt);



        //Aguarda teclas
        tecla = getch();
        if (tecla == 0 || tecla == 224) tecla = getch();
        if (tecla == 72 || (tecla == 119) || (tecla == 87)) { //Seta pra cima
            while (strcmp(lista[opt - 2], "???") == 0) {
                opt --;
            }
            if(opt == 1) opt = qtd;
            else if (opt > 1) opt --;
        } else if (tecla == 80 || (tecla == 115) || (tecla == 83)) { //Seta pra baixo
            while (strcmp(lista[opt], "???") == 0) {
                opt ++;
            }
            if (opt == qtd) opt = 1;
            else if (opt < qtd) opt ++;
        } else if (tecla == 102 || tecla == 70) {
            isFullScreen = !isFullScreen;
            changeScreenMode();
        } else if (tecla == 27) { //ESC
            opt = 9;
            break;
        }

        if(GetAsyncKeyState(VK_RETURN) & 0x8000) {
            if (!enterPressed) {
                enterPressed = true;
            } else {
                enterPressed = false;
            }
            while(GetAsyncKeyState(VK_RETURN) & 0x8000); //Espera até soltar a tecla Enter
        }
    }
    //PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    textColor(WHITE, _BLACK);
    return opt;
}

void currentProgressionBanner(char difficulty[8], int currentProgression[26], int acertos, int erros, int pontos) {
    int cont, numColuna, numPerg, numBar, colAtual;
    bool perguntaAtual = false;
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

        SetConsoleOutputCP(CP_UTF8);
        linhaCol(33, colAtual);

        if (currentProgression[cont] == 0) {
            textColor(LIGHTRED, _BLACK);
            printf("X");
            linhaCol(35, colAtual); printf(" ");
        } else if (currentProgression[cont] == 1) {
            textColor(LIGHTGREEN, _BLACK);
            printf("\u263b");
            linhaCol(35, colAtual); printf(" ");
        } else {
            textColor(WHITE, _BLACK);
            printf("\u2666");
            if (perguntaAtual == false) {
                textColor(BROWN, _BLACK);
                linhaCol(35, colAtual); printf("\u2302");
                textColor(WHITE, _BLACK);
                perguntaAtual = true;
            }
        }

        SetConsoleOutputCP(850);

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

    setlocale(LC_ALL, "C");
    linhaCol(38, 39); printf("%c", 193);
    linhaCol(38, 80); printf("%c", 193);

    linhaCol(36, 53); printf("%c", 194);
    linhaCol(36, 65); printf("%c", 194);
    linhaCol(38, 53); printf("%c", 193);
    linhaCol(38, 65); printf("%c", 193);

    linhaCol(37, 40);
    printf(" ACERTOS: ");
    if (acertos < 10) printf(" ");
    printf("%d %c ERROS: ", acertos, 179);
    if (erros < 10) printf(" ");
    printf("%d %c PONTOS: ", erros, 179);
    if (pontos < 10) printf("   ");
    else if (pontos < 100) printf("  ");
    else if (pontos < 1000) printf(" ");
    printf("%d", pontos);
    setlocale(LC_ALL, "Portuguese");
}

int pressEnter(void) {
    bool enterPressed = false;
    while (!enterPressed) {
        if(GetAsyncKeyState(VK_RETURN) & 0x8000) { //Retirar o enterPressed = false, talvez
            if (!enterPressed) {
                enterPressed = true;
            } else {
                enterPressed = false;
            }
            while(GetAsyncKeyState(VK_RETURN) & 0x8000); //Espera até soltar a tecla Enter
        }
    }
}

DWORD WINAPI e1(LPVOID params) {
    int contador = 0;
    cleanScreen(6);

    while(contador < 4){
        //linhaCol(37, 2); printf("%d", contador);
        linhaCol(11, 3); printf("       ,lllllllllc:,.           ");
        linhaCol(12, 3); printf("       ,0MMMMMMMMMWNKd,         ");
        linhaCol(13, 3); printf("       .dWMNxcllllllool'        ");
        linhaCol(14, 3); printf("        oWMK;'xOOOOOkxdoc,..    ");
        linhaCol(15, 3); printf("     ...oWMK;;0XXXXXNWWMMWX0xl,.");
        linhaCol(16, 3); printf("   .oKx'oWMK; ......';codk0NMWO,");
        linhaCol(17, 3); printf("  :0WWx'oWMK,        ;kko,.,dx' ");
        linhaCol(18, 3); printf(" :XMWk'.oWMK,       ;0MM0'      ");
        linhaCol(19, 3); printf(".kMM0'  oWMXo'''',ckNMWO,       ");
        linhaCol(20, 3); printf("'0MWx.  oWMMWNNNNWMMNOl.        ");
        linhaCol(21, 3); printf(".kMM0,  oWMW0xk0XWMNx.          ");
        linhaCol(22, 3); printf(" ;KMWO;.cKWX;  .'xNMNd.         ");
        linhaCol(23, 3); printf("  ;0WMXxc:ll.    .lXMWk'  .;xk, ");
        linhaCol(24, 3); printf("   .l0WMWKkoc;''...cKMW0;.dNMWO'");
        linhaCol(25, 3); printf("     .;dOXWMMWNNNXO;;0WMKc;odc' ");
        linhaCol(26, 3); printf("        'cllodxkkkkl.'kWMXl.    ");
        linhaCol(27, 3); printf("      .oX0d'         .dNMNd.    ");
        linhaCol(28, 3); printf("      ;0WWNd.         .lXWWOc.  ");
        linhaCol(29, 3); printf("      '::::;.           ':::;.  ");

        textColor(LIGHTRED, _BLACK);
        linhaCol(11, 36); printf("            ########################            ");
        linhaCol(12, 36); printf("              ####################              ");
        linhaCol(13, 36); printf("                ################                ");
        linhaCol(14, 36); printf("                 ##############                 ");
        linhaCol(15, 36); printf("#                  ##########                  #");
        linhaCol(16, 36); printf("####                ########                ####");
        linhaCol(17, 36); printf("########             ######             ########");
        linhaCol(18, 36); printf("#############        ######        #############");
        linhaCol(19, 36); printf("################################################");
        linhaCol(20, 36); printf("################################################");
        linhaCol(21, 36); printf("################################################");
        linhaCol(22, 36); printf("############         ######         ############");
        linhaCol(23, 36); printf("#######              ######             ########");
        linhaCol(24, 36); printf("####                ########                ####");
        linhaCol(25, 36); printf("#                  ##########                  #");
        linhaCol(26, 36); printf("                 ##############                 ");
        linhaCol(27, 36); printf("                ################                ");
        linhaCol(28, 36); printf("              ####################              ");
        linhaCol(29, 36); printf("            ########################            ");
        textColor(WHITE, _BLACK);

        linhaCol(11, 85); printf(" ......                    ...... ");
        linhaCol(12, 85); printf(".:OXX0:                    lKXKk, ");
        linhaCol(13, 85); printf("  lNMWd.                  .OMMK;  ");
        linhaCol(14, 85); printf("  .oNMNl.  .';::ccc::;,'..'lxk:   ");
        linhaCol(15, 85); printf("   .xWMXc.oKNWWMMMMMWWWNX0kdl:.   ");
        linhaCol(16, 85); printf("    'kWMK:;xkxolllllodxk0XNWMWKx' ");
        linhaCol(17, 85); printf("  .:;;0MM0,            ,ccccdKXd. ");
        linhaCol(18, 85); printf(" .xW0;:KMWk.          ,0WNd. .'   ");
        linhaCol(19, 85); printf(".dWMX: cXMWx.         :dxo'       ");
        linhaCol(20, 85); printf("'0MMk.  lNMNo..cllllloooooolllll, ");
        linhaCol(21, 85); printf(".OMMk.  .dWMXc.dNMMMMMMMMMMMMMMWd.");
        linhaCol(22, 85); printf(" oNMNo.  .kWMK:.;:cllllc::::dXMWd.");
        linhaCol(23, 85); printf(" .dNMNk;. 'OWM0, .:kOk:     ,KMWd.");
        linhaCol(24, 85); printf("  .:0WMNOo';0MWOdxKMWk'..':oOWMWd.");
        linhaCol(25, 85); printf("    .:kXWMO;:KMMWWMM0;:OXNWMWXOo' ");
        linhaCol(26, 85); printf("       .:oxc.lNMMMMK:,kK0kdl;..   ");
        linhaCol(27, 85); printf("             .oNMMXc ....         ");
        linhaCol(28, 85); printf("              .xXKo.              ");
        linhaCol(29, 85); printf("               .;'.               ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6);

        linhaCol(10, 2); printf(" .d8888b.  888          888             888            8888888b.                            888                                ");
        linhaCol(11, 2); printf("d88P  Y88b 888          888             888            888   Y88b                           888                                ");
        linhaCol(12, 2); printf("888    888 888          888             888            888    888                           888                                ");
        linhaCol(13, 2); printf("888        888 888  888 88888b.     .d88888  .d88b.    888   d88P .d88b.   .d88b.   8888b.  888888  8888b.  .d8888b            ");
        linhaCol(14, 2); printf("888        888 888  888 888 \"88b   d88\" 888 d8P  Y8b   8888888P\" d8P  Y8b d88P\"88b     \"88b 888        \"88b 88K          ");
        linhaCol(15, 2); printf("888    888 888 888  888 888  888   888  888 88888888   888 T88b  88888888 888  888 .d888888 888    .d888888 \"Y8888b.          ");
        linhaCol(16, 2); printf("Y88b  d88P 888 Y88b 888 888 d88P   Y88b 888 Y8b.       888  T88b Y8b.     Y88b 888 888  888 Y88b.  888  888      X88           ");
        linhaCol(17, 2); printf(" \"Y8888P\"  888  \"Y88888 88888P\"     \"Y88888  \"Y8888    888   T88b \"Y8888   \"Y88888 \"Y888888  \"Y888 \"Y888888  88888P'");
        linhaCol(18, 2); printf("                                                                               888                                             ");
        linhaCol(19, 2); printf("                                                                          Y8b d88P                                             ");
        linhaCol(20, 2); printf("                                                                           \"Y88P\"                                            ");

        linhaCol(23, 2); printf("888     888                                             888                .d8888b.                                            ");
        linhaCol(24, 2); printf("888     888                                             888               d88P  Y88b                                           ");
        linhaCol(25, 2); printf("888     888                                             888               888    888                                           ");
        linhaCol(26, 2); printf("Y88b   d88P 8888b.  .d8888b   .d8888b .d88b.        .d88888  8888b.       888         8888b.  88888b.d88b.   8888b.            ");
        linhaCol(27, 2); printf(" Y88b d88P     \"88b 88K      d88P\"   d88\"\"88b      d88\" 888     \"88b      888  88888     \"88b 888 \"888 \"88b     \"88b ");
        linhaCol(28, 2); printf("  Y88o88P  .d888888 \"Y8888b. 888     888  888      888  888 .d888888      888    888 .d888888 888  888  888 .d888888          ");
        linhaCol(29, 2); printf("   Y888P   888  888      X88 Y88b.   Y88..88P      Y88b 888 888  888      Y88b  d88P 888  888 888  888  888 888  888           ");
        linhaCol(30, 2); printf("    Y8P    \"Y888888  88888P'  \"Y8888P \"Y88P\"        \"Y88888 \"Y888888       \"Y8888P88 \"Y888888 888  888  888 \"Y888888  ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6);

        int linha = 9;
        int col = 9;
        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        for (int lin = linha; lin <= 31; lin ++) {
            linhaCol(lin, col);
            printf("\u2591\u2592\u2593");
            for (int control = 0; control <= 30; control ++) {
                printf("\u2588");
            }
            printf("\u2593\u2592\u2591");
            col += 3;
        }
        textColor(_WHITE, LIGHTRED);
        linhaCol(17, 56); printf("\u2588\u2588\u2588\u2588\u2588\u2588");
        linhaCol(18, 57); printf("\u2588\u2588\u2588\u2588");
        linhaCol(19, 53); printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588");
        linhaCol(20, 53); printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588");
        linhaCol(21, 57); printf("\u2588\u2588\u2588\u2588");
        linhaCol(22, 56); printf("\u2588\u2588\u2588\u2588\u2588\u2588");

        linhaCol(18, 53); printf("\u2588\u2588");
        linhaCol(18, 63); printf("\u2588\u2588");
        linhaCol(21, 53); printf("\u2588\u2588");
        linhaCol(21, 63); printf("\u2588\u2588");

        textColor(_BLACK, BROWN);
        linhaCol(10, 96); printf("*    *    *    *");
        linhaCol(12, 96); printf("*    *    *    *");

        textColor(_BLACK, WHITE);
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6);

        linhaCol(11, 14); printf(" .d88888b.        .d8888b.  8888888 .d8888b.         d8888 888b    888 88888888888 8888888888 ");
        linhaCol(12, 14); printf("d88P\" \"Y88b      d88P  Y88b   888  d88P  Y88b       d88888 8888b   888     888     888        ");
        linhaCol(13, 14); printf("888     888      888    888   888  888    888      d88P888 88888b  888     888     888        ");
        linhaCol(14, 14); printf("888     888      888          888  888            d88P 888 888Y88b 888     888     8888888    ");
        linhaCol(15, 14); printf("888     888      888  88888   888  888  88888    d88P  888 888 Y88b888     888     888        ");
        linhaCol(16, 14); printf("888     888      888    888   888  888    888   d88P   888 888  Y88888     888     888        ");
        linhaCol(17, 14); printf("Y88b. .d88P      Y88b  d88P   888  Y88b  d88P  d8888888888 888   Y8888     888     888        ");
        linhaCol(18, 14); printf(" \"Y88888P\"        \"Y8888P88 8888888 \"Y8888P88 d88P     888 888    Y888     888     8888888888");
        linhaCol(22, 14); printf("8888888b.        d8888       .d8888b.   .d88888b.  888      8888888 888b    888        d8888");
        linhaCol(23, 14); printf("888  \"Y88b      d88888      d88P  Y88b d88P\" \"Y88b 888        888   8888b   888       d88888");
        linhaCol(24, 14); printf("888    888     d88P888      888    888 888     888 888        888   88888b  888      d88P888");
        linhaCol(25, 14); printf("888    888    d88P 888      888        888     888 888        888   888Y88b 888     d88P 888");
        linhaCol(26, 14); printf("888    888   d88P  888      888        888     888 888        888   888 Y88b888    d88P  888");
        linhaCol(27, 14); printf("888    888  d88P   888      888    888 888     888 888        888   888  Y88888   d88P   888");
        linhaCol(28, 14); printf("888  .d88P d8888888888      Y88b  d88P Y88b. .d88P 888        888   888   Y8888  d8888888888");
        linhaCol(29, 14); printf("8888888P\" d88P     888       \"Y8888P\"   \"Y88888P\"  88888888 8888888 888    Y888 d88P     888");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6);

        linhaCol(16, 23); printf("       d8888 8888888b.  8888888888 888b    888        d8888  .d8888b.  888   ");
        linhaCol(17, 23); printf("      d88888 888   Y88b 888        8888b   888       d88888 d88P  Y88b 888   ");
        linhaCol(18, 23); printf("     d88P888 888    888 888        88888b  888      d88P888 Y88b.      888   ");
        linhaCol(19, 23); printf("    d88P 888 888   d88P 8888888    888Y88b 888     d88P 888  \"Y888b.   888  ");
        linhaCol(20, 23); printf("   d88P  888 8888888P\"  888        888 Y88b888    d88P  888     \"Y88b. 888 ");
        linhaCol(21, 23); printf("  d88P   888 888        888        888  Y88888   d88P   888       \"888 Y8P  ");
        linhaCol(22, 23); printf(" d8888888888 888        888        888   Y8888  d8888888888 Y88b  d88P  \"   ");
        linhaCol(23, 23); printf("d88P     888 888        8888888888 888    Y888 d88P     888  \"Y8888P\"  888 ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6);


        contador ++;
    }

    box(9, 1, 31, 119);

    linhaCol(10, 3); printf(" _____         _              _____              _        _____                      _        _____               ");
    linhaCol(11, 3); printf("|   __|___ ___| |_ ___ ___   |   __|___ ___    _| |___   |  |  |___ ___ ___ ___    _| |___   |   __|___ _____ ___ ");
    linhaCol(12, 3); printf("|   __| .'|_ -|  _| -_|  _|  |   __| . | . |  | . | . |  |  |  | .'|_ -|  _| . |  | . | .'|  |  |  | .'|     | .'|");
    linhaCol(13, 3); printf("|_____|__,|___|_| |___|_|    |_____|_  |_  |  |___|___|   \\___/|__,|___|___|___|  |___|__,|  |_____|__,|_|_|_|__,|");
    linhaCol(14, 3); printf("                                   |___|___|                                                                      ");

    linhaCol(16, 18); printf("Acalme-se, torcedor(a) flamenguista/tricolor/botafoguense ou de qualquer outro time!");

    linhaCol(19, 12); printf("Isso aqui foi uma brincadeira que eu quis adicionar ao Jogo do Braile! Foi bem divertido criá-lo");
    linhaCol(20, 13); printf("pois o Vasco da Gama sempre foi muito importante para a minha vida. Por fim, dedico esta minha");
    linhaCol(21, 15); printf("singela homenagem do Gigante da Colina ao meu pai, um grande vascaíno que me ensinou a ser");
    linhaCol(22, 33); printf("apaixonado pelo Legítimo Clube do Povo desde criança!");

    linhaCol(25, 3); printf("Espero que tenha gostado, e claro, respeito em primeiro lugar! Pressione Enter para continuar com o Jogo do Braile.");

    textColor(_BLACK, LIGHTRED);
    box(28, 5, 30, 115);
    linhaCol(29, 7); printf("O hino do Vasco em 8 bits foi criado pelo canal \"Clubes em 8-Bits\" no YouTube: https://youtu.be/tehFoER2e2E");
    textColor(_BLACK, WHITE);

    return 0;
}

DWORD WINAPI letra(LPVOID params){
    setlocale(LC_ALL, "Portuguese");

    Sleep(3000); //18180
    mudar = true;
    Sleep(3250);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3000);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3000);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3000);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2700);
    textColor(_BLACK, BROWN);

    linhaCol(37, 41); printf("    Vamos todos cantar de coração     ");
    textColor(_BLACK, WHITE);
    Sleep(3700); //18100
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    A Cruz de Malta é o meu pendão    ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3820); //21920
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf(" Tu tens o nome do heroico português  ");
    textColor(_BLACK, WHITE);
    Sleep(3740); //25660
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("Vasco da Gama, a tua fama assim se fez");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3980); //29640
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    Tua imensa torcida é bem feliz    ");
    textColor(_BLACK, WHITE);
    Sleep(3750); //33390
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("  Norte-Sul, Norte-Sul deste Brasil   ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3730); //37120
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("   Tua estrela, na terra a brilhar    ");
    textColor(_BLACK, WHITE);
    Sleep(3600); //40720
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("            Ilumina o mar             ");
    textColor(_BLACK, WHITE);
    mudar = true;


    Sleep(3750); //44470
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2700);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2650);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2650);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;

    Sleep(3050);//56130
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      No atletismo, és um braço       ");
    textColor(_BLACK, WHITE);
    Sleep(3500); //59630
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("         No remo, és imortal          ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3750); //63380
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       No futebol, és um traço        ");
    textColor(_BLACK, WHITE);
    Sleep(3270); //66650
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      De união Brasil-Portugal!       ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(4500); //71130
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      No atletismo, és um braço       ");
    textColor(_BLACK, WHITE);
    Sleep(3500); //59630
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("         No remo, és imortal          ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3750); //63380
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       No futebol, és um traço        ");
    textColor(_BLACK, WHITE);
    Sleep(3270); //66650
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      De união Brasil-Portugal!       ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3970); //86190
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3950); //94080
    mudar = true;
    Sleep(3890); //94080
    mudar = true;
    Sleep(1000); //94080
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                VASCO!                ");
    textColor(_BLACK, WHITE);
    Sleep(2000); //94080
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf(" Criado com carinho pelo vascaíno Gui ");
    textColor(_BLACK, WHITE);


    setlocale(LC_ALL, "C");
    return 0;
}

DWORD WINAPI redes(LPVOID params){
    int linha = 10, coluna = 9;
    textColor(WHITE, _BLACK);
    box(9, coluna - 2, 12, coluna + 56);
    linhaCol(linha, coluna + 1); printf("O código-fonte do jogo está disponível no repositório");
    linhaCol(linha + 1, coluna + 4); printf("\"https://github.com/gui-cordeiro/JogoDoBraile\"");
    linhaCol(linha + 4, coluna); printf("                  @@@@@@@@@@@@@@@@@@@                  ");
    linhaCol(linha + 5, coluna); printf("              @@@@@@@@@@@@@@@@@@@@@@@@@@@              ");
    linhaCol(linha + 6, coluna); printf("           @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@           ");
    linhaCol(linha + 7, coluna); printf("         @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@         ");
    linhaCol(linha + 8, coluna); printf("       @@@@@@@@                         @@@@@@@@       ");
    linhaCol(linha + 9, coluna); printf("      @@@@@@@@@                         @@@@@@@@@      ");
    linhaCol(linha + 10, coluna); printf("     @@@@@@@@@                           @@@@@@@@@     ");
    linhaCol(linha + 11, coluna); printf("     @@@@@@@@                             @@@@@@@@     ");
    linhaCol(linha + 12, coluna); printf("     @@@@@@@@                             @@@@@@@@     ");
    linhaCol(linha + 13, coluna); printf("     @@@@@@@@                             @@@@@@@@     ");
    linhaCol(linha + 14, coluna); printf("     @@@@@@@@@                           @@@@@@@@@     ");
    linhaCol(linha + 15, coluna); printf("      @@@@@@@@@@                       @@@@@@@@@@      ");
    linhaCol(linha + 16, coluna); printf("       @@@@   @@@@@@@@           @@@@@@@@@@@@@@@       ");
    linhaCol(linha + 17, coluna); printf("        @@@@@   @@@@@@           @@@@@@@@@@@@@@        ");
    linhaCol(linha + 18, coluna); printf("          @@@@@                  @@@@@@@@@@@@          ");
    linhaCol(linha + 19, coluna); printf("             @@@@@@@@@           @@@@@@@@@             ");
    linhaCol(linha + 20, coluna); printf("                @@@@@@           @@@@@@                ");

    while(1) {
        textColor(LIGHTBLUE, _BLACK);
        box(9, coluna + 68, 12, coluna + 100);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 73); printf("Twitter: @guis_cordeiro");
        linhaCol(linha + 4, coluna + 65); printf("                         ..::.          ");
        linhaCol(linha + 5, coluna + 65); printf("  :.                  ~G&@@@@@@#?..:75^ ");
        linhaCol(linha + 6, coluna + 65); printf(" .@@P:              :&@@@@@@@@@@@@@@&7:.");
        linhaCol(linha + 7, coluna + 65); printf(" ~@@@@#7.          .@@@@@@@@@@@@@@@@&#J ");
        linhaCol(linha + 8, coluna + 65); printf("  @@@@@@@&5~.      ?@@@@@@@@@@@@@@@@?   ");
        linhaCol(linha + 9, coluna + 65); printf("  .&@@@@@@@@@@&BPY?G@@@@@@@@@@@@@@@&    ");
        linhaCol(linha + 10, coluna + 65); printf(" :P?B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B    ");
        linhaCol(linha + 11, coluna + 65); printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@~    ");
        linhaCol(linha + 12, coluna + 65); printf("  .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B     ");
        linhaCol(linha + 13, coluna + 65); printf("    ^5&@@@@@@@@@@@@@@@@@@@@@@@@@@&.     ");
        linhaCol(linha + 14, coluna + 65); printf("    .G&@@@@@@@@@@@@@@@@@@@@@@@@@&.      ");
        linhaCol(linha + 15, coluna + 65); printf("     :B@@@@@@@@@@@@@@@@@@@@@@@@P        ");
        linhaCol(linha + 16, coluna + 65); printf("       .!5B&@@@@@@@@@@@@@@@@@#^         ");
        linhaCol(linha + 17, coluna + 65); printf("        .~5&@@@@@@@@@@@@@@@B^           ");
        linhaCol(linha + 18, coluna + 65); printf(".~?YPB#@@@@@@@@@@@@@@@@@B7.             ");
        linhaCol(linha + 19, coluna + 65); printf("  :!5B&@@@@@@@@@@@&#P7:                 ");
        linhaCol(linha + 20, coluna + 65); printf("        ...::::..                       ");
        textColor(WHITE, _BLACK);

        mudarRedes = true;
        Sleep(3000);
        mudarRedes = false;

        textColor(LIGHTMAGENTA, _BLACK);
        box(9, coluna + 68, 12, coluna + 100);

        textColor(BROWN, _BLACK);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 72); printf("Instagram: @gui.scordeiro");

        textColor(BLUE, _BLACK);
        linhaCol(linha + 4, coluna + 62); printf("           .~?Y55555555555555Y?~.           ");textColor(MAGENTA, _BLACK);
        linhaCol(linha + 5, coluna + 62); printf("        :P@@@@&&&&&&&&&&&&&&&&@@@@P:        ");
        linhaCol(linha + 6, coluna + 62); printf("      .B@@G~.                   ^G@@B.      ");
        linhaCol(linha + 7, coluna + 62); printf("     .&@&:                   7BB~ :&@&.     ");
        linhaCol(linha + 8, coluna + 62); printf("     G@@:        .~YGBBGY!.  B@@G  :@@G     ");
        linhaCol(linha + 9, coluna + 62); printf("     &@&       ^B@@@#GGB&@@#! ..    &@&     ");
        linhaCol(linha + 10, coluna + 62); printf("     &@&      5@@G:      .Y@@B      &@&     ");
        linhaCol(linha + 11, coluna + 62); printf("     &@&     7@@?          ^@@P     &@&     ");textColor(LIGHTMAGENTA, _BLACK);
        linhaCol(linha + 12, coluna + 62); printf("     &@&     B@@            &@&     &@&     ");
        linhaCol(linha + 13, coluna + 62); printf("     &@&     ?@@7          ^@@G     &@&     ");
        linhaCol(linha + 14, coluna + 62); printf("     &@&      P@@P.      .J@@#      &@&     ");
        linhaCol(linha + 15, coluna + 62); printf("     &@&       ~#@@&BPPG&@@&7       &@&     ");
        linhaCol(linha + 16, coluna + 62); printf("     G@@:        .!5B##BP7:        :@@G     ");textColor(RED, _BLACK);
        linhaCol(linha + 17, coluna + 62); printf("     .&@&:                        :&@&.     ");
        linhaCol(linha + 18, coluna + 62); printf("      .B@@G~.                  .~G@@B.      ");
        linhaCol(linha + 19, coluna + 62); printf("        :P@@@@&&&&&&&&&&&&&&&&@@@@P:        ");textColor(BROWN, _BLACK);
        linhaCol(linha + 20, coluna + 62); printf("           .~?Y55555555555555Y?~.           ");
        textColor(WHITE, _BLACK);

        mudarRedes = true;
        Sleep(3000);
        mudarRedes = false;

        textColor(BLUE, _BLACK);
        box(9, coluna + 68, 12, coluna + 100);

        textColor(BLUE, _BLACK);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 73); printf("LinkedIn: @gui-cordeiro");

        linhaCol(linha + 4, coluna + 66); printf(" .YB##P^                            ");
        linhaCol(linha + 5, coluna + 66); printf("~@@@@@@@Y                           ");
        linhaCol(linha + 6, coluna + 66); printf("?@@@@@@@#                           ");
        linhaCol(linha + 7, coluna + 66); printf(" J&@@@@P.                           ");
        linhaCol(linha + 8, coluna + 66); printf("   ...                              ");
        linhaCol(linha + 9, coluna + 66); printf(" ^^^^^^~     ^~^^^~:   ^7Y55Y?~.    ");
        linhaCol(linha + 10, coluna + 66); printf(" @@@@@@@~   .@@@@@@&:G@@@@@@@@@@#~  ");
        linhaCol(linha + 11, coluna + 66); printf(" @@@@@@@^   .@@@@@@@@@@@@@@@@@@@@@Y ");
        linhaCol(linha + 12, coluna + 66); printf(" @@@@@@@^   .@@@@@@@@@GJ?JB@@@@@@@@:");
        linhaCol(linha + 13, coluna + 66); printf(" @@@@@@@^   .@@@@@@@B      ^@@@@@@@?");
        linhaCol(linha + 14, coluna + 66); printf(" @@@@@@@^   .@@@@@@@:       #@@@@@@5");
        linhaCol(linha + 15, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 16, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 17, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 18, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 19, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 20, coluna + 66); printf(" B&####&:   .#&###&#.       Y&####&?");
        textColor(WHITE, _BLACK);

        mudarRedes = true;
        Sleep(3000);
        mudarRedes = false;
    }
}
