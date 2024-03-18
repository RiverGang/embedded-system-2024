//desc: stack 자료구조 배열로 구현
 # include <stdio.h>

 # define STACK_SIZE 2

 // stack 배열 정의
 int stack[STACK_SIZE];
 int top = -1;

 // main 아래 함수가 정의되므로 미리 선언
 void push();
 int  pop();
 int isFull();
 int isEmpty();

 void main()
 {
   // 배열에 data를 넣음
   push(3);
   push(5);
   push(10);

   printf("%d\n",pop());
   printf("%d\n",pop());
   printf("%d\n",pop());

 }

 // data 추가
 void push(int data)
 {
   // overflow 예외처리
   if(isFull()) { //isFull()
     printf("stack overflow!\n");
     return;
     // return의 의미? => fail 상황 표기
   }
   stack[++top] = data; // data를 추가할 때 마다 증가하는 index top
 }

 int pop()
 {
   if(isEmpty()){
     printf("stack underflow!\n");
     return -1;
     // 함수의 출력형태가 int 이므로 -1 return
   }
   return stack[top--];
   // stack[top]을 빼내고 top index -1
 }

 int isFull()
 {
   if(top == STACK_SIZE - 1){
     return 1;
   }
   else
     return 0;
 }

 int isEmpty()
 {
   if(top <= -1) // 물리적인 변수에 의한 예외도 고려
     return 1;
   else
     return 0;
 }

