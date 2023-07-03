#include <stdio.h>
#include <stdint.h>

void demsolan(uint8_t array[], int size) {
    uint8_t kiemtra[size];
    for (int i = 0; i < size; i++) {
        kiemtra[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (kiemtra[i] == 1) {
            continue;
        }

        int dem = 1;
        for (int j = i + 1; j < size; j++) {
            if (array[j] == array[i]) {
                dem++;
                kiemtra[j] = 1;
            }
        }

        printf("So %d xuat hien: %d lan\n", array[i], dem);
    }
}

int main() {
    uint8_t array[] = {1, 3, 5, 2, 3, 4, 5, 6, 2, 6, 9};
    int size = sizeof(array) / sizeof(array[0]);
    demsolan(array, size);
    return 0;
}

