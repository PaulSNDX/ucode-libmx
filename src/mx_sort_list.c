#include "../inc/libmx.h"

static void swap_data(void **a, void **b) {
    void *temp = a;
    *a = *b;
    *b = temp;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst != NULL && cmp != NULL) {
        t_list *copy1 = lst;

        while (copy1 != NULL) {
            t_list *copy2 = lst;

            while (copy2->next != NULL) {
                if (cmp(copy1->data, copy2->next->data))
                    swap_data(&copy1->data, &copy2->next->data);

                copy2 = copy2->next;
            }

            copy1 = copy1->next;
        }
    }
    return lst;
}
