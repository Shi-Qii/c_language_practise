#include <stdio.h>
#include <dirent.h>   // opendir, readdir
#include <sys/stat.h> // stat
#include <string.h>

/*
*📂 真實版：folder_size_recursive_real.c

這個版本會真的去讀取檔案系統，適用 Linux/macOS（Windows 寫法不同，要用 FindFirstFile/FindNextFile）。
 *
    真實版：資料夾大小計算
    - 使用 dirent.h 走訪目錄
    - 使用 stat 取得檔案大小
    - 用遞迴累加總和
*/

long calculateFolderSize(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    if (dp == NULL) {
        return 0; // 無法開啟目錄
    }

    long totalSize = 0;
    char fullPath[1024];
    struct stat fileStat;

    while ((entry = readdir(dp)) != NULL) {
        // 忽略 "." 和 ".."
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
            }

        // 建立完整路徑
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (stat(fullPath, &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                // 如果是資料夾 -> 遞迴進去
                totalSize += calculateFolderSize(fullPath);
            } else {
                // 如果是檔案 -> 累加檔案大小
                totalSize += fileStat.st_size;
            }
        }
    }

    closedir(dp);
    return totalSize;
}

int main() {
    char path[256];
    printf("請輸入資料夾路徑: ");
    scanf("%s", path);

    long size = calculateFolderSize(path);
    printf("資料夾 %s 總大小: %ld bytes\n", path, size);

    return 0;
}
