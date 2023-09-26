/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
 */

/* A) TELA DO GITHUB */
void exibirTelaRedes(int endOfGame, char nivel[8]){

    DWORD threadId;
    DWORD threadId2;
    HANDLE hThread;
    HANDLE hThread2;

    hThread = CreateThread(NULL, 0x0, redes, NULL, 0, &threadId);

    if (endOfGame == 0) {
        Sleep(350);
        if (strcmp(nivel, "DIFÍCIL") != 0) hThread2 = CreateThread(NULL, 0x0, bannerEncerramento, NULL, 0, &threadId2);
        else {
            textColor(BROWN, _BLACK);
            setlocale(LC_ALL, "C");
            linhaCol(35, 35); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese");
            printf("Pressione Enter para retornar ao Menu Principal");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese");
            textColor(WHITE, _BLACK);
        }
    } else if (endOfGame == 1){
        Sleep(2450);
        textColor(BROWN, _BLACK);
        box(34, 36, 36, 86);
        setlocale(LC_ALL, "C");
        linhaCol(35, 38); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Pressione Enter para sair do Jogo do Braile");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        textColor(WHITE, _BLACK);
    } else if (endOfGame == 2) {
        Sleep(350);
        textColor(BROWN, _BLACK);
        exibirBannerDificuldade("Pressione Enter para retornar ao Menu", 35, 11, "NÃO DESISTA", 32, 64);
        textColor(WHITE, _BLACK);
    }
    pressEnter();

    if (mudarRedes != true) Sleep(100);
    TerminateThread(hThread, 0x0);
    TerminateThread(hThread2, 0x0);
    CloseHandle(hThread);
    CloseHandle(hThread2);

    return;
}

