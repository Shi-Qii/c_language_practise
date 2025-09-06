#include <stdio.h>

int main(void) {
    int num1, num2, result;
    char operator;

    printf("請輸入第一個數字: ");
    scanf("%d", &num1);
    printf("請輸入運算符 (+, -, *, /): ");
    scanf(" %c", &operator);  // 注意在 %c 之前加上空格，防止讀取上一個輸入留下的換行符
    printf("請輸入第二個數字: ");
    scanf("%d", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("結果: %d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("結果: %d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("結果: %d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("結果: %d / %d = %d\n", num1, num2, result);
            } else {
                printf("錯誤: 除數不能為零！\n");
            }
            break;
        default:
            printf("無效的運算符！\n");
    }

    return 0;
}
