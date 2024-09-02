/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2024
 */

// Função para verificar se o arquivo existe e, se não, criar um novo arquivo
void verificarOuCriarArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        // O arquivo não existe, então ele será criado
        arquivo = fopen(nomeArquivo, "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo %s!", nomeArquivo);
            exit(1);
        }

        // Criando um arquivo limpo
        for (int i = 1; i <= 7; i++) {
            fprintf(arquivo, "------------ - 0 0\n", i);
        }
    }
    fclose(arquivo);
}

// Função para ler os dados dos jogadores de um arquivo
int lerPontuacoes(const char *nomeArquivo, Jogador *jogadores, int maxJogadores, bool retornarOrdemRegistro) {
    verificarOuCriarArquivo(nomeArquivo);
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para LEITURA!");
        return 0;
    }

    int i = 0;

    while (i < maxJogadores && fscanf(arquivo, "%12s %c %d %d %d", jogadores[i].nome, &jogadores[i].nota, &jogadores[i].pontuacao, &jogadores[i].tempo, &jogadores[i].ordemRegistro) == 5) {
        SpaceToSub(jogadores[i].nome, false);
        i++;
    }

    fclose(arquivo);

    if (retornarOrdemRegistro) {
        int maiorValRegistroEncontrado = 0;
        for (int cont = 0; cont < maxJogadores; cont ++) {
            if (jogadores[cont].ordemRegistro > maiorValRegistroEncontrado) maiorValRegistroEncontrado = jogadores[cont].ordemRegistro;
        }
        return maiorValRegistroEncontrado;
    } else return i;
}

// Função para salvar os dados dos jogadores em um arquivo
void salvarPontuacoes(const char *nomeArquivo, Jogador *jogadores, int numJogadores) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para ESCRITA!");
        exit(1);
    }

    for (int i = 0; i < numJogadores; i++) {
        SpaceToSub(jogadores[i].nome, true);
        fprintf(arquivo, "%d %s %c %d %d\n", i + 1, jogadores[i].nome, jogadores[i].nota, jogadores[i].pontuacao, jogadores[i].tempo);
    }

    fclose(arquivo);

    /*system("cls");
    for (int cont = 0; cont < numJogadores; cont ++) {
        linhaCol(17 + (cont * 2), 10); printf("%dº", jogadores[cont].posicao);
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
    Sleep(10000);*/
}

void apagarArquivo(const char *nomeArquivo) {
    if (remove(nomeArquivo) != 0) {
        printf("Erro ao apagar o arquivo %s.\n", nomeArquivo);
    }
}

// Função de comparação para ordenar os regitros dos jogadores (ordem decrescente de pontuação)
int compararJogadores(const void *a, const void *b) {
    Jogador *jogadorA = (Jogador *)a;
    Jogador *jogadorB = (Jogador *)b;

    // Critério 1: Maior pontuação
    if (jogadorA->pontuacao != jogadorB->pontuacao) {
        return jogadorB->pontuacao - jogadorA->pontuacao;
    }

    // Critério 2: Menor tempo
    if (jogadorA->tempo != jogadorB->tempo) {
        return jogadorA->tempo - jogadorB->tempo;
    }

    // Critério 3: Ordem de registro (mais antigo primeiro)
    return jogadorA->ordemRegistro - jogadorB->ordemRegistro;
}


// Função para adicionar uma nova pontuação e manter o top 7
void atualizarTopPontuacoes(Jogador *jogadores, const char *nomeArquivo) {
    //Jogador jogadores[8];  // Array para armazenar até 8 jogadores (7 existentes + 1 novo)
    int numJogadores = 8;

    int maiorRegistro = lerPontuacoes("fácil.txt", jogadores, numJogadores - 1, true) + 1;

    // Adicionar o novo jogador
    /*jogadores[numJogadores] = novoJogador;
    numJogadores++;*/

    // Ordenar os jogadores por pontuação (ordem decrescente)
    qsort(jogadores, numJogadores, sizeof(Jogador), compararJogadores);

    // Manter apenas os top 7 jogadores
    if (numJogadores > 7) numJogadores = 7;

    /*system("cls");
    for (int cont = 0; cont < numJogadores; cont ++) {
        linhaCol(17 + (cont * 2), 10); printf("%dº", jogadores[cont].posicao);
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
    Sleep(10000);*/

    // Salvar os top 7 jogadores de volta no arquivo
    salvarPontuacoes(nomeArquivo, jogadores, numJogadores);
}

void SpaceToSub(char *str, bool inverse) {
    while (*str) {
        if (inverse){
            if (*str == ' ') {
                *str = '_';
            }
        } else {
            if (*str == '_') {
                *str = ' ';
            }
        }
        str++;
    }
}