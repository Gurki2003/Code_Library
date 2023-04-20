// Power set of a string
#include<bits/stdc++.h>
using namespace std;

void powerset(vector<char>a, string s, int index, vector<string> &ans)
{
    if(index >= a.size())
    {
        ans.push_back(s);
        return;
    }
    powerset(a,s,index+1,ans);

    char element = a[index];
    s.push_back(element);
    powerset(a,s,index+1,ans);
    
}
int main()
{
    vector<string> ans;
    vector<char> a;
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    powerset(a,"",0,ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}