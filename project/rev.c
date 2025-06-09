#include <stdio.h>
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
        fprintf(stderr, "사용법: ./rev [파일]\n");
        return 1;
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp)) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        for (int i = (int)len - 1; i >= 0; i--) {
            putchar(line[i]);
        }
        putchar('\n');
    }

    if (fp != stdin) fclose(fp);
    return 0;
}
