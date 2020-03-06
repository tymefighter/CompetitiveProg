#include<iostream>

using namespace std;

int n;

void solve()
{
    int ans = n;
    for(int i = 2;i * i <= n;i++)
    {
        if(n % i)
            continue;
        ans -= ans / i;
        while(n % i == 0)
            n /= i;
    }

    if(n != 1)
        ans -= ans / n;

    cout<<ans<<"\n";
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        if(n == 1)
            cout<<"0\n";
        else
            solve();
    }

    return 0;
}