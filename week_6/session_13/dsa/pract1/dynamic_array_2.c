#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate_ints(void);

int main(void)
{
	allocate_ints();

	return (0);
}

void allocate_ints(void)
{
	int N = 8;
	int i = 0;
	int current_element = 0;
	int* p_array = (int*)malloc(N*sizeof(int));
	if(p_array == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < N;++i)
		p_array[i] = (i+1) * 100;
	
	for(i = 0; i < N; ++i) {
		current_element = p_array[i];
		printf("Element at index : %d : %d\n", i, p_array[i]);
	}

	N = 5;
	puts("N is 5");

	p_array = (int*) realloc(p_array, N * sizeof(int));
	if(p_array == NULL) {
		puts("Error int allocating memory");
		exit(EXIT_FAILURE);
	}

	for(i=0;i<N;++i)
		printf("p_array[%d] : %d \n", i, p_array[i]);

	N = 10;

	puts("N is 10");
	p_array = (int*) realloc(p_array, N * sizeof(int));
        if(p_array == NULL) {
                puts("Error int allocating memory");
                exit(EXIT_FAILURE);
        }
	
	for(i = 0; i < N ; ++i)
        	printf("p_array[%d] : %d \n", i, p_array[i]);

	for(i = 7; i < N; ++i)
	{
		p_array[i] = i*1000;
	}

	for(i=0;i<N;++i)
                printf("p_array[%d] : %d \n", i, p_array[i]);

	free(p_array);
	p_array = NULL;
}	
