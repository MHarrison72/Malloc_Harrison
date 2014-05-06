//Author: Michael Harrison
#include "my_malloc.h"

void printHeap(){
	int i,len,alloc;
	char *p = &heap[0];
	//print bytes in hex
	for (i=0; i<24; i++, p++) {
    		if (i%8==0) {
      			printf("\n");
      			printf("%.8u", i);
    		}
    		printf(" %2u", *p);
 	}
	printf("\n----------------\n");

	//print header/footer data along w/ char value of array
	
	for(i=0;i<BUFFSIZE;i++){
		head = (struct hdr*)&heap[i];
		len = head->len*8;
		alloc = head->allocated;
		printf("heap[%d]: len = %d alloc = %d\n",i,len,alloc);
		len += i;
		for(i+=1;i<len+1;i++){
			printf("heap[%d]:%d\n",i,heap[i]);
		}
		head = (struct hdr*)&heap[i];
		len = head->len*8;
		alloc = head->allocated;
		printf("heap[%d]: len = %d alloc = %d\n",i,len,alloc);
	}
	printf("---------------------\n");
	
	
}

