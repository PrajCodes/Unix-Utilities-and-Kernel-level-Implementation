#include "malloc2.h"
#include<stdio.h>
#include<stdlib.h>


int *tuple_addr[100]=NULL;
size_t tuple_len[100];

void *malloc2(size_t size)
{
	
	tuple_addr[0] = (int *)malloc(size);
	tuple_len[0] = size;
	if(size==0)
	{
		printf("\n Unusual, Size allocated by malloc is 0");
	}		
}

void free2(void *ptr)
{
	
	while(tuple_addr[i]!=NULL)
		{
			if(ptr!=tuple_addr[i])
			{
				printf("Error !! Trying to free a memory which is not been allocated by malloc2");	
			}
		i=i+tuple_len[0];
		}

	if(ptr!=tuple_addr[0])
	{
		printf("Error !! Trying to free a memory which is not first byte of range of memory allocated by malloc2");	
	}

	if(tuple_addr[1]==ptr)
	{
		printf("Memory has been already free'd or given ptr null");
	}


	tuple_addr[1] = ptr;
	free(tuple_addr[1]);
	
}

void *realloc2(void *ptr,size_t size)
{
	if(ptr==NULL)
	{
		malloc2(size);
	}
	if(size==0 && ptr==NULL)
	{
		free2(*ptr);
	}
	else
	{
		int *tmp;
		tmp= (int*) realloc(ptr, size);
		while(tuple_addr[i]!=NULL)
		{
			if(ptr==tuple_addr[i])
			{
				free(tuple_addr[i]);
				tuple_addr[i]=(int *)realloc(tmp, size);	
			}
		i=i+size;
		}
	}
}

void memcheck2(void *ptr, size_t size)
{
	if(tuple_addr[0]>ptr)
	{
		printf("Error! Out of Range ,ptr memory is out of the bounds of memory allocated by malloc2"); 
		return -1;
	}

	if(tuple_addr[1]!=NULL && tuple_addr[0]>ptr)
	{
		printf("ptr memory not allocated by malloc2 nad not freed by free2"); 
		return -1;
	}
}


