#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> st;
string s;

bool solve()
{
    char c;
    int i;

    for(i = 0;i < s.size();i++)
    {
        c = s[i];
        if(c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if(st.empty())
                break;
            if(c == ')' && st.top() != '(')
                break;
            else if(c == ']' && st.top() != '[')
                break;
            else if(c == '}' && st.top() != '{')
                break;
            st.pop();
        }
    }

    if(i == s.size() && st.empty())
        return true;

    while(!st.empty())
        st.pop();
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}