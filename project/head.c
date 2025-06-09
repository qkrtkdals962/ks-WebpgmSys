#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int lines = 10;
    char *filename = NULL;

    if (argc == 2) {
        filename = argv[1];
    } else if (argc == 3 && strcmp(argv[1], "-n") == 0) {
        lines = atoi(argv[2]);
        return 0;
    } else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
        lines = atoi(argv[2]);
        filename = argv[3];
    } else {
        fprintf(stderr, "사용법: ./head [-n <줄수>] <파일>\n");
        return 1;
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char buf[4096];
    int count = 0;
    while (fgets(buf, sizeof(buf), fp) && count < lines) {
        fputs(buf, stdout);
        count++;
    }
    fclose(fp);
    return 0;
}
