#include <cstdio>

float add(int, int);
int add(int, int);

int main(void)
{
	int i_result;
	float f_result;


	i_result = add(100, 200);
	f_result = add(100, 200);


	return 0;
}

int add(int a, int b){
	return a + b;
}

float add(int a, int b){
	return ((float)(a+b))/7.0;
}
