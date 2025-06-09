#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void search(const char *base, const char *target) {
    DIR *dp = opendir(base);
    if (!dp) return;

    struct dirent *ent;
    char path[4096];
    while ((ent = readdir(dp)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;
        snprintf(path, sizeof(path), "%s/%s", base, ent->d_name);

        struct stat st;
        if (stat(path, &st) == -1) continue;

        if (S_ISDIR(st.st_mode)) {
            search(path, target);
        } else {
            if (strcmp(ent->d_name, target) == 0) {
                printf("%s\n", path);
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./find <파일이름>\n");
        return 1;
    }
    search(".", argv[1]);
    return 0;
}
