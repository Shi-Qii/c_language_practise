#include <stdio.h>

int main(void) {
    // 宣告不同資料型別的變數
    int a = 10;
    float b = 3.14;
    double c = 2.718281828;
    char d = 'A';

    // 輸出變數
    printf("整數 a: %d\n", a);
    printf("浮點數 b: %.2f\n", b);
    printf("雙精度數 c: %.8f\n", c);
    printf("字符 d: %c\n", d);

    return 0;
}
