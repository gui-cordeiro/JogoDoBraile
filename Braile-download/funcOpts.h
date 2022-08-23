/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2022
 */

/* 0) MENU PRINCIPAL */
int menu(int erro){
    int i = 0, a = 0;
    char opt[100];
    char optMenu [7][24] = {"  Jogar - NÍVEL FÁCIL  "," Jogar - NÍVEL MÉDIO I "," Jogar - NÍVEL MÉDIO II"," Jogar - NÍVEL DIFÍCIL ","  Instruções do Jogo   ","   Créditos do Jogo    ","     Sair do Jogo      "};
    titulo("-", "Menu Principal");
    fflush(stdin);
    if (erro == 0) {
        addFade(3, tempo, 0);
    }
    printf("\n\t\t\t\t _____                 _____     _         _         _ \n");Sleep(tempo);
    printf("\t\t\t\t|     |___ ___ _ _    |  _  |___|_|___ ___|_|___ ___| |\n");Sleep(tempo);
    printf("\t\t\t\t| | | | -_|   | | |   |   __|  _| |   |  _| | . | .'| |\n");Sleep(tempo);
    printf("\t\t\t\t|_|_|_|___|_|_|___|   |__|  |_| |_|_|_|___|_|  _|__,|_|\n");Sleep(tempo);
    printf("\t\t\t\t                                            |_|        \n");Sleep(tempo);
    printf("\t\t\t\t      (Insira a opção desejada e pressione ENTER)");
    addFade(3, 50, 1);
    printf("\t\t\t\t      +-------------------------+---------------+");Sleep(tempo);
    printf("\n\t\t\t\t      |       DESCRIÇÃO         | NUM. DA OPÇÃO | ");Sleep(tempo);
    printf("\n\t\t\t\t      +-------------------------+---------------+ ");Sleep(tempo);
    for (int c = 0; c < 7; c ++) {
        printf("\n\t\t\t\t      +-------------------------+---------------+ ");Sleep(tempo);
        printf("\n\t\t\t\t      | %s |       %d       | ", optMenu[c], c + 1);Sleep(tempo);
    }
    printf("\n\t\t\t\t      +-------------------------+---------------+");addFade(2, 50, 1);
    printf("\t\t\t\t\t          Para onde vamos? -> ");
    fgets(opt, 100, stdin);
    while (opt[i] != '\0') {
        if ((opt[i] == ' ') || ((opt[i] >= 'a' && opt[i] <= 'z') || (opt[i] >= 'A' && opt[i] <= 'Z'))) {
            return 0;
        }
        i ++;
    }
    a = atoi(opt);
    addFade(4, 0, 0);
    addFade(35, 25, 1);
    return a;
}

