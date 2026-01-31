#include <stdio.h>
#include <stdlib.h>

int HASH_fun(int arr[], int k)
{
    return k;
}

int HASH_INSERT(int arr[],int k,int size){
    int i = 0;
    int j = HASH_fun(arr, k);
    int m = size;
    while(i <= m){
        if(arr[j] == NULL)
        {
            arr[j] = k;
            return j;
        }
        else i++;
    }
    printf("Hash table is full\n");
    return 0;
}

int HASH_SEARCH(int arr[],int k,int size){
    int i = 0;
    int j = HASH_fun(arr, k);
    int m = size;
    while(i <= m){
        if(arr[j] == k)
        {
            return j;
        }
        else i++;
    }
    printf("Element not found\n");
    return 0;
}

int main()
{

    return 0;
}