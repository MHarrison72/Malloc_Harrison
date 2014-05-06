//Author: Michael Harrison
#include "my_malloc.h"

void *my_free(void *mem){
	int len, alloc;

	//point to the header of the array
	mem--;
	//read header info
	head = (struct hdr*)&mem[0];
	len  = head->len;
	alloc = head->allocated;
	//make sure mem is allocated
	if (alloc == 0){printf("Trying to free unallocated memory.\n");}
	else{coalesce(&mem[0]);}
}
