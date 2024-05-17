# embedded-system-2024
IoT 개발자 임베디드시스템 학습 리포지토리

## 미니프로젝트
- project1 : File 입출력


- project2 : linkedList(도서 관리 시스템)
	- 로그인, 회원가입

		![로그인/회원가입](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_01.png)

		![파일생성](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_10.png)

		![로그인성공여부](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_02.png)


		- 회원가입 시 파일 생성
		- 올바르지 않는 정보는 로그인 불가능
		
	- 기본 메뉴

		![기본 메뉴](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_03.png)

		![메뉴 외 선택](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_04.png)

	- 도서 등록(책번호, 제목, 저자, 출판사, 가격)

		![도서등록](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_05.png)
		
	- 검색(키워드: 제목, 저자, 출판사)

		![도서검색](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_06.png)

		![옵션검색](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_07.png)

		- 키워드 별 검색
		- 대여 기능
		
	- 목록 출력

		![목록출력](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_08.png)

	- 도서 삭제 (중간에 등록된 도서 삭제 가능)
	- 대여/반납
		
		![도서반납](https://raw.githubusercontent.com/RiverGang/embedded-system-2024/main/images/%EB%8F%84%EC%84%9C%EA%B4%80%EB%A6%AC%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_09.png)

	- 헤더/메인/함수 파일 분할
	- 컴파일 파일 생성

	

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
	- mv 파일명 파일명수정 : 원본파일을 수정파일명으로 변경

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
		
## 8일차
- 정렬, Sort
	- 오름차순 정렬
	- 정렬 순차 탐색
	- 이진 탐색
		- middle 값을 기준으로 앞뒤로 탐색
		- 오름차순 or 내림차순 정렬 필수
		
- TCP/IP 소켓
	- 리눅스환경 파일 입출력함수
	
	- 파일포인터: 표준 파일입출력함수
		- fopen("파일명", "모드")
			- "w" : fprintf(파일포인터, "%type", data);
			- "r" : fscanf(파일포인터, "%type", 변수);
			
## 9일차
- 리눅스환경 파일 입출력함수


## 11일차
- miniproject1 완성
- 대출기능까지 완성