/* B) MODELO DAS PERGUNTAS */
bool newPergunta(char dificuldade[8], int questao, char letrResp1, char letrResp2, char letrResp3, char letrResp4, char letrResp5, int *acertos, int *erros, int *pts, int progresso[26]){
    char altResposta;
    bool acertoCont = false;
    int tecla = 0;
    int posCorreta;
    char opt;

    char lista[5][40];
    char alt[5] = {' ', ' ', ' ', ' ', ' '};
    if (strcmp(dificuldade, "DIFÍCIL") != 0) {
        alt[4] = '-';
        posCorreta = rand() % 4;
    } else {
        posCorreta = rand() % 5;
    }
    alt[posCorreta] = letrResp3;
    int totAcertos = *acertos;
    int totErros = *erros;
    int totPts = *pts;
    if (posCorreta == 0) {
        altResposta = 'a';
    } else if (posCorreta == 1) {
        altResposta = 'b';
    } else if (posCorreta == 2) {
        altResposta = 'c';
    } else if (posCorreta == 3) {
        altResposta = 'd';
    } else if (posCorreta == 4) {
        altResposta = 'e';
    }
    gerarSeqAlt(dificuldade, alt, letrResp3, letrResp2);
    sprintf(lista[0], " a) Letra %c ", alt[0]);
    sprintf(lista[1], " b) Letra %c ", alt[1]);
    sprintf(lista[2], " c) Letra %c ", alt[2]);
    sprintf(lista[3], " d) Letra %c ", alt[3]);
    if (strcmp(dificuldade, "DIFÍCIL") == 0) sprintf(lista[4], " e) Letra %c ", alt[4]);

    cleanScreen(5, false);
    topBannerContent("-", 0, 0, "-", 0, 0, 3);
    exibirBannerPergunta(questao);

    setlocale(LC_ALL, "C");
    linhaCol(8,72);printf("%c", 197);
    for (int divisoria = 9; divisoria < 32; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(32,72);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese");

    exibirBannerPergunta(27); //Banner do "Que letra é essa?"
    linhaCol(15, 18); printf("(Marque a ");
    textColor(LIGHTBLUE, _BLACK);
    printf("resposta correta");
    textColor(WHITE, _BLACK);
    printf(" à direita)");

    exibirBannerPergunta(0); //Banner do "Resposta:"
    linhaCol(15, 77); printf("(Use as ações especificadas logo acima)");

    textColor(BROWN, BLACK);
    if (strcmp(dificuldade, "DIFÍCIL") != 0) box(18, 12, 28, 60);
    else box(18, 5, 28, 67);
    setlocale(LC_ALL, "C");
    linhaCol(18, 22); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Letras escritas em Braile");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);

    printAlfabeto(letrResp3, 22, 35, 0);

    linhaCol(26, 34); printf("ATUAL");

    // Letras anteriores à atual
    if (letrResp1 != '-' && strcmp(dificuldade, "DIFÍCIL") == 0) {
        setlocale(LC_ALL, "C");
        textColor(DARKGRAY, _BLACK);
        linhaCol(23, 18); printf("%c", 174);
        setlocale(LC_ALL, "Portuguese");

        printAlfabeto(letrResp1, 22, 11, 1);
        linhaCol(26, 11); printf("-2");
    }
    if (letrResp2 != '-') {
        setlocale(LC_ALL, "C");
        textColor(BROWN, BLACK);
        linhaCol(23, 30); printf("%c", 174);
        setlocale(LC_ALL, "Portuguese");
        textColor(DARKGRAY, _BLACK);

        printAlfabeto(letrResp2, 22, 23, 1);
        linhaCol(26, 21); printf("Anterior");
    }
    // Letras após à atual
    if (letrResp4 != '-') {
        textColor(BROWN, BLACK);
        setlocale(LC_ALL, "C");
        linhaCol(23, 42); printf("%c", 175);
        setlocale(LC_ALL, "Portuguese");
        textColor(DARKGRAY, _BLACK);

        printAlfabeto(letrResp4, 22, 47, 0);

        setlocale(LC_ALL, "Portuguese");
        linhaCol(26, 45); printf("Próximo");
    }
    if (letrResp5 != '-' && strcmp(dificuldade, "DIFÍCIL") == 0) {
        setlocale(LC_ALL, "C");
        textColor(DARKGRAY, _BLACK);
        linhaCol(23, 54); printf("%c", 175);
        setlocale(LC_ALL, "Portuguese");

        printAlfabeto(letrResp5, 22, 59, 0);
        linhaCol(26, 59); printf("+2");
    }

    textColor(WHITE, _BLACK);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    if (strcmp(dificuldade, "DIFÍCIL") != 0) {
        linhaCol(17, 95); printf("\u25b2");
        linhaCol(29, 95); printf("\u25bc");
        textColor(WHITE, _BLUE);
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");
        opt = modeloMenu(18, 88, 4, 0, lista);
    } else {
        linhaCol(16, 95); printf("\u25b2");
        linhaCol(30, 95); printf("\u25bc");
        textColor(WHITE, _BLUE);
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");
        opt = modeloMenu(17, 88, 5, 0, lista);
    }

    //cleanScreen(6, false);
    if (opt - 1 == posCorreta) {
        acertoCont = true;
        totPts += 150;
        totAcertos ++;
        progresso[questao - 1] = 1;

        textColor(LIGHTGREEN, _BLACK);
        box(9, 1, 31, 119);
        //box(9, 18, 31, 102);

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
        printAlfabeto(letrResp3, 21, 51, 1);
        setlocale(LC_ALL, "C");

        linhaCol(18, 59); printf("%c", 194);
        for (int cont = 0; cont <= 6; cont ++) {
            linhaCol(19 + cont, 59); printf("%c", 179);
        }
        linhaCol(25, 59); printf("%c", 193);

        /*linhaCol(19, 67); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Você recebeu");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");*/
        linhaCol(19, 64); printf("   _   ___   ___ ___ ");
        linhaCol(20, 64); printf(" _| |_|_  | |  _|   |");
        linhaCol(21, 64); printf("|_   _|_| |_|_  | | |");
        linhaCol(22, 64); printf("  |_| |_____|___|___|");
        linhaCol(24, 66); printf("PONTOS ADICIONADOS");

        topBannerContent("-", 0, 0, "-", 0, 0, 4);
        PlaySound(TEXT("..\\sounds\\win.wav"), NULL, SND_ASYNC);
    } else {
        totPts += 50;
        totErros ++;
        progresso[questao - 1] = 0;

        textColor(LIGHTRED, _BLACK);
        box(9, 1, 31, 119);
        //box(9, 11, 31, 109);

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

        box(18, 15, 25, 105);
        linhaCol(21, 18); printf("Você escolheu: ");
        printAlfabeto(alt[opt - 1], 21, 37, 1);
        setlocale(LC_ALL, "C");

        linhaCol(18, 45); printf("%c", 194);
        linhaCol(18, 75); printf("%c", 194);
        for (int cont = 0; cont <= 6; cont ++) {
            linhaCol(19 + cont, 45); printf("%c", 179);
            linhaCol(19 + cont, 75); printf("%c", 179);
        }
        linhaCol(25, 45); printf("%c", 193);
        linhaCol(25, 75); printf("%c", 193);

        linhaCol(21, 49); printf(" A resposta");
        linhaCol(22, 49); printf("correta era:");
        printAlfabeto(letrResp3, 21, 67, 1);

        /*setlocale(LC_ALL, "C");
        linhaCol(20, 82); printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Você recebeu");
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(22, 79); printf("+1 ERRO  E  +50 PONTOS.");*/

        linhaCol(19, 82); printf("   _    ___ ___ ");
        linhaCol(20, 82); printf(" _| |_ |  _|   |");
        linhaCol(21, 82); printf("|_   _||_  | | |");
        linhaCol(22, 82); printf("  |_|  |___|___|");
        linhaCol(24, 81); printf("PONTOS ADICIONADOS");

        topBannerContent("-", 0, 0, "-", 0, 0, 4);
        PlaySound(TEXT("..\\sounds\\lose.wav"), NULL, SND_ASYNC);
    }

    currentProgressionBanner(dificuldade, progresso, totAcertos, totErros, totPts);

    *acertos = totAcertos;
    *erros = totErros;
    *pts = totPts;

    pressEnter();

    cleanScreen(6, false);
    textColor(WHITE, _BLACK);
    return acertoCont;
}

/* C) TELA DE APRESENTAÇÃO */
void apresentacao(){
    int tecla;
    system("cls");
    titulo("-", "Tela de título");
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
    topBannerDesign();
    bottomBannerDesign();
    return;
}

/* D) ALFABETO EM BRAILE */
void printAlfabeto(char letra, int lin1, int col, int isVisible){ //0) Insere "?"; 1) Insere letra correspondente; 2) Não insere nada
    //int tempo = 50;
    int lin2 = lin1 + 1, lin3 = lin1 + 2;
    box(lin1 - 1, col - 2, lin1 + 3, col + 4);
    if (isVisible >= 0 && isVisible <= 1) {
        linhaCol(lin1 - 2, col + 1);
        if (isVisible == 1) printf("%c", letra);
        else printf("?");
    }
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "C");
    switch(tolower(letra)){
        case 'a':
            linhaCol(lin1, col); printf("\u25cf \u25cb"); //cf de círculo cheio (full), cb de círculo vazio (em "branco", vazio)
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'b':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'c':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'd':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'e':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'f':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'g':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'h':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'i':
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'j':
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cb");
            break;
        case 'k':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'l':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'm':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'n':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'o':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'p':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'q':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'r':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 's':
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 't':
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cb");
            break;
        case 'u':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'v':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cf \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'w':
            linhaCol(lin1, col); printf("\u25cb \u25cf");
            linhaCol(lin2, col); printf("\u25cf \u25cf");
            linhaCol(lin3, col); printf("\u25cb \u25cf");
            break;
        case 'x':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cb");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'y':
            linhaCol(lin1, col); printf("\u25cf \u25cf");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
        case 'z':
            linhaCol(lin1, col); printf("\u25cf \u25cb");
            linhaCol(lin2, col); printf("\u25cb \u25cf");
            linhaCol(lin3, col); printf("\u25cf \u25cf");
            break;
    }
    SetConsoleOutputCP(850);
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

    cleanScreen(1, false);
    //PlaySound(TEXT("..\\sounds\\confirm-difficulty.wav"), NULL, SND_LOOP | SND_ASYNC);
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
    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, nivel, 3, colBanner, 2);

    setlocale(LC_ALL, "Portuguese");
    exibirLetras(nivel);
    if (strcmp("FÁCIL", nivel) == 0) {
        box(11, 11, 13, 61);

        linhaCol(12, 13); printf("GRUPO DO ALFABETO PROPOSTO: ");
        textColor(BROWN, _BLACK);
        printf("\"VOGAIS\"");
        textColor(WHITE, _BLACK);
        printf(" - ");
        textColor(GREEN, _BLACK);
        printf("5 letras");
        textColor(WHITE, _BLACK);

        linhaCol(35, 5); printf("Vamos começar a jornada rumo à maestria no Braile? Nesta dificuldade, você dará os seus primeiros passos com o");
        linhaCol(36, 4);printf("grupo das \"VOGAIS\". Pode parecer \"melzinho na chupeta\", mas será fundamental para o seu processo de aprendizado.");
    } else if (strcmp("MÉDIO I", nivel) == 0) {
        box(11, 2, 13, 70);

        linhaCol(12, 4); printf("GRUPO PROPOSTO DO ALFABETO: ");
        textColor(BROWN, _BLACK);
        printf("1º metade de \"CONSOANTES\"");
        textColor(WHITE, _BLACK);
        printf(" - ");
        textColor(LIGHTBLUE, _BLACK);
        printf("10 letras");
        textColor(WHITE, _BLACK);

        linhaCol(35, 6); printf("Agora as coisas começam a ficar mais sérias! Aqui você terá o primeiro contato com as \"CONSOANTES\", mas para");
        linhaCol(36, 4); printf("facilitar o aprendizado, dividiremos o grupo em duas partes, sendo que a 2º parte estará lá no \"NÍVEL MÉDIO II\".");
    } else if (strcmp("MÉDIO II", nivel) == 0) {
        box(11, 2, 13, 70);

        linhaCol(12, 4); printf("GRUPO DO ALFABETO PROPOSTO: ");
        textColor(BROWN, _BLACK);
        printf("2º metade de \"CONSOANTES\"");
        textColor(WHITE, _BLACK);
        printf(" - ");
        textColor(LIGHTMAGENTA, _BLACK);
        printf("11 letras");
        textColor(WHITE, _BLACK);

        linhaCol(35, 5); printf("Você está quase completando o alfabeto inteiro, continue assim! Dando continuidade ao processo de aprendizagem,");
        linhaCol(36, 8); printf("nesta dificuldade você verá a 2º parte das \"CONSOANTES\", sendo que a 1º parte está lá no \"NÍVEL MÉDIO I\".");
    } else if (strcmp("DIFÍCIL", nivel) == 0) {
        box(11, 5, 13, 67);

        linhaCol(12, 7); printf("GRUPO DO ALFABETO PROPOSTO: ");
        textColor(BROWN, _BLACK);
        printf("\"ALFABETO COMPLETO\"");
        textColor(WHITE, _BLACK);
        printf(" - ");
        textColor(LIGHTRED, _BLACK);
        printf("26 letras");
        textColor(WHITE, _BLACK);

        //linhaCol(33, 28); printf("[É RECOMENDADO JOGAR OS OUTROS MODOS ANTES DE JOGAR ESTE AQUI!]");
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

    opt = modeloMenu(20, 78, 2, 0, lista);

    if (opt == 2 || opt == 9) {
        cleanScreen(1, false);
        return 0;
    }

    cleanScreen(4, false);

    //Iniciando a thread anti-trapaça para próxima tela
    aCHandle = CreateThread(NULL, 0x0, antiCheat, NULL, 0, &aCThreadId);

    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, nivel, 3, colBanner, 6);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    //PlaySound(TEXT("..\\sounds\\getready.wav"), NULL, SND_ASYNC);
    setlocale(LC_ALL, "C");
    linhaCol(13, 42); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Boas vindas ao \"Jogo do Braile\"");
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
    for (int cont = 0; cont <= 4; cont ++) {
        if (cont % 2 == 0) textColor(BROWN, _BLACK);
        else textColor(BLACK, _BROWN);
        linhaCol(35, 41); printf(" %c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Gerando a sua barra de progresso...");
        setlocale(LC_ALL, "C");
        printf(" %c ", 254);
        Sleep(200);
    }
    textColor(WHITE, _BLACK);
    setlocale(LC_ALL, "Portuguese");
    bottomBannerTitle(1);
    cleanScreen(7, true);
    currentProgressionBanner(nivel, progresso, acertos, erros, pontos);
    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, nivel, 3, colBanner, 4);
    setlocale(LC_ALL, "C");
    linhaCol(27, 41); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Pressione Enter para iniciar o jogo");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    //linhaCol(37, 41);
    //getchar();


    /*if (strcmp(stringCopiada, "vasco") == 0) {*/
        /*titulo("-", "Easter Egg \"VASCO\" desbloqueado!");

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
        CloseHandle(hThread2);*/
    /*}
    /*else if (strcmp(stringCopiada, "kasino") == 0) {
        linhaCol(4, 10); printf("KASINO!");
        Sleep(3000);
    }*/

    pressEnter();
    cleanScreen(6, false);
    titulo(nivel, "Entrando no jogo, prepare-se!");
    PlaySound(TEXT("..\\sounds\\nosound.wav"), NULL, SND_ASYNC);
    return 1;
}

