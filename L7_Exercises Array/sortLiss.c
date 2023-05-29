#include <stdio.h>
#include <stdint.h>

void softLiss(uint8_t array[], int size) {
    uint8_t tam;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                tam = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tam;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    uint8_t array[] = {1, 3, 5, 2, 3, 4, 5, 6, 2, 6, 9};
    int size = sizeof(array) / sizeof(array[0]);
    softLiss(array, size);
    return 0;
}

