#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int len = 0;
    t_list *temp = list;
    
    while (temp != NULL) {
        temp = temp->next;
        len++; 
    }

    return len;
}
