#include <iostream>
#include <vector>
#include<bits\stdc++.h>
using namespace std;
void swap(int arr[],int i, int j)
{
    int temp=a[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void wavesort(int arr[],int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i]>arr[i-1])
        {
            swap(arr,i,i-1);
        }
        if(a[i]>a[i+1] && i<=n-2)
        {
            swap(arr,i,i+1);
        }
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    wavesort(arr,7);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
}


