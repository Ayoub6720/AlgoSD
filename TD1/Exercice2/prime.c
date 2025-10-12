#include "prime.h"

int prime(int n){
if (n < 2) return 0;
int compt = 0;


for (int i = 2; i <= n; i++) {
    int is_p = 1;
    for (int j = 2; j< i; j += 1) {
        if (i % j == 0) { 
            is_p = 0; 
            break; }}

    if (is_p) compt+=1;}

    return compt;
}

int prime_opti(int n){
    if (n < 2) return 0;
    int is_prime[n + 1];
    for (int i = 0; i <= n; ++i) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= n; i++)
        if (is_prime[i]==1){
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = 0;}}

    int compt = 0;
    for (int i = 0; i <= n; i++) if (is_prime[i]) compt+=1;
    return compt;
}