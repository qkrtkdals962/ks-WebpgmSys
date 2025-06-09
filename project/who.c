#include <stdio.h>
#include <utmp.h>
#include <pwd.h>
#include <time.h>

int main(void) {
    struct utmp *ut;
    setutent();
    while ((ut = getutent()) != NULL) {
        if (ut->ut_type == USER_PROCESS) {
            char *name = ut->ut_user;
            time_t t = ut->ut_tv.tv_sec;
            struct tm *tm_info = localtime(&t);
            printf("%-8s %s\t%02d:%02d\n",
                   name, ut->ut_line,
                   tm_info->tm_hour, tm_info->tm_min);
        }
    }
    endutent();
    return 0;
}
