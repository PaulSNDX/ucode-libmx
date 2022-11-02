#include "../inc/libmx.h"

// sorts an array of strings by their lengths in ascending order

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) return -1;

    int swaps = 0;

    if (left < right) {
        int leftwall = left;
        int rightwall = right;
        char *pivot = arr[(rightwall + leftwall) / 2];

        while (leftwall < rightwall) {

            while (mx_strlen(arr[leftwall]) < mx_strlen(pivot)) leftwall++;
            while (mx_strlen(arr[rightwall]) > mx_strlen(pivot)) rightwall--;

            if (mx_strlen(arr[leftwall]) != mx_strlen(arr[rightwall])) {
                mx_swap_str(&arr[leftwall], &arr[rightwall--]);
                swaps++;
            }
            leftwall++;
        }
        
        if (leftwall < left) swaps += mx_quicksort(arr, left, leftwall - 1);
        if (leftwall > left) swaps += mx_quicksort(arr, leftwall + 1, right);
    }
    return swaps;
}
