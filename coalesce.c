//Author: Michael Harrison
#include "my_malloc.h"

void *coalesce(void *mem){
	int len, alloc, i, x;

	//read current header
	head = (struct hdr*)&mem[0];
	len = head->len*8;
	alloc = head->allocated;
	//check next header
	head = (struct hdr*)&mem[len+2];
	x = head->len*8;
	alloc = head->allocated;
	//if not allocated coalesce, else set allocated to zero
	if (alloc == 0){
		len += x;
		set(&mem[0], len,0);
	}
	else{
		set(&mem[0], len,0);
	}
	//check previous header
	mem--;
	head = (struct hdr*)&mem[0];
	x = head->len*8;
	alloc = head->allocated;
	//if not allocated coalesce 
	if (alloc == 0){
		for (i=0;i<x+1;i++){mem--;}
		len += x;
		set(&mem[0], len,0);
	}
}











