#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	char c = '5';
	int pc;
	pc = (int)c;
	pc = c - '0';
	printf("%d\n", pc);
	*/

	char *c = "1	2";
	char *e = "	22";
	char *d = "		-213";
	char *f = "2-13";
	int i = atoi(c);
	int j = atoi(e);
	int k = atoi(d);
	int l = atoi(f);
	printf("%d\n", i);
	printf("%d\n", j);
	printf("%d\n", k);
	printf("%d\n", l);

}