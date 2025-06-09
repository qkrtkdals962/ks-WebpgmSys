#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "사용법: ./chown <사용자명> <그룹명> <파일>\n");
        return 1;
    }

    struct passwd *pw = getpwnam(argv[1]);
    if (!pw) {
        fprintf(stderr, "사용자 '%s'을(를) 찾을 수 없습니다.\n", argv[1]);
        return 1;
    }
    struct group *gr = getgrnam(argv[2]);
    if (!gr) {
        fprintf(stderr, "그룹 '%s'을(를) 찾을 수 없습니다.\n", argv[2]);
        return 1;
    }

    if (chown(argv[3], pw->pw_uid, gr->gr_gid) != 0) {
        perror("chown 실패");
        return 1;
    }
    return 0;
}