/* 1) JOGAR - NÍVEL FÁCIL */
void opcao1(){
    int cont = 10;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[5];
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;
    if(confirmarJogo("FÁCIL") == 0) return 0;
    titulo("FÁCIL", "O jogo começará em breve...");
    addFade(13, 50, 0);
    printf("\t\t\t\t      As letras em braile nesta dificuldade são:    \n");Sleep(tempo);
    printf("\n\t\t\t\t    A          E          I          O          U \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o   |     |   o|     |o   |     |o   |\n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |   o|     |o   |     |   o|     |    |\n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |    |     |    |     |o   |     |o  o|  ");addFade(3, 50, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("\t\t\t\t              Tempo restante: %d segundos",cont);Sleep(tempo);
    Sleep(800);
    system("cls");
    cont --;
    do{
        addFade(13, 50, 0);
        printf("\t\t\t\t      As letras em braile nesta dificuldade são:    \n");
        printf("\n\t\t\t\t    A          E          I          O          U \n");
        printf("\t\t\t\t  |o   |     |o   |     |   o|     |o   |     |o   |\n");
        printf("\t\t\t\t  |    |     |   o|     |o   |     |   o|     |    |\n");
        printf("\t\t\t\t  |    |     |    |     |    |     |o   |     |o  o|\n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! * \n\n");
        if(cont != 1){
            printf("\t\t\t\t              Tempo restante: %d segundos",cont);
        }else{
            printf("\t\t\t\t              Tempo restante: %d segundo",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 5; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("FÁCIL", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(1, numPergunta, 'A', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(1, numPergunta, 'E', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(1, numPergunta, 'I', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(1, numPergunta, 'O', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(1, numPergunta, 'U', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("FÁCIL", pts, acertos, totPerguntas);
    return;
}

/* 2) JOGAR - NÍVEL MÉDIO I */
void opcao2(){
    int cont = 20;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[10];
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;
    if(confirmarJogo("MÉDIO I") == 0) return 0;
    addFade(11, 50, 0);
    printf("\t\t\t\t      As letras em braile nesta dificuldade são:      \n");Sleep(tempo);
    printf("\n\t\t\t\t    B          C          D          F          G   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o  o|     |o  o|     |o  o|     |o  o|  \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |    |     |   o|     |o   |     |o  o|  \n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |    |     |    |     |    |     |    |  \n");Sleep(tempo);
    printf("\n\t\t\t\t    H          J          K          L          M   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |   o|     |o   |     |o   |     |o  o|  \n");Sleep(tempo);
    printf("\t\t\t\t  |o  o|     |o  o|     |    |     |o   |     |    |  \n");Sleep(tempo);
    printf("\t\t\t\t  |    |     |    |     |o   |     |o   |     |o   |    ");addFade(3, 50, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("\t\t\t\t              Tempo restante: %d segundos",cont);Sleep(tempo);
    Sleep(1000);
    system("cls");
    cont --;
    do{
        addFade(11, 50, 0);
        printf("\t\t\t\t      As letras em braile nesta dificuldade são:     \n");
        printf("\n\t\t\t\t    B          C          D          F          G  \n");
        printf("\t\t\t\t  |o   |     |o  o|     |o  o|     |o  o|     |o  o| \n");
        printf("\t\t\t\t  |o   |     |    |     |   o|     |o   |     |o  o| \n");
        printf("\t\t\t\t  |    |     |    |     |    |     |    |     |    | \n");
        printf("\n\t\t\t\t    H          J          K          L          M  \n");
        printf("\t\t\t\t  |o   |     |   o|     |o   |     |o   |     |o  o| \n");
        printf("\t\t\t\t  |o  o|     |o  o|     |    |     |o   |     |    | \n");
        printf("\t\t\t\t  |    |     |    |     |o   |     |o   |     |o   | \n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *  \n\n");
        if(cont == 1){
            printf("\t\t\t\t              Tempo restante: %d segundo",cont);
        }
        else{
            printf("\t\t\t\t              Tempo restante: %d segundos",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 10; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("MÉDIO I", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(2, numPergunta, 'B', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(2, numPergunta, 'C', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(2, numPergunta, 'D', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(2, numPergunta, 'F', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(2, numPergunta, 'G', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 6:
                if(newPergunta(2, numPergunta, 'H', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 7:
                if(newPergunta(2, numPergunta, 'J', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 8:
                if(newPergunta(2, numPergunta, 'K', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 9:
                if(newPergunta(2, numPergunta, 'L', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 10:
                if(newPergunta(2, numPergunta, 'M', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("MÉDIO I", pts, acertos, totPerguntas);
    return;
}

/* 3) JOGAR - NÍVEL MÉDIO II */
void opcao3(){
    int cont = 25;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[11];
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    int perguntaEscolhida = 0;
    char tituloPergunta[15];
    char numPerguntaChar[3];
    if(confirmarJogo("MÉDIO II") == 0) return 0;
    addFade(8, 0, 0);
    printf("\t\t\t\t      As letras em braile nesta dificuldade são:       \n");Sleep(tempo);
    printf("\n\t\t\t\t    N          P          Q          R          S    \n");Sleep(tempo);
    printf("\t\t\t\t  |o  o|     |o  o|     |o  o|     |o   |     |   o|   \n");Sleep(tempo);
    printf("\t\t\t\t  |   o|     |o   |     |o  o|     |o  o|     |o   |   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o   |     |o   |     |o   |     |o   |   \n");Sleep(tempo);
    printf("\n\t\t\t\t    T          V          W          X          Y    \n");Sleep(tempo);
    printf("\t\t\t\t  |   o|     |o   |     |   o|     |o  o|     |o  o|   \n");Sleep(tempo);
    printf("\t\t\t\t  |o  o|     |o   |     |o  o|     |    |     |   o|   \n");Sleep(tempo);
    printf("\t\t\t\t  |o   |     |o  o|     |   o|     |o  o|     |o  o|   \n");Sleep(tempo);
    printf("\n\t\t\t\t                          Z \n");Sleep(tempo);
    printf("\t\t\t\t                        |o   |\n");Sleep(tempo);
    printf("\t\t\t\t                        |   o|\n");Sleep(tempo);
    printf("\t\t\t\t                        |o  o|  ");addFade(3, 50, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("\t\t\t\t              Tempo restante: %d segundos",cont);
    Sleep(800);
    system("cls");
    cont --;
    do{
        addFade(8, 0, 0);
        printf("\t\t\t\t      As letras em braile nesta dificuldade são:       \n");
        printf("\n\t\t\t\t    N          P          Q          R          S    \n");
        printf("\t\t\t\t  |o  o|     |o  o|     |o  o|     |o   |     |   o|   \n");
        printf("\t\t\t\t  |   o|     |o   |     |o  o|     |o  o|     |o   |   \n");
        printf("\t\t\t\t  |o   |     |o   |     |o   |     |o   |     |o   |   \n");
        printf("\n\t\t\t\t    T          V          W          X          Y    \n");
        printf("\t\t\t\t  |   o|     |o   |     |   o|     |o  o|     |o  o|   \n");
        printf("\t\t\t\t  |o  o|     |o   |     |o  o|     |    |     |   o|   \n");
        printf("\t\t\t\t  |o   |     |o  o|     |   o|     |o  o|     |o  o|   \n");
        printf("\n\t\t\t\t                          Z     \n");
        printf("\t\t\t\t                        |o   |    \n");
        printf("\t\t\t\t                        |   o|    \n");
        printf("\t\t\t\t                        |o  o|\n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *\n\n");
        if(cont != 0){
            printf("\t\t\t\t              Tempo restante: %d segundos",cont);
        }else{
            printf("\t\t\t\t              Tempo restante: %d segundo",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    gerarSeqPerguntas(ordem, totPerguntas);

    for (int numPergunta = 1; numPergunta <= 11; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("MÉDIO II", tituloPergunta);
        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(3, numPergunta, 'N', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(3, numPergunta, 'P', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(3, numPergunta, 'Q', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(3, numPergunta, 'R', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(3, numPergunta, 'S', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 6:
                if(newPergunta(3, numPergunta, 'T', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 7:
                if(newPergunta(3, numPergunta, 'V', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 8:
                if(newPergunta(3, numPergunta, 'W', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 9:
                if(newPergunta(3, numPergunta, 'X', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 10:
                if(newPergunta(3, numPergunta, 'Y', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 11:
                if(newPergunta(3, numPergunta, 'Z', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("MÉDIO II", pts, acertos, totPerguntas);
    return;
}

/* 4) JOGAR - NÍVEL DIFÍCIL */
void opcao4(){
    int cont = 30;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[26];
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    int perguntaEscolhida = 0;
    char tituloPergunta[15];
    char numPerguntaChar[3];
    if(confirmarJogo("DIFÍCIL") == 0) return 0;
    addFade(8, 0, 0);
    printf("\t\t\t\t      As letras em braille nesta dificuldade são:\n");
    printf("\n\t      A          B          C          D          E          F          G          H          I     \n");Sleep(tempo);
    printf("\t    |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|    \n");Sleep(tempo);
    printf("\t    |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |    \n");Sleep(tempo);
    printf("\t    |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |    \n");Sleep(tempo);
    printf("\n\t      J          K          L          M          N          O          P          Q          R     \n");Sleep(tempo);
    printf("\t    |   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |    \n");Sleep(tempo);
    printf("\t    |o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|    \n");Sleep(tempo);
    printf("\t    |    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |    \n");Sleep(tempo);
    printf("\n\t\t    S          T          U          V          W          X          Y          Z                \n");Sleep(tempo);
    printf("\t\t  |   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |               \n");Sleep(tempo);
    printf("\t\t  |o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|               \n");Sleep(tempo);
    printf("\t\t  |o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|                 ");addFade(3, tempo, 1);
    printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *");addFade(2, tempo, 1);
    printf("\t\t\t\t            Tempo restante: %d segundos",cont);
    Sleep(800);
    system("cls");
    cont --;
    do{
        addFade(8, 0, 0);
        printf("\t\t\t\t      As letras em braille nesta dificuldade são:\n");
        printf("\n\t      A          B          C          D          E          F          G          H          I   \n");
        printf("\t    |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|  \n");
        printf("\t    |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |  \n");
        printf("\t    |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |  \n");
        printf("\n\t      J          K          L          M          N          O          P          Q          R   \n");
        printf("\t    |   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |  \n");
        printf("\t    |o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|  \n");
        printf("\t    |    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |  \n");
        printf("\n\t\t    S          T          U          V          W          X          Y          Z              \n");
        printf("\t\t  |   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |             \n");
        printf("\t\t  |o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|             \n");
        printf("\t\t  |o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|         \n\n\n");
        printf("\t\t\t\t   * Tente memorizar as letras acima e boa sorte! *\n\n");
        if(cont != 1){
            printf("\t\t\t\t            Tempo restante: %d segundos",cont);
        }else{
            printf("\t\t\t\t            Tempo restante: %d segundo",cont);
        }
        Sleep(950);
        system("cls");
        cont --;
    }while(cont > 0);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 26; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta nº ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("DIFÍCIL", tituloPergunta);
        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(4, numPergunta, 'A', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(4, numPergunta, 'B', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(4, numPergunta, 'C', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(4, numPergunta, 'D', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(4, numPergunta, 'E', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 6:
                if(newPergunta(4, numPergunta, 'F', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 7:
                if(newPergunta(4, numPergunta, 'G', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 8:
                if(newPergunta(4, numPergunta, 'H', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 9:
                if(newPergunta(4, numPergunta, 'I', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 10:
                if(newPergunta(4, numPergunta, 'J', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 11:
                if(newPergunta(4, numPergunta, 'K', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 12:
                if(newPergunta(4, numPergunta, 'L', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 13:
                if(newPergunta(4, numPergunta, 'M', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 14:
                if(newPergunta(4, numPergunta, 'N', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 15:
                if(newPergunta(4, numPergunta, 'O', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 16:
                if(newPergunta(4, numPergunta, 'P', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 17:
                if(newPergunta(4, numPergunta, 'Q', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 18:
                if(newPergunta(4, numPergunta, 'R', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 19:
                if(newPergunta(4, numPergunta, 'S', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 20:
                if(newPergunta(4, numPergunta, 'T', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 21:
                if(newPergunta(4, numPergunta, 'U', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 22:
                if(newPergunta(4, numPergunta, 'V', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 23:
                if(newPergunta(4, numPergunta, 'W', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 24:
                if(newPergunta(4, numPergunta, 'X', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 25:
                if(newPergunta(4, numPergunta, 'Y', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 26:
                if(newPergunta(4, numPergunta, 'Z', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("DIFÍCIL", pts, acertos, totPerguntas);
    return;
}

/* 5) INSTRUÇÕES DO JOGO */
int opcao5(){
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
        printf("\t\t        DESEJA VER UM EXEMPLO DO JOGO? (Digite 'S' para Sim ou 'N' para Não): ");
        fgets(opt, 100, stdin);
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
    printAlfabeto('E');
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
    printAlfabeto('E');
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
    printAlfabeto('E');
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

/* 6) CRÉDITOS DO JOGO */
void opcao6(){
    system("cls");
    titulo("-", "Créditos do Jogo");
    printf("\t\t\t\t\t               ___                  \n");Sleep(tempo);
    printf("\t\t\t\t\t    _____     /__/  _ _ _           \n");Sleep(tempo);
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

/* 7) SAIR DO JOGO */
void opcao7(){
    system("cls");
    titulo("-", "Obrigado por Jogar!");
    exibirBannerDificuldade("AGRADECIMENTO");
    addFade(2, 50, 1);
    exibirTelaGitHub();
    printf("\n\t\t\t\t  **** Pressione qualquer tecla para sair do jogo ****");
    getchar();
    titulo("-", "Saindo do Jogo...");
    addFade(2, 0, 0);
    addFade(37, 25, 1);
    system("cls");
}
