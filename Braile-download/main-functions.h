/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
 */

/* 0) MENU PRINCIPAL */
int mainMenu() {
    int opt = 0;
    char lista [8][40] = {"Jogar - NÍVEL FÁCIL","Jogar - NÍVEL MÉDIO I","Jogar - NÍVEL MÉDIO II","Jogar - NÍVEL DIFÍCIL","Ranking dos Jogadores","Instruções do Jogo","Créditos do Jogo","Sair do Jogo"};
    //char lista [8][40] = {"Jogar - NÍVEL FÁCIL","???","???","???","Ranking dos Jogadores","Instruções do Jogo","Créditos do Jogo","Sair do Jogo"};


    titulo("-", "Menu Principal");
    topBannerContent("VOCÊ ESTÁ NO:", 2, 28, "MENU", 3, 9);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    linhaCol(10, 59); printf("\u25b2");
    linhaCol(30, 59); printf("\u25bc");
    textColor(WHITE, _BLUE);
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese");

    opt = modeloMenu(11, 47, 8, lista);

    return opt;
}

/* 1) JOGAR - NÍVEL FÁCIL */
void opcao1(){
    int cont = 20;
    int pts = 0, acertos = 0, erros = 0, tecla = 0;
    int ordem[5];
    int progresso[5] = {2,2,2,2,2};
    char letras[5] = {'A', 'E', 'I', 'O', 'U'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;

    if(confirmarJogo("FÁCIL", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA:", 2, 23, "FÁCIL", 3, 15);

    titulo("FÁCIL", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(16, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto('A', 20, 37, true);
    printAlfabeto('E', 20, 48, true);
    printAlfabeto('I', 20, 59, true);
    printAlfabeto('O', 20, 70, true);
    printAlfabeto('U', 20, 81, true);

    setlocale(LC_ALL, "C");
    linhaCol(25, 32); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Cuidado com o ");
    textColor(_BLACK, BROWN);
    printf("temporizador");
    textColor(_BLACK, WHITE);
    printf(", situado na barra inferior!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        if ((cont != 20) && (cont % 10 == 0 || cont <= 3)){
            textColor(_BLACK, LIGHTRED);
        } else {
            textColor(_BLACK, BROWN);
        }
        setlocale(LC_ALL, "C");
        linhaCol(37, 43);printf("%c ", 254);
        setlocale(LC_ALL, "Portuguese");
        printf("Tempo restante: ");
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        setlocale(LC_ALL, "C");
        printf(" %c", 254);
        setlocale(LC_ALL, "Portuguese");
        for (int fast = 0; fast < 70; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);
    cleanScreen(2);
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
        newPergunta("FÁCIL", numPergunta, altAtuais[0], altAtuais[1], altAtuais[2], &acertos, &erros, &pts, progresso);
    }
    fimJogo("FÁCIL", pts, acertos, totPerguntas);
    return;
}

/* 2) JOGAR - NÍVEL MÉDIO I */
void opcao2(){
    int cont = 35;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[10];
    int progresso[10] = {2,2,2,2,2,2,2,2,2,2};
    char letras[10] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;

    if(confirmarJogo("MÉDIO I", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA:", 2, 20, "MÉDIO I", 5, 20);

    titulo("MÉDIO I", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(12, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto('B', 17, 37, true);
    printAlfabeto('C', 17, 48, true);
    printAlfabeto('D', 17, 59, true);
    printAlfabeto('F', 17, 70, true);
    printAlfabeto('G', 17, 81, true);

    printAlfabeto('H', 24, 37, true);
    printAlfabeto('J', 24, 48, true);
    printAlfabeto('K', 24, 59, true);
    printAlfabeto('L', 24, 70, true);
    printAlfabeto('M', 24, 81, true);

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        if ((cont != 35) && (cont % 10 == 0 || cont <= 5)){
            textColor(_BLACK, LIGHTRED);
        } else {
            textColor(_BLACK, WHITE);
        }
        linhaCol(37, 45);printf("Tempo restante: ");
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 70; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);
    cleanScreen(2);
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

        newPergunta("MÉDIO I", numPergunta, altAtuais[0], altAtuais[1], altAtuais[2], &acertos, &erros, &pts, progresso);
    }
    fimJogo("MÉDIO I", pts, acertos, totPerguntas);
    return;
}

/* 3) JOGAR - NÍVEL MÉDIO II */
void opcao3(){
    int cont = 40;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[11];
    int progresso[11] = {2,2,2,2,2,2,2,2,2,2,2};
    char letras[11] = {'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;

    if(confirmarJogo("MÉDIO II", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA:", 2, 20, "MÉDIO II", 5, 20);

    titulo("MÉDIO II", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(12, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto('N', 17, 31, true);
    printAlfabeto('P', 17, 42, true);
    printAlfabeto('Q', 17, 53, true);
    printAlfabeto('R', 17, 64, true);
    printAlfabeto('S', 17, 75, true);
    printAlfabeto('T', 17, 86, true);

    printAlfabeto('V', 24, 37, true);
    printAlfabeto('W', 24, 48, true);
    printAlfabeto('X', 24, 59, true);
    printAlfabeto('Y', 24, 70, true);
    printAlfabeto('Z', 24, 81, true);

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        if ((cont != 40) && (cont % 10 == 0 || cont <= 5)){
            textColor(_BLACK, LIGHTRED);
        } else {
            textColor(_BLACK, WHITE);
        }
        linhaCol(37, 45);printf("Tempo restante: ");
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 70; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);
    cleanScreen(2);
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
        newPergunta("MÉDIO II", numPergunta, altAtuais[0], altAtuais[1], altAtuais[2], &acertos, &erros, &pts, progresso);
    }
    fimJogo("MÉDIO II", pts, acertos, totPerguntas);
    return;
}

/* 4) JOGAR - NÍVEL DIFÍCIL */
void opcao4(){
    int cont = 60;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[26];
    int progresso[26] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    char letras[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;

    if(confirmarJogo("DIFÍCIL", progresso) == 0) return 0;
    topBannerContent("DIFICULDADE SELECIONADA:", 2, 20, "DIFÍCIL", 5, 20);

    titulo("DIFÍCIL", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(10, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto('A', 14, 9, true);
    printAlfabeto('B', 14, 20, true);
    printAlfabeto('C', 14, 31, true);
    printAlfabeto('D', 14, 42, true);
    printAlfabeto('E', 14, 53, true);
    printAlfabeto('F', 14, 64, true);
    printAlfabeto('G', 14, 75, true);
    printAlfabeto('H', 14, 86, true);
    printAlfabeto('I', 14, 97, true);
    printAlfabeto('J', 14, 108, true);

    printAlfabeto('K', 20, 9, true);
    printAlfabeto('L', 20, 20, true);
    printAlfabeto('M', 20, 31, true);
    printAlfabeto('N', 20, 42, true);
    printAlfabeto('O', 20, 53, true);
    printAlfabeto('P', 20, 64, true);
    printAlfabeto('Q', 20, 75, true);
    printAlfabeto('R', 20, 86, true);
    printAlfabeto('S', 20, 97, true);
    printAlfabeto('T', 20, 108, true);

    printAlfabeto('U', 26, 31, true);
    printAlfabeto('V', 26, 42, true);
    printAlfabeto('W', 26, 53, true);
    printAlfabeto('X', 26, 64, true);
    printAlfabeto('Y', 26, 75, true);
    printAlfabeto('Z', 26, 86, true);

    setlocale(LC_ALL, "C");
    linhaCol(36, 53); printf("%c", 196);
    linhaCol(36, 65); printf("%c", 196);
    linhaCol(38, 53); printf("%c", 196);
    linhaCol(38, 65); printf("%c", 196);

    linhaCol(37, 41); printf("  %c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c   ", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        if ((cont != 60) && (cont % 10 == 0 || cont <= 5)){
            textColor(_BLACK, LIGHTRED);
        } else {
            textColor(_BLACK, WHITE);
        }
        linhaCol(37, 45);printf("Tempo restante: ");
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 70; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SPACE)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);
    cleanScreen(2);
    currentProgressionBanner("DIFÍCIL", progresso, acertos, erros, pts);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 26; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("DIFÍCIL", tituloPergunta);

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
        newPergunta("DIFÍCIL", numPergunta, altAtuais[0], altAtuais[1], altAtuais[2], &acertos, &erros, &pts, progresso);

    }
    fimJogo("DIFÍCIL", pts, acertos, totPerguntas);
    return;
}

/* 5) Ranking dos Jogadores*/
void opcao5(){
    int tecla;
    titulo("-", "Ranking dos Jogadores");
    cleanScreen(1);
    linhaCol(35, 7); printf("Essa aqui é a futura tela do ranking de jogadores, que está em desenvolvimento. Aproveite a musiquinha! :D");
    linhaCol(36, 41); printf("Pressione a tecla ENTER pra sair daqui.");
    while(1) {
        tecla = getch();
        tecla = (tecla == 0 || tecla == 224) ? getch() : tecla;
        if (tecla == 13) break;
    }
    cleanScreen(1);
}

/* 6) INSTRUÇÕES DO JOGO */
int opcao6(){
    titulo("-", "Tela de Instruções");
    int finalopt = 0;
    char lista[2][40] = {"SIM, eu quero ver um exemplo!", "NÃO, eu quero voltar para o menu."};
    cleanScreen(1);

    topBannerContent("COMO JOGAR O:", 2, 20, "COMO JOGAR", 5, 20);

    setlocale(LC_ALL, "C");
    linhaCol(8,72);printf("%c", 197);
    for (int divisoria = 9; divisoria < 32; divisoria ++) {
        linhaCol(divisoria,72); printf("%c", 179);
    }
    linhaCol(32,72);printf("%c", 193);
    setlocale(LC_ALL, "Portuguese");

    box(11, 19, 13, 52);
    box(15, 5, 27, 67);

    linhaCol(12, 21); printf("1) O QUE É O \"JOGO DO BRAILE\"?");

    linhaCol(17, 8); printf("     O \"Jogo do Braile\" é um simples jogo de memória sob");
    linhaCol(19, 8); printf("a forma de quiz, cujo objetivo é acertar o máximo de per-");
    linhaCol(21, 8); printf("guntas possíveis. Ele tem o intuito de ensinar o sistema");
    linhaCol(23, 8); printf("de escrita tátil \"Braile\" de forma simples e lúdica, para");
    linhaCol(25, 8); printf("pessoas sem deficiência visual.");

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "C");
    linhaCol(29, 30); printf("\u25c4  \u25cf  \u25cb  \u25ba"); //cf de Full, cb de Branco
    setlocale(LC_ALL, "Portuguese");
    SetConsoleOutputCP(850);

    /*linhaCol(17, 2); printf("+------------------------------------------------------------------------------------------+");
    linhaCol(18, 2); printf("|                                  COMO O JOGO FUNCIONA?                                   |");
    linhaCol(19, 2); printf("+------------------------------------------------------------------------------------------+");
    linhaCol(20, 2); printf("| Neste jogo, cada pergunta é composta por:                                                |");
    linhaCol(21, 2); printf("|                                                                                          |");
    linhaCol(22, 2); printf("| * Uma letra exibida em destaque e de acordo com o sistema 'Braile' de escrita; e         |");
    linhaCol(23, 2); printf("| * Quatro letras referentes às alternativas, exibidas de acordo com o alfabeto latino.    |");
    linhaCol(24, 2); printf("|                                                                                          |");
    linhaCol(25, 2); printf("| Para responder tais perguntas, é necessário memorizar as letras que aparecerão na tela   |");
    linhaCol(26, 2); printf("| por alguns segundos.                                                                     |");
    linhaCol(27, 2); printf("+-----------------------------------------------------------------------------------------");*/
    //printf("\t\t        DESEJA VER UM EXEMPLO DO JOGO? (Digite 'S' para Sim ou 'N' para Não): ");


    //exibirBannerDificuldade("EXEMPLO", 0);

    setlocale(LC_ALL, "C");
    SetConsoleOutputCP(CP_UTF8);
    textColor(WHITE, _BLACK);
    linhaCol(19, 96); printf("\u25b2");
    linhaCol(27, 96); printf("\u25bc");
    textColor(WHITE, _BLUE);
    SetConsoleOutputCP(850);
    setlocale(LC_ALL, "Portuguese");

    int opt = modeloMenu(20, 78, 2, lista);

    if (opt == 2) {
        cleanScreen(1);
        return 0;
    }

    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("VEJA SÓ ESTE", 2, 15, "EXEMPLO", 4, 10);
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Como dito anteriormente, neste jogo cada pergunta é composta por:                        |\n");Sleep(tempo);
    printf("\t     |                                                                                          |\n");Sleep(tempo);
    printf("\t     | * Uma letra exibida em destaque e de acordo com o sistema 'Braile' de escrita; e         |\n");Sleep(tempo);
    printf("\t     | * Quatro letras referentes às alternativas, exibidas de acordo com o alfabeto latino.    |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |     Letra escrita em Braile (EM DESTAQUE)     |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto('E', 21, 34, true);
    printf("\n\t\t\t\t   |                                               |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\n\t\t\t\t\t     * Alternativas propostas *\n\n");Sleep(tempo);
    printf("\n\t\t\t\t\t      a) --> A        c) --> E");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n\t\t\t\t\t      b) --> I        d) --> O");Sleep(tempo);
    addFade(4, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("VEJA SÓ ESTE", 2, 15, "EXEMPLO", 4, 10);
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Respondendo a questão corretamente, você ganhará 150 pontos! Veja o exemplo a seguir:    |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |     Letra escrita em Braile (EM DESTAQUE)     |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto('E', 21, 34, true);
    printf("\n\t\t\t\t   |                                               |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\n\t\t\t\t\t      a) --> A        c) --> E");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n\t\t\t\t\t      b) --> I        d) --> O");Sleep(tempo);
    printf("\n\n\t\t\t\t\t       +--------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t\tInsira sua opção : c");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t   |                CERTA RESPOSTA!                | ");Sleep(tempo);
    printf("\n\t\t\t\t   |           VOCÊ GANHOU: +150 PONTOS!           | ");Sleep(tempo);
    printf("\n\t\t\t\t   +----------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("VEJA SÓ ESTE", 2, 15, "EXEMPLO", 4, 10);
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Caso erre a resposta, apenas 50 pontos serão somados à sua pontuação. Veja o exemplo:    |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |     Letra escrita em Braile (EM DESTAQUE)     |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto('E', 21, 34, true);
    printf("\n\t\t\t\t   |                                               |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\n\t\t\t\t\t      a) --> A        c) --> E");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n\t\t\t\t\t      b) --> I        d) --> O");Sleep(tempo);
    printf("\n\n\t\t\t\t\t       +--------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t\tInsira sua opção : a");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t   |     VOCÊ ERROU... RESPOSTA CORRETA: \"c)\"      | ");Sleep(tempo);
    printf("\n\t\t\t\t   |           VOCÊ GANHOU: +50 PONTOS!            | ");Sleep(tempo);
    printf("\n\t\t\t\t   +----------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("VEJA SÓ ESTE", 2, 15, "EXEMPLO", 4, 10);
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Ao encerrar o quiz, será possível analisar o seu desempenho final. Nele você poderá ver: |\n");Sleep(tempo);
    printf("\t     |                                                                                          |\n");Sleep(tempo);
    printf("\t     | * O \"Número de perguntas respondidas corretamente\" / \"Número total de perguntas\"; e      |\n");Sleep(tempo);
    printf("\t     | * A pontuação total com base nos acertos e erros cometidos durante o quiz.               |\n");Sleep(tempo);
    printf("\t     |                                                                                          |\n");Sleep(tempo);
    printf("\t     | Divirta-se com o \"Jogo do Braile\"!                                                       |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t       +---------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t       |       EXEMPLO DAS ESTATÍSTICAS        |\n");Sleep(tempo);
    printf("\t\t\t\t       +---------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       |        Total de ACERTOS: 5 / 5        |\n");
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       |         Total de PONTOS: 750          |\n");
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       +---------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t\t\t\t *****");Sleep(tempo);
    addFade(1, tempo, 1);
    banner();
    addFade(2, 50, 1);
    printf("\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getche();
    addFade(39, 25, 1);
    system("cls");
    return 0;
}

/* 7) CRÉDITOS DO JOGO */
void opcao7(){
    system("cls");
    titulo("-", "Créditos do Jogo");
    printf("\t\t\t\t\t                __                  \n");Sleep(tempo);
    printf("\t\t\t\t\t    _____      /_/  _ _ _           \n");Sleep(tempo);
    printf("\t\t\t\t\t   |     |___ ___ _| |_| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t\t\t   |   --|  _| -_| . | |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t\t\t   |_____|_| |___|___|_|_| |___|___|");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t +-----------------------------------------------------------------------------------+ ");Sleep(tempo);
    printf("\n\t\t | Este jogo foi originalmente desenvolvido como forma de uma avaliação parcial do   | ");Sleep(tempo);
    printf("\n\t\t | trabalho final do 1º ano do Curso Técnico em Informática, ofertado pelo Instituto | ");Sleep(tempo);
    printf("\n\t\t | Federal do Paraná - Campus Colombo. Tal trabalho foi apresentado no ano de 2017   | ");Sleep(tempo);
    printf("\n\t\t | sob o nome 'Acessibilidade das pessoas com deficiência visual na atualidade'.     | ");Sleep(tempo);
    printf("\n\t\t +-----------------------------------------------------------------------------------+ \n");Sleep(tempo);


    printf("\t\t\t      _____               _         _               _           \n");Sleep(tempo);
    printf("\t\t\t     |  _  |___ ___ ___ _| |___ ___|_|_____ ___ ___| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t     |     | . |  _| .'| . | -_|  _| |     | -_|   |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t     |__|__|_  |_| |__,|___|___|___|_|_|_|_|___|_|_|_| |___|___|\n");Sleep(tempo);
    printf("\t\t\t           |___|                                                \n");Sleep(tempo);
    printf("\t\t\t(Membros da equipe do trabalho original - Obrigado por todo o apoio!) \n");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n     -> Arthur Ogg - 'https://github.com/Arthur-Diesel'\n");Sleep(tempo);
    printf("\n     -> Guilherme Cordeiro - 'https://github.com/gui-cordeiro'\n");Sleep(tempo);
    printf("\n     -> João Lucas - Nenhum contato dele foi encontrado, mas fica aqui registrado o agradecimento a ele!\n");Sleep(tempo);
    printf("\n     -> Lucas Pereira - 'https://github.com/Luc45-Pereira'\n");Sleep(tempo);
    printf("\n     -> Matheus Delay - 'https://twitter.com/DelayMath'\n");Sleep(tempo);
    banner();
    printf("\n\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getch();
    system("cls");
    addFade(4, 50, 0);
    exibirTelaRedes(0);
    printf("\n\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    addFade(39, 25, 1);
    system("cls");
}

/* 8) SAIR DO JOGO */
void opcao8(){
    system("cls");
    PlaySound(TEXT("..\\sounds\\ending.wav"), NULL, SND_ASYNC);
    titulo("-", "Obrigado por Jogar!");
    exibirBannerDificuldade("MUITO OBRIGADO POR JOGAR O", 2, 47, "AGRADECIMENTO", 3, 33);
    Sleep(1800);
    exibirTelaRedes(1);
    PlaySound(TEXT("..\\sounds\\intro.wav"), NULL, SND_ASYNC);
    titulo("-", "Saindo do Jogo...");
    addFade(8, 0, 0);
    addFade(37, 175, 1);
    system("cls");
    system("mode con:cols=120 lines=30");
    showCursor();
}
