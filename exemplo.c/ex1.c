#include <stdio.h>

void bubble_sort(int vetor[], int tam) {
    // Variável auxiliar para troca
    int temp;

    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            // Comparando elementos adjacentes
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void imprimir_vetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor antes da ordenacao:\n");
    imprimir_vetor(vetor, tam);

    bubble_sort(vetor, tam);

    printf("Vetor apos a ordenacao:\n");
    imprimir_vetor(vetor, tam);

    return 0;
}