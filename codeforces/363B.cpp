#include<iostream>

using namespace std;

int n, k;
int a[1000005];

void read()
{
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int solve()
{
    int i, min_val, val = 0, idx;

    for(i = 0;i < k;i++)
        val += a[i];

    min_val = val;
    idx = 0;
    
    for(i = k;i < n;i++)
    {
        val = val + a[i] - a[i - k];
        if(min_val > val)
        {
            idx = i - k + 1;
            min_val = val;
        }
    }
    return idx + 1;
}

int main()
{
    cin>>n>>k;
    read();
    cout<<solve()<<'\n';
    return 0;
}