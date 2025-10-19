#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    clock_t start, end;
    
    int n = 100000000;  
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int* liste=arr;
    int target=53283637;
    int taille=n;

    if (is_sorted_nondecreasing(liste,5)){

        start = clock();
        int i_jump =jump_search(liste,taille,target);
        end = clock();
        double time_jump =(double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        int i_binary =binary_search(liste,taille,target);
        end = clock();
        double time_binary =(double)(end-start)/CLOCKS_PER_SEC;



        printf("recherche jump en %f secondes: %i\n",time_jump,i_jump);
        printf("recherche binaire en %f secondes: %i\n",time_binary,i_binary);}


    else{

        start = clock();
        int i_lin =linear_search(liste,taille,target);
        end = clock();
        double time_lin =(double)(end-start)/CLOCKS_PER_SEC;

        printf("recherche lineaire en %f secondes: %i\n",time_lin,i_lin);}
    return 0;
}

