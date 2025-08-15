#include <stdio.h>

void bubbleSort(int *vetor, int qtdVetor){
    int i, continua, aux;
    int fim = qtdVetor;

    do{
        continua = 0;
        //troca dois valores consecutivos no vetor
        for(i = 0; i < fim - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                continua = i;
            }
        }
        fim --;
    }while(continua != 0);
}

int particiona(int *vetor, int inicio, int fim){
    int dir, esq, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];

    while(esq < dir){
        while(vetor[esq] <= pivo){
            esq++; //avança posição da esquerda
        }
        while(vetor[dir] > pivo){
            dir--;  //recua posição da direita
        }

        //troca esquerda e direita
        if(esq < dir){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void quickSort(int *vetor, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        //separa os dados em duas partições
        pivo = particiona(vetor, inicio, fim);
        //chama a função para as duas metades
        quickSort(vetor, inicio, pivo -1);
        quickSort(vetor, pivo + 1, fim);
    }
}