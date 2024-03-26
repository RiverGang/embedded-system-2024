#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_ver3.h"

// 회원가입
void user_signup(){

  char inID[MAX], inPASS[MAX];
  char IDFile[MAX], PASSFile[MAX];

  printf("\n ----- 회원가입 -----\n");
  printf("아이디 입력 >> ");
  scanf("%s", inID);
  printf("비밀번호 입력 >> ");
  scanf("%s", inPASS);

  char CopyID[MAX], CopyPASS[MAX];
  strcpy(CopyID, inID);
  strcpy(CopyPASS, inID);
  strcpy(IDFile, strcat(CopyID, "ID.txt"));
  strcpy(PASSFile, strcat(CopyPASS, "PASS.txt"));

  FILE* fp;
  fp = fopen(IDFile, "w");
  fprintf(fp, "%s", inID);
  fclose(fp);

  fp = fopen(PASSFile, "w");
  fprintf(fp, "%s", inPASS);
  fclose(fp);

}

// 로그인
int login(){

  char inID[MAX], inPASS[MAX];
  char CopyID[MAX], CopyPASS[MAX];
  char IDFile[MAX], PASSFile[MAX];

  printf("\n----- 시스템 로그인 ----- \n\n");
  printf("아이디 >> ");
  scanf("%s", inID);
  printf("비밀번호 >> ");
  scanf("%s", inPASS);

  strcpy(CopyID, inID);
  strcpy(CopyPASS, inID);
  strcpy(IDFile, strcat(CopyID, "ID.txt"));
  strcpy(PASSFile, strcat(CopyPASS, "PASS.txt"));

  char IDInfo[MAX], PASSInfo[MAX];

  //FILE* fp;
  FILE* fp1;
  FILE* fp2;

  if((fp1 = fopen(IDFile, "r")) == NULL)
    fprintf(stderr, "[실패] 등록되지 않은 회원입니다\n");
  else
    fgets(IDInfo, sizeof(IDInfo), fp1);
  fclose(fp1);

  if((fp2 = fopen(PASSFile, "r")) == NULL)
    fprintf(stderr, "[실패] 등록되지 않은 회원입니다\n");
  else
    fgets(PASSInfo, sizeof(PASSInfo), fp2);
  fclose(fp2);


  if(strcmp(inID, IDInfo) == 0 && strcmp(inPASS, PASSInfo) == 0){
    printf("\n----- 로그인 성공 -----\n");
    return 0;
  }

  else{
    printf("\n[실패] 로그인 정보가 일치하지 않습니다\n");
    return 1;
  }
}

// 도서 등록(구매)
void book_add(node* pnode)
{
  printf("\n----- 도서 등록 -----\n\n");
  char* intitle = malloc(MAX * sizeof(char));
  char* inauthor = malloc(MAX* sizeof(char));
  char* inbrand = malloc(MAX* sizeof(char));
  char* inprice = malloc(MAX* sizeof(char));
  static int inindex = 0;
  printf("책 제목 입력 >> ");
  scanf("%s", intitle);
  printf("책 저자 입력 >> ");
  scanf("%s", inauthor);
  printf("책 출판사 입력 >> ");
  scanf("%s", inbrand);
  printf("책 가격 입력 >> ");
  scanf("%s", inprice);

  node* newNode = (node*)malloc(sizeof(node));
  newNode->title = intitle;
  newNode->author = inauthor;
  newNode->brand = inbrand;
  newNode->price = inprice;
  newNode->checkout = 0;
  newNode->index = ++inindex;
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
  char intitle[MAX];
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


}
// 도서 출력
void book_list(node* pnode)
{
  printf("\n----- 도서 목록 -----\n");
  node* curr;
  curr = pnode->next;

  char* book;
  while(curr !=NULL){
    printf("\n[책번호] %d\n", curr->index);
    printf("[도서명] %s\n", curr->title);
    printf("[저  자] %s\n", curr->author);
    printf("[출판사] %s\n", curr->brand);
    printf("[가  격] %s원\n", curr->price);

    if(curr->checkout == 0) book = "대출가능";
    else book = "대출중";
    printf("[상  태] %s\n", book);

    curr = curr->next;
  }
}