/* H) FIM DO JOGO (TABELA DE ESTATÍSTICAS) */
void fimJogo(char nivel[9], int pts, int acertos, int numPerg){
    int tecla = 0, colNivel = 0;
    /*
     * Código do sistema de Ranking - Futuro (sem previsão no momento)
     */
    //Banner "animado" do Parabéns
    DWORD threadId;
    HANDLE hThread;

    cleanScreen(2, false);
    titulo(nivel, "Resultado final");

    if (strcmp(nivel, "FÁCIL") == 0) {
        colNivel = 17;
    } else if (strcmp(nivel, "MÉDIO I") == 0) {
        colNivel = 11;
    } else if (strcmp(nivel, "MÉDIO II") == 0) {
        colNivel = 8;
    } else if (strcmp(nivel, "DIFÍCIL") == 0) {
        colNivel = 15;
    }
    topBannerContent("RESULTADO FINAL DO", 2, 26, nivel, 3, colNivel, 6);

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

    Sleep(2000); //3500

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
    topBannerContent("RESULTADO FINAL DO", 2, 26, nivel, 3, colNivel, 4);
    setlocale(LC_ALL, "C");
    linhaCol(26, 43); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" Pressione ENTER para continuar ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    pressEnter();

    //As telas de desbloqueio de modos serão mostrados apenas uma única vez
    if (((strcmp(nivel, "FÁCIL") == 0 && modosDisponiveis == 0) || (strcmp(nivel, "MÉDIO I") == 0 && modosDisponiveis == 1)) || ((strcmp(nivel, "MÉDIO II") == 0 && modosDisponiveis == 2) || (strcmp(nivel, "DIFÍCIL") == 0 && modosDisponiveis == 3))) {
        if(acertos == numPerg && strcmp(nivel, "DIFÍCIL") != 0) { // Todas as respostas respondidas corretamente
            int linCad = 10, colCad = 33;

            //box(9, 28, 31, 92);
            box(9, 7, 31, 113);

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
            exibirBannerDificuldade("-", 0, 0, "OH", 16, 71);
            setlocale(LC_ALL, "C");
            linhaCol(23, 69); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" Pressione Enter ");
            setlocale(LC_ALL, "C");
            printf("%c", 254);
            pressEnter();

            topBannerContent("RESULTADO FINAL DO", 2, 26, nivel, 3, colNivel, 6);
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
                exibirBannerDificuldade("-", 0, 0, "MÉDIO I", 15, 55);
                if (modosDisponiveis < 1) modosDisponiveis = 1;
            } else if (strcmp(nivel, "MÉDIO I") == 0 && acertos == 10) {
                exibirBannerDificuldade("-", 0, 0, "MÉDIO II", 15, 53);
                if (modosDisponiveis < 2) modosDisponiveis = 2;
            } else if (strcmp(nivel, "MÉDIO II") == 0 && acertos == 11) {
                exibirBannerDificuldade("-", 0, 0, "DIFÍCIL", 15, 59);
                if (modosDisponiveis < 3) modosDisponiveis = 3;
            }

            exibirBannerDificuldade("-", 0, 0, "DESBLOQUEADA", 19, 55);

            Sleep(1700);
            topBannerContent("RESULTADO FINAL DO", 2, 26, nivel, 3, colNivel, 4);
            linhaCol(27, 63); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" Pressione ENTER para continuar ");
            setlocale(LC_ALL, "C");
            printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            pressEnter();
        } else if (acertos == numPerg && strcmp(nivel, "DIFÍCIL") == 0){
            cleanScreen(6, false);
            titulo("-", "Parabéns por completar o Jogo do Braile");
            topBannerContent("VOCÊ ACABOU DE COMPLETAR O", 13, 66, "AGRADECIMENTO", 14, 53, 6);
            if (modosDisponiveis < 4) modosDisponiveis = 4;
            PlaySound(TEXT("..\\sounds\\gamecomplete.wav"), NULL, SND_ASYNC);

            linhaCol(9, 15); printf("    .5~  :Y:      J?  .5J     ");
            linhaCol(10, 15); printf("     .Y^  .J:    J?  .5J      ");
            linhaCol(11, 15); printf("      .Y^  .J:  J7   J?       ");
            linhaCol(12, 15); printf("       .5^  .Y~?7   ?7        ");
            linhaCol(13, 15); printf("        :P~  ~G!   ?7         ");
            linhaCol(14, 15); printf("         :G7^Y7  .?7          ");
            linhaCol(15, 15); printf("          ^?YY^::?J.          ");
            textColor(BROWN, _BLACK);
            linhaCol(16, 15); printf("          : .    ...          ");
            linhaCol(17, 15); printf("        ..:........:.         ");
            linhaCol(18, 15); printf("     .:^^:...........:..      ");
            linhaCol(19, 15); printf("   .^^^::::::.:::^^^^::::.    ");
            linhaCol(20, 15); printf("  :^::^^^^^:::::::::^^^^:::.  ");
            linhaCol(21, 15); printf(" :^::~~^^^^^^:::::::::^^::::. ");
            linhaCol(22, 15); printf(".^..~^^~^^^^^^^^^::::::::::::.");
            linhaCol(23, 15); printf(".^..~~~~~~~^^^^^^^^^^::^:::^::");
            linhaCol(24, 15); printf(".^..~~~~~~~~~~~^^^^^^^^^^::^^.");
            linhaCol(25, 15); printf(" ::.^^~~~~~~~~~~~~~~^^^^^::^^ ");
            linhaCol(26, 15); printf(" .::.:^^~~^~~~~~~~~^~~^^:.:^. ");
            linhaCol(27, 15); printf("   :::::^^^^^~^~~^~~~^:..::.  ");
            linhaCol(28, 15); printf("    .:^^::::::::^^^^::.::.    ");
            linhaCol(29, 15); printf("      .::^^:::::::::::.       ");
            linhaCol(30, 15); printf("           .......            ");

            textColor(WHITE, _BLACK);

            printAlfabeto('P', 22, 56, 2); Sleep(50);
            printAlfabeto('A', 22, 63, 2); Sleep(50);
            printAlfabeto('R', 22, 70, 2); Sleep(50);
            printAlfabeto('A', 22, 77, 2); Sleep(50);
            printAlfabeto('B', 22, 84, 2); Sleep(50);
            printAlfabeto('E', 22, 91, 2); Sleep(50);
            printAlfabeto('N', 22, 98, 2); Sleep(50);
            printAlfabeto('S', 22, 105, 2); Sleep(1000);

            linhaCol(21, 54); printf(" _____ ");
            linhaCol(22, 54); printf("|  _  |");
            linhaCol(23, 54); printf("|   __|");
            linhaCol(24, 54); printf("|__|   ");
            linhaCol(25, 54); printf("       ");
            Sleep(500);
            linhaCol(21, 61); printf(" _____ ");
            linhaCol(22, 61); printf("|  _  |");
            linhaCol(23, 61); printf("|     |");
            linhaCol(24, 61); printf("|__|__|");
            linhaCol(25, 61); printf("       ");
            Sleep(500);
            linhaCol(21, 68); printf(" _____ ");
            linhaCol(22, 68); printf("| __  |");
            linhaCol(23, 68); printf("|    -|");
            linhaCol(24, 68); printf("|__|__|");
            linhaCol(25, 68); printf("       ");
            Sleep(500);
            linhaCol(21, 75); printf(" _____ ");
            linhaCol(22, 75); printf("|  _  |");
            linhaCol(23, 75); printf("|     |");
            linhaCol(24, 75); printf("|__|__|");
            linhaCol(25, 75); printf("       ");
            Sleep(500);
            linhaCol(21, 82); printf(" _____ ");
            linhaCol(22, 82); printf("| __  |");
            linhaCol(23, 82); printf("| __ -|");
            linhaCol(24, 82); printf("|_____|");
            linhaCol(25, 82); printf("       ");
            Sleep(500);
            linhaCol(19, 91); printf(" __");
            linhaCol(20, 91); printf("/_/");
            linhaCol(21, 89); printf(" _____ ");
            linhaCol(22, 89); printf("|   __|");
            linhaCol(23, 89); printf("|   __|");
            linhaCol(24, 89); printf("|_____|");
            linhaCol(25, 89); printf("       ");
            Sleep(500);
            linhaCol(21, 96); printf(" _____ ");
            linhaCol(22, 96); printf("|   | |");
            linhaCol(23, 96); printf("| | | |");
            linhaCol(24, 96); printf("|_|___|");
            linhaCol(25, 96); printf("       ");
            Sleep(500);
            linhaCol(21, 103); printf(" _____ ");
            linhaCol(22, 103); printf("|   __|");
            linhaCol(23, 103); printf("|__   |");
            linhaCol(24, 103); printf("|_____|");
            linhaCol(25, 103); printf("       ");
            Sleep(750);

            topBannerContent("VOCÊ ACABOU DE COMPLETAR O", 13, 66, "AGRADECIMENTO", 14, 53, 4);

            setlocale(LC_ALL, "C");
            linhaCol(27, 65); printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");
            printf(" Pressione ENTER para continuar ");
            setlocale(LC_ALL, "C");
            printf("%c", 254);
            setlocale(LC_ALL, "Portuguese");

            hThread = CreateThread(NULL, 0x0, bannerParabens, NULL, 0, &threadId);

            pressEnter();
            TerminateThread(hThread, 0x0);
            CloseHandle(hThread);
            textColor(WHITE, _BLACK);
        }
    }

    cleanScreen(1, true);
    topBannerContent("OBRIGADO POR JOGAR O", 2, 25, "AGRADECIMENTO", 2, 8, 4);
    if (acertos == numPerg) exibirTelaRedes(0, nivel);
    else exibirTelaRedes(2, nivel);
    cleanScreen(1, false);
    PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
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
    hideCursor();
    setlocale(LC_ALL,"Portuguese");
    setScreenMode(false);
}

