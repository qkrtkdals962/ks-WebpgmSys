#include <stdio.h>
#include <sys/utsname.h>

int main(void) {
    struct utsname u;
    if (uname(&u) != 0) {
        perror("uname 실패");
        return 1;
    }
    printf("%s\n", u.sysname);
    return 0;
}
