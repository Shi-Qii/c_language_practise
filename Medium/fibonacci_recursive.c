#include <stdio.h>

/*
    題目：輸入一個數字 n
    -> 使用遞迴計算第 n 項費氏數列
    -> 額外輸出從第 1 項到第 n 項的所有數字
*/

long fibonacci(int position) {
    if (position == 0) return 0;
    if (position == 1) return 1;
    return fibonacci(position - 1) + fibonacci(position - 2);
}

int main() {
    int term;
    printf("請輸入要計算的費氏數列項數: ");
    scanf("%d", &term);

    printf("費氏數列第 %d 項為: %ld\n", term, fibonacci(term));

    printf("完整序列: ");
    for (int index = 0; index <= term; index++) {
        printf("%ld ", fibonacci(index));
    }
    printf("\n");

    return 0;
}
