#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) 
            swap_int(&arr[i], &arr[min_index]);
    }
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        
        arr[j + 1] = key;
    }
}


void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) 
                swap_int(&arr[j],&arr[j+1]);
        }
    }
        
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    int left = l;
    int right = m + 1;
    int pos = l;

    while (left <= m && right <= r){
        if (arr[left] <= arr[right]){
            tmp[pos] = arr[left];
            left = left + 1;
        }
        else{
            tmp[pos] = arr[right];
            right = right + 1;
        }
        pos = pos + 1;
    }

    // Copie du reste de la partie gauche
    while (left <= m)
    {
        tmp[pos] = arr[left];
        left = left + 1;
        pos = pos + 1;
    }

    // Copie du reste de la partie droite
    while (right <= r)
    {
        tmp[pos] = arr[right];
        right = right + 1;
        pos = pos + 1;
    }

    copy_array(tmp + l, arr + l, r - l + 1);
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
    if (l >= r)
        return;

    int m = (l + r) / 2;

    mergesort_rec(arr, tmp, l, m);
    mergesort_rec(arr, tmp, m + 1, r);

    merge(arr, tmp, l, m, r);
}


void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}




int partition(int *arr, int l, int r)
{
    // partition function
    int pivot = arr[r];
    int i = l;          
    int j;
    int temp;

    for (j = l; j < r; j = j + 1){
        if (arr[j] < pivot){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = i + 1;
        }
    }

    temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i; 
}






void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
    if (l >= r)
        return;

    int pivot_index = partition(arr, l, r);

    // gauche du pivot
    quick_sort_rec(arr, l, pivot_index - 1);

    // droite du pivot
    quick_sort_rec(arr, pivot_index + 1, r);
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}
