#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: ./chgrp <그룹명> <파일>\n");
        return 1;
    }

    struct group *gr = getgrnam(argv[1]);
    if (!gr) {
        fprintf(stderr, "그룹 '%s'을(를) 찾을 수 없습니다.\n", argv[1]);
        return 1;
    }

    if (chown(argv[2], -1, gr->gr_gid) != 0) {
        perror("chgrp 실패");
        return 1;
    }
    return 0;
}
