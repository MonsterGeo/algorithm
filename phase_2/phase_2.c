#include <stdio.h>
#include <math.h>
#include <limits.h>
/*
 插入排序
*/
void Insert_Sort(int arr[],int len)
{
    int i,j,key;
    for(j = 1; j <len;j++)
    {   
        i = j-1;
        key = arr[j];
        while(i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i-1;
             
        }
        arr[i+1] = key;  
    }
    for(int k = 0; k < len;k++)
    {
        printf("%d ",arr[k]);   
    }
    printf(" \r\n");
}

/*
归并排序
*/

void merge(int arr[],int p,int q, int r)
{
    //注意，必须满足条件 p <= q < r
    int n1 = q - p + 1,i,j;
    int n2 = r - q;
    int L[n1+1],R[n2+1];
    for(i = 0; i < n1 ;i++)
    {
        L[i] = arr[p+i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = arr[q+j+1];
    }
    //由于实际编程不存在无穷大，我们用Limit提供的定义来替代
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for(int k= p; k < r ; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i = i+1;
        }
        else
        {
            arr[k] = R[j];
            j = j+1;
        }
    }

}

void merge_sort(int arr[],int p,int r)
{
    if(p < r)
    {
        int q = floor((p+r)/2);
        merge_sort(arr,p,q); //q前面的子数组
        merge_sort(arr,q+1,r); //q到r的子数组
        merge(arr,p,q,r);
    }
}

int main()
{
    int A[] = {5,2,4,7,1,3,2,6};
    int Alen = sizeof(A) / sizeof(A[0]);
    Insert_Sort(A,Alen); //插入排序
    merge_sort(A,0,Alen-1);//归并排序
    for(int i = 0; i < Alen; i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}