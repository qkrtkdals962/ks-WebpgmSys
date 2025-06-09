#include <stdio.h>
#include <sys/sysinfo.h>

int main(void) {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo 실패");
        return 1;
    }

    long total = info.totalram * info.mem_unit;
    long free_mem = info.freeram * info.mem_unit;
    long used = total - free_mem;

    printf("              total        used        free\n");
    printf("Mem:  %12lu %12lu %12lu\n", total, used, free_mem);
    return 0;
}
