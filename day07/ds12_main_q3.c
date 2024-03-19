 #include <stdio.h>
 #include <stdlib.h>
 #include "header_queue03.h"


 // 함수 선언
 extern linkQ* create();
 extern void enQueue(linkQ*, int);
 extern void printQ(linkQ*);
 extern void deQueue(linkQ*);

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
