#include <stdio.h>

int main(void) {
    int num;
    printf("請輸入一個整數: ");
    scanf("%d", &num);

    // 判斷正數、負數或零
    if (num > 0) {
        printf("輸入的數字是正數。\n");
    } else if (num < 0) {
        printf("輸入的數字是負數。\n");
    } else {
        printf("輸入的數字是零。\n");
    }

    return 0;
}
