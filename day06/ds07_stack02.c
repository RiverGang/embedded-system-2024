 // desc: 연결리스트로 stack 구현
 #include <stdio.h>
 #include <stdlib.h>

 #define STACK_SIZE 10

 typedef struct STACK {
   int buf[STACK_SIZE];
   int top;
 }stack;

 // push 함수
 void push(stack* pstack, int value)
 {

   pstack->buf[++(pstack->top)] = value; // pstack의 필드 top을 배열의 index로 사용
 }

 // pop 함수
 int pop(stack* pstack)
 {
   if(pstack->top == -1){

     printf("underflow\n");
     return 0;
   }
   else
     return pstack->buf[(pstack->top)--];
 }

 void main()
 {
  //stack 생성
  stack stackA;

  // top 초기화
  stackA.top = -1;

  push(&stackA, 30); //stackA 변수의 '주소'(&)를 입력으로 전달
  push(&stackA, 15);

  printf("%d\n", pop(&stackA));
  printf("%d\n", pop(&stackA));
  printf("%d\n", pop(&stackA));

 }
