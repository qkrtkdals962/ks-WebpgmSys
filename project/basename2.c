#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "사용법: ./basename2 <경로> [제거할접미사]\n");
        return 1;
    }
    char *path = argv[1];
    char *suffix = (argc == 3) ? argv[2] : NULL;

    char *s = strrchr(path, '/');
    char *name = (s) ? s + 1 : path;

    if (suffix) {
        size_t len_name = strlen(name);
        size_t len_suf = strlen(suffix);
        if (len_name >= len_suf && strcmp(name + len_name - len_suf, suffix) == 0) {
            name[len_name - len_suf] = '\0';
        }
    }
    printf("%s\n", name);
    return 0;
}
