#include<iostream>
#include<algorithm>

using namespace std;

int a[100005];
int n;

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int solve()
{
    sort(a, a+n);
    int n_mem = 0;

    for(int i = 0;i < n;i++)
    {
        if(n_mem >= a[i])
            n_mem++;
        else
            return n_mem;
    }
    return n_mem;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<solve()<<'\n';
    }
    return 0;
}