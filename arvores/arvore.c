#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arv{
    char tipo;
    struct arv* esq;
    struct arv* dir;
};

//Cria uma árvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char c, Arv* e, Arv* d){
    Arv *arv = (Arv*)malloc(sizeof(Arv));
    arv->tipo = c;
    arv->esq = e;
    arv->dir = d;

    return arv;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a){
    if(a != NULL){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a){
    return a == NULL;
}

//indica a ocorrência (1) ou não (0) do char
int arv_pertence (Arv* a, char c){
    if(arv_vazia(a)){
        return 0; //arvore vazia
    }
    else{
        if(a->tipo == c){
            return 1;
        }
        else if(arv_pertence(a->esq, c) == 1){
            return 1;
        }
        else if(arv_pertence(a->dir, c) == 1){
            return 1;
        }
        else{
            return 0; //nao encontrou
        }
    }
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a){
    if(!arv_vazia(a)){
        printf("%c ", a->tipo); //raiz
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

//retorna a mãe/pai de um dado 
Arv* arv_pai (Arv* a, char c){
    if(a == NULL || a->esq == NULL && a->dir == NULL){
        return NULL;  //arvore vazia ou é folha ent n tem pai
    }

    if(a->esq != NULL && a->esq->tipo == c){
        return a; //nó esquerdo é o pai
    }
    if(a->dir != NULL && a->dir->tipo == c){
        return a; //nó direito é o pai
    }

    //procura o pai na subárvore esquerda e direita
    Arv* pai = arv_pai(a->esq, c);
    if(pai != NULL){
        return pai; //encontrou o pai na subárvore esquerda
    }
    return arv_pai(a->dir, c); //procura na subárvore direita
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a){
    if(arv_vazia(a)){
        return 0;  //arvore vazia
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1;  //é uma folha
    }
    else{
        return folhas(a->esq) + folhas(a->dir);  //soma das folhas
    }
}

//retorna o numero de ocorrencias de um dado char na árvore
int ocorrencias (Arv* a, char c){
    if(arv_vazia(a)){
        return 0;  //arvore vazia
    }
    if(a->tipo == c){  //a raiz é uma ocorrencia
        return 1 + ocorrencias(a->esq, c) + ocorrencias(a->dir, c); //conta a raiz e soma as ocorrências nas subárvores
    }
    else{   //a raiz não é uma ocorrência
        return ocorrencias(a->esq, c) + ocorrencias(a->dir, c); //soma as ocorrências nas subárvores
    }
}

//retorna a altura da árvore a
int altura(Arv* a){
    if(arv_vazia(a)){
        return -1;  //arvore vazia
    }
    
    int altura_esq = altura(a->esq);
    int altura_dir = altura(a->dir);
    
    if(altura_esq > altura_dir){
        return altura_esq + 1;    
    }
    else{
        return altura_dir + 1;
    }
}