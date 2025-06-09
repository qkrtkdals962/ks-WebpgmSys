#include <stdio.h>
#include <stdlib.h>

long file_size(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp);
    rewind(fp);
    return sz;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc == 2) {
        fp = fopen(argv[1], "rb");
        if (!fp) {
            perror("파일 열기 실패");
            return 1;
        }
    } else if (argc > 2) {
        fprintf(stderr, "사용법: ./rev2 [파일]\n");
        return 1;
    }

    long sz = file_size(fp);
    unsigned char *buf = malloc(sz);
    if (!buf) {
        perror("메모리 할당 실패");
        if (fp != stdin) fclose(fp);
        return 1;
    }
    fread(buf, 1, sz, fp);
    for (long i = sz - 1; i >= 0; i--) {
        putchar(buf[i]);
    }
    free(buf);
    if (fp != stdin) fclose(fp);
    return 0;
}
