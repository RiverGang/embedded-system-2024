// decs: 정렬 순차탐색
#include <stdio.h>

 int lSeach(int *ary, int size, int num)
 {
   for(int i=0; i<size; i++)
   {
     if(ary[i] == num) // 찾는 값이 배열에 존재할 시, 해당 값의 배열순서 리턴
       return i;

     else
       continue;
   }
   return -1; // num 값이 배열에 없으면 -1 리턴
 }


 void main()
 {
   int ary[] = {3, 5, 2, 4, 9, 8, 1};
   int size = sizeof(ary)/sizeof(ary[0]);
   int num;
   int ridx;

   printf("검색할 정수입력 >> ");
   scanf("%d", &num);

   ridx = lSeach(ary, size, num); // 입력 값: 배열, 크기, 찾을 값

   if(ridx == -1)
     printf("찾는 원소가 없습니다\n");
   else
     printf("%d는 arr[]배열의 %d번째 방에 있습니다\n", num, ridx+1);
 }

