#include <stdio.h>
#include <time.h>
#include "prime.h"

int main(void) {
    int n=500000;
    clock_t start, end;

    start = clock();
    int r=prime(n);
    end = clock();
    double time_1=(double)(end-start)/CLOCKS_PER_SEC;

    
    

    start = clock();
    int rd = prime_opti(n);
    end = clock();
    double time_2=(double)(end-start)/CLOCKS_PER_SEC;



    
    printf("prime(%d) naif = %d en %f secondes\n", n, r, time_1);
    printf("prime(%d) efficace = %d en %f secondes\n", n, rd, time_2);
}
