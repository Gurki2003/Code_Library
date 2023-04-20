#include<bits/stdc++.h>
using namespace std;
void findTriplets(int arr[], int n);
int main()
{
 int n=5 ;
 int arr[5]={0,-1,2,-3,1};
 findTriplets(arr,n);
 return 0;
}

    void findTriplets(int arr[], int n)
   { 
       sort(arr, arr+n);
       for (int i=0;i<n-2;i++){
           int j=i+1;
           int k=n-1;
           while (j<k){
               if (arr[i]+arr[j]+arr[k]==0){
                   cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                exit(0);
               }
               else if (arr[i]+arr[j]+arr[k]>0){
                   --k;
               }
               else{
                   ++j;
               }
           }
       }
       
   }