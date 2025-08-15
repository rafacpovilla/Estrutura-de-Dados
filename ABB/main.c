#include "aluno_abb.h"

int main() {
    No* raiz = NULL;

    printf("--- Teste de Insercao ---\n");
    Aluno a1 = {101, "Carlos Silva", 7.5};
    Aluno a2 = {50, "Ana Souza", 8.0};
    Aluno a3 = {150, "Bruno Costa", 6.8};
    Aluno a4 = {25, "Diana Lima", 9.2};
    Aluno a5 = {75, "Eduardo Alves", 7.0};
    Aluno a6 = {125, "Fernanda Garcia", 8.5};
    Aluno a7 = {175, "Gustavo Santos", 6.0};

    raiz = inserir(raiz, a1);
    raiz = inserir(raiz, a2);
    raiz = inserir(raiz, a3);
    raiz = inserir(raiz, a4);
    raiz = inserir(raiz, a5);
    raiz = inserir(raiz, a6);
    raiz = inserir(raiz, a7);

    // Tentando inserir um aluno com matrícula duplicada
    Aluno a_dup = {101, "Aluno Duplicado", 5.0};
    raiz = inserir(raiz, a_dup);

    printf("\n--- Impressao da ABB (Em Ordem) ---\n");
    imprimirEmOrdem(raiz);

    printf("\n--- Teste de Busca ---\n");
    int matriculaBusca1 = 75;
    No* encontrado1 = buscar(raiz, matriculaBusca1);
    if (encontrado1 != NULL) {
        printf("Aluno com matrícula %d encontrado: %s\n", matriculaBusca1, encontrado1->aluno.nome);
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matriculaBusca1);
    }

    int matriculaBusca2 = 200;
    No* encontrado2 = buscar(raiz, matriculaBusca2);
    if (encontrado2 != NULL) {
        printf("Aluno com matrícula %d encontrado: %s\n", matriculaBusca2, encontrado2->aluno.nome);
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matriculaBusca2);
    }

    printf("\n--- Teste de Remocao ---\n");

    // Remover nó folha (Diana Lima - 25)
    printf("Removendo aluno com matrícula 25...\n");
    raiz = remover(raiz, 25);
    printf("ABB após remover 25:\n");
    imprimirEmOrdem(raiz);

    // Remover nó com um filho (Gustavo Santos - 175)
    printf("\nRemovendo aluno com matrícula 175...\n");
    raiz = remover(raiz, 175);
    printf("ABB após remover 175:\n");
    imprimirEmOrdem(raiz);

    // Remover nó com dois filhos (Carlos Silva - 101)
    printf("\nRemovendo aluno com matrícula 101...\n");
    raiz = remover(raiz, 101);
    printf("ABB após remover 101:\n");
    imprimirEmOrdem(raiz);

    // Tentar remover um aluno que não existe
    printf("\nRemovendo aluno com matrícula 999 (inexistente)...\n");
    raiz = remover(raiz, 999);
    printf("ABB após tentar remover 999:\n");
    imprimirEmOrdem(raiz);

    printf("\n--- Liberando a ABB ---\n");
    liberarABB(raiz);
    raiz = NULL; // A raiz deve ser NULL após a liberação
    printf("ABB liberada. Tentando imprimir (não deve mostrar nada):\n");
    imprimirEmOrdem(raiz);

    return 0;
}