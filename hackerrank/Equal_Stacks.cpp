#include<iostream>
#include<stack>

using namespace std;

int n[3], h[3];
int a[100005];
stack<int> s[3];

void read()
{
    cin>>n[0]>>n[1]>>n[2];
    int i, j;

    for(j = 0;j < 3;j++)
    {
        h[j] = 0;
        for(i = 0;i < n[j];i++)
        {
            cin>>a[i];
            h[j] += a[i];
        }

        for(i = n[j] - 1; i >= 0;i--)
            s[j].push(a[i]);
    }
}

void solve()
{
    int i, idx;

    while(h[0] != h[1] || h[1] != h[2])
    {
        idx = 0;
        for(i = 0;i < 3;i++)
        {
            if(h[i] > h[idx])
                idx = i;
        }

        h[idx] -= s[idx].top();
        s[idx].pop();
    }

    cout<<h[0]<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}