#include "fibo.h"

long long fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-2)+fibo(n-1);
}


long long fibo_dynamic(int n,long long * tableFib){
    if (n<=1){
        return n;
    }

    if (tableFib[n]!=-1){
        return tableFib[n];
    }
    else{
        tableFib[n]=fibo_dynamic(n-1,tableFib)+fibo_dynamic(n-2,tableFib);
        return tableFib[n];
    }
}
