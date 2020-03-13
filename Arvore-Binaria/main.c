#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"arvore.h"

int main(){
    No *raiz, *no;
    int op = -1, valor, qtd, alt;
    clock_t inicio, fim, total;

    srand(time(NULL));
    raiz = inicializar();

    while (op != 0){
        printf("\n1 - Criar árvore\n2 - Mostrar Árvore\n"
               "3 - Realizar buscas\n4 - Quantidade de nós\n"
               "5 - Altura da árvore\n0 - Sair\n");

        printf("Opção: ");
        scanf("%d", &op);
        printf("\n");

        switch (op){
            case 1:
                liberarMemoria(raiz);
                printf("Criando Árvore.\n");
                printf("Digite a altura: ");
                scanf("%d", &alt);

                printf("Valores inseridos aleatoriamente.\n");

                do{
                    valor = rand()%100;
                    no = criarNo(valor);
                    raiz = inserir(raiz, no);
                    //printf("%d ", valor);
                }while (altura(raiz) != alt);

                break;
            
            case 2:
                printf("Elementos da árvore:\n");

                mostrar(raiz);
                printf("\n");
                break;
            case 3:
                printf("---------Realizar buscas---------\n");
                int valores[] = {10, 400, 87, 520, 333, 666, 229, 933, 715, 190}, i = 0;

                for (int j = 0; j < 4; j++){
                    printf("Árvore %d -----------------------------------------------------------------------------------------\n", j+1);
                
                    raiz = inicializar();

                    do{
                        no = criarNo(rand()%1000);
                        raiz = inserir(raiz, no);
                        //printf("%d ", valor);
                    }while (altura(raiz) != 100);

                    printf("Árvore Gerada: ");
                    mostrar(raiz);

                    for (i = 0; i < 10; i++) {
                        printf("\nValor a ser buscado: %d\n", valores[i]);
                        printf("Caminho percorrido: ");
                        inicio = clock();
                        buscar(raiz, valores[i]);
                        fim = clock();
                        printf("\n");

                        total = fim - inicio;

                        printf("Tempo de execução: %f\n", (((double)total * 10000)/CLOCKS_PER_SEC));
                        printf("- --- -- -- -- -- -- -- --- -- -- --- --- -- --- -- -- -- -- -- -- -- -- -\n");
                    }
                    liberarMemoria(raiz);
                }

                break;
            case 4:
                printf("Quantidade de nós: %d\n", qtdElementos(raiz));
                break;
            case 5:
                printf("Altura da árvore: %d\n", altura(raiz));
                break;
            default:
                break;
        }
    }


    return 0;
}
