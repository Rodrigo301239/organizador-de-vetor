#include <stdio.h>

void insertion_sort(int vetor[], int tam) {
    for (int i = 1; i < tam; i++) {
        int chave = vetor[i]; // Elemento a ser inserido
        int j = i - 1;

        // Move os elementos do vetor que são maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave; // Insere a chave na posição correta
    }
}

void imprimir_vetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6};
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor antes da ordenação:\n");
    imprimir_vetor(vetor, tam);

    insertion_sort(vetor, tam);

    printf("Vetor após a ordenação:\n");
    imprimir_vetor(vetor, tam);

    return 0;
}
