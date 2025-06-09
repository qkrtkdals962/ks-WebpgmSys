#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main(void) {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo 실패");
        return 1;
    }

    long total_seconds = info.uptime;
    int days = total_seconds / 86400;
    int hours = (total_seconds % 86400) / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    printf("up ");
    if (days > 0) printf("%d days, ", days);
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    return 0;
}
