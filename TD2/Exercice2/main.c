#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    // implement main here
    // create array example using malloc
    // use sorting algorithms and compare runtime
    int n=50;
    int *arr=malloc(n*sizeof(int));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);}
    
        
    quick_sort(arr, n);
    
    
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);}
    return 0;
}
