#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct no No;
typedef struct arvBin ArvBin;

int insereArvBin(ArvBin *arv, int valor);
int removeArvBin(ArvBin *arv, int valor);
int buscaArvBin(ArvBin *arv, int valor);

#endif