#include <cstdio>
#include <cstdlib>

#define N 100

int arr[N];

const int gnum = 100;

void test(void);

int main(void){
	test();
	return (0);
}
void test(void){
	const int local_num = 500;

	int* ptr = NULL;

	ptr = const_cast<int*>(&local_num);

	printf("*ptr - %d\n", *ptr);
	*ptr = 6000;

	printf("*ptr = %d\n", *ptr);
	printf("local_num = %d\n", local_num);
}
