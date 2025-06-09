#include <stdio.h>
#include <stdlib.h>

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
        fprintf(stderr, "사용법: ./nl [파일]\n");
        return 1;
    }

    char line[MAX_LEN];
    int lineno = 1;
    while (fgets(line, sizeof(line), fp)) {
        printf("%6d\t%s", lineno++, line);
    }

    if (fp != stdin) fclose(fp);
    return 0;
}
