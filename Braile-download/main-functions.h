/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
 */

/* 0) MENU PRINCIPAL */
int menu(int lin1, int col1, int qtd, char lista[][40]) {
    int opt = 1, lin2, col2, linhaSelecionada, i, tamMaxItem, tecla, limpar, espacamento, popup;
    titulo("-", "Menu Principal");

    topBannerContent("MENU");

    addFade(3, 50, 1);

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
    setlocale(LC_ALL, "C");
    textColor(WHITE, _BLACK);
    linhaCol(lin1 - 1, col1 + 12); printf("%c", 30);
    linhaCol(lin2 + 1, col1 + 12); printf("%c", 31);
    textColor(WHITE, _BLUE);
    setlocale(LC_ALL, "Portuguese");

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

        bottomBannerContent(opt);

        //Aguarda teclas
        linhaCol(1,1);
        tecla = getch();
        if (tecla == 0 || tecla == 224) tecla = getch();
        /*if (GetAsyncKeyState(VK_UP)&1)
            printf("Seta pra cima pressionada!");
        else if (GetAsyncKeyState(VK_DOWN)&1)
            printf("Seta pra baixo pressionada!");
        else if (GetAsyncKeyState(VK_LEFT)&1)
            printf("Seta pra esquerda pressionada!");
        else if (GetAsyncKeyState(VK_RIGHT)&1)
            printf("Seta pra direita pressionada!");
        else if (GetAsyncKeyState(VK_RETURN)&1)
            printf("Tecla ENTER pressionada!");*/
        if (tecla == 72 || (tecla == 119) || (tecla == 87)) { //Seta pra cima
            if(opt == 1) opt = qtd;
            else if (opt > 1) opt --;
        } else if (tecla == 80 || (tecla == 115) || (tecla == 83)) { //Seta pra baixo
            if (opt == qtd) opt = 1;
            else if (opt < qtd) opt ++;
        } else if (tecla == 13) { //ENTER
            break;
        } else if (tecla == 27) { //ESC
            opt = 9;
            break;
        } else if (tecla == 49) opt = 1;
        else if (tecla == 50) opt = 2;
        else if (tecla == 51) opt = 3;
        else if (tecla == 52) opt = 4;
        else if (tecla == 53) opt = 5;
        else if (tecla == 54) opt = 6;
        else if (tecla == 55) opt = 7;
        else if (tecla == 56) opt = 8;
        /*else if (tecla == 112 || tecla == 80) {
            char popupItens[][40] = {"SIM", "NÃO"};
            while(popup != 2) {
                popup = modeloMenu(15, 50, 2, popupItens);
            }
            popup = 1;
            cleanScreen(6);
        }*/
    }
    //PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    textColor(WHITE, _BLACK);
    return opt;
}

