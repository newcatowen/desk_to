#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
struct employee
{
	char name[20];
	char sex;
	char tel[11];
	char site[50];
	char card[18];
};

struck Stack
{
	int top =-1;
	employee recode[40];

};

void add(stack *s)
{
	s->top++;
	printf("place enter name:");
	scanf("%s",s->recode[s->top].mane,20);
	printf("place enter sex:");
	getchar();
	scanf("%s",s->recode[s->top].sex);
	printf("place enter phone card:");
	scanf("%ss",s->recode[s->top].tel,11);
	printf("place enter addres");
	scanf("%s",s->recode[s->top].site,50);
	printf("place enter ID card NO:");
	scanf("%s",s->recode[s->top].card,18);

}
void del();
void alter();
void find();


int main()
{
	Stack stack;
	add(&stack);
	return 0;
	

} 
