# include <stdio.h>

 // 버블 정렬함수
 void sort(int *pary, int size) // 배열을 입력으로 전다할 때는 포인터형태로
 {

   for(int j=0; j<size-1; j++){
     for(int i=j; i<size-1; i++){
       if(pary[j]>pary[i+1])
       {
         int num = pary[j];
         pary[j] = pary[i+1];
         pary[i+1] = num;
       }
       else
         continue;
     }
   }
 }
 void main()
 {
   int ary[] =  {9, 4, 8, 15, 3, 7, 2, 1};
   int SIZE = sizeof(ary)/sizeof(ary[0]);

   //기존의 배열출력
   for(int i=0; i<8; i++)
     printf("%d ", ary[i]);
   printf("\n");

   // 정렬함수 호출
   sort(ary, SIZE);

   //정렬된 배열출력
   for(int i=0; i<sizeof(ary)/sizeof(ary[0]); i++)
       printf("%d ",ary[i]);
   printf("\n");

 }


