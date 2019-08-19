#include<iostream>

using namespace std;

int n;
int a[1001];
bool vis[1001];


void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        a[i]--;
        vis[i] = false;
    }
}

int find_ans(int x)
{
    if(vis[x])
        return x;
    vis[x] = true;
    int ans = find_ans(a[x]);
    vis[x] = false;

    return ans;
}

void solve()
{
    for(int i = 0;i < n;i++)
        cout<<find_ans(i)+1<<" ";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}