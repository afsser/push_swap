#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Tamanho máximo de cada string

// Função para encontrar o maior elemento em um array de strings
int findMax(char **arr, int size) {
    int max = strlen(arr[0]);
    for (int i = 1; i < size; i++) {
        if (strlen(arr[i]) > max)
            max = strlen(arr[i]);
    }
    return max;
}

int main() {
    char arr[][MAX_LENGTH] = {"170", "45", "75", "90", "802", "24", "2", "66"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);

    radixSort(arr, n);

    printf("\n\nArray ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);

    return 0;
}
