//hash.c
#include "kvs.h"

int hash(const char *str) {
	char temp[100];
	int index;
	sscanf(str, "%[^0-9] %d",temp,&index);
	// printf("%d\n",index);
	return index;
}