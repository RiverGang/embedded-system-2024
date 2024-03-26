#ifndef _HEADER_VER3_H_
#define _HEADER_VER3_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 256

typedef struct NODE{
  int index;
  int checkout;
  char* title;
  char* author;
  char* brand;
  char* price;
  struct NODE* next;
}node;

#endif
