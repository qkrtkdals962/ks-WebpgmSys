#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 16

void print_hex(const unsigned char *buf, size_t n, size_t base_offset) {
    for (size_t i = 0; i < n; i++) {
        if (i % 8 == 0) {
            printf("%08zx:  ", base_offset + i);
        }
        printf("%02x ", buf[i]);
        if ((i + 1) % 8 == 0) printf("\n");
    }
    if (n % 8 != 0) printf("\n");
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
        fprintf(stderr, "사용법: ./od2 [파일]\n");
        return 1;
    }

    unsigned char buf[BUF_SIZE];
    size_t n;
    size_t offset = 0;
    while ((n = fread(buf, 1, BUF_SIZE, fp)) > 0) {
        print_hex(buf, n, offset);
        offset += n;
    }

    if (fp != stdin) fclose(fp);
    return 0;
}
