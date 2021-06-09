#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

/* ********** ESTRUTURA DOS DADOS ***********/

struct dados
{
    char nomejogador[40];
    char resposta;
};

/* ********** MENU INICIAL ***********/

int cabecalho()
{
    int a = 0;
    printf("\n        **** SELECIONE UMA OPÇÃO **** \n");
    printf("\n       +-----------------------+---------+");
    printf("\n       |      Descrição da     | Num. da | ");
    printf("\n       |         Opção         |  Opção  | ");
    printf("\n       +-----------------------+---------+ \n\n");
    printf("\n       +-----------------------+---------+ ");
    printf("\n       |  Jogar - NÍVEL FÁCIL  |    1    | ");
    printf("\n       +-----------------------|---------+ ");
    printf("\n       | Jogar - NÍVEL MÉDIO 1 |    2    | ");
    printf("\n       +-----------------------|---------+ ");
    printf("\n       | Jogar - NÍVEL MÉDIO 2 |    3    | ");
    printf("\n       +-----------------------|---------+ ");
    printf("\n       | Jogar - NÍVEL DIFÍCIL |    4    | ");
    printf("\n       +-----------------------|---------+ ");
    printf("\n       |  Instruções do Jogo   |    5    | ");
    printf("\n       +-----------------------|---------+ ");
    printf("\n       |  Créditos da Equipe   |    6    | ");
    printf("\n       +-----------------------|---------+ ");
    printf("\n       |   Sair do programa    |    7    | ");
    printf("\n       +-----------------------+---------+ \n");
    printf("\n\n       Opção: ");
    scanf("%d",&a);
    return(a);
}

/* ********** OPÇÃO 1 - NÍVEL FÁCIL ***********/

