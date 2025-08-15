#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

struct No {
    int valor;
    struct No *esq;
    struct No *dir;
};

struct arvBin {
    struct No *raiz;
};

int insereArvBin(ArvBin *arv, int valor){
    if(arv == NULL){
        return 0;
    }

    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL){
        return 0;
    }

    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    //procurar onde inserir o novo nó
    if(arv->raiz == NULL){
        arv->raiz = novo;
        return 1;
    }

    struct No *atual = arv->raiz;
    struct No *anterior = NULL;

    //navega nos nós da arvore até chegar em um nó folha
    while(atual != NULL){
        anterior = atual;
        if(valor ==atual->valor){
            free(novo);
            return 0;  //o elemento já existe na árvore
        }

        if(valor > atual->valor){  //navega para a direita
            atual = atual->dir;
        }
        else{
            atual = atual->esq;   //navega para a esquerda
        }
    }

    //insere como filho desse nó folha
    if(valor > anterior->valor){
        anterior->dir = novo;  //insere na direita
    }
    else{
        anterior->esq = novo;  //insere na esquerda
    }

    return 1;
}

struct No* removeAtual(struct No* atual){
    struct No *no1, *no2;

    //nó folha (sem filho) ou sem filho na esquerda (no com um filho na direita)
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }

    no1 = atual;
    //procura filho mais a direita na subarvore da esquerda (2 filhos)
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }

    //copia esse filho para o lugar que foi removido
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;

    free(atual);
    return no2;
}

int removeArvBin(ArvBin *arv, int valor){
    if(arv == NULL){
        return 0;
    }
    struct No* anterior = NULL;
    struct No* atual = arv->raiz;
    
    while(atual != NULL){
        //achou o nó a ser removido
        if(valor == atual->valor){
            if(atual == arv->raiz){
                arv->raiz = removeAtual(atual);
            }
            else{
                if(anterior->dir == atual){
                    anterior->dir = removeAtual(atual);
                }
                else{
                    anterior->esq = removeAtual(atual);
                }
            }
            return 1;
        }

        //continua andando na arvore a procura do nó a ser removido
        anterior = atual;
        if(valor > atual->valor){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0; //nao encontrou o valor
}

int buscaArvBin(ArvBin *arv, int valor){
    if(arv->raiz == NULL){
        return 0;
    }
    struct No* atual = arv->raiz;

    while(atual != NULL){
        if(valor == atual->valor){
            return 1;
        }
        if(valor > atual->valor){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}