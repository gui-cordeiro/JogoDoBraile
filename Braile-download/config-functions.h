/*
 * -> C�digo-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
 */

bool mudar = false;

DWORD WINAPI e1(LPVOID params);
DWORD WINAPI letra(LPVOID params);

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
void exibirTelaGitHub(){
    //int tempo = 50;
    printf("\n\t\t\t   **** O c�digo-fonte deste jogo est� dispon�vel gratuitamente **** "); Sleep(tempo);
    printf("\n\t\t\t        no reposit�rio do GitHub de Guilherme Cordeiro. Acesse:  \n\n"); Sleep(tempo);
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
    box(17, 10, 29, 62);
    setlocale(LC_ALL, "C");
    linhaCol(17, 23); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Letra escrita em Braile");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);

    linhaCol(29, 17); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Marque a resposta correta � direita");
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

        linhaCol(26, 47); printf("Pr�ximo");
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
        printf("Voc� recebeu");
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
        linhaCol(21, 17); printf("Voc� escolheu: ");
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
        printf("Voc� recebeu");
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

/* C) TELA DE APRESENTA��O */
void apresentacao(){
    int tecla;
    system("cls");
    system("title Tela de t�tulo - Jogo do Braile 2.0");
    PlaySound(TEXT("..\\sounds\\intro.wav"), NULL, SND_ASYNC);
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

/* E) TELA DE CONFIRMA��O DE DIFICULDADE */
int confirmarJogo(char nivel[9], int progresso[26]) {
    int opt;
    int acertos = 0, erros = 0, pontos = 0;
    char lista[2][40] = {"SIM, eu quero jogar!", "N�O, eu quero voltar para o menu."};

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
    setlocale(LC_ALL, "Portuguese");
    topBannerContent(nivel);
    exibirLetras(nivel);
    if (strcmp("F�CIL", nivel) == 0) {
        box(11, 11, 13, 61);

        linhaCol(12, 13); printf("GRUPO DO ALFABETO PROPOSTO: \"VOGAIS\" - 5 letras");

        linhaCol(35, 5); printf("Vamos come�ar a jornada rumo � maestria no Braile? Nesta dificuldade, voc� dar� os seus primeiros passos com o");
        linhaCol(36, 4);printf("grupo das \"VOGAIS\". Pode parecer \"melzinho na chupeta\", mas ser� fundamental para o seu processo de aprendizado.");
    } else if (strcmp("M�DIO I", nivel) == 0) {
        box(11, 2, 13, 70);

        linhaCol(12, 4); printf("GRUPO PROPOSTO DO ALFABETO: 1� metade de \"CONSOANTES\" - 10 letras");

        linhaCol(35, 6); printf("Agora as coisas come�am a ficar mais s�rias! Aqui voc� ter� o primeiro contato com as \"CONSOANTES\", mas para");
        linhaCol(36, 4); printf("facilitar o aprendizado, dividiremos o grupo em duas partes, sendo que a 2� parte estar� l� no \"N�VEL M�DIO II\".");
    } else if (strcmp("M�DIO II", nivel) == 0) {
        box(11, 2, 13, 70);

        linhaCol(12, 4); printf("GRUPO DO ALFABETO PROPOSTO: 2� metade de \"CONSOANTES\" - 11 letras");

        linhaCol(35, 5); printf("Voc� est� quase completando o alfabeto inteiro, continue assim! Dando continuidade ao processo de aprendizagem,");
        linhaCol(36, 8); printf("nesta dificuldade voc� ver� a 2� parte das \"CONSOANTES\", sendo que a 1� parte est� l� no \"N�VEL M�DIO I\".");
    } else if (strcmp("DIF�CIL", nivel) == 0) {
        box(11, 5, 13, 67);

        linhaCol(12, 7); printf("GRUPO DO ALFABETO PROPOSTO: \"ALFABETO COMPLETO\" - 26 letras");

        linhaCol(33, 30); printf("[RECOMENDA-SE JOGAR OS OUTROS MODOS ANTES DE JOGAR ESTE AQUI]");
        linhaCol(35, 5); printf("O teste supremo! O \"Gran Finale\"! Coloque � prova todo o conhecimento adquirido at� aqui para provar de uma vez");
        linhaCol(36, 7); printf("por todas se voc� realmente adquiriu o dom�nio do Braile com maestria. Ah, n�o vamos pegar leve dessa vez!");
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

    if (opt == 2) {
        cleanScreen(1);
        return 0;
    }

    cleanScreen(4);
    topBannerContent(nivel);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    PlaySound(TEXT("..\\sounds\\getready.wav"), NULL, SND_ASYNC);
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
    printf("DICA: Acompanhe o seu progresso de acertos e erros atrav�s da barra situada logo abaixo");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    currentProgressionBanner(nivel, progresso, acertos, erros, pontos);
    //linhaCol(37, 41);
    //getchar();

    int tecla = 0, easter = 0;
    while(1){
        tecla = getch();
        if (tecla == 0 || tecla == 224) tecla = getch();

        if (easter == 0) {
            if (tecla == 118 || tecla == 86) easter ++;
            else easter = 0;
        } else if (easter == 1){
            if (tecla == 97 || tecla == 65) easter ++;
            else easter = 0;
         }else if (easter == 2) {
            if (tecla == 115 || tecla == 83) easter ++;
            else easter = 0;
        }else if (easter == 3) {
            if (tecla == 99 || tecla == 67) easter ++;
            else easter = 0;
        }else if (easter == 4) {
            if (tecla == 111 || tecla == 79) easter ++;
            else easter = 0;
        }



        if (easter == 5) {
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
            easter = 0;
            while(1){
                tecla = getch();
                if (tecla == 0 || tecla == 224) tecla = getch();
                if (tecla == 13) break;
            }
            PlaySound(TEXT("..\\sounds\\nosound.wav"), NULL, SND_ASYNC);
            currentProgressionBanner(nivel, progresso, acertos, erros, pontos);
        }
        if (tecla == 13) break; // Tecla Enter
    }

    TerminateThread(hThread, 0x0);
    TerminateThread(hThread2, 0x0);

    CloseHandle(hThread);
    CloseHandle(hThread2);

    cleanScreen(6);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    return 1;
}

/* H) FIM DO JOGO (TABELA DE ESTAT�STICAS) */
void fimJogo(char nivel[9], int pts, int acertos, int numPerg){

    /*C�digo do sistema de Ranking - Futuro*/

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

    if(((strcmp(nivel, "F�CIL") == 0 && acertos <= 2) || (strcmp(nivel, "M�DIO I") == 0 && acertos <= 3)) || ((strcmp(nivel, "M�DIO II") == 0 && acertos <= 4) || (strcmp(nivel, "DIF�CIL") == 0 && acertos <= 8))){
        printf("\t\t\t+----------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t| N�o se frustre! Errar faz parte, e � somente errando que se aprende! |\n");Sleep(tempo);
        printf("\t\t\t+----------------------------------------------------------------------+\n");Sleep(tempo);
    }

    else if(((strcmp(nivel, "F�CIL") == 0 && acertos <= 3) || (strcmp(nivel, "M�DIO I") == 0 && acertos <= 6)) || ((strcmp(nivel, "M�DIO II") == 0 && acertos <= 7) || (strcmp(nivel, "DIF�CIL") == 0 && acertos <= 16))){
        printf("\t\t\t  +-----------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t  | Voc� est� indo no caminho certo! Continue firme, voc� consegue! |\n");Sleep(tempo);
        printf("\t\t\t  +-----------------------------------------------------------------+\n");Sleep(tempo);
    }

    else if(((strcmp(nivel, "F�CIL") == 0 && acertos <= 4) || (strcmp(nivel, "M�DIO I") == 0 && acertos <= 9)) || ((strcmp(nivel, "M�DIO II") == 0 && acertos <= 10) || (strcmp(nivel, "DIF�CIL") == 0 && acertos <= 25))){
        printf("\t\t\t   +---------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t   | Muito bem! A perseveran�a � a chave, ent�o continue tentando! |\n");
        printf("\t\t\t   +---------------------------------------------------------------+\n");Sleep(tempo);
    }

    else if(((strcmp(nivel, "F�CIL") == 0 && acertos == 5) || (strcmp(nivel, "M�DIO I") == 0 && acertos == 10)) || ((strcmp(nivel, "M�DIO II") == 0 && acertos == 11) || (strcmp(nivel, "DIF�CIL") == 0 && acertos == 26))){
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t | Meus parab�ns, voc� acertou TODAS AS QUEST�ES! � assim que se faz! |\n");Sleep(tempo);
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
    } else {
        printf("\t\t\t +--------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t\t\t | [ERRO] Dificuldade n�o condiz com o n�mero de acertos.             |\n");Sleep(tempo);
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
    if (strcmp(nivel, "F�CIL") == 0 && acertos == 5) {
        printf("\t\t  * ESSA FOI F�CIL! MAS AGORA AS COISAS V�O DIFICULTAR UM POUCO: EXPERIMENTE AGORA O: *\n");Sleep(1500);
        exibirBannerDificuldade("M�DIO I");
        addFade(1, 1000, 1);
        printf("\t\t\t\t\t    * Selecione no menu principal! *");Sleep(1000);
    } else if (strcmp(nivel, "M�DIO I") == 0 && acertos == 10) {
        printf("\t\t\t\t * SIGA ADIANTE! CONTINUE O SEU APRENDIZADO JOGANDO O: *\n");Sleep(2000);
        exibirBannerDificuldade("M�DIO II");
        addFade(1, 1000, 1);
        printf("\t\t\t\t\t    * Selecione no menu principal! *");Sleep(1000);
    } else if (strcmp(nivel, "M�DIO II") == 0 && acertos == 11) {
        printf("\t\t  * BOM TRABALHO, AGORA V� ADIANTE AO SEU �LTIMO DESAFIO! AO INIGUAL�VEL, AO TEM�VEL: *\n");Sleep(2000);
        exibirBannerDificuldade("DIF�CIL");
        addFade(1, 1000, 1);
        printf("\t\t\t\t\t    * Selecione no menu principal! *");Sleep(1000);
    } else if (strcmp(nivel, "DIF�CIL") == 0 && acertos == 26) {
        printf("\t\t\t  * MEUS PARAB�NS! VOC� PROVOU COM MAESTRIA QUE � EXPERT NO BRAILE! *\n");Sleep(2000);
        exibirBannerDificuldade("AGRADECIMENTO");
    } else {
        printf("\t\t\t\t\t  * BOA TENTATIVA. TENTE NOVAMENTE! *\n");Sleep(1000);
        exibirBannerDificuldade("N�O DESISTA");
        addFade(1, 1000, 1);
        printf("\t\t\t       \"A persist�ncia � o caminho do �xito\". Continue tentando! ");Sleep(1500);
    }
    addFade(4, tempo, 1);
    printf("\t\t\t\t\t\t\t  ***");Sleep(tempo);
    addFade(3, tempo, 1);
    banner();
    addFade(1, tempo, 1);
    printf("\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    if (((strcmp(nivel, "F�CIL") == 0 && acertos == 5) || (strcmp(nivel, "M�DIO I") == 0 && acertos == 10)) || ((strcmp(nivel, "M�DIO II") == 0 && acertos == 11) || (strcmp(nivel, "DIF�CIL") == 0 && acertos == 26))){
        addFade(9, 0, 0);
        addFade(30, 25, 1);
    } else {
        addFade(8, 0, 0);
        addFade(31, 25, 1);
    }
    system("cls");
    return;
}

/* I) ANIMA��O DE TRANSI��O DE TELA */
void addFade(int rep, int millis, int isLento){
    for(int cont = 0; cont < rep; cont ++){
            printf("\n");
            if(isLento != 0) Sleep(millis);
    }
}

/* J) BANNER DE APRESENTA��O */
void banner(){
    //int tempo = 50;
    printf("\n\t\t\t\t     +-------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t     |        Jogo do Braile - 2017, %d        |", obterAnoAtual());Sleep(tempo);
    printf("\n\t\t\t\t     +-------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t     |      Criado por: Guilherme Cordeiro       |");Sleep(tempo);
    printf("\n\t\t\t\t     +-------------------------------------------+\n");Sleep(tempo);
    return;
}

/* K) TELA DE ERRO (AO DIGITAR UMA OP��O ERRADA) */
void telaErro(){
    //int tempo = 50;
    printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t      |                       * ATEN��O *                       |\n");Sleep(tempo);
    printf("\t\t\t      +---------------------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t      | Op��o inv�lida. Siga as instru��es especificadas abaixo |\n");Sleep(tempo);
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

/* M) CONFIGURA��ES INICIAIS DO JOGO  */
void configJogo(){
    int largura = 89;
    int altura = 8;
    hideCursor();
    setlocale(LC_ALL,"Portuguese");
    system("mode con:cols=119 lines=38");
    system("color 0f");
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

/* O) RETORNA T�TULO DO CONSOLE PERSONALIZADO */
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

/* P) VERIFICA SE A OP��O EST� CORRETA (RETORNO 0=ERRO, 1=SIM, 2=N�O) */
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

/* Q) RETORNA O BANNER CORRESPONDENTE AO N�MERO DA PERGUNTA */
void exibirBannerPergunta(int questao){
    setlocale(LC_ALL, "C");
    linhaCol(2, 28); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" VOC� EST� NA ");
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

/* R) RETORNA O BANNER CORRESPONDENTE � DIFICULDADE */
void exibirBannerDificuldade(char nivel[20]){
    if (strcmp(nivel, "MENU") == 0) {
        setlocale(LC_ALL, "C");
        linhaCol(2, 28); printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        printf(" VOC� EST� NO ");
        setlocale(LC_ALL, "C");
        printf("%c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(3, 9); printf(" _____                 _____     _         _         _ ");
        linhaCol(4, 9); printf("|     |___ ___ _ _    |  _  |___|_|___ ___|_|___ ___| |");
        linhaCol(5, 9); printf("| | | | -_|   | | |   |   __|  _| |   |  _| | . | .'| |");
        linhaCol(6, 9); printf("|_|_|_|___|_|_|___|   |__|  |_| |_|_|_|___|_|  _|__,|_|");
        linhaCol(7, 9); printf("                                            |_|        ");
    } else if (strcmp(nivel, "F�CIL") == 0) {
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
    } else if (strcmp(nivel, "M�DIO I") == 0) {
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
    } else if (strcmp(nivel, "M�DIO II") == 0) {
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
    } else if (strcmp(nivel, "DIF�CIL") == 0) {
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
    } else if (strcmp(nivel, "N�O DESISTA") == 0) {
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

/* S) GERA A SEQU�NCIA DE EXIBI��O DAS PERGUNTAS DE MANEIRA ALEAT�RIA */
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
        // O n�mero gerado foi o 0? Se sim, descarta.
        if (numGerado == 0) {
            continue;
        }
        // Verifica se o vetor j� cont�m tal n�mero gerado. Se tiver, descarta. Se n�o tiver, armazena.
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

/* T) GERA UMA LETRA ALEATORIA PARA FORMAR AS OP��ES DAS ALTERNATIVAS, DE ACORDO COM A DIFICULDADE SELECIONADA */
char gerarLetra(char dificuldade[8]){
    if (dificuldade == "F�CIL") {
        char letras[5] = {'a', 'e', 'i', 'o', 'u'};
        return letras[rand() % 5];
    } else if (dificuldade == "M�DIO I") {
        char letras[10] = {'b', 'c', 'd', 'f', 'g',
            'h', 'j', 'k', 'l', 'm'};
        return letras[rand() % 10];
    } else if (dificuldade == "M�DIO II") {
        char letras[11] = {'n', 'p', 'q', 'r', 's',
            't', 'v', 'w', 'x', 'y', 'z'};
        return letras[rand() % 11];
    } else if (dificuldade == "DIF�CIL") {
        char letras[26] = {'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's' ,'t', 'u',
            'v', 'w', 'x', 'y', 'z'};
        return letras[rand() % 26];
    }
    return ' ';
}

/* U) GERA A SEQU�NCIA DE ALTERNATIVAS DAS PERGUNTAS DE MANEIRA ALEAT�RIA */
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
            //printf("Descartado! A letra gerada � igual a da resposta ou j� foi apresentada na pergunta anterior!\n");
            continue;
        }
        for (c = 0; c < 3; c ++) {
            if (alt[c] == toupper(altGerada)) {
                //printf("Descartado! A letra gerada j� existe no vetor!\n");
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

    //Definindo os v�rtices da caixa
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

void topBannerContent(char titulo[20]) {
    exibirBannerDificuldade(titulo);

    setlocale(LC_ALL, "C");
    linhaCol(2, 80); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" A��ES DISPON�VEIS NESTA TELA ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);

    int refer = 75;

    box(3, refer + 4, 5, refer + 8);
    box(5, refer + 4, 7, refer + 8);
    box(5, refer, 7, refer + 4); //Seta pra esquerda
    box(5, refer + 8, 7, refer + 12);

    //Jun��es
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
        printf(" Descri��o:");
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
            linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade \"F�cil\".");
            break;
        case 2:
            linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade \"M�dio I\".");
            break;
        case 3:
            linhaCol(35, 36); printf("Jogue o Jogo do Braile na dificuldade \"M�dio II\".");
            break;
        case 4:
            linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade \"Dif�cil\".");
            break;
        case 5:
            linhaCol(35, 31); printf("Consulte a pontua��o de todos os jogadores salvos no seu PC.");
            break;
        case 6:
            linhaCol(35, 40); printf("Consulte as instru��es do Jogo do Braile");
            linhaCol(36, 37); printf("(e veja tamb�m um passo-a-passo de como jogar).");
            break;
        case 7:
            linhaCol(35, 32); printf("Acesse os cr�ditos do projeto \"Jogo do Braile\". Voc� ver�:");
            linhaCol(36, 8); printf("1) O motivo inicial do projeto; 2) As pessoas envolvidas na �poca; e 3) Contato do desenvolvedor do jogo.");
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
                if (coluna != 72) { // Divis�ria do Banner
                    linhaCol(linha, coluna); printf(" ");
                }
            }
        }
    }

    //Conte�do do Meio
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

    //Banner Inferior (Rodap�)
    if ((opt == 1 || opt == 3) || (opt == 4 || opt == 7)) {
        for (linha = 33; linha < 37; linha ++) {
            for (coluna = 2; coluna < 119; coluna ++) {
                if (linha == 33 && coluna < 23) { // T�tulo do Banner
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
            if (strcmp(nivel, "F�CIL") == 0) {
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
            } else if (strcmp(nivel, "M�DIO I") == 0) {
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
            } else if (strcmp(nivel, "M�DIO II") == 0) {
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
            } else if (strcmp(nivel, "DIF�CIL") == 0) {
                textColor(BLACK, _WHITE);
            }
            box(linha, coluna, linha + 2, coluna + 4);
            linhaCol(linha + 1, coluna + 2); printf("%c", toupper(letras[contLetras]));
            contLetras ++;
        }
    }
    for (int coluna = 6; coluna < 65; coluna += 8) {
        if (strcmp(nivel, "F�CIL") == 0) {
            switch(contLetras) {
                case 20:
                    textColor(BLACK, _WHITE);
                    break;
                default:
                    textColor(WHITE, _BLACK);
            }
        } else if (strcmp(nivel, "M�DIO II") == 0) {
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
        } else if (strcmp(nivel, "DIF�CIL") == 0) {
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

    //Tamanho m�ximo dos itens
    for(i = 1; i < qtd; i ++) {
        tamMaxItem = (strlen(lista[i]) > tamMaxItem) ? strlen(lista[i]) : tamMaxItem;
    }

    lin2 = lin1 + (qtd * 2 + 2);
    col2 = col1 + tamMaxItem + 3;

    //Montando a tela do menu
    textColor(WHITE, _BLUE);

    box(lin1, col1, lin2, col2);


    //La�o das op��es
    while(1){
        linhaSelecionada = lin1 + 2;
        for(i = 0; i < qtd; i ++) {
            if((i + 1) == opt) {
                textColor(BLUE, _WHITE);
                //PlaySound(TEXT("..\\sounds\\select.wav"), NULL, SND_ASYNC);
            } else {
                textColor(WHITE, _BLUE);
            }
            espacamento = (tamMaxItem - strlen(lista[i])) / 2; //Criar espa�amento para centralizar op��es no menu
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
    bool perguntaAtual = false;
    setlocale(LC_ALL, "C");
    if (strcmp(difficulty, "F�CIL") == 0) {
        numPerg = 5;
        numBar = 16;
        numColuna = 28;
    } else if (strcmp(difficulty, "M�DIO I") == 0) {
        numPerg = 10;
        numBar = 8;
        numColuna = 24;
    } else if (strcmp(difficulty, "M�DIO II") == 0) {
        numPerg = 11;
        numBar = 8;
        numColuna = 20;
    } else if (strcmp(difficulty, "DIF�CIL") == 0) {
        numPerg = 26;
        numColuna = 10;
    }

    for (cont = 0; cont < numPerg; cont ++) {
        if (strcmp(difficulty, "DIF�CIL") == 0) {
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
            textColor(GREEN, _BLACK);
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

        if (strcmp(difficulty, "DIF�CIL") == 0) {
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
            if (strcmp(difficulty, "DIF�CIL") == 0) {
                printf("%c", 205);
            } else {
                for (int barras = 0; barras < numBar / 2; barras ++) {
                    printf("%c", 205);
                }
            }
        }

        printf("%c", 254);

        if (cont != numPerg - 1) {
            if (strcmp(difficulty, "DIF�CIL") == 0) {
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
    if (acertos < 10) printf("0");
    printf("%d %c ERROS: ", acertos, 179);
    if (erros < 10) printf("0");
    printf("%d %c PONTOS: ", erros, 179);
    if (pontos < 10) printf("000");
    else if (pontos < 100) printf("00");
    else if (pontos < 1000) printf("0");
    printf("%d", pontos);
    setlocale(LC_ALL, "Portuguese");
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

    linhaCol(19, 12); printf("Isso aqui foi uma brincadeira que eu quis adicionar ao Jogo do Braile! Foi bem divertido cri�-lo");
    linhaCol(20, 13); printf("pois o Vasco da Gama sempre foi muito importante para a minha vida. Por fim, dedico esta minha");
    linhaCol(21, 15); printf("singela homenagem do Gigante da Colina ao meu pai, um grande vasca�no que me ensinou a ser");
    linhaCol(22, 33); printf("apaixonado pelo Leg�timo Clube do Povo desde crian�a!");

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

    linhaCol(37, 41); printf("    Vamos todos cantar de cora��o     ");
    textColor(_BLACK, WHITE);
    Sleep(3700); //18100
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    A Cruz de Malta � o meu pend�o    ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3820); //21920
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf(" Tu tens o nome do heroico portugu�s  ");
    textColor(_BLACK, WHITE);
    Sleep(3740); //25660
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("Vasco da Gama, a tua fama assim se fez");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3980); //29640
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    Tua imensa torcida � bem feliz    ");
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
    linhaCol(37, 41); printf("      No atletismo, �s um bra�o       ");
    textColor(_BLACK, WHITE);
    Sleep(3500); //59630
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("         No remo, �s imortal          ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3750); //63380
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       No futebol, �s um tra�o        ");
    textColor(_BLACK, WHITE);
    Sleep(3270); //66650
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      De uni�o Brasil-Portugal!       ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(4500); //71130
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      No atletismo, �s um bra�o       ");
    textColor(_BLACK, WHITE);
    Sleep(3500); //59630
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("         No remo, �s imortal          ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3750); //63380
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       No futebol, �s um tra�o        ");
    textColor(_BLACK, WHITE);
    Sleep(3270); //66650
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      De uni�o Brasil-Portugal!       ");
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
    linhaCol(37, 41); printf(" Criado com carinho pelo vasca�no Gui ");
    textColor(_BLACK, WHITE);


    setlocale(LC_ALL, "C");
    return 0;
}




