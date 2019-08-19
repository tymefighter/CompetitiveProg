#include<iostream>
#include<string>
#include<stack>

using namespace std;

string s, pre, w;
stack<string> st;

void solve()
{
    int q, id, k;
    cin>>q;
    while(q--)
    {
        cin>>id;

        if(id == 1)
        {
            cin>>w;
            st.push(s);
            s = s + w;
        }
        else if(id == 2)
        {
            cin>>k;
            st.push(s);
            if(k != 0)
                s.erase(s.size() - k, string::npos);
        }
        else if(id == 3)
        {
            cin>>k;
            cout<<s[k - 1]<<"\n";
        }
        else
        {
            s = st.top();
            st.pop();
        }
    }
}

int main()
{
    solve();
    return 0;
}