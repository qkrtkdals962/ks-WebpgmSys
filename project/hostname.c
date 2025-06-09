#include <stdio.h>
#include <unistd.h>

#define MAX_NAME 256

int main(void) {
    char name[MAX_NAME];
    if (gethostname(name, sizeof(name)) != 0) {
        perror("gethostname 실패");
        return 1;
    }
    printf("%s\n", name);
    return 0;
}
