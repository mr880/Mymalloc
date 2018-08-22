#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "mymalloc.h"
// #include "mymalloc.c"

/**********************************************************************************
***********************************************************************************

Your memgrind.c should run all the workloads, one after the other, 100 times. 
It should record the run time for each workload and store it. 
When all 100 iterations of all the workloads have been run, memgrind.c should 
calculate the mean time for each workload to execute and output them in sequence.

You might find the gettimeofday(struct timeval * tv, struct timezone * tz) function 
in the time.h library useful. You should run memgrind yourself and include its results 
in your readme.pdf. Be sure to discuss your findings, especially any interesting 
or unexpected results.

***********************************************************************************
***********************************************************************************/

static int x[5000]; 

int main(int argc, char** argv)
{
	
	

	// int * d = (int*)malloc(5);
	int * a;
	int byte = 1;
	int big = 3;

	for(int i = 0; i < 1000; i++)
	{
		a = (int*)malloc(byte);
		x[i] = a;
	}
	// printblock();

	for(int i = 999; i >= 0; i--)
	{
		int * b = x[i];
		free(b);
	}

	// for(int i = 0; i < 1000; i++)
	// {
	// 	a = (int*)malloc(byte);
	// 	free(a);
	// }
	// printblock();

	return 0;
}