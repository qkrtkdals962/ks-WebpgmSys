#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *s = (argc > 1) ? argv[1] : "y";
    while (1) {
        printf("%s\n", s);
    }
    return 0;
}
