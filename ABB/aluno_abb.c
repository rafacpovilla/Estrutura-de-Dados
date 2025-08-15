#include "aluno_abb.h"


No* criarNo(Aluno aluno) {
    No* no = (No*)malloc(sizeof(No));
    if (no == NULL) {
        perror("Erro ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    no->aluno = aluno;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

No* inserir(No* raiz, Aluno aluno) {
    if (raiz == NULL) {
        return criarNo(aluno);
    }

    if (aluno.matricula < raiz->aluno.matricula) {  //insere na esquerda
        raiz->esquerda = inserir(raiz->esquerda, aluno);
    } 
    else if (aluno.matricula > raiz->aluno.matricula) {   //insere na direita
        raiz->direita = inserir(raiz->direita, aluno);
    } 
    else {   //já existe
        printf("Aluno com matrícula %d já existe na árvore. Não inserido.\n", aluno.matricula);
    }

    return raiz;
}

No* buscar(No* raiz, int matricula) {
    if (raiz == NULL || raiz->aluno.matricula == matricula) {
        return raiz;
    }

    if (matricula < raiz->aluno.matricula) {  //busca na esquerda
        return buscar(raiz->esquerda, matricula);
    } 
    else {   //busca na direita
        return buscar(raiz->direita, matricula);
    }
}

void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("Matrícula: %d, Nome: %s, Média: %.2f\n", raiz->aluno.matricula, raiz->aluno.nome, raiz->aluno.media);
        imprimirEmOrdem(raiz->direita);
    }
}

No* encontrarMinimo(No* no) {
    No* atual = no;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover(No* raiz, int matricula) {
    if (raiz == NULL) {
        return raiz;
    }

    if (matricula < raiz->aluno.matricula) {  //remove na esquerda
        raiz->esquerda = remover(raiz->esquerda, matricula);
    } 
    else if (matricula > raiz->aluno.matricula) {  //remove na adireita
        raiz->direita = remover(raiz->direita, matricula);
    } 
    else {
        //nó com apenas um filho ou nenhum filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } 
        else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        //nó com dois filhos: obter o sucessor in-order (menor na subárvore direita)
        No* temp = encontrarMinimo(raiz->direita);

        //copia os dados do sucessor para este nó
        raiz->aluno = temp->aluno;

        //remover o sucessor
        raiz->direita = remover(raiz->direita, temp->aluno.matricula);
    }
    return raiz;
}

void liberarABB(No* raiz) {
    if (raiz != NULL) {
        liberarABB(raiz->esquerda);
        liberarABB(raiz->direita);
        free(raiz);
    }
}