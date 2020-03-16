#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"

#define true 1
#define false 0

struct no {
    int valor;
    No *esquerdo, *direito;
}; 

No *inicializar() {
    return NULL;
}

No *criarNo(int valor){
    No *novo;

    novo = (No *)malloc(sizeof(No));

    (*novo).esquerdo = NULL;
    (*novo).direito = NULL;
    (*novo).valor = valor;

    return novo;
}

No *inserir(No *raiz, No *no){

    if (raiz == NULL){
        raiz = no;
    }else if ((*no).valor < (*raiz).valor){
        (*raiz).esquerdo = inserir((*raiz).esquerdo, no);
    }else{
        (*raiz).direito = inserir((*raiz).direito, no);
    }

    return raiz;
}

void mostrar(No *raiz){
    if (raiz != NULL){
        printf("%d(", (*raiz).valor);
        mostrar((*raiz).esquerdo);
        mostrar((*raiz).direito);
        printf(")");
    }
}

void buscar(No *raiz, int valor){
    if (raiz == NULL){
        printf("Não encontrado\n");

    }else if((*raiz).valor == valor){
        printf("(%d)\n", (*raiz).valor);

    }else if ((*raiz).valor > valor){
        printf("(%d) -> ", (*raiz).valor);
        buscar((*raiz).esquerdo, valor);

    }else{
        printf("(%d) -> ", (*raiz).valor);
        buscar((*raiz).direito, valor);

    }
}

void mostrarNo(No *no){
    printf("%d\n", no->valor);
}

int qtdElementos(No *raiz){
    int count = 0;

    if(raiz == NULL){
        count = 0;
    }else{
        count = qtdElementos((*raiz).esquerdo)
                + 1 
                + qtdElementos((*raiz).direito);
    }
    return count;
}

int altura(No *raiz) {
    int alt = 0, esq, dir;

    if (raiz == NULL){
        alt = -1;
    } else {
        esq = altura((*raiz).esquerdo);
        dir = altura((*raiz).direito);

        if (esq < dir){
            alt = dir + 1;
        }else{
            alt = esq + 1;
        }
    }
    return alt;
}

void liberarMemoria(No *raiz) {
    if (raiz != NULL){
        liberarMemoria((*raiz).esquerdo);
        liberarMemoria((*raiz).direito);
        free(raiz);
    }
}