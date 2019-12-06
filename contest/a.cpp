#include<iostream>

using namespace std;

void read_solve()
{
    int n;
    long long int sum = 0, x, ans;

    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>x;
        sum += x;
    }

    ans = sum / n;

    if(sum % n)
        ans ++;
    
    cout<<ans<<"\n";
}

int main()
{
    int q;
    cin>>q;

    while(q--)
        read_solve();

    return 0;
}