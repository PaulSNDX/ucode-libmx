#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst != NULL && cmp != NULL) {
        t_list *copy1 = lst;

        while (copy1 != NULL) {
            t_list *copy2 = copy1;

            while (copy2->next != NULL) {
                if (cmp(copy1->data, copy2->next->data)) {
                    void *temp = copy1->data;
                    copy1->data = copy2->data;
                    copy2->data = temp;
                }
                copy2 = copy2->next;
            }
            copy1 = copy1->next;
        }
    }
    return lst;
}
