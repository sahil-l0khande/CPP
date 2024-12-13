#include <cstdio>
#include <cstdlib>

void test(void) 
{
	int m;
	int& n = m;

	int *p = (int*)malloc(sizeof(int));
	if(p == NULL)
	{
		puts("Error malloc");
		exit(-1);
	}

	int& ref = *p;

	printf("addr in p = %p\n", p);
	printf("addr in ref = %p\n", &ref);

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
