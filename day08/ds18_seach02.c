// desc: 이진 탐색

 #include <stdio.h>

 void b_seach(int *ary, int size, int target)
 {
   int first = 0;
   int last = size;
   int middle = 0;

   while(first <= last){

     middle = (first+last)/2;

     if(target == ary[middle]){
       printf("%d은 ary[%d]에 있습니다\n", target, middle);
       break;
     }
     else{
       if(target > ary[middle]) first = middle+1;
       else last = middle-1; // target < ary[middle]
     }
   }
 }

void main()
 {
   int ary[] ={1, 2, 3, 4, 5, 6, 7, 8};
   int size = sizeof(ary)/sizeof(ary[0]); // 배열의 크기

   b_seach(ary, size, 3);

 }

