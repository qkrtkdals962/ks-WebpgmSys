#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(void) {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (!pw) {
        perror("getpwuid 실패");
        return 1;
    }
    printf("%s\n", pw->pw_name);
    return 0;
}
