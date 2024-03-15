// desc: 구조체(node)를 필드로 가진 구조체(headNode) 생성함수
 
#include <stdio.h>
#include <stdlib.h>

 typedef struct NODE{
   int data;
   struct NODE* next;
 }node;

 typedef struct {
  node *head;
 }headNode;

 headNode* createHeadNode(void)
 {
   headNode* Newhead = (headNode*)malloc(sizeof(headNode)); // headNode(9)행 구조체 동적할당
   Newhead->head = (node*)malloc(sizeof(node)); // headNode 구조체 내 필드인 node(4)행 구조체 동적
   Newhead->head->next = NULL;
     return Newhead;
 }

22 void pre_addNode(node* pnode, int indata)
 { ... }

void rear_addNode(node* pnode, int indata)
 { ... }

 void showNode(node* pnode)
 { ... }

void allFreeNode(node* pnode)
 { ... }


 void main()
 {
   // head 노드 생성
   headNode* Newhead =createHeadNode();
   // createHeadNode()함수를 받을 변수 설정


   // 노드 추가
   rear_addNode(Newhead->head, 10);
   rear_addNode(Newhead->head, 20);
   rear_addNode(Newhead->head, 30);

   // 노드 출력
   showNode(Newhead->head);

   // 노드 삭제
   allFreeNode(Newhead->head);
   showNode(Newhead->head);

   free(Newhead);
 }


