# embedded-system-2024
IoT 개발자 임베디드시스템 학습 리포지토리

## 1일차
- 라즈베리파이 설정
- SD Card 초기화
- putty 사용
- 라즈베리파이 종료
	- exit : 창닫기
	- sudo shutdown -h now
	- 초록불 종료시 끄기

## 2일차
- Putty 기본 설정
- 리눅스 기초 명령어
	- pwd : 현재 나의 위치
	- ls : 디렉터리 목록
	- mkdir 폴더명 : 새로운 디렉터리 생성
	- rm fr - 폴더명 : 디렉터리 삭제
	- clear : 화면 초기화
	- cd 폴더명 : 하위 디렉터리로 이동
	- cd .. : 상위 디렉터리로 이동
	- cp 원파일명 복제파일명 : 파일 복제
	- mv 파일명 디렉토리명 : 파일을 디렉토리로 이동

## 3일차
- C언어 기초
	- %d(정수), %f(실수), %c(문자), %s(문자열)
	
	- 0: 8진수 키워드
		- printf("%d", 0123) => 8진수 123
	- 0x: 16진수 키워드
		- printf("%d", 0xACC) => 16진수 ACC
	
	- printf("%d", 'A'); => 대문자 A 아스키코드 65
	- printf("%d", 'a'); => 소문자 a 아스키코드 97
	
	- 입력: scanf("%입력 받을 형태", 변수의 주소(%));
	- 출력: printf();

## 4일차
- 연결리스트의 특징
	- 물리적으로 연결되어 있지 않으나, sw적으로 구현
	- head Node : 항상 첫번째 node를 가리킴

- 동적할당
	- #include <stdlib.h>
	- malloc(할당크기) : 메모리 할당
	- free() : 메모리 해제

- 전위/후위 리스트 구현
- node 삭제 구현
- node 출력 함수 구현

## 5일차
- 리눅스 명령어
	- cp 원본파일명 복사파일명
- 구조체를 필드로 가진 구조체 생성함수 구현


## 6일차
- 동적할당(heap영역 메모리 할당) 예외처리
	- if (newNode == NULL) : 할당받지 못할 때 return 될 값
	- if (newNode != NULL) : 할당을 받을 때 실행할 문장
- 연결리스트 검색함수

- Stack(LIFO:후입선출) 자료구조
	- 되돌리기/뒤로가기 기능의 기본 구조
	- push와 pop 함수
	- overflow와 underflow
	
	- 배열로 구현
	- 연결리스트(구조체)로 구현

- Queue(FIFO:선입선출) 자료구조
	- rear: 입구
	- front: 출구
	
	- front == rear -> overflow 상태
	

## 7일차
- 동적할당 Queue 구현
	- enQueue()
	- deQueue()
	- printQueue()
	
- makeT dir : 실행파일 만들기(makefile)
	- 실행파일 생성
	- gcc -o 실행파일명 .c 파일명
	
	- 오브젝트파일 생성
	- gcc -c .c 파일명
	- .c 파일로 object 파일 생성
	
	```
	exet: main.o inputf.o printf.o
		gcc -o love main.c inputf.c printf.h
 
	main.o: main.c
    	gcc -c main.c
 
	inputf.o: inputf.c
		gcc -c inputf.c

	printf.o: printf.h
		gcc -c printf.h
	
	```
	
- 파일분할
	- static : 전역변수 설정
	- extern 함수() 
	
	- 헤더파일 : 파일명.h
		```c
		#ifndef _헤더파일명_
		#define _헤더파일명_
		
		#endif
		```
	- main()과 function()
		- #include "헤더파일명.h"