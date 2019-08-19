#include<iostream>
#define EPS 0.000001

using namespace std;

int n;
int a[100005];
long long int sum;

void read()
{
    cin>>n;
    sum = 0;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        sum += a[i] * 1ll;
    }
}

int solve()
{
    int val;
    for(int i = 0;i < n;i++)
    {
        if(sum == n * (a[i] * 1ll))
            return i + 1;
    }

    return -1;
}

int main()
{
    int ans;
    int t;
    cin>>t;
    while(t--)
    {
        read();
        ans = solve();
        if(ans == -1)
            cout<<"Impossible\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}