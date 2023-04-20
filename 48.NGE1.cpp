/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to "next greater element on the right" for all elements of array
4. Input and output is handled for you.

"Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
e.g.
for the array [2 5 9 3 1 12 6 8 7]
Next greater for 2 is 5
Next greater for 5 is 9
Next greater for 9 is 12
Next greater for 3 is 12
Next greater for 1 is 12
Next greater for 12 is -1
Next greater for 6 is 8
Next greater for 8 is -1
Next greater for 7 is -1
*/

//Sol : https://youtu.be/XP8iEi9Aa8c?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// This approach is from Left to Right

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> v(n,-1);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    stack<int> st; // stack which will store indices of elements

    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            st.push(i);
        }
        else
        {
            //pop already existing elements in stack ,which are smaller than current element
            // and become their answer i.e N.G.E
                while(!st.empty() && arr[i]>arr[st.top()])
                {
                    v[st.top()]=arr[i];
                    st.pop();
                }
            st.push(i);
        }
    }
    for(auto &it:v)
    cout<<it<<" ";
}