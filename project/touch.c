#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <utime.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./touch <파일명>\n");
        return 1;
    }

    int fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("파일 생성/오픈 실패");
        return 1;
    }
    close(fd);

    struct utimbuf times;
    times.actime = time(NULL);
    times.modtime = times.actime;
    if (utime(argv[1], &times) != 0) {
        perror("utime 실패");
        return 1;
    }
    return 0;
}
