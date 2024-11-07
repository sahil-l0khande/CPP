#include <cstdio>
#include <cstdlib>

const int gnum = 100;

void test(void);

int main(void){
	test();
	int* ptr= &gnum;
	*ptr = 50000;
	puts("END OF PROGRAM");
	return (0);
}

void test(void){
	const int local_num = 500;

	int *ptr = NULL;

	ptr = &local_num;//warnig 
		// type(local_num) == const int 
		// type(&local_num) == const int*
		// type(ptr) == int*

	printf("*ptr = %d\n", *ptr);	// 500
	*ptr = 6000;
	printf("*ptr = %d\n", *ptr);	// 6000
	printf("local_num = %d\n", local_num);	// 500
}
