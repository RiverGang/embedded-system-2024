// desc: 생성한 파일 data.txt에 저장된 데이터를 read 함수를 이용해 읽기
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <unistd.h>
 #define BUF_SIZE 100
 void error_handling(char* message);

 int main(void)
 {
   int fd;
   char buf[BUF_SIZE];

   fd=open("data.txt", O_RDONLY); // 읽기 전용으로 파일 열기

   // 예외처리(리눅스에서 -1은 실패)
   if(fd == -1)
     error_handling("open() error!");
   printf("file descriptor: %d \n", fd);

   if(read(fd, buf, sizeof(buf))==-1) // read 함수이용, 11행에 선언된 buf에 읽어 들인 데이터 저장
     error_handling("read() error!");

   printf("file data: %s", buf); // buf 출력

   close(fd);
   return 0;
 }

