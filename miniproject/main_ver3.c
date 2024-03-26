#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_ver3.h"


// 회원가입
extern void user_signup();
// 로그인
extern int login();

// 도서 등록(구매)
extern void book_add(node* pnode);

// 도서 삭제
extern void book_delete(node* pnode);

// 도서 출력
extern void book_list(node* pnode);

// 제목 검색
extern void seach_Title(node* pnode);

//저자 검색
extern void seach_Author(node* pnode);

//출판사 검색
extern void seach_Brand(node* pnode);
// 책대여
extern void book_checkout(node* pnode);

// 반납
extern void book_return(node* pnode);

// 메뉴 목록
extern void  menu();

// 메뉴 선택
extern int menuSelect ();

// 검색 키워드 선택
extern int seachSelect();

// main
void main()
{
  node * head = malloc(sizeof(node));
  head->next = NULL;
  printf("\n< 도서관리 프로그램 >\n");
  while(1){
    int choice;
    printf("\n[1]로그인 [2]회원가입 [0]종료\n메뉴선택 >> ");
    scanf("%d", &choice);
    switch(choice){
      case 1 :
        if(login() != 0) { continue;}
        else{
          menu();
          while(1){
            switch(menuSelect()){
              case 1 :
                book_add(head);
              break;

              case 2 :
                switch(seachSelect()){
                  case 1 ://제목검색
                    seach_Title(head);
                    book_checkout(head);
                    break;
                  case 2 ://저자검색
                    seach_Author(head);
                    book_checkout(head);
                    break;
                  case 3 ://출판사검색
                    seach_Brand(head);
                    book_checkout(head);
                    break;
                  default :
                    printf("\n[경고] 올바르지 않은 키워드 입니다\n");
                }
                break;

              case 3 :
                book_delete(head);
                break;

              case 4 :
                book_list(head);
                book_checkout(head);
                break;

              case 5 :
                book_return(head);
                break;

              case 0 :
                printf("프로그램이 종료됩니다\n");
                exit(1);
                break;

              default:
                printf("\n[경고] 올바른 메뉴(0~4)를 입력하세요\n");
                menu();
            }
            continue;
          } // while end
        } // if end
        break;

      case 2 :
        user_signup();
        break;

      case 0 :
        printf("프로그램이 종료됩니다\n");
        exit(1);
        break;

      default:
        printf("\n[경고] 올바른 메뉴(0~2)를 입력하세요\n");
      } //switch end
      continue;
  }//while end
} // main end

