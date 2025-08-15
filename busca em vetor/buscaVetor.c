#include <stdio.h>

int buscaLinear(int *vetor, int qtdVetor, int elem){
    int i;
    for(i = 0; i < qtdVetor; i++){
        if(elem == vetor[i]){
            return i;   //elemento encontrado, retorna a posição
        }
    }
    return -1;  //elemento não encontrado
}

int buscaOrdenada(int *vetor, int qtdVetor, int elem){
    int i;
    for(i = 0; i <qtdVetor; i++){
        if(elem == vetor[i]){
            return i;  //elemento encontrado, retorna a posição
        }
        if(elem < vetor[i]){
            return -1;  //para a busca, pq todos os elemntos daí em diante serão maiores
        }
    }
    return -1;   //elemento não encontrado
}

int buscaBinaria(int *vetor, int qtdVetor, int elem){
    int i;
    int inicio, final, meio = 0;
    inicio = 0;
    final = qtdVetor -1;

    while(inicio <= final){
        meio = (inicio + final) / 2;
        if(elem < vetor[meio]){   //busca na esquerda
            final = meio - 1;
        }
        else{
            if(elem > vetor[meio]){   //busca na direita
                inicio = meio + 1;
            }
            else{  //o próprio meio
                return meio;
            }
        }
    }

    return -1;  //elemento não encontrado
}

int main(){
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int elem;

    printf("Digite o num que deseja buscar:\n");
    scanf("%d", &elem);

    int retorno;
    retorno = buscaLinear(vetor, 10, elem);
    // retorno = buscaOrdenada(vetor, 10, elem);
    // retorno = buscaBinaria(vetor, 10, elem);

    if(retorno == -1){
        printf("elemento nao encontrado!\n");
    }
    else{
        printf("elemento encontrado na posicao: %d\n", retorno);
    }

    return 0;
}