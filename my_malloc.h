//Author: Michael Harrison
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef STUFF
#define STUFF
struct hdr {
  unsigned int len : 7;		/* we're using 7 bits for len */
  unsigned int allocated : 1;    /*  1 bit for allocated/free */
} *head;
extern char *heap;
#endif

#define BUFFSIZE 20

void InitMyMalloc();

void *my_malloc(size_t size);
void *search(size_t size, int alloc);
void set(char *mem, size_t size, int used);

void *my_free(void *mem);
void *coalesce(void *mem);