int opcao1(){
    long tamanho;
    int num = 0, a = 0, b = 0, c = 0;
    system("cls");
    printf("\n     **** OPÇÃO SELECIONADA : 'Jogar - NÍVEL FÁCIL' **** \n");
    printf("\n           Confirma? ('1' para Sim, '2' para Não): ");
    scanf("%d",&num);
    if(num == 2){
        return;
    }
    system("cls");
    struct dados dados1;
    printf("\n * Digite o seu nome : ");
    scanf("%s",&dados1.nomejogador);
    system("cls");
    printf("\n Bem-vindo(a)! : %s \n\n",dados1.nomejogador);
    printf("\n Aguarde um momento. As letras em braille irão aparecer em breve. . .");
    Sleep(2500);
    system("cls");
    for(a = 10; a > 0; a --){
        printf("\n           As letras em braille nesta dificuldade são:     \n");
        printf("\n          A          E          I          O          U    \n");
        printf("\n        |o   |     |o   |     |   o|     |o   |     |o   |   ");
        printf("\n        |    |     |   o|     |o   |     |   o|     |    |   ");
        printf("\n        |    |     |    |     |    |     |o   |     |o  o| \n");
        if(a==1)
        {
            printf("\n              * Tempo restante : %d segundo  *",a);
        }
        else
        {
            printf("\n              * Tempo restante : %d segundos *",a);
        }
        Sleep(950);
        system("cls");
    }
    printf("\n +-----------------------------------------------+");
    printf("\n |                PERGUNTA Nº 1                  |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o   |                      |");
    printf("\n |                   |   o|                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) A");
    printf("\n b) I");
    printf("\n c) E");
    printf("\n d) U");
    printf("\n\n Opção : ");
    scanf("%s",&dados1.resposta);
    if((dados1.resposta == 'e')||(dados1.resposta == 'E'))
    {
        printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
        printf("\n      PONTOS GANHOS : 150    ");
        b=b+150;
        c=c+1;
    }
    else
    {
       printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
       printf("\n      RESPOSTA CORRETA : 'E'         ");
       printf("\n      PONTOS GANHOS : 50             ");
       b=b+50;
    }
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n +-----------------------------------------------+");
    printf("\n |                PERGUNTA Nº 2                  |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o   |                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                   |o  o|                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) U");
    printf("\n b) I");
    printf("\n c) O");
    printf("\n d) A");
    printf("\n\n Opção : ");
    scanf("%s",&dados1.resposta);
    if((dados1.resposta == 'u')||(dados1.resposta == 'U'))
    {
        printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
        printf("\n      PONTOS GANHOS : 150    ");
        b=b+150;
        c=c+1;
    }
    else
    {
       printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
       printf("\n      RESPOSTA CORRETA : 'U'         ");
       printf("\n      PONTOS GANHOS : 50             ");
       b=b+50;
    }
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n +-----------------------------------------------+");
    printf("\n |                PERGUNTA Nº 3                  |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o   |                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) A");
    printf("\n b) O");
    printf("\n c) I");
    printf("\n d) U");
    printf("\n\n Opção : ");
    scanf("%s",&dados1.resposta);
    if((dados1.resposta == 'a')||(dados1.resposta == 'A'))
    {
        printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
        printf("\n      PONTOS GANHOS : 150    ");
        b=b+150;
        c=c+1;
    }
    else
    {
       printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
       printf("\n      RESPOSTA CORRETA : 'A'         ");
       printf("\n      PONTOS GANHOS : 50             ");
       b=b+50;
    }
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n +-----------------------------------------------+");
    printf("\n |                PERGUNTA Nº 4                  |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |   o|                      |");
    printf("\n |                   |o   |                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) O");
    printf("\n b) I");
    printf("\n c) U");
    printf("\n d) E");
    printf("\n\n Opção : ");
    scanf("%s",&dados1.resposta);
    if((dados1.resposta == 'i')||(dados1.resposta == 'I'))
    {
        printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
        printf("\n      PONTOS GANHOS : 150    ");
        b=b+150;
        c=c+1;
    }
    else
    {
       printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
       printf("\n      RESPOSTA CORRETA : 'I'         ");
       printf("\n      PONTOS GANHOS : 50             ");
       b=b+50;
    }
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n +-----------------------------------------------+");
    printf("\n |                PERGUNTA Nº 5                  |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o   |                      |");
    printf("\n |                   |   o|                      |");
    printf("\n |                   |o   |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) O");
    printf("\n b) A");
    printf("\n c) U");
    printf("\n d) E");
    printf("\n\n Opção : ");
    scanf("%s",&dados1.resposta);
    if((dados1.resposta == 'o')||(dados1.resposta == 'O'))
    {
        printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
        printf("\n      PONTOS GANHOS : 150    ");
        b=b+150;
        c=c+1;
    }
    else
    {
       printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
       printf("\n      RESPOSTA CORRETA : 'O'         ");
       printf("\n      PONTOS GANHOS : 50             ");
       b=b+50;
    }
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n +--------------------------------------+");
    printf("\n             SEU DESEMPENHO              ");
    printf("\n +--------------------------------------+");
    printf("\n                                         ");
    printf("\n           Nº de acertos : ");
    Sleep(1500);
    printf("%d",c);
    printf(" / 5");
    printf("\n                                         ");
    printf("\n         Nº total de pontos : ");
    Sleep(2000);
    printf("%d",b);
    printf("\n                                         ");
    Sleep(200);
    printf("\n +--------------------------------------+");
    Sleep(1500);
    if((c>=0)&&(c<=2))
    {
        printf("\n\n\n Bom. . . Você precisa aprender um pouco mais de braille. Não desanime, tente novamente!");
    }
    if(c==3)
    {
        printf("\n\n\n Você tem potencial, mas precisa se esforçar um pouco mais!");
    }
    if(c==4)
    {
        printf("\n\n\n Muito bem! Você realmente mandou bem, mas um pouquinho mais de empenho não faz mal para ninguém!");
    }
    if(c==5)
    {
        printf("\n\n\n Meus parabéns! Você acertou todas as questões! Estou impressionado!");
    }
    Sleep(2500);
    printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n * TESTE SEUS CONHECIMENTOS COM AS PRIMEIRAS 10 CONSOANTES EXPERIMENTANDO *");
    printf("\n                          O NÍVEL 'MÉDIO 1'! \n");
    printf("\n                         Selecione-o no menu!\n");
    printf("\n                     **** OBRIGADO POR JOGAR! **** ");
    printf("\n\n\n\n\n\n\n                        +---------------------+");
    printf("\n                        |   Jogo do Braille   |");
    printf("\n                        |    Bancas finais    |");
    printf("\n                        |IFPR - Campus Colombo|");
    printf("\n                        +---------------------+");
    printf("\n\n\n\n\n\n\n\n\n\n\n         **** Pressione qualquer tecla para retornar ao menu ****");
    getche();
    return;
}

/* ********** OPÇÃO 2 - NÍVEL MÉDIO 1 ***********/

