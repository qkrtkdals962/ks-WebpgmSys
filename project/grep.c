#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: ./grep <패턴> <파일>\n");
        return 1;
    }

    char *pattern = argv[1];
    FILE *fp = fopen(argv[2], "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            fputs(line, stdout);
        }
    }

    fclose(fp);
    return 0;
}
