#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: ./factor <양의정수>\n");
        return 1;
    }

    long n = atol(argv[1]);
    if (n <= 1) {
        fprintf(stderr, "2 이상의 정수를 입력하세요.\n");
        return 1;
    }

    printf("%ld = ", n);
    long orig = n;
    int first = 1;
    for (long p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            if (!first) printf(" * ");
            printf("%ld", p);
            first = 0;
            n /= p;
        }
    }
    if (n > 1) {
        if (!first) printf(" * ");
        printf("%ld", n);
    }
    printf("\n");
    return 0;
}
