#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./dirname <경로>\n");
        return 1;
    }
    char *s = strdup(argv[1]);
    char *p = strrchr(s, '/');
    if (p) {
        if (p == s) {
            printf("/\n");
        } else {
            *p = '\0';
            printf("%s\n", s);
        }
    } else {
        printf(".\n");
    }
    free(s);
    return 0;
}
