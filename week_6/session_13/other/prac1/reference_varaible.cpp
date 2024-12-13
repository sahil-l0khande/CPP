#include <cstdio>
#include <cstdlib>

void test(void)
{
	int m;

	int& n = m;

	int* p = (int*)malloc(sizeof(int));
	if(NULL == p) {
		puts("Error in allocating memory");
		exit(-1);
	}

	int& ref = *p;

	printf("Addr in p = %p\n", p);
	printf("addr of ref  = %p\n", &ref);
	
	*p = 500;
	printf("ref = %d\n", ref);

	*p = 600;
	printf("ref = %d\n", ref);

	free(&ref);
}

int main(void)
{
	test();
	return (0);
}
