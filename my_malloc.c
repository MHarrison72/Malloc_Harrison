//Author: Michael Harrison
#include "my_malloc.h"

void *my_malloc (size_t size){
	char *buff;
	if (size == 0){return NULL;}
	else if (size < 8) {size = 8;}
	else if (size%8 != 0){size += (size%8);}
	//search heap for next free section
	if((buff = search(size,0))==NULL){return NULL;}
	//set header and footer
	set(&buff[0],size,1);
	//return pointer to writable allocated memory
	return &buff[1];
}
