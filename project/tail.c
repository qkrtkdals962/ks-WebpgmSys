#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000
#define MAX_LEN   4096

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
        fprintf(stderr, "사용법: ./tail [-n <줄수>] <파일>\n");
        return 1;
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char **buffer = malloc(sizeof(char *) * MAX_LINES);
    int count = 0;
    while (count < MAX_LINES && !feof(fp)) {
        buffer[count] = malloc(MAX_LEN);
        if (!fgets(buffer[count], MAX_LEN, fp)) {
            free(buffer[count]);
            break;
        }
        count++;
    }
    fclose(fp);

    int start = count - lines;
    if (start < 0) start = 0;
    for (int i = start; i < count; i++) {
        fputs(buffer[i], stdout);
        free(buffer[i]);
    }
    free(buffer);
    return 0;
}
