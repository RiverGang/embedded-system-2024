 #ifndef _HEADER_QUEUE03_H_
 #define _HEADER_QUEUE03_H_
 #include <stdio.h>
 #include <stdlib.h>

 typedef struct NODE{
   int data;
   struct NODE *link;
 }node;

 typedef struct {
   node* rear;
   node* front;
 }linkQ;

 #endif



