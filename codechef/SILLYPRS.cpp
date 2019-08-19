#include<iostream>

using namespace std;

int n;
int num1, num2;
long long int ans;

void read_solve()
{
    num1 = num2 = 0;

    cin>>n;
    int i;
    long long int x;
    
    ans = 0;

    for(i = 0;i < n;i++)
    {
        cin>>x;
        if(x % 2)
            num1 ++;

        ans += (x / 2);
    }
    for(i = 0;i < n;i++)
    {
        cin>>x;
        if(x % 2)
            num2 ++;

        ans += (x / 2);
    }

    ans += min(num1, num2) * 1ll;

    cout<<ans<<"\n";
}


int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        read_solve();
    }
    
    return 0;
}