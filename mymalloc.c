#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

static char myblock[5000];
int firstCall = 1;

struct indexnsize
{
	size_t size;
	int index;
};

void printblock(){

	for(int i = 0; i < 5000; i++)
	{
		printf("%c", myblock[i]);
	}

	printf("\n");
	return;
}

void addnewblock(int index, size_t size)
{
	int i = index;
	myblock[i] = '2';
	
	
	i++;
	while(size -1 > 0)
	{

		myblock[i] = '1';
		i++;
		size--;
	}

	printblock();
	printf("------------------------------------------------\n");

	return;
}

struct indexnsize getfreeblocks(int index)
{
	int i = index;

	struct indexnsize *ins = malloc(sizeof(*ins));

	char o = '0'; // open
	char c = '1'; // closed
	char p = '2'; // pointer

	int count = 0; 

	while(i < 5000)
	{

		if(myblock[i] == '0')
		{
			count = 1;
			// printf("Empty Block Found\n");
			// printf("Index: [%d]\n", i);
			ins->index = i;
			i++;
			while(myblock[i] != p)
			{
				i++;
				count++;
				if(i >= 5000)
					break;
			}
			
			//printf("Size of block: %d\n", count);
			ins->size = count;
			break;
		}
		else
			i++;
		//printf("%c", myblock[i]);
		
	}
	return *ins;
}

void* mymalloc(size_t size, char* file, size_t line)
{
	char o = '0';
	char c = '1';
	char p = '2';

	if(firstCall == 1){
		for(int i = 0; i < 5000; i++)
		{
			myblock[i] = '0';
		}
		firstCall = 0;
	}

				
	
	struct indexnsize ins = getfreeblocks(0);

	// printf("size: %zu\n", size);
	// printf("ins.index: %d\n", ins.index);
	// printf("ins.size: %zu\n", ins.size);

	if(size < ins.size)
		addnewblock(ins.index, size);

	int * ptr = &ins.index;
	
	return *ptr;
}

void myfree(void* ptr, char* file, size_t line)
{
	
	printf("Inside Free: %d\n", (int)ptr);
	
	// printf("Inside Free 2: %c\n", myblock[(int)ptr]);
	
	myblock[(int)ptr] = '0';
	ptr++;
	printf("Inside Free: %d\n", (int)ptr);
	while(myblock[(int)ptr] == '1')
	{

		myblock[(int)ptr] = '0';
		ptr++;
		//printf("yikes\n");
	}


	printblock();
	//exit(1);
	printf("------------------------------------------------\n");

	return;
}