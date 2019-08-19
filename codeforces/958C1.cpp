#include<iostream>

using namespace std;

int n, p;
int fd[100005], rev[100005], a[100005];

void read()
{
    cin>>n>>p;

    int i;
    for(i = 0;i < n;i++)
    {
        cin>>a[i];
        fd[i] = (i > 0 ? (fd[i - 1] + a[i]) % p : a[i] % p);
    }

    for(i = n - 1;i >= 0;i--)
        rev[i] = (i <= n - 2 ? (rev[i + 1] + a[i]) % p : a[i] % p);
}

void solve()
{
    int ans = -1;

    for(int i = 0;i <= n - 2;i++)
        ans = max(ans, fd[i] + rev[i + 1]);

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}