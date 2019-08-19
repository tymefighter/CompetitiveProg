#include<iostream>

using namespace std;

int a[21];
int n, m;

void read()
{
    cin>>n>>m;

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

bool solve(int i, int val)
{
    if(i == n)
    {
        if(val == 0)
            return true;
        else
            return false;
    }

    bool flag1 = solve(i + 1, val);
    if(flag1)
        return true;
    bool flag2 = solve(i + 1, val - a[i]);
    if(flag2)
        return true;

    return false;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        if(solve(0, m))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}