#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int main(void) {
    uid_t uid = getuid();
    gid_t gid = getgid();
    struct passwd *pw = getpwuid(uid);
    if (!pw) {
        perror("getpwuid 실패");
        return 1;
    }
    printf("uid=%d(%s)  gid=%d\n", uid, pw->pw_name, gid);

    int ngroups = 0;
    getgrouplist(pw->pw_name, gid, NULL, &ngroups);
    gid_t *groups = malloc(sizeof(gid_t) * ngroups);
    getgrouplist(pw->pw_name, gid, groups, &ngroups);

    printf("groups: ");
    for (int i = 0; i < ngroups; i++) {
        struct group *gr = getgrgid(groups[i]);
        if (gr) printf("%s(%d) ", gr->gr_name, groups[i]);
    }
    printf("\n");
    free(groups);
    return 0;
}
