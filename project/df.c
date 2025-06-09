#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
    const char *path = (argc == 1) ? "/" : argv[1];
    struct statvfs st;
    if (statvfs(path, &st) != 0) {
        perror("statvfs 실패");
        return 1;
    }

    unsigned long total = st.f_blocks * st.f_frsize;
    unsigned long available = st.f_bavail * st.f_frsize;
    unsigned long used = total - (st.f_bfree * st.f_frsize);

    printf("Filesystem: %s\n", path);
    printf("  Total: %lu bytes\n", total);
    printf("  Used:  %lu bytes\n", used);
    printf("  Free:  %lu bytes\n", available);
    return 0;
}
