#include "../inc/libmx.h"

// sorts an array of strings by their lengths in ascending order

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    int counter = 0;

    if (left < right) {
        int k = left;
        int j = right;
        char *pivot = arr[(j + k) / 2];

        while (k <= j) {
            while (mx_strlen(arr[k]) < mx_strlen(pivot)) k++;
            while (mx_strlen(arr[j]) > mx_strlen(pivot)) j--;

            if (k <= j) {
                if (mx_strlen(arr[j]) != mx_strlen(arr[k])) {
                    char *temp = arr[k];
                    arr[k] = arr[j];
                    arr[j] = temp;
                    counter++;
                }
                j--;
                k++;
            }
        }

        counter += mx_quicksort(arr, left, j);
        counter += mx_quicksort(arr, k, right);
    }    
    return counter;
}

// work with mistakes in rare cases
// int mx_quicksort(char **arr, int left, int right) {
//     if (arr == NULL) return -1;

//     int swaps = 0;

//     if (left < right) {
//         int leftwall = left;
//         int rightwall = right;
//         char *pivot = arr[(rightwall + leftwall) / 2];

//         while (leftwall < rightwall) {
//             while (mx_strlen(arr[leftwall]) < mx_strlen(pivot)) leftwall++;
//             while (mx_strlen(arr[rightwall]) > mx_strlen(pivot)) rightwall--;

//             if (mx_strlen(arr[leftwall]) != mx_strlen(arr[rightwall])) {
//                 mx_swap_str(&arr[leftwall], &arr[rightwall--]);
//                 swaps++;
//             }
//             leftwall++;
//         }
        
//         if (leftwall < left) swaps += mx_quicksort(arr, left, leftwall - 1);
//         if (leftwall > left) swaps += mx_quicksort(arr, leftwall + 1, right);
//     }
//     return swaps;
// }
