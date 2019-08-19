#include<iostream>
#include<cmath>

using namespace std;

long long int n;

void solve()
{
    n = max(n, 0ll);
    if(n == 0)
    {
        cout<<"0\n";
        return;
    }
    long long int sqrn = sqrt((double)n);
    long long int prev = n, curr;
    long long int ans = n;

    for(int i = 2;i <= sqrn;i++)
    {
        curr = n / i;
        ans += (prev - curr) * (i - 1);
        ans += (n / i);
        prev = curr;
    }
    if(n / sqrn != sqrn)
    {
        curr = n / (sqrn + 1);
        ans += (prev - curr) * (sqrn);
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve();
    }
    
    return 0;
}