// a number is dialed on a keypad phone
//  tell us what text can it genrate

#include<bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string>&ans,string mapping[])
{
    if(index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    int number = digits[index] -'0';
    string trav = mapping[number];
    for(int i=0;i<trav.length();i++)
    {
        output.push_back(trav[i]);
        solve(digits , output , index+1, ans, mapping);
        output.pop_back();
    }
}
int main()
{
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    string output;
    solve("23",output,0,ans, mapping);
    for(int i=0;i< ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}