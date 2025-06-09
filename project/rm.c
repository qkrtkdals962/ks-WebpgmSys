#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: ./rm <파일1> [파일2 ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (remove(argv[i]) != 0) {
            perror(argv[i]);
        }
    }
    return 0;
}
