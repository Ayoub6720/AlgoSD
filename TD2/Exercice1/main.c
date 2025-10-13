#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    
    int arr1[] = {1, 2, 3, 4, 5};           // trié
    int arr2[] = {5, 4, 3, 2, 1};           // décroissant
    int arr3[] = {2, 2, 3, 3, 4, 4};        // trié (non décroissant)
    int arr4[] = {1, 3, 2, 4, 5};           // pas trié
    int arr5[] = {42};                      // un seul élément
    int arr6[] = {};                        // vide (possible si tu veux tester ça)

    if (is_sorted_nondecreasing(arr1,5)){
    printf("recherche jump: %i\n",jump_search(arr1,5,5));}
    else printf("recherche lineaire: %i\n",linear_search(arr1,5,10));
    return 0;
}

