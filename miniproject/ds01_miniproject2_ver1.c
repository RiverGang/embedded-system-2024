// miniproject 2
// 연결리스트 자료구조로 도서관리 프로그램 작성
// 메뉴기능 : 도서 등록, 검색, 삭제, 출력, 종료

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MAX_TITLE_LENGTH 256

 typedef struct NODE {
   char* title;
   struct NODE* next;
 }node;

 // 도서 등록(구매)
 void book_add(node* pnode)
 {
   printf("\n----- 도서 등록 -----\n\n");
   char *intitle = malloc(MAX_TITLE_LENGTH * sizeof(char));
   printf("책 제목 입력 >> ");
   //char intitle[MAX_TITLE_LENGTH];
   scanf("%s", intitle);
   node* newNode = (node*)malloc(sizeof(node));
   newNode->title = intitle;
   newNode->next = NULL;

   while(pnode->next !=NULL){
     pnode = pnode->next;
   }
   pnode->next = newNode;

 }
 

// 도서 삭제
 void book_delete(node* pnode)
 {
   printf("\n----- 도서 삭제 -----\n\n");
   char* intitle = malloc(MAX_TITLE_LENGTH*sizeof(char));
   printf("삭제 도서 제목 입력 >> ");
   scanf("%s", intitle);

   node* curr = pnode;
   node* temp = NULL;

   while(curr->next != NULL && strcmp(curr->next->title, intitle) != 0){
     curr = curr->next;
   }

   if(curr->next != NULL) {
     temp = curr->next;
     curr->next = temp->next;
     free(temp->title);
     free(temp);
     printf("%s 도서를 삭제했습니다\n", intitle);
   }

   else
     printf("도서를 찾을 수 없습니다\n");

   free(intitle);
 }

 //도서 출력
 void book_list(node* pnode)
 {
   printf("\n----- 도서 목록 -----\n\n");
   node* curr;
   curr = pnode->next;
   while(curr !=NULL){
     printf("%s\n", curr->title);
     curr = curr->next;
   }
 }

 //도서 검색
 void book_seach(node* pnode)
 {
   printf("\n----- 도서 검색 -----\n\n");
   char* intitle = malloc(MAX_TITLE_LENGTH * sizeof(char));
   printf("검색 도서 제목 입력 >> ");
   scanf("%s", intitle);
   node* curr;
   curr = pnode->next;
   while(curr !=NULL){

     if(strcmp(curr->title, intitle) == 0){
       printf("검색하신 도서 [%s]이(가) 있습니다\n", intitle);
       break;
     }
     if(curr->next == NULL){
       printf("도서 [%s]은(는) 목록에 없습니다\n", intitle);
       break;
     }
     else
       curr = curr->next;

   }
   free(intitle);
 }

 // 메뉴 목록
 void  menu()
 {
   printf("\n***** 메뉴 *****\n");
   printf("1 도서구입(등록)\n2 도서검색\n3 도서삭제\n4 도서(목록)출력\n0 종료\n");
   printf("****************\n");
 }

 // 메뉴 선택
 int menuSelect ()
 {
   int num;
   printf("메뉴 선택 >> ");
   scanf("%d", &num);
   return num;
 }

 // main
 void main()
 {
   node * head = (node*)malloc(sizeof(node));
   head->next = NULL;
   printf("\n< 도서관리 프로그램 >\n");

   menu();
   while(1){
     switch(menuSelect()){
       case 1 :
         book_add(head);
         break;

       case 2 :
         book_seach(head);
         break;

       case 3 :
         book_delete(head);
         break;

       case 4 :
         book_list(head);
         break;

       case 0 :
         printf("프로그램이 종료됩니다\n");
         exit(1);

       default:
         printf("\n[경고] 올바른 메뉴(0~4)를 입력하세요\n");
         menu();
     }
     continue;
   }
 }