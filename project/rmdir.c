#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./rmdir <디렉토리명>\n");
        return 1;
    }

    if (rmdir(argv[1]) != 0) {
        perror("rmdir 실패");
        return 1;
    }
    return 0;
}
