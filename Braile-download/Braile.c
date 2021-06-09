#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

int main(void){
    int a=0;
    setlocale(LC_ALL,"Portuguese");
        do{
            a = cabecalho();
            if((a > 7) || (a < 1)){
                system("cls");
                printf("\n Opção inválida! Por favor, digite um número válido entre '1' e '7'...");
                Sleep(1200);
                system("cls");
            }else{
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
                };
            system("cls");
            }
        }while(a != 7);
        system("cls");
        github();
        printf("\n   **** Pressione qualquer tecla para sair do jogo ****");
        getche();
}
