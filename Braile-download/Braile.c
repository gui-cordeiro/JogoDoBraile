#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main(void){
    int a = 0, tempo = 0;
    setlocale(LC_ALL,"Portuguese");
    apresentacao();
    do{
        a = menu();
        switch(a){
            case 1:
                opcao1();
                break;
            case 2:
                opcao2();
                break;
            case 3:
                opcao3();
                break;
            case 4:
                opcao4();
                break;
            case 5:
                opcao5();
                break;
            case 6:
                opcao6();
                break;
            case 7:
                continue;
            default:
                system("cls");
                printf("\n Opção inválida! Por favor, digite um número válido entre '1' e '7'...");Sleep(tempo);
                addFade(2, 50, 1);
                printf("\n           **** Pressione qualquer tecla para continuar ****");
                getch();
                //addFade(25, 0, 0);
                //addFade(5, 30, 1);
                system("cls");
        };
        system("cls");
    }while(a != 7);
    system("cls");
    github();
    printf("\n **** Obrigado por jogar! Pressione qualquer tecla para sair do jogo ****");
    getch();
    //addFade(30, 30, 1);
    system("cls");
}