int opcao2()
{
    long tamanho;
    int num=0,a=0,b=0,c=0;
    system("cls");
    printf("\n     **** VOCÊ SELECIONOU : 'Jogar - NÍVEL MÉDIO 1' **** \n");
    printf("\n           Confirma? ('1' para Sim, '2' para Não) : ");
    scanf("%d",&num);
    if(num==2)
    {
        return 0;
    }
    system("cls");
      struct dados dados1;
        printf("\n * Digite o seu nome : ");
        scanf("%s",&dados1.nomejogador);
        system("cls");
        printf("\n Bem-vindo(a)! : %s \n\n",dados1.nomejogador);
        printf("\n Aguarde um momento. As letras em braille irão aparecer em breve. . .");
        Sleep(2500);
        system("cls");
        for(a=15;a>0;a--)
        {
            printf("\n           As letras em braille nesta dificuldade são:     \n");
            printf("\n          B          C          D          F          G    \n");
            printf("\n        |o   |     |o  o|     |o  o|     |o  o|     |o  o|   ");
            printf("\n        |o   |     |    |     |   o|     |o   |     |o  o|   ");
            printf("\n        |    |     |    |     |    |     |    |     |    | \n");
            printf("\n          H          J          K          L          M    \n");
            printf("\n        |o   |     |   o|     |o   |     |o   |     |o  o|   ");
            printf("\n        |o  o|     |o  o|     |    |     |o   |     |    |   ");
            printf("\n        |    |     |    |     |o   |     |o   |     |o   | \n");
            if(a==1)
            {
                printf("\n              * Tempo restante : %d segundo  *",a);
            }
            else
            {
                printf("\n              * Tempo restante : %d segundos *",a);
            }
            Sleep(950);
            system("cls");
        }
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 1                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) G");
        printf("\n b) D");
        printf("\n c) M");
        printf("\n d) J");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'g')||(dados1.resposta == 'G'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'G'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 2                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) C");
        printf("\n b) H");
        printf("\n c) L");
        printf("\n d) B");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'l')||(dados1.resposta == 'L'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'L'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 3                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) B");
        printf("\n b) F");
        printf("\n c) J");
        printf("\n d) C");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'c')||(dados1.resposta == 'C'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'C'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 4                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) G");
        printf("\n b) J");
        printf("\n c) D");
        printf("\n d) M");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'j')||(dados1.resposta == 'J'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'J'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 5                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) D");
        printf("\n b) B");
        printf("\n c) M");
        printf("\n d) H");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'm')||(dados1.resposta == 'M'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'M'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");

        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 6                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) B");
        printf("\n b) J");
        printf("\n c) H");
        printf("\n d) D");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'b')||(dados1.resposta == 'B'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'B'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 7                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) K");
        printf("\n b) F");
        printf("\n c) B");
        printf("\n d) H");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'k')||(dados1.resposta == 'K'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'K'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 8                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) M");
        printf("\n b) D");
        printf("\n c) C");
        printf("\n d) H");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'h')||(dados1.resposta == 'H'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'H'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 9                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) G");
        printf("\n b) D");
        printf("\n c) K");
        printf("\n d) F");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'd')||(dados1.resposta == 'D'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'D'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 10                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) F");
        printf("\n b) M");
        printf("\n c) B");
        printf("\n d) J");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'f')||(dados1.resposta == 'F'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'F'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +--------------------------------------+");
        printf("\n             SEU DESEMPENHO              ");
        printf("\n +--------------------------------------+");
        printf("\n                                         ");
        printf("\n           Nº de acertos : ");
        Sleep(1500);
        printf("%d",c);
        printf(" / 10");
        printf("\n                                         ");
        printf("\n         Nº total de pontos : ");
        Sleep(2000);
        printf("%d",b);
        printf("\n                                         ");
        Sleep(200);
        printf("\n +--------------------------------------+");
        Sleep(1500);
        if((c>=0)&&(c<=3))
        {
            printf("\n\n\n Bom. . . Você precisa aprender um pouco mais de braille. Não desanime, tente novamente!");
        }
        if((c>=4)&&(c<=6))
        {
            printf("\n\n\n Você tem potencial, mas precisa se esforçar um pouco mais!");
        }
        if((c>=7)&&(c<=9))
        {
            printf("\n\n\n Muito bem! Você realmente mandou bem, mas um pouquinho mais de empenho não faz mal para ninguém!");
        }
        if(c==10)
        {
            printf("\n\n\n Meus parabéns! Você acertou todas as questões! Estou impressionado!");
        }
        Sleep(2500);
        printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n * TESTE SEUS CONHECIMENTOS COM AS OUTRAS 11 CONSOANTES EXPERIMENTANDO O NÍVEL 'MÉDIO 2'! * \n");
        printf("\n                          Selecione-o no menu! \n\n");
        printf("\n                     **** OBRIGADO POR JOGAR! **** ");
        printf("\n\n\n\n\n\n\n                        +---------------------+");
        printf("\n                        |   Jogo do Braille   |");
        printf("\n                        |    Bancas finais    |");
        printf("\n                        |IFPR - Campus Colombo|");
        printf("\n                        +---------------------+");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n         **** Pressione qualquer tecla para retornar ao menu ****");
      getche();
    return(0);
}

