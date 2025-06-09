#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 4096

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("파일 열기 실패");
            return 1;
        }
    } else if (argc > 2) {
        fprintf(stderr, "사용법: ./uniq [파일]\n");
        return 1;
    }

    char prev[MAX_LEN] = "";
    char cur[MAX_LEN];
    while (fgets(cur, sizeof(cur), fp)) {
        if (strcmp(cur, prev) != 0) {
            fputs(cur, stdout);
            strcpy(prev, cur);
        }
    }

    if (fp != stdin) fclose(fp);
    return 0;
}
