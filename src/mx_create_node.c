#include "../inc/libmx.h"

t_list *mx_create_node(void *data) {
    t_list *first_node = (t_list *)malloc(sizeof(t_list));
    first_node->data = data;
    first_node->next = NULL;
    return first_node;
}
