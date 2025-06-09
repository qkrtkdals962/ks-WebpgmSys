#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: ./mv <원본이름> <새이름>\n");
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0) {
        perror("mv 실패");
        return 1;
    }
    return 0;
}
