#include <bits/stdc++.h>
using namespace std;

bool checkParathesis(string &s)
{
    stack<char> st;
    int i=0;
    for ( i = 0; i<=s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
        {
            if(st.top()!= '(')
            {
                return 0;
            }else{
                st.pop();
            }
        }
        else if (s[i] == '}')
        {
            if(st.top()!= '{')
            {
                return 0;
            }else{
                st.pop();
            }
        }
        if (s[i] == ']')
        {
            if(st.top()!= '[')
            {
                return 0;
            }else{
                st.pop();
            }
        }
    }
    if(st.empty())
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string s;
    cout << "Enter the paranthesis string" << endl;
    cin >> s;
    if (checkParathesis(s))
    {
        cout << "they are balanced ";
    }
    else
    {
        cout << "they are not balanced ";
    }
}