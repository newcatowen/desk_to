#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <assert.h>

#include<signal.h>

void fun(int sign)
{
	printf("hello world:%d\n",sign);
}

int main()
{
	signal(SIGINT,fun);//signal 仅仅完成信号相应方式的修改
	while(1)
	{
		sleep(5);
		printf("i am main,running\n");
	}
}
