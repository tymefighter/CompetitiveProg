#include<iostream>

using namespace std;

int freq, amp;

void solve(int t)
{
    int i, j, k;
    

    for(k = 0;k < freq;k++)
    {
        for(j = 1;j <= amp;j++)
        {
            for(i = 1;i <= j;i++)
                cout<<j;
            cout<<"\n";
        }
        for(j = amp - 1;j >= 1;j--)
        {
            for(i = 1;i <= j;i++)
                cout<<j;
            cout<<"\n";
        }
        if(!(t == 0 && k == freq - 1))
            cout<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>amp>>freq;
        solve(t);
    }
    return 0;
}