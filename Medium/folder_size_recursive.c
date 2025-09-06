#include <stdio.h>

/*
 *題目 6：模擬遞迴計算資料夾大小
    題目：模擬資料夾結構，並用遞迴計算資料夾大小
    - 每個資料夾包含多個檔案與子資料夾
    - 遞迴計算整個資料夾大小
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

    // 加總所有檔案大小
    for (int i = 0; i < folder->fileCount; i++) {
        totalSize += folder->files[i].size;
    }

    // 遞迴計算所有子資料夾大小
    for (int i = 0; i < folder->subfolderCount; i++) {
        totalSize += calculateFolderSize(folder->subfolders[i]);
    }

    return totalSize;
}

int main() {
    // 建立檔案與資料夾
    struct File fileA = {"report.txt", 120};
    struct File fileB = {"data.csv", 200};
    struct File fileC = {"notes.doc", 150};

    struct Folder subfolder = {"SubFolder", {fileC}, 1, {NULL}, 0};
    struct Folder root = {"/Users/shiqi/CLionProjects/first_c_project/Medium/", {fileA, fileB}, 2, {&subfolder}, 1};

    printf("資料夾 %s 總大小: %d KB\n",
           root.name, calculateFolderSize(&root));

    return 0;
}