/* N) ALTERA EXIBIÇÃO DA TELA E FAZ OS AJUSTES NECESSÁRIOS*/
void setScreenMode(bool changeMode) {
    int fontsizeY = 16;

    if(changeMode) isFullScreen = !isFullScreen;

    //Armazenando coordenadas atuais do mouse ANTES de ir para tela cheia
    if(isFullScreen) {
        POINT cursorPos;
        if(GetCursorPos(&cursorPos)){
            mouseX = cursorPos.x;
            mouseY = cursorPos.y;
        }
    }

    //Definindo comandos referentes ao pressionar dos botões "Alt+Enter" para alteração de exibição do jogo
    if(changeMode || (!changeMode && isFullScreen)) {
        keybd_event(VK_MENU  , 0x36, 0, 0);
        keybd_event(VK_RETURN, 0x1C, 0, 0);
        keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_MENU  , 0x38, KEYEVENTF_KEYUP, 0);
    }


    if (!isFullScreen) { //Referente ao modo Janela
        if(changeMode) SetCursorPos(mouseX, mouseY);

        //Definindo as cores e as dimensões da janela do console
        system("color 0f");
        system("mode con:cols=119 lines=38");

        HWND hwnd = GetConsoleWindow(); // Obtém o identificador da janela do console
        int x = GetSystemMetrics(SM_CXSCREEN); // quantidade de pixel por linhas da tela
        int y = GetSystemMetrics(SM_CYSCREEN); // quantidade de pixel por coluna da tela
        SetWindowPos(hwnd, HWND_TOPMOST, x/7.02, y/20, 970, 647, SWP_NOZORDER | SWP_ASYNCWINDOWPOS);

        //Definindo o tamanho do buffer do console (definido APÓS o redimensionamento da janela do console)
        HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
        COORD bufferSize;
        bufferSize.X = 39;
        bufferSize.Y = 120;
        SetConsoleScreenBufferSize(hConsole, bufferSize);

        //Definindo o tamanho da fonte das informações do console para o modo janela
        CONSOLE_FONT_INFOEX fontInfo;
        fontInfo.cbSize = sizeof fontInfo;
        fontInfo.nFont = 0;
        fontInfo.dwFontSize.X = 0;
        fontInfo.dwFontSize.Y = fontsizeY;
        fontInfo.FontFamily = TMPF_TRUETYPE;
        fontInfo.FontWeight = 400;
        wcscpy(fontInfo.FaceName, L"Consolas");
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);

        //Bloqueando o redimensionamento da janela do console
        HWND cW = GetConsoleWindow();
        LONG_PTR style = GetWindowLongPtr(cW, GWL_STYLE);
        style &= ~WS_SIZEBOX;
        style &= ~WS_MAXIMIZEBOX;
        SetWindowLongPtr(cW, GWL_STYLE, style);
    } else { //Referente ao modo Tela Cheia
        //Movimentando cursor do mouse para "escondê-lo"
        SetCursorPos(2000, 2000);

        //Definindo o tamanho da fonte das informações do console para o modo tela cheia
        CONSOLE_FONT_INFOEX fontInfo;
        fontInfo.cbSize = sizeof fontInfo;
        fontInfo.nFont = 0;
        fontInfo.dwFontSize.X = 0;
        fontInfo.dwFontSize.Y = fontsizeY + 4;
        fontInfo.FontFamily = TMPF_TRUETYPE;
        fontInfo.FontWeight = 400;
        wcscpy(fontInfo.FaceName, L"Consolas");
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
    }

    if(changeMode) {
        system("cls");
        topBannerDesign();
        bottomBannerDesign();
    }
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
            linhaCol(10, 77); printf(" _____                     _        _ ");
            linhaCol(11, 77); printf("| __  |___ ___ ___ ___ ___| |_ ___ |_|");
            linhaCol(12, 77); printf("|    -| -_|_ -| . | . |_ -|  _| .'| _ ");
            linhaCol(13, 77); printf("|__|__|___|___|  _|___|___|_| |__,||_|");
            linhaCol(14, 77); printf("              |_|                     ");
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
        case 27:
            linhaCol(9, 4); printf("                                         __                 _____ ");
            linhaCol(10, 4); printf(" _____            _     _               /_/                |___  |");
            linhaCol(11, 4); printf("|     |_ _ ___   | |___| |_ ___ ___    ___    ___ ___ ___ ___|  _|");
            linhaCol(12, 4); printf("|  |  | | | -_|  | | -_|  _|  _| .'|  | -_|  | -_|_ -|_ -| .'|_|  ");
            linhaCol(13, 4); printf("|__  _|___|___|  |_|___|_| |_| |__,|  |___|  |___|___|___|__,|_|  ");
            linhaCol(14, 4); printf("   |__|                                                           ");
        break;
    }
}

