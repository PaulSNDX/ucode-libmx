#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *front = mx_create_node(data);
    t_list *copy = *list;
    *list = front;

    if (list != NULL || *list != NULL)
        front->next = copy;
}
