#include<iostream>
#include<queue>
#include<set>
#include<stack>

using namespace std;

int n, k;
queue<int> q;
set<int> s;
stack<int> st;

void reset()
{
    s.clear();
    while(!q.empty())
        q.pop();
    while(!st.empty())
        st.pop();
}

void read_solve()
{
    cin>>n>>k;
    int id;

    while(n--)
    {
        cin>>id;

        if(s.find(id) == s.end())
        {
            if(q.size() == k)
            {
                s.erase(q.front());
                q.pop();
            }
            
            q.push(id);
            s.insert(id);
        }
    }

    cout<<q.size()<<"\n";
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    cout<<"\n";
}

int main()
{
    reset();
    read_solve();
    return 0;
}