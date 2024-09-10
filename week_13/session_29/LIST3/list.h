#ifndef _LIST_H
#define _LIST_H

/* symbolic constants */

#define SUCCESS 1
#define LIST_DATA_INVALID 2
#define LIST_EMPTY 3
#define TRUE 1
#define FALSE 0

/* typedefs */

typedef struct node node_t;
typedef int data_t;
typedef node_t list_t;
typedef int len_t;
typedef unsigned int status_t;

struct node {
	int data;
	struct node* next;
	struct node* prev;
}

/* Interface funcitons declarations */

list_t* create_list(void);

status_t insert_start(list_t* p_list, data_t data);
status_t insert_end(list_t* p_list, data_t data);
status_t insert_before(list_t* p_list, data_t data);
status_t insert_after(list_t* p_list, data_t data);

status_t get_start(list_t* p_list, data_t* p_data);
status_t get_end(list_t* p_list, data_t* p_data);
status_t pop_start(list_t* p_list, data_t* p_data);
status_t pop_end(list_t* p_list, data_t* p_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

len_t get_length(list_t* p_list);
status_t is_list_empty(list_t* p_list);
status_t find(list_t* p_list);
void show_list(list_t* p_list, const char* msg);

status_t destroy_list(list_t* p_list);

/* List auxillary functions */
static void generic_insert(node_t* p_start, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);
static node_t* search_node(list_t* p_list, data_t data);
static node_t* get_node(data_t data);

/* General auxillary function declarations */

static void* xmalloc(size_t size_in_bytes);

#endif /* _LIST_H */

