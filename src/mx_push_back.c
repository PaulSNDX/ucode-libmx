#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *back = mx_create_node(data);
    t_list *copy = *list;

    if (list == NULL || *list == NULL) *list = back;
    else {
        while (copy->next != NULL) copy = copy->next;
        
        copy->next = back;
    }
}
