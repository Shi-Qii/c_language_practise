#include <stdio.h>
#include <stdlib.h>

/*
    題目：使用者輸入一個數字 n
    -> 建立一個動態陣列存放 n 個整數
    -> 計算總和與平均數
*/

int main() {
    int elementCount;
    printf("請輸入要處理的整數個數: ");
    scanf("%d", &elementCount);

    // 使用 malloc 配置動態陣列
    int *numberArray = (int *)malloc(elementCount * sizeof(int));
    if (numberArray == NULL) {
        printf("記憶體配置失敗！\n");
        return 1;
    }

    // 輸入陣列內容
    for (int index = 0; index < elementCount; index++) {
        printf("請輸入第 %d 個整數: ", index + 1);
        scanf("%d", &numberArray[index]);
    }

    // 計算總和與平均
    long sum = 0;
    for (int index = 0; index < elementCount; index++) {
        sum += numberArray[index];
    }
    double average = (double)sum / elementCount;

    printf("整數總和: %ld\n", sum);
    printf("平均數: %.2f\n", average);

    // 釋放記憶體
    free(numberArray);

    return 0;
}
