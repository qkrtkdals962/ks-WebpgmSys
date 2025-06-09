#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000
#define MAX_LEN   4096

int cmp(const void *a, const void *b) {
    const char * const *sa = a;
    const char * const *sb = b;
    return strcmp(*sa, *sb);
}

int main(int argc, char *argv[]) {
    char **lines = malloc(sizeof(char *) * MAX_LINES);
    int count = 0;

    if (argc == 1) {
        char buf[MAX_LEN];
        while (count < MAX_LINES && fgets(buf, MAX_LEN, stdin)) {
            lines[count] = strdup(buf);
            count++;
        }
    } else if (argc == 2) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            perror("파일 열기 실패");
            return 1;
        }
        char buf[MAX_LEN];
        while (count < MAX_LINES && fgets(buf, MAX_LEN, fp)) {
            lines[count] = strdup(buf);
            count++;
        }
        fclose(fp);
    } else {
        fprintf(stderr, "사용법: ./sort [파일]\n");
        return 1;
    }

    qsort(lines, count, sizeof(char *), cmp);
    for (int i = 0; i < count; i++) {
        fputs(lines[i], stdout);
        free(lines[i]);
    }
    free(lines);
    return 0;
}
