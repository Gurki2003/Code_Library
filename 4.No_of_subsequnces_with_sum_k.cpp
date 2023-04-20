//print the number of sub sequence that have a sum k
#include <bits/stdc++.h>
using namespace std;

int sumofseq(vector<int> v, int sum, int index, int req)
{
    if (index >= v.size())
    {
        if (sum == req)
        {
            return 1;
        }
        return 0;
    }

    int element = v[index];
    sum = sum + element;
   
    int l = sumofseq(v, sum, index + 1, req);
    sum = sum - element;

    int r = sumofseq(v, sum, index + 1, req);
    return l+r; 
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);

    int sum = 0;
    int reqans = 2;
    vector<int> help;
    cout<< sumofseq(v, sum, 0, reqans);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}