 #include <stdio.h>
 #include <stdlib.h>
 #include "header_queue03.h"


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

