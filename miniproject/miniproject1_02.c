/*
	로그인 기능 구현완료
*/
 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>

 #define SIZE 256
 int login(char*, char*);

 void main()
 {
   char inID[SIZE];
   char inPASS[SIZE];

   printf("아이디 입력 >> ");
   scanf("%s", inID);
   printf("비밀번호 입력 >> ");
   scanf("%s", inPASS);

   //printf("아이디:%s, 비밀번호:%s\n", inID, inPASS);

   int num = login(inID, inPASS);
   printf("%d\n", num);
 }


 int login(char* inID, char* inPASS)
 {
   char ID[] = "201912186";
   char PASS[] = "비밀번호486";

   if(strcmp(ID, inID) == 0 && strcmp(PASS, inPASS) == 0){
     printf("로그인 성공\n");
     return 1;
   }

   else
     return 0;
 }
