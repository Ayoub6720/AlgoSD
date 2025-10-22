#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    FILE *f_in = fopen("data.txt", "r");
    

    int n = 100000; 
    int *arr = malloc(n * sizeof(int));
    int *arr2 = malloc(n * sizeof(int));
    int *arr3 = malloc(n * sizeof(int));
    int *arr4 = malloc(n * sizeof(int));
    int *arr5 = malloc(n * sizeof(int));

    // Lecture des nombres
    int count = 0;
    while (count < n && fscanf(f_in, "%d", &arr[count]) == 1) {
        count++;
    }
    fclose(f_in);

    copy_array(arr,arr2,n);
    copy_array(arr,arr3,n);
    copy_array(arr,arr4,n);
    copy_array(arr,arr5,n);


    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quick_sort(arr, count);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps de quick sort : %.6f secondes\n", cpu_time_used);

    start = clock();
    merge_sort(arr2, count);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps de merge sort : %.6f secondes\n", cpu_time_used);

    start = clock();
    bubble_sort(arr3, count);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps de bubble sort : %.6f secondes\n", cpu_time_used);
    
    start = clock();
    insertion_sort(arr4, count);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps de insertition sort : %.6f secondes\n", cpu_time_used);

    start = clock();
    selection_sort(arr5, count);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps de selection sort : %.6f secondes\n", cpu_time_used);

    // Écriture dans data_out.txt
    FILE *f_out = fopen("data_out.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(f_out, "%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < count; i++) {
        fprintf(f_out, "%d ", arr2[i]);
    }
    printf("\n");
    for (int i = 0; i < count; i++) {
        fprintf(f_out, "%d ", arr3[i]);
    }
    printf("\n");
    for (int i = 0; i < count; i++) {
        fprintf(f_out, "%d ", arr4[i]);
    }
    printf("\n");
    for (int i = 0; i < count; i++) {
        fprintf(f_out, "%d ", arr5[i]);
    }

    fclose(f_out);
    free(arr);

    return 0;
}