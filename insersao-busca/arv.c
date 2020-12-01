#include<stdio.h>
#include<stdlib.h>

#include"arvore.h"

struct no {
    int valor;
    No *esq, *dir;
};

No *inicializar() {
    return NULL;
}

No *criarNo(int valor){
    No *novo;

    novo = (No *)malloc(sizeof(No));

    (*novo).esq = NULL;
    (*novo).dir = NULL;
    (*novo).valor = valor;

    return novo;
}

No *inserir(No *raiz, No *no){
	if(raiz == NULL){
		raiz = no;
	}else if((*raiz).valor > (*no).valor){
		(*raiz).esq = inserir((*raiz).esq, no);
	}else if((*raiz).valor < (*no).valor){
		(*raiz).dir = inserir((*raiz).dir, no);
	}
    return raiz;
}

No *retira(No *raiz, No *no) {
    
}

void mostrar(No *raiz){
    if(raiz != NULL){
        printf("%d(", (*raiz).valor);
        mostrar((*raiz).esq);
        mostrar((*raiz).dir);
        printf(")");
    }
}

void buscar(No *raiz, int valor){
    if (raiz != NULL){
        if (valor == (*raiz).valor){
            printf("(%d) |", (*raiz).valor);
        }else if (valor > (*raiz).valor){
            printf("(%d) -> ", (*raiz).valor);
            buscar((*raiz).dir, valor);
        }else if(valor < (*raiz).valor){
            printf("(%d) -> ", (*raiz).valor);
            buscar((*raiz).esq, valor);
        }
    }
}

void liberarMemoria(No *raiz) {
    if (raiz != NULL){
        liberarMemoria((*raiz).esq);
        liberarMemoria((*raiz).dir);
        free(raiz);
    }
}