#include<stdio.h>

int main() {
    char student_id[20];
    char name[50];

    printf("학번을 입력하세요: ");
    scanf("%s", student_id);

    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("학번: %s, 이름: %s\n", student_id, name);

    return 0;
}