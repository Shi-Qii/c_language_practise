#include <stdio.h>

int main(void) {
    int num;
    unsigned long long factorial = 1;

    printf("請輸入一個正整數: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("負數沒有階乘！\n");
    } else {
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("%d 的階乘是 %llu\n", num, factorial);
    }

    return 0;
}
