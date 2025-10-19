#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    // return -1 if not found

    for(int i=0;i<n;i++){
        if (arr[i]==target) return i;
    }

    return -1;
}

int jump_search(int *arr, int n, int target)
{
    // jump search on sorted array, return index
    // of target, return -1 if not found
        int prev=0;
        int jump=floor(sqrt(n));
        for(int i=0;i<n;i+=jump){
            if (arr[i]==target) return i;
            else if (arr[i]<target){
                prev=i;
                }
            else break;
        for(int i=prev;i<=prev+jump;i++){
        if (arr[i]==target) return i;
        }
    }
    return -1;}

int binary_search(int *arr, int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int i = left + (right - left) / 2;

        if (arr[i] == target) {
            return i;
        }
        else if (arr[i] < target) {
            left = i + 1;
        }
        else {
            right = i - 1;
        }
    }

    return -1; 
}