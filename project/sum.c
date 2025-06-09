#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: ./sum <숫자1> [숫자2 ...]\n");
        return 1;
    }

    long total = 0;
    for (int i = 1; i < argc; i++) {
        total += atol(argv[i]);
    }
    printf("%ld\n", total);
    return 0;
}
