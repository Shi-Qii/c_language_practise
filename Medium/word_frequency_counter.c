#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// 定義一個結構體來儲存單字與出現次數
typedef struct WordFrequency {
    char *word;
    int count;
} WordFrequency;

// 動態陣列的初始大小
#define INITIAL_CAPACITY 100

// 將單字轉成小寫
void convertToLowerCase(char *text) {
    for (int index = 0; text[index]; index++) {
        text[index] = (char)tolower(text[index]);
    }
}

// 從字串中去除標點符號，只保留字母和數字
void removePunctuation(char *text) {
    char cleanedText[MAX_WORD_LENGTH];
    int cleanedIndex = 0;

    for (int originalIndex = 0; text[originalIndex]; originalIndex++) {
        if (isalnum(text[originalIndex])) {
            cleanedText[cleanedIndex++] = text[originalIndex];
        }
    }
    cleanedText[cleanedIndex] = '\0';
    strcpy(text, cleanedText);
}

// 尋找單字在陣列中是否已存在
int findWordIndex(WordFrequency *wordList, int wordCount, const char *targetWord) {
    for (int index = 0; index < wordCount; index++) {
        if (strcmp(wordList[index].word, targetWord) == 0) {
            return index;
        }
    }
    return -1;
}

// 比較函數，用於 qsort 排序
int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *filePointer = fopen("/Users/shiqi/CLionProjects/first_c_project/Ｍedium/sample.txt", "r");

    // FILE *filePointer = fopen("sample.txt", "/Users/shiqi/CLionProjects/first_c_project/Ｍedium/sample.txt");
    if (filePointer == NULL) {
        perror("無法開啟檔案");
        return 1;
    }

    WordFrequency *wordList = malloc(sizeof(WordFrequency) * INITIAL_CAPACITY);
    if (wordList == NULL) {
        perror("記憶體配置失敗");
        return 1;
    }

    int currentCapacity = INITIAL_CAPACITY;
    int wordCount = 0;

    char currentWord[MAX_WORD_LENGTH];
    while (fscanf(filePointer, "%s", currentWord) != EOF) {
        removePunctuation(currentWord);
        convertToLowerCase(currentWord);

        if (strlen(currentWord) == 0) {
            continue;
        }

        int existingIndex = findWordIndex(wordList, wordCount, currentWord);
        if (existingIndex != -1) {
            wordList[existingIndex].count++;
        } else {
            if (wordCount >= currentCapacity) {
                currentCapacity *= 2;
                wordList = realloc(wordList, sizeof(WordFrequency) * currentCapacity);
                if (wordList == NULL) {
                    perror("記憶體重新配置失敗");
                    return 1;
                }
            }

            wordList[wordCount].word = malloc(strlen(currentWord) + 1);
            strcpy(wordList[wordCount].word, currentWord);
            wordList[wordCount].count = 1;
            wordCount++;
        }
    }

    fclose(filePointer);

    // 排序
    qsort(wordList, wordCount, sizeof(WordFrequency), compareWords);

    // 印出結果
    printf("單字\t出現次數\n");
    printf("-------------------\n");
    for (int index = 0; index < wordCount; index++) {
        printf("%s\t%d\n", wordList[index].word, wordList[index].count);
        free(wordList[index].word); // 釋放每個單字的記憶體
    }

    free(wordList); // 釋放整個陣列
    return 0;
}
