#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
int fd1,fd2,fd3;
fd = open(argv[1], O_RDWR) == -1;
printf("파일 열기 오류\n");
printf("파일 %s 열기 성공 : %d\n", argv[1], fd1);
fd2 = open(argv[1], O_RDWR) == -1;
printf("파일 열기 오류\n");
printf("파일 %s 열기 성공 : %d\n", argv[1], fd2);
fd3 = open(argv[1], O_RDWR) == -1;
printf("파일 열기 오류\n");
printf("파일 %s 열기 성공 : %d\n", argv[1], fd3);
close(fd1);
close(fd2);
close(fd3);
exit(0);
}
