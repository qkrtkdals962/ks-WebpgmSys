#include <stdio.h>

void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int countOnes(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void printUpper4Bits(int n) {
    for (int i = 3; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    int num;

    printf("0~255 사이의 정수를 입력하세요: ");
    scanf("%d", &num);

    if (num < 0 || num > 255) {
        printf("입력 값이 범위를 벗어났습니다. 0~255 사이의 숫자를 입력해주세요.\n");
        return 1;
    }

    printf("2진수: ");
    printBinary(num);
    printf("\n");

    int onesCount = countOnes(num);
    printf("1의 개수: %d\n", onesCount);

    printf("상위 4비트: ");
    int upper4Bits = (num >> 4) & 0x0F;
    printUpper4Bits(upper4Bits);
    printf("\n");

    return 0;
}
