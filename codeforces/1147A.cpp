#include<iostream>

using namespace std;

int n, k;
int first[100005], last[100005];

void read()
{
    int x, i;
    cin>>n>>k;
    for(i = 1;i <= n;i++)
        first[i] = last[i] = -1;

    for(i = 0;i < k;i++)
    {
        cin>>x;
        if(first[x] == -1)
            first[x] = i;

        last[x] = i;
    }
}

void solve()
{
    long long int ans = 0;

    for(int x = 1;x <= n;x++)
    {
        if(first[x] == -1)
        {
            ans += 1ll;
            if(x > 1)
                ans += 1ll;
            if(x < n)
                ans += 1ll;
        }
        else
        {    
            if(x > 1 && first[x] > last[x-1])
                ans += 1ll;
            if(x < n && first[x] > last[x+1])
                ans += 1ll;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    
    return 0;
}