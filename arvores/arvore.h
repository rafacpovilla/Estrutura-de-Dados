#ifndef ARVORE_H
#define ARVORE_H


typedef struct arv Arv ;

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char c, Arv* e, Arv* d);

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do char
int arv_pertence (Arv* a, char c);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, char c);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado char na árvore
int ocorrencias (Arv* a, char c);

//retorna a altura da árvore a
int altura(Arv* a);

#endif