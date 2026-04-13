#include "../inc/ft_ls.h"

void	check_time_data(t_merge_data data, int *i, int *j, char *arr[]) {
	if (data.right.st_mtime == data.left.st_mtime) {
		if(data.right.st_mtimespec.tv_nsec == data.left.st_mtimespec.tv_nsec) {
			if(compare_strs_lowercase(data.L[*i], data.R[*j]) <= 0) 
				arr[data.k] = data.L[*i++];
			 else 
				arr[data.k] = data.R[*j++];
	 	} else {
			if (data.right.st_mtimespec.tv_nsec < data.left.st_mtimespec.tv_nsec)
				arr[data.k] = data.L[*i++];
			else 
				arr[data.k] = data.R[*j++];
		}
	} else {
		if (data.right.st_mtime < data.left.st_mtime)
			arr[data.k] = data.L[*i++];
		else 
			arr[data.k] = data.R[*j++];
	}
}

void	merge_sides_t(char *arr[], char **L, char **R, t_merge *merge) {
	int i;
	int j;
	t_merge_data data;

	i = 0;
	j = 0;
	data.L = L;
	data.R = R;
	data.k = merge->l;
	while (i < merge->n1 && j < merge->n2) {
		lstat(R[j], &data.right);
		lstat(L[i], &data.left);
		check_time_data(data, &i, &j, arr);
		data.k++;
	}
	while (i < merge->n1) 
		arr[data.k++] = L[i++];
	while (j < merge->n2) 
		arr[data.k++] = R[j++];
	free(L);
	free(R);
}

void merge_data_t(char* arr[], t_merge *merge) {
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
	merge_sides_t(arr, L, R, merge);
}

void	init_t_merge_t(t_merge *merge) {
	merge->m = 0;
	merge->l = 0;
	merge->r = 0;
	merge->n1 = 0;
	merge->n2 = 0;
	merge->k = 0;
}

void merge_time2(char* arr[], int l, int r, int r_flag) {
	t_merge merge;
	int m;

	init_t_merge_t(&merge);
	merge.m = l + (r - l) / 2;
	merge.l = l;
	merge.r = r;
	merge.r_flag = r_flag;
	m = l + (r - l) / 2;
	if (l < r) {
        	merge_time2(arr, l, m, r_flag);
        	merge_time2(arr, m + 1, r, r_flag);
        	merge_data_t(arr, &merge);
    	}
}
