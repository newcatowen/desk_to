#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main()
{
	printf("Hello ");
	sleep(5);//使进程睡眠5s
	printf("world!");


	//exit(0);
	_exit(0);
}
