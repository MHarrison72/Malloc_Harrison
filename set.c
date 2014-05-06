//Author: Michael Harrison
#include "my_malloc.h"

void set(char *mem, size_t size, int used){
	int len, alloc;
	//read in current header info
	head = (struct hdr*)&mem[0];
	len = head->len*8;
	alloc = head->allocated;	
	//set header
	(*head).len = size/8;
	(*head).allocated = used;
	//set footer
	head = (struct hdr*)&mem[size+1];
	(*head).len = size/8;
	(*head).allocated = used;
	//fix excess memory
	if(len > size){
		alloc = len-(size);
		head = (struct hdr*)&mem[size+2];
		(*head).len = alloc/8;
		(*head).allocated = 0;
		head = (struct hdr*)&mem[len+3];
		(*head).len = alloc/8;
		(*head).allocated = 0;
	}
}
