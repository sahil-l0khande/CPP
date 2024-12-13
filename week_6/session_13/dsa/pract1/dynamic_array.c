#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alloc_use_free_array_of_ints(void);

int main(void){
	alloc_use_free_array_of_ints();
	return (0);
}

void alloc_use_free_array_of_ints(void){
	size_t N = 8;
	int * p_array = NULL;
	int current_element;
	size_t i;

	p_array = (int*)malloc(N * sizeof(int));
	if(p_array == NULL){
		fprintf(stderr, "Error in allocating mempry\n");
		exit(EXIT_FAILURE);
	}

	memset(p_array, 0, N * sizeof(int));

	for(i = 0; i<N;++i)
		p_array[i] = (i+1) * 100;

	for(i = 0; i < N; ++i){
		current_element = p_array[i];
		printf("Element at index : %lu : %d\n", i, p_array[i]);
	}

	free(p_array);
	p_array = NULL;
}
