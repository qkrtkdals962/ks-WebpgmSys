#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sig = SIGTERM;
    int idx = 1;

    if (argc < 2) {
        fprintf(stderr, "사용법: ./kill [-<신호번호>] <PID>\n");
        return 1;
    }

    if (argv[1][0] == '-') {
        sig = atoi(argv[1] + 1);
        idx = 2;
    }

    if (idx >= argc) {
        fprintf(stderr, "사용법: ./kill [-<신호번호>] <PID>\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[idx]);
    if (kill(pid, sig) != 0) {
        perror("kill 실패");
        return 1;
    }
    return 0;
}
