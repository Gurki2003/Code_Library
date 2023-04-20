//print the sub sequence which has the sum as k
#include <bits/stdc++.h>
using namespace std;

void sumofseq(vector<int> v, int sum, int index, vector<int> help, int req)
{
    if (index >= v.size())
    {
        if (sum == req)
        {
            for (auto it : help)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    int element = v[index];
    sum = sum + element;
    help.push_back(element);
    sumofseq(v, sum, index + 1, help, req);
    help.pop_back();
    sum = sum - element;

    sumofseq(v, sum, index + 1, help, req);
}

int main()
{
    vector<int> v ={2,5,2,1,2};
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(1);

    int sum = 0;
    int reqans = 5;
    vector<int> help;
    sumofseq(v, sum, 0, help, reqans);
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