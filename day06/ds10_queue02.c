 /*
 desc: 연결 리스트를 이용한 큐(Queue) 자료구조
 */
 # include <stdio.h>
 # include <stdlib.h>

# define Q_SIZE 10

 typedef struct {
   int rear;
   int front;
   char arr[Q_SIZE];
 }queue;

 queue* create();
 void enqueue(queue*, char);
 char dequeue(queue*);
 void printQueue(queue*);

 void main()
 {
   create();
   queue* QueueA = create();
   enqueue(QueueA, 'A');
   enqueue(QueueA, 'F');
   printQueue(QueueA);
   dequeue(QueueA);
   printQueue(QueueA);
   enqueue(QueueA, 'D');
   printQueue(QueueA);
 }

// Queue 생성함수
   queue* create()
 {
   queue* newQueue = (queue*)malloc(sizeof(queue));
   newQueue->rear = -1;
   newQueue->front = -1;
   return newQueue;
 }

 // 데이터입력함수
 void enqueue(queue* inqueue, char data)
 {
   printf("enQueue()\n");
   if(inqueue->rear==Q_SIZE)
     printf("OverFlow!\n");

   inqueue->arr[++(inqueue->rear)] = data;
 }

 // 데이터 삭제함수
 char dequeue(queue* inqueue)
 {
   printf("deQueue()\n");
   if(inqueue->front == inqueue->rear)
     printf("UnderFlow!\n");

   return inqueue->arr[++(inqueue->front)];

 }

 // Queue 출력함수
 void printQueue (queue* inqueue)
 {
   int curr = inqueue->front;
   printf("현재 Queue의 데이터 => ");
   while(curr != inqueue->rear){
     printf("%c ", inqueue->arr[++curr]);
   }
   printf("\n");

 }
