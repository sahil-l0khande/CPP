#include <stdio.h>
void test(void);

int main(void){
	test();
	test();
	return 0;
}

void test(void){
	int  m;
	static int n;

	printf("==%d==\n", n);

	n++;
}