/* R) RETORNA O BANNER CORRESPONDENTE À DIFICULDADE */
void exibirBannerDificuldade(char titulo1[40], int lin1, int col1, char nivel[20], int lin2, int col2) { //"lin1" e "col1" são coordenadas relacionadas ao "titulo1"; "lin2" e "col2", ao "titulo2".
    if (strcmp(titulo1, "-") != 0) {
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
    } else if (strcmp(nivel, "MODOS") == 0){
        linhaCol(linha, coluna); printf(" _____       _              _           __             ");
        linhaCol(linha + 1, coluna); printf("|     |___ _| |___ ___    _| |___    __|  |___ ___ ___ ");
        linhaCol(linha + 2, coluna); printf("| | | | . | . | . |_ -|  | . | -_|  |  |  | . | . | . |");
        linhaCol(linha + 3, coluna); printf("|_|_|_|___|___|___|___|  |___|___|  |_____|___|_  |___|");
        linhaCol(linha + 4, coluna); printf("                                              |___|    ");
    } else if (strcmp(nivel, "COMO JOGAR") == 0){
        linhaCol(linha, coluna); printf(" _____                     __                 ");
        linhaCol(linha + 1, coluna); printf("|     |___ _____ ___    __|  |___ ___ ___ ___ ");
        linhaCol(linha + 2, coluna); printf("|   --| . |     | . |  |  |  | . | . | .'|  _|");
        linhaCol(linha + 3, coluna); printf("|_____|___|_|_|_|___|  |_____|___|_  |__,|_|   (o Jogo do Braile)");
        linhaCol(linha + 4, coluna); printf("                                 |___|        ");
    } else if (strcmp(nivel, "NÃO DESISTA") == 0) {
        linhaCol(linha + 1, coluna); printf(" _____ /\\/        ____          _     _      ");
        linhaCol(linha + 2, coluna); printf("|   | |___ ___   |    \\ ___ ___|_|___| |_ ___");
        linhaCol(linha + 3, coluna); printf("| | | | .'| . |  |  |  | -_|_ -| |_ -|  _| .'|");
        linhaCol(linha + 4, coluna); printf("|_|___|__,|___|  |____/|___|___|_|___|_| |__,|");
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
    } else if(strcmp(nivel, "???") == 0) {
        linhaCol(linha + 1, coluna); printf(" _____  _____  _____  _____  _____ ");
        linhaCol(linha + 2, coluna); printf("|___  ||___  ||___  ||___  ||___  |");
        linhaCol(linha + 3, coluna); printf("  |  _|  |  _|  |  _|  |  _|  |  _|");
        linhaCol(linha + 4, coluna); printf("  |_|    |_|    |_|    |_|    |_|  ");
        linhaCol(linha + 5, coluna); printf("  |_|    |_|    |_|    |_|    |_|  ");
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
        linhaCol(16, 13); printf("| __  |___ ___| |_   |   __|   ___   |_   _|     |  _  |   __|     |  _  |  |  |   __|  |  |  |");
        linhaCol(17, 13); printf("|    -| .'|   | '_|  |__   |  |___|   _| |_| | | |   __|   __|   --|     |  |  |   __|  |__|__|");
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
    int totOpt;
    if (strcmp(dificuldade, "DIFÍCIL") != 0) totOpt = 3;
    else totOpt = 4;
    do {
        altGerada = toupper(gerarLetra(dificuldade));
        //printf("Caractere gerado: %c\n", altGerada);
        if (altGerada == letrResp1 || altGerada == letrResp2) {
            //printf("Descartado! A letra gerada é igual a da resposta ou já foi apresentada na pergunta anterior!\n");
            continue;
        }
        for (c = 0; c < totOpt; c ++) {
            if (alt[c] == toupper(altGerada)) {
                //printf("Descartado! A letra gerada já existe no vetor!\n");
                break;
            }
        }
        if (c == totOpt) {
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
    }while(cont < totOpt);
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

void topBannerContent(char titulo1[40], int lin1, int col1, char nivel[20], int lin2, int col2, int modoBotoes) { //"lin1" e "col1" são coordenadas relacionadas ao "titulo1"; "lin2" e "col2", ao "titulo2".
    exibirBannerDificuldade(titulo1, lin1, col1, nivel, lin2, col2);

    textColor(WHITE, _BLACK);
    cleanScreen(8, false);

    setlocale(LC_ALL, "C");
    linhaCol(2, 80); printf("%c", 254);
    setlocale(LC_ALL, "Portuguese");
    printf(" AÇÕES DISPONÍVEIS NESTA TELA ");
    setlocale(LC_ALL, "C");
    printf("%c", 254);

    int refer = 75;

    //Botão Esc
    if (modoBotoes == 0 || modoBotoes == 2) {
        if (modoBotoes == 0) refer = 75;
        else refer = 72;
        textColor(LIGHTRED, _BLACK);
        box(5, refer + 16, 7, refer + 20);
        linhaCol(6, refer + 17); printf("Esc");
        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        linhaCol(6, refer + 22); printf("\u276f");
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(6, refer + 24); printf("Voltar");
        textColor(WHITE, _BLACK);
    }

    // 0) Todas as teclas, Enter e Esc; 1) Todas as teclas e Enter; 2) Teclas CIMA e BAIXO, Enter e Esc; 3) Teclas CIMA e BAIXO e Enter; 4) Somente Enter; 5) Somente Barra de Espaço (2x); 6) Nenhuma ação ou botão.
    if (modoBotoes == 2 || modoBotoes == 3) {
        if (modoBotoes == 2) refer = 71;
        if (modoBotoes == 3) refer = 74;

        textColor(LIGHTBLUE, _BLACK);

        box(3, refer + 6, 5, refer + 10); //Caixa da Seta pra CIMA
        box(5, refer + 6, 7, refer + 10); //Caixa da Seta pra BAIXO
        //box(3, refer + 17, 5, refer + 21); //Caixa da tecla W (pra CIMA)
        //box(5, refer + 17, 7, refer + 21); //Caixa da tecla S (pra BAIXO)

        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        linhaCol(4, refer + 12); printf("\u276f");
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(4, refer + 14); printf("Navegar");

        textColor(WHITE, _BLACK);
    }

    if (modoBotoes == 0 || modoBotoes == 1) {
        // Caixas das Setas do Teclado:

        if (modoBotoes == 0) refer = 75;
        if (modoBotoes == 1) refer = 78;

        textColor(LIGHTBLUE, _BLACK);

        box(3, refer + 4, 5, refer + 8); //Caixa da Seta pra CIMA
        box(5, refer + 4, 7, refer + 8); //Caixa da Seta pra BAIXO
        box(5, refer + 0, 7, refer + 4); //Caixa da Seta pra ESQUERDA
        box(5, refer + 8, 7, refer + 12); //Caixa da Seta pra DIREITA

        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        linhaCol(4, refer + 10); printf("\u276f");
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");
        linhaCol(4, refer + 12); printf("Navegar");

        textColor(WHITE, _BLACK);

        //box(3, refer + 21, 5, refer + 25); //Caixa da tecla W (pra CIMA)
        //box(5, refer + 21, 7, refer + 25); //Caixa da tecla S (pra BAIXO)
        //box(5, refer + 17, 7, refer + 21); //Caixa da tecla A (pra ESQUERDA)
        //box(5, refer + 25, 7, refer + 29); //Caixa da tecla D (pra DIREITA)
    }

    //Junções das Setas do Teclado:
    setlocale(LC_ALL, "C");
    if (modoBotoes == 2 || modoBotoes == 3) {
        textColor(LIGHTBLUE, _BLACK);
        linhaCol(5, refer + 6);printf("%c", 195); // Junção esquerdo (setas)
        linhaCol(5, refer + 10);printf("%c", 180); // Junção direito (setas)
        //linhaCol(5, refer + 17);printf("%c", 195); // Junção esquerdo (WASD)
        //linhaCol(5, refer + 21);printf("%c", 180); // Junção direito (WASD)
        textColor(WHITE, _BLACK);
    }
    if (modoBotoes == 0 || modoBotoes == 1) {
        textColor(LIGHTBLUE, _BLACK);
        linhaCol(5, refer + 4);printf("%c", 197); // Junção superior esquerdo (setas)
        linhaCol(5, refer + 8);printf("%c", 197); // Junção superior direito (setas)
        linhaCol(7, refer + 4);printf("%c", 193); // Junção inferior esquerdo (setas)
        linhaCol(7, refer + 8);printf("%c", 193); // Junção inferior direito (setas)

        //linhaCol(5, refer + 21);printf("%c", 197); // Junção superior esquerdo (WASD)
        //linhaCol(5, refer + 25);printf("%c", 197); // Junção superior direito (WASD)
        //linhaCol(7, refer + 21);printf("%c", 193); // Junção inferior esquerdo (WASD)
        //linhaCol(7, refer + 25);printf("%c", 193); // Junção inferior direito (WASD)
        textColor(WHITE, _BLACK);
    }

    //Ícones das Setas do Teclado:
    SetConsoleOutputCP(CP_UTF8);
    if (modoBotoes == 2 || modoBotoes == 3) {
        textColor(LIGHTBLUE, _BLACK);
        linhaCol(4, refer + 8); printf("\u25b2");  //Ícone de Seta para Cima
        linhaCol(6, refer + 8); printf("\u25bc");  //Ícone de Seta para Baixo
        //linhaCol(4, refer + 19);printf("W"); //Tecla W (pra CIMA)
        //linhaCol(6, refer + 19);printf("S"); //Tecla S (pra BAIXO)
        textColor(WHITE, _BLACK);
    }
    if (modoBotoes == 0 || modoBotoes == 1) {
        textColor(LIGHTBLUE, _BLACK);
        linhaCol(4, refer + 6); printf("\u25b2");  //Ícone de Seta para Cima
        linhaCol(6, refer + 6); printf("\u25bc");  //Ícone de Seta para Baixo
        linhaCol(6, refer + 2); printf("\u25c4");  //Ícone de Seta para Esquerda
        linhaCol(6, refer + 10); printf("\u25ba"); //Ícone de Seta para Direita

        //linhaCol(4, refer + 23);printf("W"); //Tecla W (pra CIMA)
        //linhaCol(6, refer + 23);printf("S"); //Tecla S (pra BAIXO)
        //linhaCol(6, refer + 19);printf("A"); //Tecla A (pra ESQUERDA)
        //linhaCol(6, refer + 27);printf("D"); //Tecla D (pra DIREITA)
        textColor(WHITE, _BLACK);
    }
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese");

    // Tecla Enter
    if (modoBotoes >= 0 && modoBotoes <= 4) {
        if (modoBotoes == 0) refer = 75;
        else if (modoBotoes == 1) refer = 72;
        else if (modoBotoes == 2) refer = 73;
        else if (modoBotoes == 3) refer = 70;
        else refer = 64;
        textColor(BROWN, _BLACK);
        box(3, refer + 35, 7, refer + 41);// Retângulo principal
        setlocale(LC_ALL, "C");
        linhaCol(5, refer + 34); printf("%c", 196); // Barra inferior
        linhaCol(4, refer + 33); printf("%c", 179); // Barra do meio
        linhaCol(3, refer + 34); printf("%c%c", 196, 196); // Barras superiores
        SetConsoleOutputCP(CP_UTF8);
        linhaCol(5, refer + 35); printf("\u256e"); // Curva inferior direita
        linhaCol(5, refer + 33); printf("\u2570"); // Curva inferior esquerda
        linhaCol(3, refer + 33); printf("\u256d"); // Curva superior esquerda
        SetConsoleOutputCP(850);
        linhaCol(4, refer + 35); printf("Enter");

        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        if (modoBotoes == 0 || modoBotoes == 2) {
            linhaCol(4, refer + 31); printf("\u276e");
            SetConsoleOutputCP(850);
            setlocale(LC_ALL, "Portuguese");
            linhaCol(4, refer + 21); printf("Confirmar");
        } else if (modoBotoes == 1 || modoBotoes == 3){
            linhaCol(6, refer + 33); printf("\u276e");
            SetConsoleOutputCP(850);
            setlocale(LC_ALL, "Portuguese");
            linhaCol(6, refer + 23); printf("Confirmar");
        } else {
            linhaCol(5, refer + 31); printf("\u276e");
            SetConsoleOutputCP(850);
            setlocale(LC_ALL, "Portuguese");
            linhaCol(5, refer + 21); printf("Confirmar");
        }
        textColor(WHITE, _BLACK);
    }

    // Tecla da Barra de Espaço
    if (modoBotoes == 5) {
        textColor(BROWN, _BLACK);
        box(4, refer + 5, 6, refer + 36);
        linhaCol(5, refer + 13); printf("BARRA DE ESPAÇO");
        linhaCol(7, refer + 7);
        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        printf("Acelerar temporizador \u1405\u1405 x10");
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");
        textColor(WHITE, _BLACK);
    }

    if (modoBotoes == 6) {
        textColor(DARKGRAY, _BLACK);
        linhaCol(5, refer + 9); printf("~ SEM AÇÕES NO MOMENTO ~");
        textColor(WHITE, _BLACK);
    }

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

void bottomBannerContent(int opt, int menuAtual) {
    for (int descLinha = 34; descLinha <= 36; descLinha ++) {
        linhaCol(descLinha, 2);
        for (int limpar = 2; limpar < 117; limpar ++) {
            printf(" ");
        }
    }
    if (menuAtual == 1) {
        switch(opt) {
            case 1:
                linhaCol(35, 34); printf("Acesse os modos disponíveis e ");
                textColor(BROWN, _BLACK);
                printf("jogue o Jogo do Braile");
                textColor(WHITE, _BLACK);
                printf("!");
                break;
            case 2:
                linhaCol(35, 31); printf("Consulte a ");
                textColor(BROWN, _BLACK);
                printf("pontuação");
                textColor(WHITE, _BLACK);
                printf(" de todos os jogadores salvos no seu PC.");
                break;
            case 3:
                linhaCol(35, 40); printf("Consulte as ");
                textColor(BROWN, _BLACK);
                printf("instruções");
                textColor(WHITE, _BLACK);
                printf(" do Jogo do Braile");
                linhaCol(36, 37); printf("(e veja também um ");
                textColor(BROWN, _BLACK);
                printf("passo-a-passo");
                textColor(WHITE, _BLACK);
                printf(" de como jogar).");
                break;
            case 4:
                linhaCol(35, 7); printf("Acesse os ");
                textColor(BROWN, _BLACK);
                printf("créditos");
                textColor(WHITE, _BLACK);
                printf(" do projeto \"Jogo do Braile\" e descubra:");
                textColor(LIGHTBLUE, _BLACK);
                linhaCol(34, 68); printf("1) O motivo inicial do projeto");
                textColor(WHITE, _BLACK);
                printf(";");
                textColor(LIGHTCYAN, _BLACK);
                linhaCol(35, 68); printf("2) As pessoas envolvidas no inicio do projeto");
                textColor(WHITE, _BLACK);
                printf("; e ");
                textColor(LIGHTRED, _BLACK);
                linhaCol(36, 68); printf("3) O contato do desenvolvedor do projeto");
                textColor(WHITE, _BLACK);
                printf(".");
                break;
            case 5:
                if (!isFullScreen) {
                    linhaCol(35, 18); printf("Selecione esta opção para definir a exibição do Jogo do Braile no modo ");
                    textColor(BROWN, _BLACK);
                    printf("\"Tela Cheia\"");
                } else {
                    linhaCol(35, 20); printf("Selecione esta opção para definir a exibição do Jogo do Braile no modo ");
                    textColor(BROWN, _BLACK);
                    printf("\"Janela\"");
                }
                textColor(WHITE, _BLACK);
                printf(".");
                textColor(LIGHTRED, _BLACK);
                linhaCol(36, 7); printf("[ATENÇÃO]");
                textColor(WHITE, _BLACK);
                printf(" Não use o ");
                textColor(BROWN, _BLACK);
                printf("\"Alt+Enter\"");
                textColor(WHITE, _BLACK);
                printf("! Use ");
                textColor(BROWN, _BLACK);
                printf("esta opção");
                textColor(WHITE, _BLACK);
                printf(" para que a mudança de exibição seja aplicada corretamente.");
                break;
            case 6:
                linhaCol(35, 38);
                textColor(BROWN, _BLACK);
                printf("Feche");
                textColor(WHITE, _BLACK);
                printf(" o Jogo do Braile. ");
                textColor(LIGHTGREEN, _BLACK);
                printf("Obrigado por jogar");
                textColor(WHITE, _BLACK);
                printf("!");
                break;
        }
    } else if (menuAtual == 2){
        switch(opt) {
            case 1:
                linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade ");
                textColor(BROWN, _BLACK);
                printf("\"Fácil\"");
                textColor(WHITE, _BLACK);
                printf(".");
                break;
            case 2:
                linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade ");
                textColor(BROWN, _BLACK);
                printf("\"Médio I\"");
                textColor(WHITE, _BLACK);
                printf(".");
                break;
            case 3:
                linhaCol(35, 36); printf("Jogue o Jogo do Braile na dificuldade ");
                textColor(BROWN, _BLACK);
                printf("\"Médio II\"");
                textColor(WHITE, _BLACK);
                printf(".");
                break;
            case 4:
                linhaCol(35, 37); printf("Jogue o Jogo do Braile na dificuldade ");
                textColor(BROWN, _BLACK);
                printf("\"Difícil\"");
                textColor(WHITE, _BLACK);
                printf(".");
                break;
            case 5:
                linhaCol(35, 28); printf("Jogue o Jogo do Braile na dificuldade... ");
                textColor(BROWN, _BLACK);
                printf("Espera, que modo é esse?");
                textColor(WHITE, _BLACK);
            break;
            case 6:
                linhaCol(35, 48); printf("Volte ao ");
                textColor(BROWN, _BLACK);
                printf("Menu Principal");
                textColor(WHITE, _BLACK);
                printf(".");
                break;
        }
    }
}

void cleanScreen(int opt, bool inferiorCompleto) { // 1) Tudo; 2) Superior + Meio; 3) Superior + Inferior; 4) Meio + Inferior; 5) Superior; 6) Meio; 7) Inferior; 8) Área de ações disponíveis
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

    if (opt == 1 || opt == 8) {
        for (linha = 3; linha < 8; linha ++) {
            for (coluna = 73; coluna < 119; coluna ++) {
                linhaCol(linha, coluna); printf(" ");
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
                if ((linha == 33 && coluna < 23) && !inferiorCompleto) { // Título do Banner
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

int modeloMenu(int lin1, int col1, int qtd, int menuAtual, char lista[][40]) {
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


        if (qtd >= 6) {
            bottomBannerContent(opt, menuAtual);
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
        } else if (tecla == 27) { //ESC
            if (menuAtual == 2) opt = 6;
            else opt = 9;
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

void cheatBanner() {
    textColor(WHITE, _BLACK);
    linhaCol(13, 27); printf("Você achou que poderia trapacear na cara dura? ACHOU ERRADO, OTÁRIO!");
    PlaySound(TEXT("..\\sounds\\wasted.wav"), NULL, SND_ASYNC);
    Sleep(2146); //7039
    textColor(LIGHTRED, _BLACK);
    linhaCol(14, 2); printf("                                                                                                            .......  ");
    linhaCol(15, 2); printf("                                                                                                           ^777777~  ");
    linhaCol(16, 2); printf("                                                                                                           ^??????~  ");
    linhaCol(17, 2); printf(" :^^^^^^:   ^^^^^^^.  .^^^^^^:.:^^^^^^^^^^^^:  .^^^^^^^^^^^^^:  .^^^^^^^          .^^^^^^^^^^^^^:  .^^^^^^^!??????~  ");
    linhaCol(18, 2); printf(" ^??????7  .7??????~  ^??????^!??????????????~.7??????????????~~7???????!!!!!!!!~.7??????????????~.7??????????????~  ");
    linhaCol(19, 2); printf(" .7?????7: ^?????7?!  !?????7:7??????77??????!:7?????777??????77????????????????!:??????777??????!:??????777??????~  ");
    linhaCol(20, 2); printf("  ~??????^ !???????7..7?????~.~~~~~~~.:??????!:7?????7.:~~~~~~^~!7?????7!~~~~~~~^:7?????7.^??????~:??????!.^??????~  ");
    linhaCol(21, 2); printf("  :??????!.7????????^^??????: .^~~~~~~!??????!:7?????7~~~~~~~^. .7?????7 .~~~~~~^:7?????7^~??????~:??????! ^??????~  ");
    linhaCol(22, 2); printf("  .7??7??7~????7????!!?????7 .7??????????????!:7??????????????! .7?????7 :??????!:7??????????????!:7?????! ^??????~  ");
    linhaCol(23, 2); printf("   ~??????7???7^7???7??????~ .7?????7~!??????! ^!!!!!!77??????! .7?????7 :??????!:7?????77!!!!!!7~:??????! ^??????~  ");
    linhaCol(24, 2); printf("   :??????????! !?????????7: .7?????7 :??????!.^^^^^^^ :??????! .7?????7 :??????!:7?????!..^^^^^^::??????! ^??????~  ");
    linhaCol(25, 2); printf("   .7?????????~ ^?????????!  .7?????7!7??????!:??????7!7??????! .7?????7!7??????!:7?????7!7??????!:??????7!7??????~  ");
    linhaCol(26, 2); printf("    ~?????????: .7????????~  .7??????????????!.7??????????????! .7??????????????!.7??????????????~:???????????????!  ");
    linhaCol(27, 2); printf("    :!!!!!!!!~   ~!!!!!!!!.   :~!!!!!!!!!!!!!~ :~!!!!!!!!!!!~~.  :~!!!!!!!!!!!!~. :~!!!!!!!!!!!~^. :~!!!!!!!!!!!!!^  ");
    textColor(WHITE, _BLACK);
    Sleep(3500);

    cleanScreen(6, false);
    PlaySound(TEXT("..\\sounds\\cheat.wav"), NULL, SND_LOOP | SND_ASYNC);

    box(21, 16, 30, 104);

    linhaCol(9, 7); printf(" _____ _         _        _    _____      _                ___     _    _   _                       _     ");
    linhaCol(10, 7); printf("|  _  | |___ ___| |_ ___ |_|  |     |    |_|___ ___ ___   |  _|___|_|  | |_| |___ ___ _ _ ___ ___ _| |___ ");
    linhaCol(11, 7); printf("|     | | -_|  _|  _| .'| _   |  |  |    | | . | . | . |  |  _| . | |  | . | | . | . | | | -_| .'| . | . |");
    linhaCol(12, 7); printf("|__|__|_|___|_| |_| |__,||_|  |_____|   _| |___|_  |___|  |_| |___|_|  |___|_|___|_  |___|___|__,|___|___|");
    linhaCol(13, 7); printf("                                       |___|   |___|                               |_|                    ");

    linhaCol(15, 15); printf("O Jogo do Braile detectou que o");
    textColor(BROWN, _BLACK);
    linhaCol(15, 47); printf("\"Modo de Edição Rápida\"");
    textColor(WHITE, _BLACK);
    linhaCol(15, 71); printf("do console do Windows está ativado.");
    linhaCol(18, 14); printf("Para evitar quaisquer vantagens indevidas a qualquer um que ative esta configuração à força,");
    textColor(LIGHTRED, _BLACK);
    linhaCol(19, 21); printf("o jogo ficará bloqueado até que tal configuração seja DESATIVADA pelo usuário.");
    textColor(WHITE, _BLACK);

    linhaCol(25, 19); printf("Para");
    textColor(LIGHTGREEN, _BLACK);
    linhaCol(25, 24); printf("DESBLOQUEAR o jogo");
    textColor(WHITE, _BLACK);
    linhaCol(25, 42); printf(",");
    linhaCol(26, 19); printf("faça os passos a seguir:");

    linhaCol(23, 56); printf("- Clique com o botão direito na borda superior");
    linhaCol(24, 58); printf("do console e vá em");
    textColor(BROWN, _BLACK);
    linhaCol(24, 77); printf("\"Propriedades\"");
    textColor(WHITE, _BLACK);
    linhaCol(24, 91); printf(";");

    linhaCol(25, 56); printf("- Na aba");
    textColor(BROWN, _BLACK);
    linhaCol(25, 65); printf("\"Opções\"");
    textColor(WHITE, _BLACK);
    linhaCol(25, 73); printf(", procure a seção");
    textColor(BROWN, _BLACK);
    linhaCol(25, 91); printf("\"Opções de");
    linhaCol(26, 58); printf("Edição\"");
    textColor(WHITE, _BLACK);
    linhaCol(26, 65); printf(";");

    linhaCol(27, 56); printf("- Desmarque a caixa");
    textColor(BROWN, _BLACK);
    linhaCol(27, 76); printf("\"Modo de Edição Rápida\"");
    textColor(WHITE, _BLACK);
    linhaCol(28, 58); printf("e por fim selecione em ");
    textColor(BROWN, _BLACK);
    linhaCol(28, 81); printf("OK");
    textColor(WHITE, _BLACK);
    linhaCol(28, 83); printf(".");
}
