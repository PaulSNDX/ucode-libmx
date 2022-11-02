#include "../inc/libmx.h"

void mx_pop_front(t_list **list) {
    if (list != NULL && (*list) != NULL) {
        t_list *temp_node = NULL;

        if ((*list)->next == NULL) {
            free(*list);
            *list = NULL;
        } else {
            temp_node = (*list)->next;
            free(*list);
            *list = temp_node;
        }
    }
}
