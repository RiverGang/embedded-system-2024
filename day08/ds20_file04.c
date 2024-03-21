 /*
 파일 이름 : 이름.txt, data: 정보
 복사할 파일 이름: 이름copy.txt
 표준 파일 입출력함수 이용
 */

 #include <stdio.h>

 void main()
 {
   char myInfo[30] = "LEESUNGHEE,201912186";
   char myInfoCopy[30];

   //파일생성
   FILE* origen;
   origen = fopen("이성희.txt", "w");
   fprintf(origen, "%s", myInfo);
   
   
   // 원본파일 데이터 읽기   
   origen = fopen("이성희.txt", "r");
   fscanf(origen, "%s", myInfoCopy);
   fclose(origen);

   FILE* copy;
   copy = fopen("이성희copy.txt", "w");
   fprintf(copy, "%s", myInfoCopy);

   fclose(copy);
 }

