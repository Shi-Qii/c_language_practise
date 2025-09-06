#include <stdio.h>

int main(void) {
    int x = 10, y = 3;

    // 算術運算符
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);  // 注意使用 %% 輸出 %

    // 比較運算符
    printf("x == y: %d\n", x == y);
    printf("x != y: %d\n", x != y);
    printf("x > y: %d\n", x > y);
    printf("x < y: %d\n", x < y);

    // 邏輯運算符
    printf("x > 5 && y < 5: %d\n", x > 5 && y < 5);
    printf("x > 5 || y < 5: %d\n", x > 5 || y < 5);

    return 0;
}
