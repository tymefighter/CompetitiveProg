#include<iostream>

using namespace std;

int n;
int rem0, rem1, rem2;

void read()
{
    int x;
    cin>>n;
    rem0 = rem1 = rem2 = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(x % 3 == 0)
            rem0++;
        else if(x % 3 == 1)
            rem1++;
        else
            rem2++;
    }
}

int solve()
{
    int ans = 0;

    ans += rem0;

    if(rem1 < rem2)
    {
        ans += rem1;
        rem2 = rem2 - rem1;
        ans += (rem2) / 3;
    }
    else
    {
        ans += rem2;
        rem1 = rem1 - rem2;
        ans += (rem1) / 3;
    }
     
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        cout<<solve()<<"\n";
    }

    return 0;
}