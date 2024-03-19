// desc: 연결구조(list)를 이용한 큐
 #include <stdio.h>
 #include <stdlib.h>

 typedef struct NODE {

   int data;
   struct NODE *link;
 }node;

 typedef struct {
   node* rear;
   node* front;
 }linkQ;

 // 함수 선언
 linkQ* create();
 void enQueue(linkQ*, int);
 void printQ(linkQ*);
 void deQueue(linkQ*);

 // main
 void main()
 {
   linkQ* QueueA = create();
   enQueue(QueueA, 10);
   enQueue(QueueA, 18);
   enQueue(QueueA, 30);
   enQueue(QueueA, 40);

   printQ(QueueA);

   deQueue(QueueA);
   printQ(QueueA);

   enQueue(QueueA, 50);
   printQ(QueueA);
 }

 // linkQ 생성
 linkQ* create()
 {
   linkQ* NewQueue = malloc(sizeof(linkQ));

   NewQueue->front = NULL;
   NewQueue->rear = NULL;

   return NewQueue;
 }

 void enQueue(linkQ* pqueue, int indata)
 {
   node* NewNode = malloc(sizeof(node));
   NewNode->data = indata;
   NewNode->link = NULL;

   if(pqueue->front  == NULL){
     pqueue->front = NewNode;
     pqueue->rear = NewNode;
   }

   else
   {
     pqueue->rear->link = NewNode;
     pqueue->rear = NewNode;
   }
 }

 // deQueue 함수
 void deQueue(linkQ* pqueue)
 {
   node* curr = pqueue->front;
   pqueue->front = pqueue->front->link;
   free(curr);
 }

// Queue 데이터 출력
 void printQ(linkQ* pqueue)
 {
   node* curr = pqueue->front;

   while(curr != NULL)
   {
     printf("%d ",curr->data);
     curr = curr->link;
   }
   printf("\n");
 }