/* ********** OPÇÃO 3 - NÍVEL MÉDIO 2 ***********/

int opcao3()
{
    long tamanho;
    int num=0,a=0,b=0,c=0;
    system("cls");
    printf("\n     **** VOCÊ SELECIONOU : 'Jogar - NÍVEL MÉDIO 2' **** \n");
    printf("\n           Confirma? ('1' para Sim, '2' para Não) : ");
    scanf("%d",&num);
    if(num==2)
    {
        return 0;
    }
    system("cls");
      struct dados dados1;
        printf("\n * Digite o seu nome : ");
        scanf("%s",&dados1.nomejogador);
        system("cls");
        printf("\n Bem-vindo(a)! : %s \n\n",dados1.nomejogador);
        printf("\n Aguarde um momento. As letras em braille irão aparecer em breve. . .");
        Sleep(2500);
        system("cls");
        for(a=15;a>0;a--)
        {
            printf("\n           As letras em braille nesta dificuldade são:     \n");
            printf("\n          N          P          Q          R          S    \n");
            printf("\n        |o  o|     |o  o|     |o  o|     |o   |     |   o|   ");
            printf("\n        |   o|     |o   |     |o  o|     |o  o|     |o   |   ");
            printf("\n        |o   |     |o   |     |o   |     |o   |     |o   | \n");
            printf("\n          T          V          W          X          Y    \n");
            printf("\n        |   o|     |o   |     |   o|     |o  o|     |o  o|   ");
            printf("\n        |o  o|     |o   |     |o  o|     |    |     |   o|   ");
            printf("\n        |o   |     |o  o|     |   o|     |o  o|     |o  o| \n");
            printf("\n                                Z     \n");
            printf("\n                              |o   |    ");
            printf("\n                              |   o|    ");
            printf("\n                              |o  o|  \n\n");
            if(a==1)
            {
                printf("\n              * Tempo restante : %d segundo *",a);
            }
            else
            {
                printf("\n              * Tempo restante : %d segundos *",a);
            }
            Sleep(950);
            system("cls");
        }
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 1                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) V");
        printf("\n b) W");
        printf("\n c) T");
        printf("\n d) N");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'v')||(dados1.resposta == 'V'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'V'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 2                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) Q");
        printf("\n b) S");
        printf("\n c) P");
        printf("\n d) R");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'q')||(dados1.resposta == 'Q'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'Q'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 3                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) N");
        printf("\n b) P");
        printf("\n c) T");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'y')||(dados1.resposta == 'Y'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'Y'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 4                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) Z");
        printf("\n b) T");
        printf("\n c) S");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 't')||(dados1.resposta == 'T'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'T'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 5                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) R");
        printf("\n b) Z");
        printf("\n c) P");
        printf("\n d) W");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'z')||(dados1.resposta == 'Z'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'Z'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 6                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) V");
        printf("\n b) W");
        printf("\n c) Z");
        printf("\n d) N");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'n')||(dados1.resposta == 'N'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'N'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 7                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) N");
        printf("\n b) S");
        printf("\n c) Y");
        printf("\n d) P");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 's')||(dados1.resposta == 'S'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'S'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 8                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) S");
        printf("\n b) W");
        printf("\n c) Q");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'w')||(dados1.resposta == 'W'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'W'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 9                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) R");
        printf("\n b) Q");
        printf("\n c) P");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'r')||(dados1.resposta == 'R'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'R'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 10                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) Z");
        printf("\n b) X");
        printf("\n c) P");
        printf("\n d) T");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'x')||(dados1.resposta == 'X'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'X'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 11                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) P");
        printf("\n b) W");
        printf("\n c) S");
        printf("\n d) X");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'p')||(dados1.resposta == 'P'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'P'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +--------------------------------------+");
        printf("\n             SEU DESEMPENHO              ");
        printf("\n +--------------------------------------+");
        printf("\n                                         ");
        printf("\n           Nº de acertos : ");
        Sleep(1500);
        printf("%d",c);
        printf(" / 11");
        printf("\n                                         ");
        printf("\n         Nº total de pontos : ");
        Sleep(2000);
        printf("%d",b);
        printf("\n                                         ");
        Sleep(200);
        printf("\n +--------------------------------------+");
        Sleep(1500);
        if((c>=0)&&(c<=3))
        {
            printf("\n\n\n Bom. . . Você precisa aprender um pouco mais de braille. Não desanime, tente novamente!");
        }
        if((c>=4)&&(c<=7))
        {
            printf("\n\n\n Você tem potencial, mas precisa se esforçar um pouco mais!");
        }
        if((c>=8)&&(c<=10))
        {
            printf("\n\n\n Muito bem! Você realmente mandou bem, mas um pouquinho mais de empenho não faz mal para ninguém!");
        }
        if(c==11)
        {
            printf("\n\n\n Meus parabéns! Você acertou todas as questões! Estou impressionado!");
        }
        Sleep(2500);
        printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n * SE VOCÊ QUER PROVAR QUE REALMENTE SABE DE BRAILLE, VÁ AO NÍVEL 'DIFÍCIL'! *");
        printf("\n                          Selecione-o no menu!\n\n");
        printf("\n                     **** OBRIGADO POR JOGAR! **** ");
        printf("\n\n\n\n\n\n\n\n                        +---------------------+");
        printf("\n                        |   Jogo do Braille   |");
        printf("\n                        |    Bancas finais    |");
        printf("\n                        |IFPR - Campus Colombo|");
        printf("\n                        +---------------------+");
        printf("\n\n\n\n\n\n\n\n\n\n\n       **** Pressione qualquer tecla para retornar ao menu ****");
      getche();
    return(0);
}

