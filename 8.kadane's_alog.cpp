// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int arr[],int n)
    {
        int currentsum=0;
        int maxsum=-1;
        for(int i=0;i<n;i++)
        {
            currentsum+=arr[i];
            if(currentsum<0){
                currentsum=0;
            }
            maxsum=max(maxsum,currentsum);
        }
        return maxsum; 
    }
    int circularSubarraySum(int arr[], int num){
        if(num==1)
        {
            return arr[0];
        }
        
        int wrapsum=0;
        int nonwrapsum=0;
        int totalsum=0;
        nonwrapsum=kadane(arr,num);
        for(int i= 0;i<num;i++)
        {
            totalsum+=arr[i];
            arr[i]=-arr[i];
        }
        wrapsum=totalsum + kadane(arr,num);
        return max(wrapsum,nonwrapsum);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends