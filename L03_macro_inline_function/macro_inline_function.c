#include <stdio.h>

#define sum_macro(a, b) ((a) + (b))
// do trình biên dịch này không hỗ trợ từ khóa inline nên ta thêm static vào.
static inline int sum_inline(int a, int b) {
    return a + b;
}

int sum_function(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    
    // Sử dụng Macro
    int result_macro = sum_macro(num1, num2);
    printf("sum of macro: %d\n", result_macro);
    
    // Sử dụng inline function
    int result_inline = sum_inline(num1, num2);
    printf("sum of inline: %d\n", result_inline);
    
    // Sử dụng function
    int result_function = sum_function(num1, num2);
    printf("sum of function: %d\n", result_function);
    
    return 0;
}