/* ********** OPÇÃO 4 - NÍVEL DIFÍCIL ***********/

int opcao4()
{
    long tamanho;
    int num=0,a=0,b=0,c=0;
    system("cls");
    printf("\n     **** VOCÊ SELECIONOU : 'Jogar - NÍVEL DIFÍCIL' **** \n");
    printf("\n           Confirma? ('1' para Sim, '2' para Não) : ");
    scanf("%d",&num);
    if(num==2)
    {
        return 0;
    }
    system("cls");
      struct dados dados1;
        printf("\n * Digite o seu nome : ");
        scanf("%s",&dados1.nomejogador);
        system("cls");
        printf("\n Bem-vindo(a)! : %s \n\n",dados1.nomejogador);
        printf("\n Aguarde um momento. As letras em braille irão aparecer em breve. . .");
        Sleep(2500);
        system("cls");
        for(a=25;a>0;a--)
        {
            printf("\n                                                  As letras em braille nesta dificuldade são:\n");
            printf("\n          A          B          C          D          E          F          G          H          I           J          K          L     \n");
            printf("\n        |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|      |   o|     |o   |     |o   |    ");
            printf("\n        |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |      |o  o|     |    |     |o   |    ");
            printf("\n        |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |      |    |     |o   |     |o   |  \n");
            printf("\n          M          N          O          P          Q          R          S          T          U           V          W          X     \n");
            printf("\n        |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|     |   o|     |o   |      |o   |     |   o|     |o  o|    ");
            printf("\n        |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |    |      |o   |     |o  o|     |    |    ");
            printf("\n        |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o  o|      |o  o|     |   o|     |o  o|   \n");
            printf("\n                                                                 Y          Z     \n");
            printf("\n                                                               |o  o|     |o   |    ");
            printf("\n                                                               |   o|     |   o|    ");
            printf("\n                                                               |o  o|     |o  o|\n\n");
            if(a==1)
            {
                printf("\n              * Tempo restante : %d segundo  *",a);
            }
            else
            {
                printf("\n              * Tempo restante : %d segundos *",a);
            }
            Sleep(950);
            system("cls");
        }
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 1                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) G");
        printf("\n b) D");
        printf("\n c) M");
        printf("\n d) J");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'g')||(dados1.resposta == 'G'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'G'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 2                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) V");
        printf("\n b) W");
        printf("\n c) T");
        printf("\n d) N");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'v')||(dados1.resposta == 'V'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'V'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 3                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) Q");
        printf("\n b) S");
        printf("\n c) P");
        printf("\n d) R");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'q')||(dados1.resposta == 'Q'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'Q'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 4                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) C");
        printf("\n b) H");
        printf("\n c) L");
        printf("\n d) B");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'l')||(dados1.resposta == 'L'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'L'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 5                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) A");
        printf("\n b) I");
        printf("\n c) E");
        printf("\n d) U");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'e')||(dados1.resposta == 'E'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'E'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 6                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) B");
        printf("\n b) F");
        printf("\n c) J");
        printf("\n d) C");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'c')||(dados1.resposta == 'C'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'C'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 7                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) N");
        printf("\n b) P");
        printf("\n c) T");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'y')||(dados1.resposta == 'Y'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'Y'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 8                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) Z");
        printf("\n b) T");
        printf("\n c) S");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 't')||(dados1.resposta == 'T'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'T'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 9                  |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) G");
        printf("\n b) J");
        printf("\n c) D");
        printf("\n d) M");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'j')||(dados1.resposta == 'J'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'J'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 10                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) U");
        printf("\n b) I");
        printf("\n c) O");
        printf("\n d) A");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'u')||(dados1.resposta == 'U'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'U'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 11                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) D");
        printf("\n b) B");
        printf("\n c) M");
        printf("\n d) H");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'm')||(dados1.resposta == 'M'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'M'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 12                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) R");
        printf("\n b) Z");
        printf("\n c) P");
        printf("\n d) W");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'z')||(dados1.resposta == 'Z'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'Z'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 13                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) V");
        printf("\n b) W");
        printf("\n c) Z");
        printf("\n d) N");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'n')||(dados1.resposta == 'N'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'N'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 14                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) B");
        printf("\n b) J");
        printf("\n c) H");
        printf("\n d) D");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'b')||(dados1.resposta == 'B'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'B'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 15                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) A");
        printf("\n b) O");
        printf("\n c) I");
        printf("\n d) U");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'a')||(dados1.resposta == 'A'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'A'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 16                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) K");
        printf("\n b) F");
        printf("\n c) B");
        printf("\n d) H");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'k')||(dados1.resposta == 'K'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'K'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 17                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) N");
        printf("\n b) S");
        printf("\n c) Y");
        printf("\n d) P");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 's')||(dados1.resposta == 'S'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'S'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 18                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) S");
        printf("\n b) W");
        printf("\n c) Q");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'w')||(dados1.resposta == 'W'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'W'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 19                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) M");
        printf("\n b) D");
        printf("\n c) C");
        printf("\n d) H");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'h')||(dados1.resposta == 'H'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'H'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 20                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) O");
        printf("\n b) I");
        printf("\n c) U");
        printf("\n d) E");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'i')||(dados1.resposta == 'I'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'I'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 21                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) G");
        printf("\n b) D");
        printf("\n c) K");
        printf("\n d) F");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'd')||(dados1.resposta == 'D'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'D'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 22                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) R");
        printf("\n b) Q");
        printf("\n c) P");
        printf("\n d) Y");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'r')||(dados1.resposta == 'R'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'R'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 23                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) Z");
        printf("\n b) X");
        printf("\n c) P");
        printf("\n d) T");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'x')||(dados1.resposta == 'X'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'X'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 24                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |    |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) F");
        printf("\n b) M");
        printf("\n c) B");
        printf("\n d) J");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'f')||(dados1.resposta == 'F'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'F'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 25                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |   o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) O");
        printf("\n b) A");
        printf("\n c) U");
        printf("\n d) E");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'o')||(dados1.resposta == 'O'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'O'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +-----------------------------------------------+");
        printf("\n |                PERGUNTA Nº 26                 |");
        printf("\n +-----------------------------------------------+");
        printf("\n |                                               |");
        printf("\n |                   |o  o|                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                   |o   |                      |");
        printf("\n |                                               |");
        printf("\n +-----------------------------------------------+");
        printf("\n\n Qual é a letra correspondente?                 ");
        printf("\n\n a) P");
        printf("\n b) W");
        printf("\n c) S");
        printf("\n d) X");
        printf("\n\n Opção : ");
        scanf("%s",&dados1.resposta);
        if((dados1.resposta == 'p')||(dados1.resposta == 'P'))
        {
            printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
            printf("\n      PONTOS GANHOS : 150    ");
            b=b+150;
            c=c+1;
        }
        else
        {
           printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
           printf("\n      RESPOSTA CORRETA : 'P'         ");
           printf("\n      PONTOS GANHOS : 50             ");
           b=b+50;
        }
        printf("\n\n**** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        printf("\n +--------------------------------------+");
        printf("\n             SEU DESEMPENHO              ");
        printf("\n +--------------------------------------+");
        printf("\n                                         ");
        printf("\n           Nº de acertos : ");
        Sleep(1500);
        printf("%d",c);
        printf(" / 26");
        printf("\n                                         ");
        printf("\n         Nº total de pontos : ");
        Sleep(2000);
        printf("%d",b);
        printf("\n                                         ");
        Sleep(200);
        printf("\n +--------------------------------------+");
        Sleep(1500);
        if((c>=0)&&(c<=13))
        {
            printf("\n\n\n Bom. . . Você precisa aprender um pouco mais de braille. Não desanime, tente novamente!");
        }
        if((c>=14)&&(c<=19))
        {
            printf("\n\n\n Você tem potencial, mas precisa se esforçar um pouco mais!");
        }
        if((c>=20)&&(c<=25))
        {
            printf("\n\n\n Muito bem! Você realmente mandou bem, mas um pouquinho mais de empenho não faz mal para ninguém!");
        }
        if(c==26)
        {
            printf("\n\n\n Meus parabéns! Você acertou todas as questões! Estou impressionado!");
        }
        Sleep(2500);
        printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
        getche();
        system("cls");
        if(c==21)
        {
            printf("\n * MEUS SINCEROS PARABÉNS! VOCÊ PROVOU QUE MANDA VER NO BRAILLE!!! * \n");
        }
        else
        {
            printf("\n * TENTE NOVAMENTE NESTE OU EM OUTRO MODO DE JOGO PARA MELHORAR  * \n");
            printf("\n                      SEUS CONHECIMENTOS!");
        }
        printf("\n                     **** OBRIGADO POR JOGAR! **** ");
        printf("\n\n\n\n\n\n\n\n                        +---------------------+");
        printf("\n                        |   Jogo do Braille   |");
        printf("\n                        |    Bancas finais    |");
        printf("\n                        |IFPR - Campus Colombo|");
        printf("\n                        +---------------------+");
        printf("\n\n\n\n\n\n\n\n\n\n\n       **** Pressione qualquer tecla para retornar ao menu ****");
      getche();
    return(0);
}

/* ********** OPÇÃO 5 - INSTRUÇÕES ***********/

int opcao5()
{
    int a;
    system("cls");
    printf("\n **** INSTRUÇÕES DO JOGO **** \n");
    printf("\n     O jogador deve memorizar as letras escritas em braille que estarão impressas na tela por um certo \n período de tempo e responder as perguntas que irão aparecer na mesma. Cada pergunta terá uma das letras \n apresentadas anteriormente e o jogador terá que responder qual é a letra correspondente, selecionando \n umas das 4 alternativas propostas.");
    printf("\n\n\n VOCÊ DESEJA VER O EXEMPLO? ('1' para Sim, '2' para Não): ");
    scanf("%d",&a);
    if(a==2)
    {
        return 0;
    }
    system("cls");
    printf("\n **** EXEMPLO DO JOGO **** \n");
    printf("\n Após o jogador memorizar as letras escritas em braille, correspondentes à dificuldade selecionada, \n uma pergunta irá aparecer na tela, contendo : \n\n 1) Uma das letras já mostradas anteriormente em destaque; \n 2) 4 possíveis respostas para a pergunta (alternativas).\n");
    printf("\n +-----------------------------------------------+");
    printf("\n |             EXEMPLO DE PERGUNTA               |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o  o|                      |");
    printf("\n |                   |   o|                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) A");
    printf("\n b) B");
    printf("\n c) C");
    printf("\n d) D");
    printf("\n\n Opção : ___ ");
    printf("\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso o jogador acerte a questão, ele ganhará 150 pontos : \n");
    printf("\n +-----------------------------------------------+");
    printf("\n |             EXEMPLO DE PERGUNTA               |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o  o|                      |");
    printf("\n |                   |   o|                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) A");
    printf("\n b) B");
    printf("\n c) C");
    printf("\n d) D");
    printf("\n\n Opção : D ");
    printf("\n\n\n\n **** CERTA RESPOSTA! **** ");
    printf("\n      PONTOS GANHOS : 150    ");
    printf("\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso contrário, ganhará apenas 50 : \n");
    printf("\n +-----------------------------------------------+");
    printf("\n |             EXEMPLO DE PERGUNTA               |");
    printf("\n +-----------------------------------------------+");
    printf("\n |                                               |");
    printf("\n |                   |o  o|                      |");
    printf("\n |                   |   o|                      |");
    printf("\n |                   |    |                      |");
    printf("\n |                                               |");
    printf("\n +-----------------------------------------------+");
    printf("\n\n Qual é a letra correspondente?                 ");
    printf("\n\n a) A");
    printf("\n b) B");
    printf("\n c) C");
    printf("\n d) D");
    printf("\n\n Opção : B ");
    printf("\n\n\n\n **** RESPOSTA INCORRETA! **** ");
    printf("\n      RESPOSTA CORRETA : 'D'         ");
    printf("\n      PONTOS GANHOS : 50             ");
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n No final do jogo, algumas estatísticas irão aparecer na tela em relação ao desempenho do jogador : \n\n\n");
    printf("\n +--------------------------------------+");
    printf("\n             SEU DESEMPENHO              ");
    printf("\n +--------------------------------------+");
    printf("\n                                         ");
    printf("\n           Nº de acertos : 8 / 10        ");
    printf("\n                                         ");
    printf("\n         Nº total de pontos : 1200       ");
    printf("\n                                         ");
    printf("\n +--------------------------------------+");
    printf("\n\n\n\n\n         **** BOA DIVERSÃO! **** \n\n\n\n");
    printf("\n\n\n\n\n **** Pressione qualquer tecla para retornar ao menu **** ");
    getche();
    return 0;
}

/* ********** OPÇÃO 6 - CRÉDITOS ***********/

int opcao6()
{
    system("cls");
    printf("\n **** CRÉDITOS (VERSÃO ORIGINAL) **** \n\n");
    Sleep(800);
    printf("\n    Tema : Acessibilidade dos deficientes visuais na atualidade \n");
    Sleep(1500);
    printf("\n +---------------------------------------------------------------+ \n");
    Sleep(200);
    printf("\n Equipe original formada por : \n");
    Sleep(500);
    printf("\n     - Arthur Ogg - github.com/Arthur-Diesel\n");
    Sleep(500);
    printf("\n     - Guilherme Cordeiro - github.com/gui-cordeiro\n");
    Sleep(500);
    printf("\n     - João Lucas - *contato não encontrado*\n");
    Sleep(500);
    printf("\n     - Lucas Pereira - facebook.com/luca.lima.9674\n");
    Sleep(500);
    printf("\n     - Matheus Delay - twitter.com/DelayMath\n\n");
    Sleep(2000);
    printf("\n     +---------------------+");
    printf("\n     |   Jogo do Braille   |");
    printf("\n     |    Bancas finais    |");
    printf("\n     |IFPR - Campus Colombo|");
    printf("\n     +---------------------+");
    printf("\n\n\n   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    github();
    printf("\n   **** Pressione qualquer tecla para retornar ao menu ****      ");
    getche();
    return 0;
}

/* ********** TELA DO GITHUB ***********/

int github(){
    printf("\n **** O código-fonte deste jogo está disponível gratuitamente ****"); Sleep(80);
    printf("\n      no repositório do GitHub de Guilherme Cordeiro. Acesse:\n\n "); Sleep(80);
    printf("\n                        @@@@@@@@@@@@@@@@@@@                       "); Sleep(80);
    printf("\n                    @@@@@@@@@@@@@@@@@@@@@@@@@@@                   "); Sleep(80);
    printf("\n                 @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@                "); Sleep(80);
    printf("\n               @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@              "); Sleep(80);
    printf("\n             @@@@@@@@                         @@@@@@@@            "); Sleep(80);
    printf("\n            @@@@@@@@@                         @@@@@@@@@           "); Sleep(80);
    printf("\n           @@@@@@@@@                           @@@@@@@@@          "); Sleep(80);
    printf("\n           @@@@@@@@                             @@@@@@@@          "); Sleep(80);
    printf("\n           @@@@@@@@                             @@@@@@@@          "); Sleep(80);
    printf("\n           @@@@@@@@                             @@@@@@@@          "); Sleep(80);
    printf("\n           @@@@@@@@@                           @@@@@@@@@          "); Sleep(80);
    printf("\n            @@@@@@@@@@                       @@@@@@@@@@           "); Sleep(80);
    printf("\n             @@@@   @@@@@@@@           @@@@@@@@@@@@@@@            "); Sleep(80);
    printf("\n              @@@@@   @@@@@@           @@@@@@@@@@@@@              "); Sleep(80);
    printf("\n                @@@@@                  @@@@@@@@@@@@               "); Sleep(80);
    printf("\n                   @@@@@@@@@           @@@@@@@@@                  "); Sleep(80);
    printf("\n                      @@@@@@           @@@@@@                 \n\n"); Sleep(80);
    printf("\n              +-------------------------------------+             "); Sleep(80);
    printf("\n              |   https://github.com/gui-cordeiro   |             "); Sleep(80);
    printf("\n              +-------------------------------------+           \n"); Sleep(1000);
    return 0;
}
