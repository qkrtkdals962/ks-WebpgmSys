#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./wc <파일명>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    int ch, lines = 0, words = 0, bytes = 0;
    int in_word = 0;
    while ((ch = fgetc(fp)) != EOF) {
        bytes++;
        if (ch == '\n') lines++;
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    fclose(fp);

    struct stat st;
    if (stat(argv[1], &st) == 0) {
        bytes = st.st_size;
    }

    printf("%d %d %d %s\n", lines, words, bytes, argv[1]);
    return 0;
}
