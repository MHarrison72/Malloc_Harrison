//Author: Michael Harrison
#include "my_malloc.h"
char *heap;

int main(int argv, char **argc){
	char *abc;	
	int *num, len, alloc,i;	
	
	InitMyMalloc();

	printf("main\n");
	printHeap();

	if( (abc=my_malloc(5)) == NULL){printf("Unable to allocate suitable memory for array 'abc'.\n");}
	abc[0] = 'a'; abc[1] = 'b'; abc[2] = 'c'; abc[3] = 'd'; abc[4] = 'e';
	
	if( (num=my_malloc(2)) == NULL){printf("Unable to allocate suitable memory for array 'num'.\n");}
	num[0] = 2; num[1] = 7;

	printf("main\n");
	printHeap();

	my_free(num);

	printf("main\n");
	printHeap();
	
	my_free(abc);

	printf("main\n");
	printHeap();

	if( (abc=my_malloc(12)) == NULL){printf("Unable to allocate suitable memory for array 'abc'.\n");}
	abc[0] = 'a'; abc[1] = 'b'; abc[2] = 'c'; abc[3] = 'd'; abc[4] = 'e'; abc[5] = 'f';
	abc[6] = 'g'; abc[7] = 'h'; abc[8] = 'i'; abc[9] = 'j'; abc[10] = 'k'; abc[11] = 'l';
	
	printf("main\n");
	printHeap();

	return 0;
}
