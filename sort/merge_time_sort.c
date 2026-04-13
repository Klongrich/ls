#include "../inc/ft_ls.h"

int	check_letter(t_merge_data data, int i, int j, char *arr[]) {
	if(compare_strs_lowercase(data.L[i], data.R[j]) <= 0) {
		arr[data.k] = data.L[i];
		return (1);
	}  else { 
		arr[data.k] = data.R[j];
		return(2);
	}
}

int	check_time_data(t_merge_data data, int i, int j, char *arr[]) {
	if (data.right.st_mtime == data.left.st_mtime) {
		if(data.right.st_mtimespec.tv_nsec == data.left.st_mtimespec.tv_nsec) {
			return check_letter(data, i, j, arr);
	 	} else {
			if (data.right.st_mtimespec.tv_nsec < data.left.st_mtimespec.tv_nsec) {
				arr[data.k] = data.L[i];
				return (1);
			} else { 
				arr[data.k] = data.R[j];
				return (2);
			}
		}
	} else {
		if (data.right.st_mtime < data.left.st_mtime) {
			arr[data.k] = data.L[i];
			return(1);
		} else { 
			arr[data.k] = data.R[j];
			return(2);
		}
	}
	return(0);
}

void	put_rest_n1(t_merge_data data, t_merge *merge, int i, char *arr[]) {
	while (i < merge->n1) 
		arr[data.k++] = data.L[i++];
}

void    put_rest_n2(t_merge_data data, t_merge *merge, int j, char *arr[]) {
	while (j < merge->n2)
		arr[data.k++] = data.R[j++];
}

void	merge_sides_t(char *arr[], char **L, char **R, t_merge *merge) {
	int i;
	int j;
	int res;
	t_merge_data data;

	i = 0;
	j = 0;
	data.L = L;
	data.R = R;
	data.k = merge->l;
	while (i < merge->n1 && j < merge->n2) {
		lstat(R[j], &data.right);
		lstat(L[i], &data.left);
		res = check_time_data(data, i, j, arr);
		if (res == 1)
			i++;
		else if (res == 2)
			j++;
		data.k++;
	}
	put_rest_n1(data, merge, i, arr);
	put_rest_n2(data, merge, j, arr);
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

void merge_time_sort(char* arr[], int l, int r, int r_flag) {
	t_merge merge;
	int m;

	init_t_merge_t(&merge);
	merge.m = l + (r - l) / 2;
	merge.l = l;
	merge.r = r;
	merge.r_flag = r_flag;
	m = l + (r - l) / 2;
	if (l < r) {
        	merge_time_sort(arr, l, m, r_flag);
        	merge_time_sort(arr, m + 1, r, r_flag);
        	merge_data_t(arr, &merge);
    	}
}
