//Author: Michael Harrison
#include "my_malloc.h"

void *search(size_t size, int alloc){
	int i = 0;
	while (i != BUFFSIZE-1){
		head = (struct hdr*)&heap[i];
		if (head->len*8 >= size && head->allocated == alloc){
			return &heap[i];
		}
		i += (head->len*8+2);
	}
	return NULL;
}
