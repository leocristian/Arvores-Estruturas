#include<stdio.h>
#include<stdlib.h>

#include"arvore.h"


int main(){
    No *arv, *no;
    int valor, op, valores[] = {80, 40, 60, 20, 30, 200, 100, 150};

    arv = inicializar();

    for (int i = 0; i < 8; i++){
        no = criarNo(valores[i]);
        arv = inserir(arv, no);
    }

    do{
        printf("1 - Mostrar\n2 - Buscar\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                mostrar(arv);
                printf("\n");

                break;
            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                buscar(arv, valor);
                printf("\n");

                break;
        }   
        
    } while (op != 0);

    liberarMemoria(arv);
    return 0;
}
