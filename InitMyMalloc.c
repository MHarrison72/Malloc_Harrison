//Author: Michael Harrison
#include "my_malloc.h"

void InitMyMalloc(){
	if ((heap = (char*)malloc(BUFFSIZE+1)) == NULL){
		printf("Unable to allocate heap.\n");
	}
	//clear array
	int i;
	for(i=0;i<BUFFSIZE+1;i++){heap[i] = 0;}
	
	set(&heap[0],BUFFSIZE-4,0);

	//set end of memory marker
	head = (struct hdr*)&heap[BUFFSIZE];
	(*head).len = 0;
	(*head).allocated = 1;
}

