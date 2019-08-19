#include<iostream>

using namespace std;

long long int n, k;
int m;
long long int a[100005];

void read()
{
    cin>>n>>m>>k;

    for(int i = 0;i < m;i++)
    {
        cin>>a[i];
        a[i]--;
    }
}

void solve()
{
    int i = 0, j, ans = 0;

    long long int x, val = 0;

    while(i < m)
    {
        x = (a[i] - val) / k;
        j = i + 1;
        while(j < m && x == (a[j] - val) / k)
            j++;
        
        val += j - i;
        ans++;
        i = j;
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}