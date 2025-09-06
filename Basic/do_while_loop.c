#include <stdio.h>

int main(void) {
    int i = 1;
    printf("1到10的數字：\n");
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);
    printf("\n");

    return 0;
}
