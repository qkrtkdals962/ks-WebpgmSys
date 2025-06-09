#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: ./cmp <파일1> <파일2>\n");
        return 1;
    }

    FILE *f1 = fopen(argv[1], "rb");
    if (!f1) {
        perror(argv[1]);
        return 1;
    }
    FILE *f2 = fopen(argv[2], "rb");
    if (!f2) {
        perror(argv[2]);
        fclose(f1);
        return 1;
    }

    int c1, c2;
    size_t pos = 0;
    while (1) {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 == EOF || c2 == EOF) break;
        if (c1 != c2) {
            printf("차이 발생: 바이트 위치 %zu, %s=0x%02X, %s=0x%02X\n",
                   pos, argv[1], (unsigned char)c1, argv[2], (unsigned char)c2);
            fclose(f1);
            fclose(f2);
            return 0;
        }
        pos++;
    }

    if (c1 != c2) {
        printf("파일 길이 차이: %s와 %s 서로 길이가 다릅니다.\n", argv[1], argv[2]);
    } else {
        printf("두 파일이 동일합니다.\n");
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
