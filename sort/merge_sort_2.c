#include "../inc/ft_ls.h"

void	merge_sides(char *arr[], char **L, char **R, t_merge *merge) {
	int i;
	int j;

	i = 0;
	j = 0;
	merge->k = merge->l;
	while (i < merge->n1 && j < merge->n2) {
		if ((!merge->r_flag && compare_strs_lowercase(L[i], R[j]) <= 0) ||
			(merge->r_flag && compare_strs_lowercase(L[i], R[j]) >= 0)) {
			arr[merge->k] = L[i];
			i++;
	 	} else {
			arr[merge->k] = R[j];
			j++;
		}
		merge->k++;
	}
	while (i < merge->n1) 
		arr[merge->k++] = L[i++];
	while (j < merge->n2) 
		arr[merge->k++] = R[j++];
	free(L);
	free(R);
}

void merge2(char* arr[], t_merge *merge) {
	int i;
	int j;
	char **L;
	char **R;

	i = 0;
	j = 0;
	merge->n1 = merge->m - merge->l + 1;
	merge->n2 = merge->r - merge->m;
	L = (char **)malloc(sizeof(char *) * merge->n1);
	R = (char **)malloc(sizeof(char *) * merge->n2);
	while (i < merge->n1) {
		L[i] = arr[merge->l + i];
		i++;
	}
	while (j < merge->n2) {
		R[j] = arr[merge->m + 1 + j];
		j++;
	}
	merge_sides(arr, L, R, merge);
}

void	init_t_merge(t_merge *merge) {
	merge->m = 0;
	merge->l = 0;
	merge->r = 0;
	merge->n1 = 0;
	merge->n2 = 0;
	merge->k = 0;
}

void merge_sort2(char* arr[], int l, int r, int r_flag) {
	t_merge merge;
	int m;

	init_t_merge(&merge);
	merge.m = l + (r - l) / 2;
	merge.l = l;
	merge.r = r;
	merge.r_flag = r_flag;
	m = l + (r - l) / 2;
	if (l < r) {
        	merge_sort2(arr, l, m, r_flag);
        	merge_sort2(arr, m + 1, r, r_flag);
        	merge2(arr, &merge);
    	}
}
