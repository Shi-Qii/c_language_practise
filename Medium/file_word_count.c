#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *題目 5：檔案讀取與單字計數
    題目：讀取一個文字檔案
    -> 計算檔案中的單字數量
    單字定義：以空白或換行分隔的字串
*/

#define MAX_WORD 100
#define MAX_WORD_LENGTH 50

int main() {
    char fileName[100];
    printf("請輸入檔案名稱: ");
    scanf("%s", fileName);

    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("無法開啟檔案 %s\n", fileName);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    // 使用 fscanf 一次讀取一個單字
    while (fscanf(filePointer, "%s", word) == 1) {
        wordCount++;
    }

    fclose(filePointer);

    printf("檔案中共有 %d 個單字。\n", wordCount);

    return 0;
}
