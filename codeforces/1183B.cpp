#include<iostream>

using namespace std;

int n, k;
int a[105];
int lower, higher;

void read_solve()
{
    cin>>n>>k;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(i)
        {
            lower = max(lower, a[i] - k);
            higher = min(higher, a[i] + k);
        }
        else
        {
            lower = a[i] - k;
            higher = a[i] + k;
        }
    }
    if(lower > higher || higher <= 0)
    {
        cout<<"-1\n";
        return;
    }

    cout<<higher<<"\n";
}

int main()
{
    int q;
    cin>>q;

    while(q--)
        read_solve();
    
    return 0;
}