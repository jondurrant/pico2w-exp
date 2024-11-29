/*
 * myMemory.c
 *
 *  Created on: 7 Nov 2023
 *      Author: jondurrant
 */

#include <FreeRTOS.h>
#include <wolfssl/wolfcrypt/memory.h>





void *myMalloc(size_t n, void* heap, int type){
	//printf("myMalloc %d\n", n);
	HeapStats_t heapStats;
	vPortGetHeapStats(&heapStats);
	if (( heapStats.xAvailableHeapSpaceInBytes < (n *2))   || (heapStats.xAvailableHeapSpaceInBytes < 1000)){
		printf("myMalloc %d Heap %d\n", n, heapStats.xAvailableHeapSpaceInBytes);
	}
	return pvPortMalloc(n);
}

void myFree(void *p, void* heap, int type){
	vPortFree(p);
}
void *myRealloc(void *p, size_t n, void* heap, int type){
	vPortFree(p);
	return myMalloc(n, heap, type);
}
