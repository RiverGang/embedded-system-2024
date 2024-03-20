/* 
desc: queue 자료구조 이해
입구 (rear)로 삽입하고, 출구(front)를 통해서 삭제한다
*/

 #include <stdio.h>

 void main()
 {
   int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int queue[20];
   int rear = 0, front = 0;

   int size = sizeof(ary) / sizeof(ary[0]);

   for(int i=0; i<size; i++){
     queue[rear++] = ary[i];
   }

   while(front != rear){
     printf("%d ",queue[front++]);
   }
   printf("\n");
 }

d