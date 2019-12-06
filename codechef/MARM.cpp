#include<iostream>

using namespace std;

int n, a[10005], b[10005];
long long k;

void read()
{
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    long long rot = k / n, val;
    int offset = k % n;

    for(int i = 0;i < n;i++)
    {
        val = rot;
        if(i < offset)
            val = rot + 1;
        val %= 3;

        if((i < (n - 1) / 2) || ((i == (n - 1) / 2) && ((n - 1) % 2 != 0)))
        {
            if(val == 0)
                b[i] = a[i];
            else if(val == 1)
                b[i] = a[i] ^ a[n - i - 1];
            else
                b[i] = a[n - i - 1];
        }
        else if((i == (n - 1) / 2) && ((n - 1) % 2 == 0))
        {
            if(rot > 0 || i < offset)
                b[i] = 0;
            else
                b[i] = a[i];
        }
        else
        {
            if(val == 0)
                b[i] = a[i];
            else if(val == 1)
                b[i] = a[n - i - 1];
            else
                b[i] = a[i] ^ a[n - i - 1];
        }
    }

    for(int i = 0;i < n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}