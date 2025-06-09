#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: ./tr <SRC_SET> <DEST_SET>\n");
        return 1;
    }

    char map[MAP_SIZE];
    memset(map, 0, sizeof(map));
    char *a = argv[1];
    char *b = argv[2];

    if (strlen(a) != strlen(b)) {
        fprintf(stderr, "문자 집합의 길이가 동일해야 합니다\n");
        return 1;
    }
    for (size_t i = 0; i < strlen(a); i++) {
        map[(unsigned char)a[i]] = b[i];
    }

    int ch;
    while ((ch = getchar()) != EOF) {
        if (map[ch]) putchar(map[ch]);
        else putchar(ch);
    }
    return 0;
}
