#include <cstdio>
#include <cstdlib>

#define N 100

int arr[N];
const int gunm = 100;

void test(void);

int main(void){
	test();
	return (0);
}

void test(void){
	const int local_num = 500;

	int *ptr = NULL;

	ptr = const_cast<int*>(&local_num);	//warnig 
		// type(local_num) == const int 
		// type(&local_num) == const int*
		// type(ptr) == int*

	printf("*ptr = %d\n", *ptr);	// 500
	*ptr = 6000;
	printf("*ptr = %d\n", *ptr);	// 6000
	printf("local_num = %d\n", local_num);	// 500
}
