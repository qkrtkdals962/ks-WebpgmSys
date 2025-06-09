#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *path = (argc == 1) ? "." : argv[1];
    DIR *dp = opendir(path);
    if (!dp) {
        perror("디렉토리 열기 실패");
        return 1;
    }

    struct dirent *ent;
    while ((ent = readdir(dp)) != NULL) {
        printf("%s  ", ent->d_name);
    }
    printf("\n");
    closedir(dp);
    return 0;
}
