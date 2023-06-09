#include <stdio.h>
#include <stdlib.h>

int n = 5;

int main() {

    // Sử dụng malloc để cấp phát bộ nhớ cho một mảng các số nguyên
    int* ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Không thể cấp phát bộ nhớ.");
        return 0;
    }
    printf("Giá trị của mảng sau khi sử dụng malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Sử dụng calloc để cấp phát bộ nhớ cho một mảng các số nguyên với giá trị ban đầu là 0
    int* ptr2 = (int*)calloc(n, sizeof(int));
    if (ptr2 == NULL) {
        printf("Không thể cấp phát bộ nhớ.");
        return 0;
    }
    printf("\n\nGiá trị của mảng sau khi sử dụng calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr2[i]);
    }

    // Sử dụng realloc để thay đổi kích thước của mảng đã cấp phát từ 5 thành 10 phần tử kiểu int
    ptr = (int*)realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("Không thể cấp phát bộ nhớ.");
        return 0;
    }
    printf("\n\nGiá trị của mảng sau khi sử dụng realloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    // Giải phóng bộ nhớ đã cấp phát
    free(ptr);
    free(ptr2);

    return 0;
}

