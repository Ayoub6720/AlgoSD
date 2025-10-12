#include <stdio.h>
#include <time.h>
#include "prime.h"

int main(void) {
    int n=30;
    clock_t start, end;

    start = clock();
    
    end = clock();
    double time_1=(double)(end-start)/CLOCKS_PER_SEC;

    
    

    start = clock();
    
    end = clock();
    double time_2=(double)(end-start)/CLOCKS_PER_SEC;



    
    printf("prime(%d) naif = %lld en %f secondes\n", n, r,time_1);
    printf("prime(%d) efficace = %lld en %f secondes\n", n, rd,time_2);
}
