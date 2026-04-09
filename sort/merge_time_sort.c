#include "../inc/ft_ls.h"

void merge_time(char* arr[], int l, int m, int r, int r_flag) {
    int n1 = m - l + 1;
    int n2 = r - m;
    struct stat right;
    struct stat left;

    char** L = malloc(n1 * sizeof(char*));
    char** R = malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
	lstat(R[j], &right);
	lstat(L[i], &left);
	if(r_flag) {
		if (right.st_mtime == left.st_mtime) {
			if(right.st_mtimespec.tv_nsec > left.st_mtimespec.tv_nsec) {
				arr[k] = L[i];
				i++;
			} else {
				arr[k] = R[j];
				j++;
			}
		} else {
			if(right.st_mtime > left.st_mtime) {
				arr[k] = L[i];
				i++;
			} else {
				arr[k] = R[j];
				j++;
			}
		}
		k++;
	} else {
		if (right.st_mtime == left.st_mtime) {
			if (right.st_mtimespec.tv_nsec == left.st_mtimespec.tv_nsec) {
				if(compare_strs_lowercase(L[i], R[j]) <= 0) {
					arr[k] = L[i];
					i++;
				} else {
					arr[k] = R[j];
					j++;
				}
			} else {
				if(right.st_mtimespec.tv_nsec < left.st_mtimespec.tv_nsec) {
					arr[k] = L[i];
					i++;
				} else {
					arr[k] = R[j];
					j++;
				}
			}
		} else {
			if(right.st_mtime < left.st_mtime) {
				arr[k] = L[i];
				i++;
			} else {
				arr[k] = R[j];
				j++;
			}
		}
		k++;
	}
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_time_sort(char* arr[], int l, int r, int r_flag) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_time_sort(arr, l, m, r_flag);
        merge_time_sort(arr, m + 1, r, r_flag);
        merge_time(arr, l, m, r, r_flag);
    }
}
