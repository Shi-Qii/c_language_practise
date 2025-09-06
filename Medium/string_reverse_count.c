#include <stdio.h>
#include <string.h>

/*
    題目：輸入一個字串，輸出：
    1. 字串長度
    2. 字串反轉結果
    3. 字母、數字、其他字元的數量
*/

int main() {
    char inputString[200];

    printf("請輸入一個字串: ");
    fgets(inputString, sizeof(inputString), stdin);

    // 移除換行符號（若存在）
    size_t stringLength = strlen(inputString);
    if (stringLength > 0 && inputString[stringLength - 1] == '\n') {
        inputString[stringLength - 1] = '\0';
        stringLength--;
    }

    // 1. 輸出長度
    printf("字串長度: %zu\n", stringLength);

    // 2. 輸出反轉字串
    printf("反轉字串: ");
    for (int index = stringLength - 1; index >= 0; index--) {
        putchar(inputString[index]);
    }
    printf("\n");

    // 3. 計算字母、數字、其他字元
    int letterCount = 0, digitCount = 0, otherCount = 0;
    for (size_t index = 0; index < stringLength; index++) {
        if ((inputString[index] >= 'A' && inputString[index] <= 'Z') ||
            (inputString[index] >= 'a' && inputString[index] <= 'z')) {
            letterCount++;
            } else if (inputString[index] >= '0' && inputString[index] <= '9') {
                digitCount++;
            } else {
                otherCount++;
            }
    }

    printf("字母數量: %d\n", letterCount);
    printf("數字數量: %d\n", digitCount);
    printf("其他字元數量: %d\n", otherCount);

    return 0;
}
