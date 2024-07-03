#include <cstdio>

void test(void){
	test();
	return (0);
}

void test(void){
	const int c_num = 100;
	int* ptr = const_cast<int*>(&c_num);

	printf("c_num = %d\n", *ptr);
	*ptr = 500;
	printf("c_num = %d\n", *ptr);
}
