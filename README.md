#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char buff[128] ="a b c d e f 1 2 3";

char *s =strtok(buff," ");
printf("s =%s\n",s);
sleep(1);
while( (s = strtok(NULL," ")) !NULL)
{
	printf("s=%s\n",s);
	sleep(1);

}
