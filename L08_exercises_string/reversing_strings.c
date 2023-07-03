#include <stdio.h>
#include <stdint.h>

void revert(char array[], int size) {
    int prei = size - 1;
    for (int i = size - 1; i >= 0; i--) {
        if (array[i] == ' ' || i == 0) {
            if (i == 0) {
                for (int j = i; j <= prei; j++) {
                    printf("%c", array[j]);
                }
            } else {
                for (int j = i + 1; j <= prei; j++) {
                    printf("%c", array[j]);
                }
                printf(" ");
            }
            prei = i - 1;
        }
    }
    printf("\n");
}

int main() {
    char array[] = "mot hai ba, bon nam";
    int size = sizeof(array) / sizeof(array[0]) - 1;
    for (int i = 0; i < size; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
    revert(array, size);
    return 0;
}

