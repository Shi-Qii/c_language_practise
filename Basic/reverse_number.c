#include <stdio.h>

int main(void) {
    int num, reversed = 0;
    printf("請輸入一個正整數: ");
    scanf("%d", &num);

    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    printf("反轉後的數字是: %d\n", reversed);

    return 0;
}
