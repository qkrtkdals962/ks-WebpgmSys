#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./sleep <초>\n");
        return 1;
    }

    int sec = atoi(argv[1]);
    if (sec < 0) {
        fprintf(stderr, "양의 정수를 입력하세요.\n");
        return 1;
    }

    sleep(sec);
    return 0;
}
