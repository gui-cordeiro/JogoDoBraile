/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2024
 */

/* MENU PRINCIPAL */
int mainMenu() {
    int opt = 0, ajusteMenu = 44;
    char lista [6][40] = {"Iniciar Jogo do Braile","Ranking Local","Instruções do Jogo","Créditos do Jogo","Mudar para modo \"Tela Cheia\"","Sair do Jogo do Braile"};

    if (isFullScreen) {
        strcpy(lista[4], "Mudar para modo \"Janela\"");
        ajusteMenu = 45;
    }

    titulo("-", "Menu Principal");

    // 0) Todas as teclas, Enter e Esc; 1) Todas as teclas e Enter; 2) Teclas CIMA e BAIXO, Enter e Esc; 3) Teclas CIMA e BAIXO e Enter; 4) Somente Enter; 5) Somente Barra de Espaço (2x); 6) Nenhuma ação ou botão.
    topBannerContent("VOCÊ ESTÁ NO", 2, 29, "MENU", 3, 9, 2);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    linhaCol(12, 59); printf("\u25b2");
    linhaCol(28, 59); printf("\u25bc");
    textColor(WHITE, _BLUE);
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    opt = modeloMenu(13, ajusteMenu, 6, 1, lista, 1);
    if (opt == 3) cleanScreen(1, true);
    else if (opt != 5) cleanScreen(1, false);

    return opt;
}

/* MENU DOS MODOS DE JOGO */
int modeSelect() {
    int opt = 0;
    //char lista [6][40] = {"Jogar - NÍVEL FÁCIL","Jogar - NÍVEL MÉDIO I","Jogar - NÍVEL MÉDIO II","Jogar - NÍVEL DIFÍCIL","Jogar - MODO LIVRE","Voltar ao Menu Principal"};
    char lista [6][40];

    strcpy(lista[0], "Jogar - NÍVEL FÁCIL");
    if (modosDisponiveis >= 1 && modosDisponiveis <= 4) strcpy(lista[1], "Jogar - NÍVEL MÉDIO I");
    else strcpy(lista[1], "???");
    if (modosDisponiveis >= 2 && modosDisponiveis <= 4) strcpy(lista[2], "Jogar - NÍVEL MÉDIO II");
    else strcpy(lista[2], "???");
    if (modosDisponiveis >= 3 && modosDisponiveis <= 4) strcpy(lista[3], "Jogar - NÍVEL DIFÍCIL");
    else strcpy(lista[3], "???");
    if (modosDisponiveis == 4) strcpy(lista[4], "Jogar - MODO ???");
    else strcpy(lista[4], "???");
    strcpy(lista[5], "Voltar ao Menu Principal");

    titulo("-", "Menu Principal");
    topBannerContent("VOCÊ ESTÁ NAVEGANDO NOS", 2, 23, "MODOS", 3, 9, 2);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    linhaCol(12, 59); printf("\u25b2");
    linhaCol(28, 59); printf("\u25bc");
    textColor(WHITE, _BLUE);
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    opt = modeloMenu(13, 46, 6, 2, lista, 1);
    return opt;
}

