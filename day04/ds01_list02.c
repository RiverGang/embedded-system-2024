 //desc: 연결리스트 출력

 1 // 연결리스트는 인덱스를 사용 못함
 2
 3 #include <stdio.h>
 4 #include <stdlib.h>
 5 typedef struct NODE{
 6   int data;
 7   struct NODE *next; 
 8 } node;
 9
10 void main()
11 {
12   // 헤드 노드 : 항상 첫번째 노드를 가리킨다
13   node * head = malloc(sizeof(node));
14   head->next = NULL; // 헤드는 데이터 필드와는 무관하다
15
16
17   // 첫번째 노드
18   node *node1 = (node*)malloc(sizeof(node)); // malloc(할당 받을 크기)
19   node1->data = 10;
20   node1->next = NULL;
21   head->next = node1; // 첫번째 노드 생성 후 헤드노드와 연결
22
23   // 두번째 노드
24   node *node2 = malloc(sizeof(node)); // heap 영역 동적할당은 주소 반환 => 따라서 type 일치를 위해 포인터 변수 사용
25   node2->data = 20;
26   node2->next = NULL;
27   node1->next = node2; // 첫번째 노드가 두번째 노드를 가리키는 형태로 연결
28
29   // 세번째 노드
30   node *node3 = malloc(sizeof(node));
31   node3->data = 30;
32   node3->next = NULL;
33   node2->next = node3;
34
35   // 순회 노드(이동시키는 형태)
36   node* curr = head->next; // 초기 설정은 첫번째 노드를 가리키도록, 항상 첫번째 노드를 가리키고 있는 헤드를 거쳐 가리키게 한다
37
38   while(curr != NULL){
39    // curr은 현재의 노드를 가리킴,  노드의 끝 = next 필드가 NULL 값인 노드
40
41     printf("%d\n", curr->data);
42     curr = curr->next;
43
44   }
45
46   // 메모리할당 해제
47   free(node1);
48   free(node2);
49   free(node3);
50 }

