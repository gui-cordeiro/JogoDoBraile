/*
 * -> C�digo-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2024
 */

#define _WIN32_WINNT 0x0500 // Define que as APIs do Windows 2000 ou posterior ser�o utilizados neste projeto

bool mudar = false;
bool mudarRedes = true;
bool isFullScreen = false;
bool isInOpeningScene = true;
bool itIsThe1stTimeOpening = true;

char caminho[50] = "sounds/";

// Vari�vel que controla os modos dispon�veis
int modosDisponiveis = 0;

int mouseX = 0;
int mouseY = 0;

const int tempo = 50;

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

// Estrutura para armazenar os dados do jogador
typedef struct {
    char nome[13];
    char nota;
    int pontuacao;
    int tempo;
    int ordemRegistro;
} Jogador;

/* 1) ASSINATURAS DAS FUN��ES DO ARQUIVO "config-functions.h" */

void exibirTelaRedes(int endOfGame, char nivel[8]);
bool newPergunta(bool isDemo, char dificuldade[8], int questao, char letrResp1, char letrResp2, char letrResp3, char letrResp4, char letrResp5, int *acertos, int *erros, int *pts, int progresso[26]);
void apresentacao();
void printAlfabeto(char letra, int lin1, int col, int isVisible);
int confirmarJogo(char nivel[9], int progresso[26]) ;
void fimJogo(char nivel[9], int pts, int acertos, int numPerg);
void addFade(int rep, int millis, int isLento);
void banner();
void telaErro();
int obterAnoAtual();
void configJogo();
void setScreenMode(bool changeMode);
void titulo(char nivel[9], char frase[50]);
int verifyOpt(char opt[100], int mode);
void exibirBannerPergunta(int questao);
void exibirBannerDificuldade(char titulo1[40], int lin1, int col1, char nivel[20], int lin2, int col2) ;
void exibirBannerResultado(int bannerOpt);
void gerarSeqPerguntas(int *ordem, int numPerguntas);
char gerarLetra(char dificuldade[8]);
void gerarSeqAlt(char dificuldade[8], char *alt, char letrResp1, char letrResp2);
void hideCursor();
void showCursor();
void linhaCol(int lin, int col);
void textColor(int letras, int fundo);
void box(int lin1, int col1, int lin2, int col2);
void topBannerDesign();
void topBannerContent(char titulo1[40], int lin1, int col1, char nivel[20], int lin2, int col2, int modoBotoes);
void bottomBannerDesign();
void bottomBannerTitle(int opt);
void bottomBannerContent(int opt, int menuAtual);
void cleanScreen(int opt, bool inferiorCompleto);
void exibirLetras(char nivel[9]);
int modeloMenu(int lin1, int col1, int qtd, int menuAtual, char lista[][40], int opt);
void currentProgressionBanner(char difficulty[8], int currentProgression[26], int acertos, int erros, int pontos);
int pressEnter(void);
void cheatBanner();
void lerStringComLimite(char *str, int limite);

/* 2) ASSINATURAS DAS FUN��ES DO ARQUIVO "main-functions.h" */

int mainMenu();
int modeSelect();
int opcaoB1();
int opcaoB2();
int opcaoB3();
int opcaoB4();
void opcaoB5();
void opcaoA2();
int opcaoA3();
void opcaoA4();
void opcaoA5();
void opcaoA6();

/* 3) CONFIGURA��ES GLOBAIS DAS THREADS AUXILIARES DO ARQUIVO "aux-threads.h" */

// Vari�veis globais que ser�o utilizadas na thread anti-trapa�a
bool isTextEditingEnabled = false;
bool mostrarLetras = true;
DWORD aCThreadId;
HANDLE aCHandle;

// Assinaturas das threads
DWORD WINAPI e1(LPVOID params);
DWORD WINAPI letra(LPVOID params);

DWORD WINAPI nicetry(LPVOID params);
DWORD WINAPI ricklyrics(LPVOID params);

DWORD WINAPI redes(LPVOID params);
DWORD WINAPI antiCheat(LPVOID params);

DWORD WINAPI bannerParabens(LPVOID params);
DWORD WINAPI bannerEncerramento(LPVOID params);

/* 4) CONFIGURA��ES GLOBAIS DAS THREADS AUXILIARES DO ARQUIVO "savesystem.h" */

void salvarPontuacoes(const char *nomeArquivo, Jogador *jogadores, int numJogadores);
int lerPontuacoes(const char *nomeArquivo, Jogador *jogadores, int maxJogadores, bool retornarOrdemRegistro);
void SpaceToSub(char *str, bool inverse);
