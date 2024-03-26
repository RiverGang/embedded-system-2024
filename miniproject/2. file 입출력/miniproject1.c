/*
File: miniproject1.c

Created: 24-03-22
Author: 이성희
*/

 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>

 #define SIZE 256
 int login(char*, char*);
 void openInfo();

 void main()
 {
   char inID[SIZE];
   char inPASS[SIZE];
   printf("<< 개인정보 열람 로그인창 >>\n\n");
   while(1){
     printf("아이디 입력 >> ");
     scanf("%s", inID);
     printf("비밀번호 입력 >> ");
     scanf("%s", inPASS);

     int num = login(inID, inPASS);

     switch(num){
       case 0:
         printf("\n회원 정보가 없습니다\n");
         break;

       case 1:
         openInfo();
         break;
         exit(1);

       case 2:
         printf("\n아이디가 틀렸습니다\n");
         break;

       case 3:
         printf("\n비밀번호가 틀렸습니다\n");
         break;
     }
     if(num==1)
       break;
   }
 }

 int login(char* inID, char* inPASS)
 {
   char ID[] = "201912186";
   char PASS[] = "비밀번호486";d

   if(strcmp(ID, inID) == 0 && strcmp(PASS, inPASS) == 0) return 1;
   if(strcmp(ID, inID) != 0 && strcmp(PASS, inPASS) == 0) return 2; //아이디 오류
   if(strcmp(ID, inID) == 0 && strcmp(PASS, inPASS)!= 0) return 3; // 비밀번호 오류
   else
     return 0;
 }

 void openInfo()
 {
   char infoCopy[SIZE];

   printf("\n[로그인 성공, 정보를 열람합니다]\n\n");
   FILE* openfile;
   openfile = fopen("myinfo.txt", "r");
   fgets(infoCopy, sizeof(infoCopy), openfile); // 전달받을 변수, 크기, 파일포인터

   printf("------ 개인 정보 -----\n%s\n", infoCopy);
   fclose(openfile);

 }


