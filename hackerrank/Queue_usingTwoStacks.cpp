#include<iostream>
#include<stack>

using namespace std;

stack<int> s1, s2;

void enq(int x)
{
    s1.push(x);
}

void deq()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    s2.pop();
}

void top()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    cout<<s2.top()<<"\n";
}

void solve()
{
    int q, id, x;
    cin>>q;
    while(q--)
    {
        cin>>id;
        if(id == 1)
        {
            cin>>x;
            enq(x);
        }
        else if(id == 2)
            deq();
        else
            top();
    }
}

int main()
{
    solve();
    return 0;
}