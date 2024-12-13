#include <cstdio>

int main(void)
{
	int n = 10;
	int& ref = n;

	printf("&n = %llu, &ref = %llu\n",
			(unsigned long long) &n,
			(unsigned long long) &ref
	      );

	return (0);
}
