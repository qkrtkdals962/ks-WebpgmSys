#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int append = 0;
    int idx = 1;

    if (argc < 2) {
        fprintf(stderr, "사용법: ./tee [-a] <파일>\n");
        return 1;
    }
    if (strcmp(argv[1], "-a") == 0) {
        append = 1;
        idx = 2;
    }
    if (idx >= argc) {
        fprintf(stderr, "사용법: ./tee [-a] <파일>\n");
        return 1;
    }

    fp = fopen(argv[idx], append ? "a" : "w");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
        fputc(ch, fp);
    }
    fclose(fp);
    return 0;
}
