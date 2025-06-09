#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH 4096

int main(void) {
    char cwd[MAX_PATH];
    if (!getcwd(cwd, sizeof(cwd))) {
        perror("getcwd 실패");
        return 1;
    }
    printf("%s\n", cwd);
    return 0;
}
