#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void VectorNew(vector *v, int elemSize, VectorFreeFunction freeFn, int initialAllocation){
	v->elems = malloc(elemSize *initialAllocation);
	assert(v->elems != NULL && "There is no available memory"); //Si no se cumple hasta ahi llega el programa
	v->elemSize = elemSize;
	v->initialSize = initialAllocation;
	v->currentPosition = 0;
	v->freeFn = freeFn;
}
//freeFn destruir memoria
void VectorDispose(vector *v){
	if(v->freeFn != NULL){
		int i;
		void *elemAddress;
		elemAddress = v->elems
		for(i=0; i<currentPosition; i++){
			elemAddress = (char *)(v->elems)+i*v->elemSize;
			v->freeFn(elemAddress);
		}
	}
	free(v->elems);
}

int VectorLength(const vector *v){ 
	return v->currentPosition;
}

void *VectorNth(const vector *v, int position){ 
	assert(position < v->currentPosition && "No valid position");
	return (char *)(v->elems)+position*v->elemSize;
}

void VectorReplace(vector *v, const void *elemAddr, int position){
	void *elemdir;
	assert(position < v->currentPosition && "No valid position");
	elemdir = (char *)v->elems+position*v->elemSize;
	memcpy(elemdir, elemAddr, v->elemSize);
}

void VectorInsert(vector *v, const void *elemAddr, int position){
	if(v->currentPosition == v->initialSize){
		v->initialSize *= 2;
		v->elems = realloc(v->elems, v->initialSize*v->elemSize);
		asssert(v->elems != NULL, && "There is no available memory");
	}
	elemdir = (char *)v->elems+v->currentPosition*v->elemSize;
	memcpy(elemdir, elemAddr, v->elemSize);
	v->currentPosition +=1;
}

void VectorAppend(vector *v, const void *elemAddr)
{}

void VectorDelete(vector *v, int position)
{}

void VectorSort(vector *v, VectorCompareFunction compare)
{}

void VectorMap(vector *v, VectorMapFunction mapFn, void *auxData)
{}

static const int kNotFound = -1;
int VectorSearch(const vector *v, const void *key, VectorCompareFunction searchFn, int startIndex, bool isSorted)
{ return -1; } 
