#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "사용법: ./ln [-s] <원본> <링크명>\n");
        return 1;
    }

    int symbolic = 0;
    int idx = 1;
    if (argc == 4 && strcmp(argv[1], "-s") == 0) {
        symbolic = 1;
        idx = 2;
    }

    char *src = argv[idx];
    char *dst = argv[idx + 1];
    if (symbolic) {
        if (symlink(src, dst) != 0) {
            perror("심볼릭 링크 생성 실패");
            return 1;
        }
    } else {
        if (link(src, dst) != 0) {
            perror("하드 링크 생성 실패");
            return 1;
        }
    }
    return 0;
}