/* 1) JOGAR - NÍVEL FÁCIL */
void opcao1(){
    int cont = 20;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[5];
    int progresso[5] = {2,2,2,2,2};
    char letras[5] = {'A', 'E', 'I', 'O', 'U'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;

    if(confirmarJogo("FÁCIL", progresso) == 0) return 0;
    topBannerContent("FÁCIL");
    currentProgressionBanner("FÁCIL", progresso, acertos, erros, pontos);

    titulo("FÁCIL", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(14, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto('A', 19, 37, true);
    printAlfabeto('E', 19, 48, true);
    printAlfabeto('I', 19, 59, true);
    printAlfabeto('O', 19, 70, true);
    printAlfabeto('U', 19, 81, true);

    setlocale(LC_ALL, "C");
    linhaCol(25, 43); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        linhaCol(25, 61);
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);
    cleanScreen(2);
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
    system("cls");
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
    topBannerContent("MÉDIO I");
    currentProgressionBanner("MÉDIO I", progresso, acertos, erros, pontos);

    titulo("MÉDIO I", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(11, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    printAlfabeto('B', 16, 37, true);
    printAlfabeto('C', 16, 48, true);
    printAlfabeto('D', 16, 59, true);
    printAlfabeto('F', 16, 70, true);
    printAlfabeto('G', 16, 81, true);

    printAlfabeto('H', 23, 37, true);
    printAlfabeto('J', 23, 48, true);
    printAlfabeto('K', 23, 59, true);
    printAlfabeto('L', 23, 70, true);
    printAlfabeto('M', 23, 81, true);

    setlocale(LC_ALL, "C");
    linhaCol(29, 43); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        linhaCol(29, 61);
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont >= 0);
    cleanScreen(2);
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
    system("cls");
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
    topBannerContent("MÉDIO II");
    currentProgressionBanner("MÉDIO II", progresso, acertos, erros, pontos);

    titulo("MÉDIO II", "O jogo começará em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(11, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras abaixo e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese"); //59 - MEIO

    printAlfabeto('N', 16, 31, true);
    printAlfabeto('P', 16, 42, true);
    printAlfabeto('Q', 16, 53, true);
    printAlfabeto('R', 16, 64, true);
    printAlfabeto('S', 16, 75, true);
    printAlfabeto('T', 16, 86, true);

    printAlfabeto('V', 23, 37, true);
    printAlfabeto('W', 23, 48, true);
    printAlfabeto('X', 23, 59, true);
    printAlfabeto('Y', 23, 70, true);
    printAlfabeto('Z', 23, 81, true);

    setlocale(LC_ALL, "C");
    linhaCol(29, 43); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    do{
        linhaCol(29, 61);
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont >= 0);
    cleanScreen(2);
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
    system("cls");
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
    topBannerContent("DIFÍCIL");
    currentProgressionBanner("DIFÍCIL", progresso, acertos, erros, pontos);

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
    linhaCol(37, 43); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tempo restante: ");
    if (cont < 10) printf("0");
    printf("%d segundo(s)", cont);
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    do{
        linhaCol(37, 61);
        if (cont < 10) printf("0");
        printf("%d segundo(s)", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont >= 0);
    cleanScreen(2);
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
    system("cls");
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
    int finalopt = 0, erro = 0;
    char opt[100];
    system("cls");
    do {
        if (erro == 0) {
            addFade(4, 50, 0);
        }
        printf("\t\t\t\t     _____                     __                 \n");Sleep(tempo);
        printf("\t\t\t\t    |     |___ _____ ___    __|  |___ ___ ___ ___ \n");Sleep(tempo);
        printf("\t\t\t\t    |   --| . |     | . |  |  |  | . | . | .'|  _|\n");Sleep(tempo);
        printf("\t\t\t\t    |_____|___|_|_|_|___|  |_____|___|_  |__,|_|  \n");Sleep(tempo);
        printf("\t\t\t\t                                     |___|        \n");Sleep(tempo);
        addFade(1, tempo, 1);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     |                               O QUE É O 'JOGO DO BRAILE'?                                |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     | O 'Jogo do Braile' é um simples jogo de memória sob a forma de quiz, cujo objetivo do(a) |\n");Sleep(tempo);
        printf("\t     | jogador(a) é acertar o máximo de perguntas possíveis. Ele tem o intuito de ensinar o     |\n");Sleep(tempo);
        printf("\t     | sistema de escrita tátil 'Braile', de forma simples e lúdica, para pessoas sem           |\n");Sleep(tempo);
        printf("\t     | deficiência visual.                                                                      |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     |                                  COMO O JOGO FUNCIONA?                                   |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     | Neste jogo, cada pergunta é composta por:                                                |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | * Uma letra exibida em destaque e de acordo com o sistema 'Braile' de escrita; e         |\n");Sleep(tempo);
        printf("\t     | * Quatro letras referentes às alternativas, exibidas de acordo com o alfabeto latino.    |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | Para responder tais perguntas, é necessário memorizar as letras que aparecerão na tela   |\n");Sleep(tempo);
        printf("\t     | por alguns segundos.                                                                     |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
        addFade(3, tempo, 1);
        showCursor();
        printf("\t\t        DESEJA VER UM EXEMPLO DO JOGO? (Digite 'S' para Sim ou 'N' para Não): ");
        fgets(opt, 100, stdin);
        hideCursor();
        finalopt = verifyOpt(opt, 1);
        if (finalopt == 0) {
            system("cls");
            erro ++;
            printf("\n");
            telaErro();
            addFade(1, tempo, 1);
        } else if (finalopt == 2) {
            addFade(2, 0, 0);
            addFade(37, 25, 1);
            system("cls");
            return 0;
        }
    } while (finalopt != 1);
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("EXEMPLO");
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
    exibirBannerDificuldade("EXEMPLO");
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
    exibirBannerDificuldade("EXEMPLO");
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
    exibirBannerDificuldade("EXEMPLO");
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
    exibirTelaGitHub();
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
    exibirBannerDificuldade("AGRADECIMENTO");
    Sleep(1500);
    addFade(2, 50, 1);
    exibirTelaGitHub();
    Sleep(1100);
    printf("\n\t\t\t\t  **** Pressione qualquer tecla para sair do jogo ****");
    getchar();
    PlaySound(TEXT("..\\sounds\\intro.wav"), NULL, SND_ASYNC);
    titulo("-", "Saindo do Jogo...");
    addFade(2, 0, 0);
    addFade(37, 175, 1);
    system("cls");
    system("mode con:cols=120 lines=30");
    showCursor();
}
