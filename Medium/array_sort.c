#include <stdio.h>

// 函式：冒泡排序
void bubble_sort(int arr[], int n) {
    // 外層迴圈：需要 n-1 輪
    for (int i = 0; i < n - 1; i++) {
        // 內層迴圈：每輪比較相鄰元素
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 如果前面比後面大 -> 交換
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};   // 測試陣列
    int n = sizeof(arr) / sizeof(arr[0]); // 計算陣列大小

    bubble_sort(arr, n);  // 呼叫排序函式

    // 輸出結果
    printf("Sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


// 函式：冒泡排序
void bubbleSort(int arrayToSort[], int totalElements) {
    for (int currentPass = 0; currentPass < totalElements - 1; currentPass++) {
        for (int currentIndex = 0; currentIndex < totalElements - currentPass - 1; currentIndex++) {
            if (arrayToSort[currentIndex] > arrayToSort[currentIndex + 1]) {
                // 交換相鄰元素
                int temporaryValue = arrayToSort[currentIndex];
                arrayToSort[currentIndex] = arrayToSort[currentIndex + 1];
                arrayToSort[currentIndex + 1] = temporaryValue;
            }
        }
    }
}

int main2() {
    int arraySize;

    printf("請輸入陣列大小: ");
    scanf("%d", &arraySize);

    int numbers[arraySize];
    printf("請輸入 %d 個整數:\n", arraySize);

    for (int elementIndex = 0; elementIndex < arraySize; elementIndex++) {
        scanf("%d", &numbers[elementIndex]);
    }

    bubbleSort(numbers, arraySize);

    printf("排序後陣列: ");
    for (int elementIndex = 0; elementIndex < arraySize; elementIndex++) {
        printf("%d ", numbers[elementIndex]);
    }
    printf("\n");

    return 0;
}
