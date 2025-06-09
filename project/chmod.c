#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: ./chmod <모드(8진수)> <파일>\n");
        return 1;
    }

    mode_t mode = strtol(argv[1], NULL, 8);
    if (chmod(argv[2], mode) != 0) {
        perror("chmod 실패");
        return 1;
    }
    return 0;
}
