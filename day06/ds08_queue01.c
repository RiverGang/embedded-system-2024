//desc: 자료구조 queue 구현

 #include <stdio.h>

// 전역변수 선언
 #define Q_SIZE 10

 // 자유성을 위해 main이 아닌 전역으로 선언
 int queue[Q_SIZE];
 int front = -1;
 int rear = -1;


 // 데이터 입력 -> rear 증가
 void enqueue(int data)
 {
   if(rear >= Q_SIZE){
     printf("QUEUE OverFlow!\n");
     return;
   }
   queue[++rear] = data;
 }


 // 데이터 출력 -> front 증가
 int dequeue()
 {
   if(front == rear){
     printf("QUEUE UnderFlow!\n");
     return -1;
   }
   return queue[++front];
 }


 void main()
 {
   // 지역변수를 바깥에서 사용하려면 "주소"형태로 전달해야함
   enqueue(10);
   enqueue(20);
   enqueue(30);

   printf("%d\n", dequeue()); // 10
   printf("%d\n", dequeue()); // 20
   printf("%d\n", dequeue()); // 30
   printf("%d\n", dequeue()); // underflow 발생

 }
