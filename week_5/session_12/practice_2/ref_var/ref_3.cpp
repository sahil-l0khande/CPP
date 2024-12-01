#include <cstdio>

void swap(int& a, int& b)
{
	int tmp =0;
	tmp = a;
	a = b;
	b = tmp;
}

int main(void)
{
	int a = 10;
	int b = 20;

	swap(a, b);

	printf(" %d %d\n", a, b);

	return (0);
}
