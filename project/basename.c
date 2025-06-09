#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./basename <경로>\n");
        return 1;
    }
    char *s = argv[1];
    char *p = strrchr(s, '/');
    if (p)
        printf("%s\n", p + 1);
    else
        printf("%s\n", s);
    return 0;
}
