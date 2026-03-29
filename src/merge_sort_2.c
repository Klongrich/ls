#include "../inc/ft_ls.h"

void merge2(char* arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char** L = malloc(n1 * sizeof(char*));
    char** R = malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (compare_strs_lowercase(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort2(char* arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort2(arr, l, m);
        merge_sort2(arr, m + 1, r);
        merge2(arr, l, m, r);
    }
}
