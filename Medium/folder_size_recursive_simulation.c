#include <stdio.h>

/*
 *題目 6：遞迴計算資料夾大小
    模擬版：資料夾大小計算
    - 使用 struct File / struct Folder 模擬檔案系統
    - 用遞迴計算總大小
*/

#define MAX_FILES 10
#define MAX_SUBFOLDERS 5

struct File {
    char name[50];
    int size; // 檔案大小 (KB)
};

struct Folder {
    char name[50];
    struct File files[MAX_FILES];
    int fileCount;
    struct Folder *subfolders[MAX_SUBFOLDERS];
    int subfolderCount;
};

// 遞迴計算資料夾大小
int calculateFolderSize(struct Folder *folder) {
    int totalSize = 0;

    // 加總檔案大小
    for (int i = 0; i < folder->fileCount; i++) {
        totalSize += folder->files[i].size;
    }

    // 遞迴處理子資料夾
    for (int i = 0; i < folder->subfolderCount; i++) {
        totalSize += calculateFolderSize(folder->subfolders[i]);
    }

    return totalSize;
}

int main() {
    // 建立檔案
    struct File fileA = {"report.txt", 120};
    struct File fileB = {"data.csv", 200};
    struct File fileC = {"notes.doc", 150};

    // 建立子資料夾 (含一個檔案)
    struct Folder subfolder = {"SubFolder", {fileC}, 1, {NULL}, 0};

    // 建立根資料夾 (含兩個檔案與一個子資料夾)
    struct Folder root = {"Root", {fileA, fileB}, 2, {&subfolder}, 1};

    // 計算總大小
    printf("資料夾 %s 總大小: %d KB\n",
           root.name, calculateFolderSize(&root));

    return 0;
}
