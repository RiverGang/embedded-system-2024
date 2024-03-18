// desc: Node 검색 함수
 
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
 { ... }

void pre_addNode(node* pnode, int indata)
 { ... }

void rear_addNode(node* pnode, int indata)
 { ... }

 void showNode(node* pnode)
 { ... }

 // Node 검색함수
 void seachNode(headNode* pnode, int indata)
 {
   node * curr = (node*)malloc(sizeof(node));
   curr = pnode->head->next;
   int i = 0;
   while(curr != NULL){
     if(curr->data != indata){
       curr = curr->next;
       i++;
     }
     else if(curr->data = indata){
       printf("%d번째 노드의 값이 %d 입니다\n", i,curr->data);
       break;
     }
   }
   free(curr);
 }

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
