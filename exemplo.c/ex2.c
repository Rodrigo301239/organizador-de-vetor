#include <stdio.h>

void merge(int vetor[], int inicio1, int fim1, int inicio2, int fim2) {
    int i = inicio1;     // Índice para a primeira metade
    int j = inicio2;     // Índice para a segunda metade
    int k = 0;           // Índice para o vetor auxiliar
    int tam = fim2 - inicio1 + 1; // Tamanho total do vetor que será mesclado
    int *temp = (int*)malloc(tam * sizeof(int)); // Vetor auxiliar

    // Mesclando as duas metades
    while (i <= fim1 && j <= fim2) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    // Copiando os elementos restantes da primeira metade
    while (i <= fim1) {
        temp[k++] = vetor[i++];
    }

    // Copiando os elementos restantes da segunda metade
    while (j <= fim2) {
        temp[k++] = vetor[j++];
    }

    // Copiando os elementos do vetor auxiliar de volta para o vetor original
    for (i = inicio1, k = 0; i <= fim2; i++, k++) {
        vetor[i] = temp[k];
    }

    free(temp); // Liberar a memória alocada
}

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);     // Ordenar a primeira metade
        merge_sort(vetor, meio + 1, fim);    // Ordenar a segunda metade
        merge(vetor, inicio, meio, meio + 1, fim); // Mesclar as duas metades
    }
}

void imprimir_vetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {38, 27, 43, 3, 9, 82, 10};
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor antes da ordenação:\n");
    imprimir_vetor(vetor, tam);

    merge_sort(vetor, 0, tam - 1);

    printf("Vetor após a ordenação:\n");
    imprimir_vetor(vetor, tam);

    return 0;
}