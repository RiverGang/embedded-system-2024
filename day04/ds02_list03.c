 #include <stdio.h>
 2 #include <stdlib.h>
 3
 4 typedef struct NODE{
 5   int data;
 6   struct NODE* next;
 7 }node;
 8
 9
10 void addNode(node* pnode, int indata)
11 {
12   node* newNode = (node*)malloc(sizeof(node));
13   newNode->data = indata;
14   newNode->next = pnode->next; // 이전 노드가 맨 마지막 노드 => 새로운 노드가 맨 뒤로 오니 NULL 값이 오도록
15   pnode->next = newNode; // 기존의 노드(pnode)의 next가 새로운 노드(newNode)를 가리키도록
16
17 }
18
19
20 void main()
21 {
22   // head 노드 생성
23   node * head = (node*)malloc(sizeof(node));
24   head->next = NULL;
25
26   // 노드 추가
27   addNode(head, 10); // head 다음에 위치할 노드 생성 (첫번째 노드 추가)
28   addNode(head, 20); // 새롭게 생성되는 노드가 첫번째로 삽입되는 형태
29   addNode(head, 30);
30   addNode(head, 40);
31   addNode(head, 50);
32
33   // 순회 노드
34   node* curr = head->next;
35
36   while(curr != NULL){
37     printf("%d\n", curr->data);
38     curr = curr->next;
39   }
40
41   curr = head->next; // curr 초기화
42
43   printf("---- 노드 삭제  ----\n");
44   while(curr !=NULL){
45     curr=curr->next; // 첫번째 노드의 다음 노드를 가리키도록
46     free(head->next); // head가 가리키는 첫번째 노드 삭제
47     head->next = curr; // 삭제된 노드 다음 노드를 head가 가리키도록
48   }
49
50   //  curr=curr->next;
51   //  free(head->next);
52   //  head->next = curr;
53
54
55   curr = head->next;
56   while(curr !=NULL){
57     printf("%d\n", curr->data);
58     curr = curr->next;
59   }
60
61   free(head);
62 }
