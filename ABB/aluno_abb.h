#ifndef ALUNO_ABB_H
#define ALUNO_ABB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura para representar um aluno
typedef struct Aluno {
    int matricula;
    char nome[50];
    float media;
} Aluno;

//estrutura para um nó da ABB
typedef struct No {
    Aluno aluno;
    struct No *esquerda;
    struct No *direita;
} No;


//cria um novo nó com os dados do aluno
No* criarNo(Aluno aluno);

//insere um aluno na ABB
No* inserir(No* raiz, Aluno aluno);

//busca um aluno na ABB pela matricula
No* buscar(No* raiz, int matricula);

//imprime a ABB em ordem (in-order traversal)
void imprimirEmOrdem(No* raiz);

//função auxiliar para encontrar o nó com o menor valor na subárvore direita (sucessor in-order)
No* encontrarMinimo(No* no);

//remove um aluno da ABB pela matrícula
No* remover(No* raiz, int matricula);

//lsibera a memória alocada pela ABB
void liberarABB(No* raiz);

#endif // ALUNO_ABB_H