#include <cstdio>
#include <cstdlib>


const int gnum = 100;

void test(void);

int main(void){
	test();
	int* ptr = &gnum;
	*ptr = 50000;
	puts("END OF PROGRAM");
	return (0);
}
void test(void){
	const int local_num = 500;

	int* ptr = NULL;

	ptr = &local_num;

	printf("*ptr - %d\n", *ptr);
	*ptr = 6000;

	printf("*ptr = %d\n", *ptr);
	printf("local_num = %d\n", local_num);

}
