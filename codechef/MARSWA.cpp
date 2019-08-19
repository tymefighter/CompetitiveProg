#include<iostream>

using namespace std;

long long int s1, s2;
int t1, t2, x;

long long int pow(int n)
{
    if(n % 2)
        return 2 * pow(n - 1);
    else
    {
        long long int val = pow(n / 2);
        return val * val;
    }
}

void read()
{
    cin>>s1>>s2>>t1>>t2;
    if(t1 > t2)
    {
        swap(t1, t2);
        swap(s1, s2);
    }
}

void solve()
{
    long long int d0 = s1 / pow(t1);
    long long int ans = d0 * pow(x);
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        solve();
    }

    return 0;
}