#include <stdio.h>
#include <string.h>

#include "getLine.h"

#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2
#define DEBUG 0

void reverse(char x);

int main(void) {
	int rc;
	int buff_size = 10;
	char buff[buff_size];
	#ifdef DEBUG
	printf("\nString Len: %ld\n",sizeof(buff));
	#endif
	rc = getLine ("Enter String: ", buff, sizeof(buff));

	if (rc == NO_INPUT) {
		printf("\nNo Input\n");
		return 1;
	}

	if (rc == TOO_LONG) {
		printf("Input too long %s\n", buff);
		return 1;
	}
	reverse(*buff);
	printf("Reversed String: %s\n",buff);
	return 0;
}

void reverse(char x) {
	int itr = sizeof(x);

	#ifdef DEBUG
	printf("\nReverse input function: %d\n",x);
	printf("\nReverse string len: %d\n",itr);
	#endif
	/*
	for (int i = 0; i <= itr-1; i++) {
		#ifdef DEBUG
		printf("\n char: %c\n",(char) x[itr-i]);
		#endif
		rev_str[i] = (char) x[itr-i];
	}
	*/
}
