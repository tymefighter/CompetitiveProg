#include<iostream>

using namespace std;

int main()
{
    int t;
    long long int n, k;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        n /= k;
        if(n % k == 0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}