// 제목 검색
void seach_Title(node* pnode)
{
  printf("\n***** 제목 검색 *****\n");
  char intitle[MAX];
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
}

//저자 검색
void seach_Author(node* pnode)
{
  printf("\n***** 저자 검색 *****\n");
  char inauthor[MAX];
  printf("검색 도서 저자 입력 >> ");
  scanf("%s", inauthor);
  printf("\n");
  node* curr;
  curr = pnode->next;

  while(curr !=NULL){
    if(strcmp(curr->author, inauthor) == 0){
      printf("[책번호] %d\n[도서명] %s\n[저  자] %s\n",curr->index, curr->title, inauthor);
      if(curr->next != NULL) {
        curr = curr->next;
        continue;
      }
      else break;
    }
    if(curr->next == NULL){
      printf("저자 %s의 도서는 목록에 없습니다\n", inauthor);
      break;
    }
    else
      curr = curr->next;
  }
}

//출판사 검색
void seach_Brand(node* pnode)
{
  printf("\n**** 출판사 검색 ****\n");
  char inbrand[MAX];
  printf("검색 도서 출판사 입력 >> ");
  scanf("%s", inbrand);
  node* curr;
  curr = pnode->next;

  while(curr != NULL){
    if(strcmp(curr->brand, inbrand) == 0){
      printf("\n[책번호] %d\n[도서명] %s\n[출판사] %s\n",curr->index, curr->title, inbrand);
      if(curr->next != NULL) {
        curr = curr->next;
        continue;
      }
      else break;
    }
    if(curr->next == NULL){
      printf("출판사 %s의 도서는 목록에 없습니다\n", inbrand);
      break;
    }
    else
      curr = curr->next;
  }
}

// 책대여
void book_checkout(node* pnode)
{
  int inindex;
  node* curr;
  curr = pnode->next;
  int yesno;
  printf("\n[Yes(0) or No(1)] 도서를 대출 하시겠습니까? >> ");
  scanf("%d", &yesno);

  if(yesno == 0){
    printf("[대출] 책번호 입력 >> ");
    scanf("%d", &inindex);
    while(curr != NULL){
      if(curr->index == inindex){
        printf("\n[도서명] %s",curr->title);
        if(curr->checkout == 0){
          printf(" -----> 대출 완료\n");
          curr->checkout = 1;
        }
        else {
          printf(" -----> 대출 불가(현재 대출중)\n");
        }
        break;
      }
      else
        curr = curr->next;
    }
  }
  else return;
}

// 반납
void book_return(node* pnode)
{
  int inindex;
  node* curr;
  curr = pnode->next;
  printf("\n----- 도서 반납 -----\n");
  printf("\n[반납] 책번호 입력 >> ");
  scanf("%d", &inindex);
  while(curr != NULL){
    if(curr->index == inindex){
      if(curr->checkout == 1){
        printf("\n[도서명] %s -----> 반납 완료\n", curr->title);
        curr->checkout = 0;
      }
      else printf("도서 \"%s\"은(는) 이미 반납된 도서입니다\n", curr->title);
      break;
    }
    else curr = curr->next;
  }
}

// 메뉴 목록
void  menu()
{
  printf("\n***** 메뉴 *****\n");
  printf("1 도서구입(등록)\n2 도서검색\n3 도서삭제\n4 도서(목록)출력\n5 도서반납\n0 종료\n");
  printf("****************\n");
}

// 메뉴 선택
int menuSelect ()
{
  int num;
  printf("\n메뉴 선택 >> ");
  scanf("%d", &num);
  return num;
}

// 검색 키워드 선택
int seachSelect()
{
  int num;
  printf("\n----- 도서 검색 -----\n\n");
  printf("****** 검색 키워드 ******\n");
  printf("[1]제목 [2]저자 [3]출판사\n");
  printf("*************************\n");
  printf("키워드 선택 >> ");
  scanf("%d", &num);
  return num;
}