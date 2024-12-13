#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alloc_ints(void);

int main(void)
{
	alloc_ints();

	return (0);
}

void alloc_ints(void)
{
	int N = 8;
	int i = 0;
	int current_element = 0;
	int* p_array = (int*)malloc(N*sizeof(int));
	if(p_array  == NULL)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < N; ++i)
		p_array[i] = (i + 1) * 100;

	for(i = 0; i < N; ++i)
		printf("Element at index %d is %d\n", i , p_array[i]);

	N = 5;

	puts("N is now 5");

	p_array = (int*)realloc(p_array, N * sizeof(int));
	if(p_array == NULL)
	{
		fprintf(stderr, "Error allocating mem\n");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < N ; ++i)
		printf("Element at index %d is %d\n", i , p_array[i]);
	
	N = 10;

	puts("N is now 10");

	p_array = (int*)realloc(p_array, N * sizeof(int));
	if(p_array == NULL)
	{
		fprintf(stderr, "Error allocating mem\n");
		exit(EXIT_FAILURE);
	}

	for(;i<N;++i)
		p_array[i] = (i+1)*100;

	for(i = 0; i < N ; ++i)
		printf("Element at index %d is %d\n", i , p_array[i]);

	free(p_array);
	p_array = NULL;
}
