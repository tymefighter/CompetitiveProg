#include<iostream>
#include<cmath>

using namespace std;

long long int n;

void solve()
{
    if(n == 1)
    {
        cout<<"0 0\n";
        return;
    }

    n--;

    if(n % 2)
    {
        cout<<"Alas\n";
        return;
    }

    long long int ans2 = n / 2;
    long long int ans1 = log2((double)(n + 1));

    cout<<ans1<<" "<<ans2<<"\n";
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