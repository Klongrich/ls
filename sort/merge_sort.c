#include "../inc/ft_ls.h"

void merge(char* arr[], int l, int m, int r) {
	int n1;
	int n2;
	int i;
	int j;
	int k;
	char **L;
	char **R;

	n1 = m - l + 1;
	n2 = r - m;
	
	L = (char **) malloc(sizeof(char *) * n1);
	R = (char **)malloc(sizeof(char * )  * n2);
	
	i = 0;
	j = 0;
	while (i < n1) {
		L[i] = arr[l + i];
		i++;
	}
	
	while (j < n2) {
		R[j] = arr[m + 1 + j];
		j++;
	}

	i = 0;
	j = 0;
	k = 0;
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

	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];

/*
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
*/
    free(L);
    free(R);
}

void merge_sort(char **arr, int l, int r) {
	int m;

	if (l < r) {
     		m = l + (r - l) / 2;
        	merge_sort(arr, l, m);
        	merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
    	}
}