/* 1) JOGAR - NÍVEL FÁCIL */
int opcaoB1() {
    int cont = 15;
    int pts = 0, acertos = 0, erros = 0, tecla = 0;
    int ordem[5];
    int progresso[5] = {2,2,2,2,2};
    char letras[5] = {'A', 'E', 'I', 'O', 'U'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;
    mostrarLetras = true;

    if(confirmarJogo("FÁCIL", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "FÁCIL", 3, 17, 5);

    titulo("FÁCIL", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    textColor(_BLACK, BROWN);
    linhaCol(37, 41);printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    textColor(WHITE, _BLACK);

    do{
        if (mostrarLetras) {
            setlocale(LC_ALL, "C");
            linhaCol(16, 36); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tente memorizar as letras abaixo e boa sorte!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");

            printAlfabeto('A', 20, 37, 1);
            printAlfabeto('E', 20, 48, 1);
            printAlfabeto('I', 20, 59, 1);
            printAlfabeto('O', 20, 70, 1);
            printAlfabeto('U', 20, 81, 1);

            setlocale(LC_ALL, "C");
            linhaCol(25, 32); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Cuidado com o ");
            textColor(_BLACK, BROWN);
            printf("temporizador");
            textColor(_BLACK, WHITE);
            printf(", situado na barra inferior!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            mostrarLetras = false;
        }
        if (!isTextEditingEnabled) {
            if ((cont != 20) && (cont % 10 == 0 || cont <= 5)){
                textColor(_BLACK, LIGHTRED);
            } else {
                textColor(_BLACK, BROWN);
            }
            setlocale(LC_ALL, "C");
            linhaCol(37, 41);printf("  %c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tempo restante: ");
            if (cont < 10) printf("0");
            printf("%d segundo(s)", cont);
            setlocale(LC_ALL, "C");
            printf(" %c   ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            textColor(WHITE, _BLACK);
        }
        for (int fast = 0; fast < 70; fast ++) {
            if (isTextEditingEnabled) { //Se a edição de texto do console estiver ativada, um loop será ativo até que a edição seja desativada
                cleanScreen(6, false);
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "FÁCIL", 3, 17, 6);
                titulo("-", "Modo de Edição Rápida detectada");
                int wav[30];
                strcat(strcpy(wav, caminho), "cheatDeactivated.wav");
                Mix_Chunk *cheatDeactivated = Mix_LoadWAV(wav);
                strcat(strcpy(wav, caminho), "countdown.wav");
                Mix_Chunk *countdown = Mix_LoadWAV(wav);
                textColor(WHITE, _BLACK);
                cheatBanner();
                while (isTextEditingEnabled){}
                cleanScreen(6, false);
                cont ++;
                linhaCol(20, 30); printf("[ATENÇÃO] Modo de Edição Rápida desativado. Voltando ao jogo...");
                Mix_PlayChannel(0, cheatDeactivated, 0);
                Sleep(1500);
                cleanScreen(6, false);
                titulo("FÁCIL", "O jogo começará em breve...");
                Mix_PlayChannel(0, countdown, -1);
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "FÁCIL", 3, 17, 5);
            }
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);

    //Encerrando thread anti-trapaça
    TerminateThread(aCHandle, 0x0);
    CloseHandle(aCHandle);

    cleanScreen(2, false);
    currentProgressionBanner("FÁCIL", progresso, acertos, erros, pts);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 5; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("FÁCIL", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];

        if (numPergunta == 1) { // Primeira pergunta
            altAtuais[0] = '-';
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        } else if (numPergunta == totPerguntas) {// Última pergunta
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = '-';
        } else { // Demais perguntas
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        }
        newPergunta(false, "FÁCIL", numPergunta, '-', altAtuais[0], altAtuais[1], altAtuais[2], '-', &acertos, &erros, &pts, progresso);
    }
    fimJogo("FÁCIL", pts, acertos, totPerguntas);
    return 0;
}

/* 2) JOGAR - NÍVEL MÉDIO I */
void opcaoB2() {
    int cont = 25;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[10];
    int progresso[10] = {2,2,2,2,2,2,2,2,2,2};
    char letras[10] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;
    mostrarLetras = true;

    if(confirmarJogo("MÉDIO I", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "MÉDIO I", 3, 11, 5);

    titulo("MÉDIO I", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    textColor(WHITE, _BLACK);

    do{
        if (mostrarLetras) {
            setlocale(LC_ALL, "C");
            linhaCol(12, 36); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tente memorizar as letras abaixo e boa sorte!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");

            printAlfabeto('B', 16, 37, 1);
            printAlfabeto('C', 16, 48, 1);
            printAlfabeto('D', 16, 59, 1);
            printAlfabeto('F', 16, 70, 1);
            printAlfabeto('G', 16, 81, 1);

            printAlfabeto('H', 23, 37, 1);
            printAlfabeto('J', 23, 48, 1);
            printAlfabeto('K', 23, 59, 1);
            printAlfabeto('L', 23, 70, 1);
            printAlfabeto('M', 23, 81, 1);

            setlocale(LC_ALL, "C");
            linhaCol(28, 32); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Cuidado com o ");
            textColor(_BLACK, BROWN);
            printf("temporizador");
            textColor(_BLACK, WHITE);
            printf(", situado na barra inferior!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            mostrarLetras = false;
        }
        if (!isTextEditingEnabled) {
            if ((cont != 35) && (cont % 10 == 0 || cont <= 5)){
                textColor(_BLACK, LIGHTRED);
            } else {
                textColor(_BLACK, BROWN);
            }
            setlocale(LC_ALL, "C");
            linhaCol(37, 41);printf("  %c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tempo restante: ");
            if (cont < 10) printf("0");
            printf("%d segundo(s)", cont);
            setlocale(LC_ALL, "C");
            printf(" %c   ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            textColor(WHITE, _BLACK);
        }
        for (int fast = 0; fast < 70; fast ++) {
            if (isTextEditingEnabled) { //Se a edição de texto do console estiver ativada, um loop será ativo até que a edição seja desativada
                cleanScreen(6, false);
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "MÉDIO I", 3, 11, 6);
                titulo("-", "Modo de Edição Rápida detectada");
                textColor(WHITE, _BLACK);
                cheatBanner();
                while (isTextEditingEnabled){}
                cleanScreen(6, false);
                cont ++;
                linhaCol(20, 30); printf("[ATENÇÃO] Modo de Edição Rápida desativado. Voltando ao jogo...");
                PlaySound(TEXT("..\\sounds\\cheatDeactivated.wav"), NULL, SND_SYNC);
                cleanScreen(6, false);
                PlaySound(TEXT("..\\sounds\\nosound.wav"), NULL, SND_LOOP | SND_ASYNC);
                titulo("MÉDIO I", "O jogo começará em breve...");
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "MÉDIO I", 3, 11, 5);
            }
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);

    //Encerrando thread anti-trapaça
    TerminateThread(aCHandle, 0x0);
    CloseHandle(aCHandle);

    cleanScreen(2, false);
    currentProgressionBanner("MÉDIO I", progresso, acertos, erros, pts);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 10; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("MÉDIO I", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];

        if (numPergunta == 1) { // Primeira pergunta
            altAtuais[0] = '-';
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        } else if (numPergunta == totPerguntas) {// Última pergunta
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = '-';
        } else { // Demais perguntas
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        }

        newPergunta(false, "MÉDIO I", numPergunta, '-', altAtuais[0], altAtuais[1], altAtuais[2], '-', &acertos, &erros, &pts, progresso);
    }
    fimJogo("MÉDIO I", pts, acertos, totPerguntas);
    return;
}

/* 3) JOGAR - NÍVEL MÉDIO II */
void opcaoB3() {
    int cont = 30;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[11];
    int progresso[11] = {2,2,2,2,2,2,2,2,2,2,2};
    char letras[11] = {'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;
    mostrarLetras = true;

    if(confirmarJogo("MÉDIO II", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "MÉDIO II", 3, 8, 5);

    titulo("MÉDIO II", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    textColor(WHITE, _BLACK);

    do{
        if (mostrarLetras) {
            setlocale(LC_ALL, "C");
            linhaCol(12, 36); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tente memorizar as letras abaixo e boa sorte!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");

            printAlfabeto('N', 16, 31, 1);
            printAlfabeto('P', 16, 42, 1);
            printAlfabeto('Q', 16, 53, 1);
            printAlfabeto('R', 16, 64, 1);
            printAlfabeto('S', 16, 75, 1);
            printAlfabeto('T', 16, 86, 1);

            printAlfabeto('V', 23, 37, 1);
            printAlfabeto('W', 23, 48, 1);
            printAlfabeto('X', 23, 59, 1);
            printAlfabeto('Y', 23, 70, 1);
            printAlfabeto('Z', 23, 81, 1);

            setlocale(LC_ALL, "C");
            linhaCol(28, 32); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Cuidado com o ");
            textColor(_BLACK, BROWN);
            printf("temporizador");
            textColor(_BLACK, WHITE);
            printf(", situado na barra inferior!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            mostrarLetras = false;
        }
        if (!isTextEditingEnabled) {
            if ((cont != 40) && (cont % 10 == 0 || cont <= 5)){
                textColor(_BLACK, LIGHTRED);
            } else {
                textColor(_BLACK, BROWN);
            }
            setlocale(LC_ALL, "C");
            linhaCol(37, 41);printf("  %c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tempo restante: ");
            if (cont < 10) printf("0");
            printf("%d segundo(s)", cont);
            setlocale(LC_ALL, "C");
            printf(" %c   ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            textColor(WHITE, _BLACK);
        }
        for (int fast = 0; fast < 70; fast ++) {
            if (isTextEditingEnabled) { //Se a edição de texto do console estiver ativada, um loop será ativo até que a edição seja desativada
                cleanScreen(6, false);
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "MÉDIO II", 3, 8, 6);
                titulo("-", "Modo de Edição Rápida detectada");
                textColor(WHITE, _BLACK);
                cheatBanner();
                while (isTextEditingEnabled){}
                cleanScreen(6, false);
                cont ++;
                linhaCol(20, 30); printf("[ATENÇÃO] Modo de Edição Rápida desativado. Voltando ao jogo...");
                PlaySound(TEXT("..\\sounds\\cheatDeactivated.wav"), NULL, SND_SYNC);
                cleanScreen(6, false);
                PlaySound(TEXT("..\\sounds\\nosound.wav"), NULL, SND_LOOP | SND_ASYNC);
                titulo("MÉDIO II", "O jogo começará em breve...");
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "MÉDIO II", 3, 8, 5);
            }
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);

    //Encerrando thread anti-trapaça
    TerminateThread(aCHandle, 0x0);
    CloseHandle(aCHandle);

    cleanScreen(2, false);
    currentProgressionBanner("MÉDIO II", progresso, acertos, erros, pts);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 11; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("MÉDIO II", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];

        if (numPergunta == 1) { // Primeira pergunta
            altAtuais[0] = '-';
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        } else if (numPergunta == totPerguntas) {// Última pergunta
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = '-';
        } else { // Demais perguntas
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        }
        newPergunta(false, "MÉDIO II", numPergunta, '-', altAtuais[0], altAtuais[1], altAtuais[2], '-', &acertos, &erros, &pts, progresso);
    }
    fimJogo("MÉDIO II", pts, acertos, totPerguntas);
    return;
}

/* 4) JOGAR - NÍVEL DIFÍCIL */
void opcaoB4() {
    int cont = 50;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[26];
    int progresso[26] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    char letras[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char altAtuais[5] = {' ', ' ', ' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    mostrarLetras = true;

    if(confirmarJogo("DIFÍCIL", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "DIFÍCIL", 3, 15, 5);

    titulo("DIFÍCIL", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    textColor(WHITE, _BLACK);

    do{
        if (mostrarLetras) {
            setlocale(LC_ALL, "C");
            linhaCol(10, 8); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tente memorizar as letras abaixo e boa sorte! Cuidado com o ");
            textColor(_BLACK, BROWN);
            printf("temporizador");
            textColor(_BLACK, WHITE);
            printf(", situado na barra inferior!");
            setlocale(LC_ALL, "C");
            printf(" %c", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");

            printAlfabeto('A', 14, 9, 1);
            printAlfabeto('B', 14, 20, 1);
            printAlfabeto('C', 14, 31, 1);
            printAlfabeto('D', 14, 42, 1);
            printAlfabeto('E', 14, 53, 1);
            printAlfabeto('F', 14, 64, 1);
            printAlfabeto('G', 14, 75, 1);
            printAlfabeto('H', 14, 86, 1);
            printAlfabeto('I', 14, 97, 1);
            printAlfabeto('J', 14, 108, 1);

            printAlfabeto('K', 20, 9, 1);
            printAlfabeto('L', 20, 20, 1);
            printAlfabeto('M', 20, 31, 1);
            printAlfabeto('N', 20, 42, 1);
            printAlfabeto('O', 20, 53, 1);
            printAlfabeto('P', 20, 64, 1);
            printAlfabeto('Q', 20, 75, 1);
            printAlfabeto('R', 20, 86, 1);
            printAlfabeto('S', 20, 97, 1);
            printAlfabeto('T', 20, 108, 1);

            printAlfabeto('U', 26, 31, 1);
            printAlfabeto('V', 26, 42, 1);
            printAlfabeto('W', 26, 53, 1);
            printAlfabeto('X', 26, 64, 1);
            printAlfabeto('Y', 26, 75, 1);
            printAlfabeto('Z', 26, 86, 1);
            mostrarLetras = false;
        }
        if (!isTextEditingEnabled) {
            if ((cont != 60) && (cont % 10 == 0 || cont <= 5)){
                textColor(_BLACK, LIGHTRED);
            } else {
                textColor(_BLACK, BROWN);
            }
            setlocale(LC_ALL, "C");
            linhaCol(37, 41);printf("  %c ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            printf("Tempo restante: ");
            if (cont < 10) printf("0");
            printf("%d segundo(s)", cont);
            setlocale(LC_ALL, "C");
            printf(" %c   ", 254);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            textColor(WHITE, _BLACK);
        }
        for (int fast = 0; fast < 70; fast ++) {
            if (isTextEditingEnabled) { //Se a edição de texto do console estiver ativada, um loop será ativo até que a edição seja desativada
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "DIFÍCIL", 3, 15, 6);
                cleanScreen(6, false);
                titulo("-", "Modo de Edição Rápida detectada");
                textColor(WHITE, _BLACK);
                cheatBanner();
                while (isTextEditingEnabled){}
                cleanScreen(6, false);
                cont ++;
                linhaCol(20, 30); printf("[ATENÇÃO] Modo de Edição Rápida desativado. Voltando ao jogo...");
                PlaySound(TEXT("..\\sounds\\cheatDeactivated.wav"), NULL, SND_SYNC);
                cleanScreen(6, false);
                PlaySound(TEXT("..\\sounds\\nosound.wav"), NULL, SND_LOOP | SND_ASYNC);
                titulo("DIFÍCIL", "O jogo começará em breve...");
                topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "DIFÍCIL", 3, 15, 5);
            }
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);

    //Encerrando thread anti-trapaça
    TerminateThread(aCHandle, 0x0);
    CloseHandle(aCHandle);

    cleanScreen(2, false);
    currentProgressionBanner("DIFÍCIL", progresso, acertos, erros, pts);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 26; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("DIFÍCIL", tituloPergunta);

        if (numPergunta == 1) { // Primeira pergunta
            altAtuais[0] = '-';
            altAtuais[1] = '-';
            altAtuais[2] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[3] = letras[ordem[numPergunta - 0] - 1];
            altAtuais[4] = letras[ordem[numPergunta + 1] - 1];
        } else if (numPergunta == 2) { // Segunda pergunta
            altAtuais[0] = '-';
            altAtuais[1] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[2] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[3] = letras[ordem[numPergunta + 0] - 1];
            altAtuais[4] = letras[ordem[numPergunta + 1] - 1];
        } else if (numPergunta == totPerguntas - 1) {// Penúltima pergunta
            altAtuais[0] = letras[ordem[numPergunta - 3] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[2] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[3] = letras[ordem[numPergunta - 0] - 1];
            altAtuais[4] = '-';
        } else if (numPergunta == totPerguntas) {// Última pergunta
            altAtuais[0] = letras[ordem[numPergunta - 3] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[2] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[3] = '-';
            altAtuais[4] = '-';
        } else { // Demais perguntas
            altAtuais[0] = letras[ordem[numPergunta - 3] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[2] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[3] = letras[ordem[numPergunta + 0] - 1];
            altAtuais[4] = letras[ordem[numPergunta + 1] - 1];
        }
        newPergunta(false, "DIFÍCIL", numPergunta, altAtuais[0], altAtuais[1], altAtuais[2], altAtuais[3], altAtuais[4], &acertos, &erros, &pts, progresso);

    }
    fimJogo("DIFÍCIL", pts, acertos, totPerguntas);
    return;
}

/* 5) JOGAR - MODO ??? */
void opcaoB5() {
    DWORD threadId;
    DWORD threadId2;

    HANDLE hThread;
    HANDLE hThread2;

    cleanScreen(1, true);

    titulo("-", "Você caiu em um \"Rickroll\"");

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    box(36, 39, 38, 80);

    setlocale(LC_ALL, "C");
    linhaCol(38, 39); printf("%c", 193);
    linhaCol(38, 80); printf("%c", 193);

    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    topBannerContent("DIFICULDADE SELECIONADA", 2, 23, "???", 2, 19, 4);

    textColor(_BLACK, BROWN);
    linhaCol(37, 40); printf("               Rickroll!                ");
    textColor(_BLACK, WHITE);

    hThread = CreateThread(NULL, 0x0, nicetry, NULL, 0, &threadId);
    hThread2 = CreateThread(NULL, 0x0, ricklyrics, NULL, 0, &threadId2);
    PlaySound(TEXT("..\\sounds\\nicetry.wav"), NULL, SND_ASYNC);
    pressEnter();

    TerminateThread(hThread, 0x0);
    TerminateThread(hThread2, 0x0);

    CloseHandle(hThread);
    CloseHandle(hThread2);

    cleanScreen(4, true);

    PlaySound(TEXT("..\\sounds\\menu.wav"), NULL, SND_LOOP | SND_ASYNC);
}

/* 6) Ranking dos Jogadores*/
void opcaoA2() {
    int opt = 1, lastOpt, numJogadores;
    bool menuTitle = true;

    char lista [6][40] = {"Ranking - NÍVEL FÁCIL","Ranking - NÍVEL MÉDIO I","Ranking - NÍVEL MÉDIO II","Ranking - NÍVEL DIFÍCIL","Resetar registros","Voltar ao Menu Principal"};
    char lista2 [2][40] = {"SIM, eu quero resetar tudo.", "NÃO, eu quero cancelar."};
    titulo("-", "Ranking dos Jogadores");
    topBannerContent("VOCÊ ESTÁ VISUALIZANDO O", 2, 23, "RANKING", 3, 11, 2);

    do {
        // Verificando ou criando os arquivos de ranking caso não existam
        verificarOuCriarArquivo("facil.txt");
        verificarOuCriarArquivo("medio1.txt");
        verificarOuCriarArquivo("medio2.txt");
        verificarOuCriarArquivo("dificil.txt");

        // Ler e exibir as pontuações atualizadas
        Jogador jogadores[7];
        if (opt == 1) {
            exibirBannerDificuldade("-", 0, 0, "FÁCIL", 9, 16);
            numJogadores = lerPontuacoes("facil.txt", jogadores, 7, false);
        } else if (opt == 2) {
            exibirBannerDificuldade("-", 0, 0, "MÉDIO I", 9, 11);
            numJogadores = lerPontuacoes("medio1.txt", jogadores, 7, false);
        } else if (opt == 3) {
            exibirBannerDificuldade("-", 0, 0, "MÉDIO II", 9, 8);
            numJogadores = lerPontuacoes("medio2.txt", jogadores, 7, false);
        } else if (opt == 4) {
            exibirBannerDificuldade("-", 0, 0, "DIFÍCIL", 9, 14);
            numJogadores = lerPontuacoes("dificil.txt", jogadores, 7, false);
        }

        linhaCol(14, 8); printf("Posição");
        linhaCol(14, 23); printf("Nome");
        linhaCol(14, 34); printf("Rank");
        linhaCol(14, 43); printf("Pontuação");
        linhaCol(14, 58); printf("Tempo");
        linhaCol(15, 6); printf("_____________________________________________________________");

        for (int cont = 0; cont < numJogadores; cont ++) {
            if (cont == 0) textColor(YELLOW, _BLACK);
            else if (cont == 1) textColor(LIGHTGRAY, _BLACK);
            else if (cont == 2) textColor(BROWN, _BLACK);
            else textColor(DARKGRAY, _BLACK);

            linhaCol(17 + (cont * 2), 10); printf("%dº", cont + 1);
            linhaCol(17 + (cont * 2), 19); printf("%s", jogadores[cont].nome);
            linhaCol(17 + (cont * 2), 36); printf("%c", jogadores[cont].nota);
            linhaCol(17 + (cont * 2), 45);
            if (jogadores[cont].pontuacao < 1000) printf("0");
            if (jogadores[cont].pontuacao < 100) printf("0");
            if (jogadores[cont].pontuacao < 10) printf("0");
            printf("%d", jogadores[cont].pontuacao);
            linhaCol(17 + (cont * 2), 56);
            printf("%dmin", ((int)jogadores[cont].tempo/60));
            if ((jogadores[cont].tempo % 60) < 10) printf("0");
            printf("%dseg", (jogadores[cont].tempo%60));
        }
        textColor(WHITE, _BLACK);
        linhaCol(30, 6); printf("_____________________________________________________________");

        if (menuTitle) {
            setlocale(LC_ALL, "C");
            linhaCol(8,72);printf("%c", 197);
            for (int divisoria = 9; divisoria < 32; divisoria ++) {
                linhaCol(divisoria,72); printf("%c", 179);
            }
            linhaCol(32,72); printf("%c", 193);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");

            setlocale(LC_ALL, "C");
            SetConsoleOutputCP(CP_UTF8);
            linhaCol(12, 96); printf("\u25b2");
            linhaCol(28, 96); printf("\u25bc");
            SetConsoleOutputCP(850);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");
            menuTitle = false;
        }
        lastOpt = opt;
        opt = modeloMenu(13, 82, 6, 4, lista, opt);

        if (opt == 5) {
            textColor(LIGHTRED, _BLACK);
            box(9, 19, 31, 101);
            textColor(WHITE, _BLACK);

            linhaCol(12, 23); printf("Você está prestes a ");
            textColor(LIGHTRED, _BLACK);
            printf("DELETAR TODOS OS REGISTROS");
            textColor(WHITE, _BLACK);
            printf(" de pontuação da dificuldade:");
            if (lastOpt == 1) exibirBannerDificuldade("-", 0, 0, "FÁCIL", 14, 40);
            else if (lastOpt == 2) exibirBannerDificuldade("-", 0, 0, "MÉDIO I", 14, 35);
            else if (lastOpt == 3) exibirBannerDificuldade("-", 0, 0, "MÉDIO II", 14, 32);
            else if (lastOpt == 4) exibirBannerDificuldade("-", 0, 0, "DIFÍCIL", 14, 38);
            linhaCol(20, 48); printf("Deseja ");
            textColor(BROWN, _BLACK);
            printf("MESMO");
            textColor(WHITE, _BLACK);
            printf(" prosseguir?");

            setlocale(LC_ALL, "C");
            SetConsoleOutputCP(CP_UTF8);
            linhaCol(22, 59); printf("\u25b2");
            linhaCol(30, 59); printf("\u25bc");
            SetConsoleOutputCP(850);
            setlocale(LC_ALL, "Portuguese_Brazil.1252");

            opt = modeloMenu(23, 44, 2, 0, lista2, 2);
            if (opt == 1) {
                if (lastOpt == 1) apagarArquivo("facil.txt");
                else if (lastOpt == 2) apagarArquivo("medio1.txt");
                else if (lastOpt == 3) apagarArquivo("medio2.txt");
                else if (lastOpt == 4) apagarArquivo("dificil.txt");
            }
            opt = lastOpt;
            cleanScreen(6, false);
            menuTitle = true;
        } else if (opt < 6) cleanScreen(9, false);
    } while(opt < 6);
    cleanScreen(1, false);
}

/* 7) INSTRUÇÕES DO JOGO */
int opcaoA3() {
    titulo("-", "Tela de Instruções");
    int opt = 0, finalopt = 0;
    char lista[2][40] = {"SIM, eu quero ver o exemplo!", "NÃO, eu quero voltar para o menu."};

    topBannerContent("VOCÊ ESTÁ VENDO AS", 2, 25, "INSTRUÇÕES", 3, 15, 6);

    setlocale(LC_ALL, "C");
    linhaCol(8,72);printf("%c", 197);
    for (int divisoria = 9; divisoria < 32; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(32,72);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    textColor(WHITE, _BLACK);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    linhaCol(19, 96); printf("\u25b2");
    linhaCol(27, 96); printf("\u25bc");
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    topBannerContent("Deseja ver um", 12, 87, "EXEMPLO", 13, 79, 6);

    opt = modeloMenu(20, 78, 2, 3, lista, 1);

    if (opt == 2 || opt == 9) {
        cleanScreen(1, true);
        bottomBannerTitle(0);
        return 0;
    }

    int pts, acertos, erros, tecla;
    int progresso[5] = {2,2,2,2,2};

    do{
        pts = 0, acertos = 0, erros = 0, tecla = 0;
        cleanScreen(1, false);
        newPergunta(true, "FÁCIL", 1, '-', '-', 'A', 'E', '-', &acertos, &erros, &pts, progresso);
        cleanScreen(1, true);
        topBannerContent("VOCÊ ESTÁ VENDO AS", 2, 25, "INSTRUÇÕES", 3, 15, 2);
        linhaCol(33, 14); printf("          __ _____ _____ _____    ____  _____    _____ _____ _____ _____ __    _____        ");
        linhaCol(34, 14); printf("       __|  |     |   __|     |  |    \\|     |  | __  | __  |  _  |_   _|  |  |   __|       ");
        linhaCol(35, 14); printf("      |  |  |  |  |  |  |  |  |  |  |  |  |  |  | __ -|    -|     |_| |_|  |__|   __|       ");
        linhaCol(36, 14); printf("      |_____|_____|_____|_____|  |____/|_____|  |_____|__|__|__|__|_____|_____|_____|       ");
        linhaCol(37, 45); printf("Feito com ");
        textColor(LIGHTRED, _BLACK);
        SetConsoleOutputCP(CP_UTF8);
        setlocale(LC_ALL, "C");
        printf("\u2665");
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
        SetConsoleOutputCP(850);
        textColor(WHITE, _BLACK);
        printf(" por Guilherme Cordeiro");
        Sleep(50);
        box(13, 35, 27, 85);
        linhaCol(16, 43); printf("Deseja ver este exemplo novamente?");
        opt = modeloMenu(18, 42, 2, 0, lista, 2);
    }while(opt != 2 && opt != 9);

    cleanScreen(1, true);
    bottomBannerTitle(0);
    return 0;
}

/* 8) CRÉDITOS DO JOGO */
void opcaoA4() {
    titulo("-", "Créditos do Jogo");

    topBannerContent("VOCÊ ESTÁ VENDO OS", 2, 25, "CRÉDITOS", 3, 4, 6);

    textColor(LIGHTBLUE, _BLACK);
    box(10, 3, 30, 53);
    textColor(LIGHTCYAN, _BLACK);
    box(11, 55, 29, 117);
    textColor(WHITE, _BLACK);

    textColor(LIGHTBLUE, _BLACK);
    linhaCol(11, 12); printf(" _____                 _ _       ");
    linhaCol(12, 12); printf("|     |___ ___ ___ ___|_| |_ ___ ");
    linhaCol(13, 12); printf("|   --| . |   |  _| -_| |  _| . |");
    linhaCol(14, 12); printf("|_____|___|_|_|___|___|_|_| |___|");
    linhaCol(15, 19); printf("original do projeto");
    textColor(WHITE, _BLACK);

    linhaCol(18, 6); printf("     Este jogo foi originalmente desenvolvido");
    linhaCol(20, 6); printf("como forma de avaliação parcial do ");
    textColor(BROWN, _BLACK);
    printf("trabalho fi-"); //Amarelo
    linhaCol(22, 6); printf("nal ");
    textColor(WHITE, _BLACK);
    printf("do 1º ano do Curso Técnico em Informática"); //Amarelo
    textColor(WHITE, _BLACK);
    printf(",");
    linhaCol(24, 6); printf("ofertado pelo ");
    textColor(LIGHTGREEN, _BLACK);
    printf("IFPR - Campus Colombo"); //Verde
    textColor(WHITE, _BLACK);
    printf(". Tal tra-");
    linhaCol(26, 6); printf("balho foi apresentado no ano de 2017 sob o nome");
    textColor(BROWN, _BLACK);
    linhaCol(28, 6); printf("'Acessibilidade das PcD visual na atualidade'"); //Amarelo
    textColor(WHITE, _BLACK);
    printf(".");

    //linhaCol(10, 65); printf("Obrigado pelo apoio!");
    textColor(LIGHTCYAN, _BLACK);
    linhaCol(12, 57); printf(" _____               _         _               _           ");
    linhaCol(13, 57); printf("|  _  |___ ___ ___ _| |___ ___|_|_____ ___ ___| |_ ___ ___ ");
    linhaCol(14, 57); printf("|     | . |  _| .'| . | -_|  _| |     | -_|   |  _| . |_ -|");
    linhaCol(15, 57); printf("|__|__|_  |_| |__,|___|___|___|_|_|_|_|___|_|_|_| |___|___|");
    linhaCol(16, 57); printf("      |___|                                                ");
    //textColor(WHITE, _BLACK);
    linhaCol(16, 71); printf("aos membros da equipe do trabalho original!");
    textColor(WHITE, _BLACK);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    linhaCol(19, 58); printf("\u2022");
    linhaCol(21, 58); printf("\u2022");
    linhaCol(23, 58); printf("\u2022");
    linhaCol(25, 58); printf("\u2022");
    linhaCol(27, 58); printf("\u2022");
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    linhaCol(19, 60); printf("Arthur Ogg - ");
    textColor(LIGHTGREEN, _BLACK);
    printf("'https://github.com/Arthur-Diesel'"); //Verde
    textColor(WHITE, _BLACK);
    linhaCol(21, 60); printf("Guilherme Cordeiro ");
    textColor(BROWN, _BLACK);
    printf("(dev.)");
    textColor(WHITE, _BLACK);
    printf(" - ");
    textColor(LIGHTGREEN, _BLACK);
    printf("Contatos na próxima tela!"); //Verde
    textColor(WHITE, _BLACK);
    linhaCol(23, 60); printf("João Lucas - ");
    textColor(LIGHTRED, _BLACK);
    printf("Nenhuma rede social foi achada... perdão :("); //Verde
    textColor(WHITE, _BLACK);
    linhaCol(25, 60); printf("Lucas Pereira - ");
    textColor(LIGHTGREEN, _BLACK);
    printf("'https://github.com/Luc45-Pereira'"); //Verde
    textColor(WHITE, _BLACK);
    linhaCol(27, 60); printf("Matheus Delay - ");
    textColor(LIGHTGREEN, _BLACK);
    printf("'https://twitter.com/DelayMath'"); //Verde
    textColor(WHITE, _BLACK);

    exibirBannerAnimado();
    topBannerContent("VOCÊ ESTÁ VENDO OS", 2, 25, "CRÉDITOS", 3, 4, 4);

    pressEnter();
    cleanScreen(4, true);
    exibirTelaRedes(0, "-");
    cleanScreen(1, true);
    textColor(WHITE, _BLACK);
}

/* 9) ALTERAR EXIBIÇÃO DO JOGO */
void opcaoA5() {
    // Armazena a resolução de tela do monitor
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    if ((screenWidth == 1280 && screenHeight == 600) && isFullScreen) {
        topBannerContent("VOCÊ ESTÁ NO", 2, 29, "MENU", 3, 9, 4);
        textColor(LIGHTRED, _BLACK);
        box(13, 12, 27, 109);
        linhaCol(14, 43); printf("                               __ ");
        linhaCol(15, 43); printf(" _____ _               /\\/    |  |");
        linhaCol(16, 43); printf("|  _  | |_ ___ ___ ___ ___ ___|  |");
        linhaCol(17, 43); printf("|     |  _| -_|   |  _| .'| . |__|");
        linhaCol(18, 43); printf("|__|__|_| |___|_|_|___|__,|___|__|");
        linhaCol(19, 43); printf("                    |             ");
        textColor(WHITE, _BLACK);
        linhaCol(21, 15); printf("Devido à ");
        textColor(BROWN, _BLACK);
        printf("resolução de tela ");
        textColor(WHITE, _BLACK);
        printf("do seu monitor, ");
        textColor(LIGHTRED, _BLACK);
        printf("não é possível alterar o jogo ");
        textColor(WHITE, _BLACK);
        printf("para o modo Janela.");
        linhaCol(24, 20); printf("Você continuará no modo Tela Cheia. ");
        textColor(BROWN, _BLACK);
        printf("Pressione Enter para voltar ao Menu Principal.");
        textColor(WHITE, _BLACK);
        pressEnter();
        cleanScreen(6, false);
    } else {
        cleanScreen(1, false);
        setScreenMode(true);
    }
}

/* 10) SAIR DO JOGO */
void opcaoA6() {
    system("cls");

    char wav[30];
    strcat(strcpy(wav, caminho), "ending.wav");
    Mix_Chunk *ending = Mix_LoadWAV(wav);
    strcat(strcpy(wav, caminho), "closing.wav");
    Mix_Chunk *closing = Mix_LoadWAV(wav);
    Mix_PlayChannel(0, ending, 0);
    titulo("-", "Obrigado por Jogar!");
    exibirBannerDificuldade("MUITO OBRIGADO POR JOGAR O", 15, 47, "AGRADECIMENTO", 15, 33);
    Sleep(1100);
    system("cls");
    exibirBannerDificuldade("MUITO OBRIGADO POR JOGAR O", 2, 47, "AGRADECIMENTO", 2, 33);
    Sleep(600);
    box(8, 3, 32, 117);
    exibirTelaRedes(1, "-");
    Mix_PlayChannel(0, closing, 0);
    titulo("-", "Saindo do Jogo...");
    if(!isFullScreen) addFade(8, 0, 0);
    else addFade(18, 0, 0);
    addFade(37, 175, 1);
    system("cls");
    system("mode con:cols=120 lines=30");
    showCursor();
}
