// desc: 후위 삽입 
#include <stdio.h>
 2 #include <stdlib.h>
 3
 4 typedef struct NODE{
 5   int data;
 6   struct NODE* next;
 7 }node;

20 // 후위 삽입
21 void rear_addNode(node* pnode, int indata)
22 {
23   node* newNode = (node*)malloc(sizeof(node));
24   newNode->data = indata;
25   newNode->next = NULL;
26
27   while(pnode->next != NULL){
28   // head의 next 필드가 가리키는 값이 NULL이 아니면 반복
29     pnode = pnode->next;
30     // head의 위치가 한칸씩 뒤로 이동
31     // head의 위치가 NULL 전에서 멈춤. while문 탈출
32   }
33
34   pnode->next = newNode;
35   // 기존의 맨 뒤 노드의 next 필드가  새로운 노드를 가리키는 형태 (연결)
36
37 }
38
39 // Node 출력함수
40 void showNode(node* pnode)
41 {
42   node * curr = (node*)malloc(sizeof(node));
43   curr = pnode->next; // curr 초기화
44   while(curr != NULL){
45     printf("%d\n", curr->data);
46     curr = curr->next;
47   }
48   free(curr);
49 }
50
51 void main()
52 {
53   // head 노드 생성
54   node * head = (node*)malloc(sizeof(node));
55   head->next = NULL;
56
57   // 노드 추가
58   rear_addNode(head, 10);
59   rear_addNode(head, 20);
60   rear_addNode(head, 30);
61   rear_addNode(head, 40);
62   rear_addNode(head, 50);
63
64   // 노드 출력
65   showNode(head);
66
67   /*curr = head->next;
68   while(curr != NULL){
69     printf("%d\n", curr->data);
70     curr = curr->next;
71   }*/
72
73 }

