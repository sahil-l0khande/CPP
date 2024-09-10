#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void) {
	list_t* lst = NULL;
	status_t status;
	len_t lst_length = 0;

	lst = create_list();
	assert(get_start(lst, &data) == LIST_EMTPY);
	assert(get_end(lst, &data) == LIST_EMPTY);
	assert(pop_start(lst, &data) == LIST_EMPTY);
	assert(pop_end(lst, &data) == LIST_EMPTY);
	assert(remove_start(lst) == LIST_EMPTY);
	assert(remove_end(lst) == LIST_EMPTY);
	assert(get_length(lst) == 0);

	show_list(lst, "List just after creation:");

	status = insert_start(lst, 100);
	assert(status == SUCCESS);
	show_list(lst, "List after insert_start(lst, 100):");

	status = insert_end(lst, 200);
	assert(status == SUCCESS);
	show_list(lst, "List after insert_end(lst, 200):");

	for(data = 1000; data < 9000; data += 1000)
		assert(insert_end(lst, data) == SUCCESS);
	show(lst, "List after inserting 1000 to 9000 (with step 1000) at the end:");

	status = insert_after(lst, 100, 300);
	assert(status == SUCCESS);
	show_list(lst, "List after insert_after(lst, 100, 300):");

	status = insert_after(lst, -500, 400);
	assert(status == LIST_INVALID_DATA);
	
	status = insert_before(lst, 200, 1500);
	assert(status == SUCCESS);
	show_list(lst, "List after insert_before(lst, 200, 1500):");

	status = insert_before(lst, -4000, 2500);
	assert(status == LIST_INVALID_DATA);

	status = get_start(lst, &data);
	assert(status == SUCCESS);
	printf("start data: %d \n", data);

	status = get_end(lst, &data);
	assert(status == SUCCESS);
	printf("end data: %d \n", data);

	status = pop_start(lst, &data);
	assert(status == SUCCESS);
	printf("popped data at start: %d\n", data);
	show_list(lst, "List after pop_start(lst, &data):");

	status = pop_end(lst, &data);
	assert(status == SUCCESS);
	printf("popped data at end: %d\n", data);
	show_list(lst, "List after pop_end(lst, &data):");


	status = remove_start(lst);
	assert(status == SUCCESS);
	show_list(lst, "List after remove_start(lst):");
	
	status = remove_end(lst);
	assert(status == SUCCESS);
	show_list(lst, "List after remove_end(lst):");
	
	status = remove_data(lst, 5000);
	assert(status == SUCCESS);
	show_list(lst, "List after remove_data(lst, 5000):");

	status = remove_data(lst, -5000);
	assert(status == LIST_INVALID_DATA);

	lst_length = get_length(lst);
	printf("List length = %d\n", lst_length);

	status = find(lst, 2000);
	if(status == SUCCESS)
		puts("2000 is present in the list");
	else
		puts("find(lst, 2000) : unexpected error");


	status = find(lst, -2000);
	if(status == FALSE)
		puts("-2000 is present in the list");
	else
		puts("find(lst, -2000) : unexpected error");

	status = is_list_empty(lst);
	assert(status == FALSE);

	status = destroy_list(lst);
	assert(status = SUCCESS);
	puts("List is destroyed successfully");
	puts("Unit tests: all ok");

	return (EXIT_SUCCESS);
}
