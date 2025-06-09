#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int is_number(const char *s) {
    while (*s) {
        if (*s < '0' || *s > '9') return 0;
        s++;
    }
    return 1;
}

void print_proc_info(const char *pid) {
    char path[256], buf[256];
    FILE *fp;

    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    fp = fopen(path, "r");
    if (!fp) return;

    int pid_i;
    char comm[256], state;
    if (fscanf(fp, "%d %255s %c", &pid_i, comm, &state) == 3) {
        printf("%5d  %-20s  %c\n", pid_i, comm, state);
    }
    fclose(fp);
}

int main(void) {
    DIR *dp = opendir("/proc");
    if (!dp) {
        perror("opendir /proc 실패");
        return 1;
    }

    struct dirent *ent;
    printf("  PID  COMMAND              STATE\n");
    while ((ent = readdir(dp)) != NULL) {
        if (is_number(ent->d_name)) {
            print_proc_info(ent->d_name);
        }
    }
    closedir(dp);
    return 0;
}
